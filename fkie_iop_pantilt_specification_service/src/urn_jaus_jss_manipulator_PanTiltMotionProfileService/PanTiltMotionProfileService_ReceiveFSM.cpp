/**
ROS/IOP Bridge
Copyright (c) 2017 Fraunhofer

This program is dual licensed; you can redistribute it and/or
modify it under the terms of the GNU General Public License
version 2 as published by the Free Software Foundation, or
enter into a proprietary license agreement with the copyright
holder.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; or you can read the full license at
<http://www.gnu.de/documents/gpl-2.0.html>
*/

/** \author Alexander Tiderko */


#include "urn_jaus_jss_manipulator_PanTiltMotionProfileService/PanTiltMotionProfileService_ReceiveFSM.h"
#include <fkie_iop_component/iop_component.h>
#include <fkie_iop_component/iop_config.h>
#include "urn_jaus_jss_manipulator_PanTiltSpecificationService/PanTiltSpecificationServiceService.h"
#include <algorithm>


using namespace JTS;
using namespace urn_jaus_jss_manipulator_PanTiltSpecificationService;

namespace urn_jaus_jss_manipulator_PanTiltMotionProfileService
{



PanTiltMotionProfileService_ReceiveFSM::PanTiltMotionProfileService_ReceiveFSM(urn_jaus_jss_core_Transport::Transport_ReceiveFSM* pTransport_ReceiveFSM, urn_jaus_jss_core_Events::Events_ReceiveFSM* pEvents_ReceiveFSM, urn_jaus_jss_core_AccessControl::AccessControl_ReceiveFSM* pAccessControl_ReceiveFSM)
{

	/*
	 * If there are other variables, context must be constructed last so that all
	 * class variables are available if an EntryAction of the InitialState of the
	 * statemachine needs them.
	 */
	context = new PanTiltMotionProfileService_ReceiveFSMContext(*this);

	this->pTransport_ReceiveFSM = pTransport_ReceiveFSM;
	this->pEvents_ReceiveFSM = pEvents_ReceiveFSM;
	this->pAccessControl_ReceiveFSM = pAccessControl_ReceiveFSM;
	joint1_max_speed = 1.5;
	joint1_max_accel = 1.5;
	joint1_max_decel = 1.5;
	joint2_max_speed = 1.5;
	joint2_max_accel = 1.5;
	joint2_max_decel = 1.5;
	p_has_profile = false;
}



PanTiltMotionProfileService_ReceiveFSM::~PanTiltMotionProfileService_ReceiveFSM()
{
	delete context;
}

void PanTiltMotionProfileService_ReceiveFSM::setupNotifications()
{
	pAccessControl_ReceiveFSM->registerNotification("Receiving_Ready_NotControlled", ieHandler, "InternalStateChange_To_PanTiltMotionProfileService_ReceiveFSM_Receiving_Ready_NotControlled", "AccessControl_ReceiveFSM");
	pAccessControl_ReceiveFSM->registerNotification("Receiving_Ready_Controlled", ieHandler, "InternalStateChange_To_PanTiltMotionProfileService_ReceiveFSM_Receiving_Ready_Controlled", "AccessControl_ReceiveFSM");
	pAccessControl_ReceiveFSM->registerNotification("Receiving_Ready", ieHandler, "InternalStateChange_To_PanTiltMotionProfileService_ReceiveFSM_Receiving_Ready_NotControlled", "AccessControl_ReceiveFSM");
	pAccessControl_ReceiveFSM->registerNotification("Receiving", ieHandler, "InternalStateChange_To_PanTiltMotionProfileService_ReceiveFSM_Receiving_Ready_NotControlled", "AccessControl_ReceiveFSM");
	registerNotification("Receiving_Ready_NotControlled", pAccessControl_ReceiveFSM->getHandler(), "InternalStateChange_To_AccessControl_ReceiveFSM_Receiving_Ready_NotControlled", "PanTiltMotionProfileService_ReceiveFSM");
	registerNotification("Receiving_Ready_Controlled", pAccessControl_ReceiveFSM->getHandler(), "InternalStateChange_To_AccessControl_ReceiveFSM_Receiving_Ready_Controlled", "PanTiltMotionProfileService_ReceiveFSM");
	registerNotification("Receiving_Ready", pAccessControl_ReceiveFSM->getHandler(), "InternalStateChange_To_AccessControl_ReceiveFSM_Receiving_Ready", "PanTiltMotionProfileService_ReceiveFSM");
	registerNotification("Receiving", pAccessControl_ReceiveFSM->getHandler(), "InternalStateChange_To_AccessControl_ReceiveFSM_Receiving", "PanTiltMotionProfileService_ReceiveFSM");
	iop::Component &cmp = iop::Component::get_instance();
	PanTiltSpecificationServiceService *spec_srv = static_cast<PanTiltSpecificationServiceService*>(cmp.get_service("PanTiltSpecificationService"));
	if (spec_srv != NULL) {
		p_joint_limits_current = spec_srv->pPanTiltSpecificationService_ReceiveFSM->getLimits();
	} else {
		throw std::runtime_error("[PanTiltMotionProfileService] no PanTiltSpecificationService in configuration found! Please include this plugin first (in the list)!");
	}
	iop::Config cfg("~PanTiltMotionProfileService");
	cfg.param("joint1_max_speed", joint1_max_speed, joint1_max_speed);
	cfg.param("joint1_max_accel", joint1_max_accel, joint1_max_accel);
	cfg.param("joint1_max_decel", joint1_max_decel, joint1_max_decel);
	cfg.param("joint2_max_speed", joint2_max_speed, joint2_max_speed);
	cfg.param("joint2_max_accel", joint2_max_accel, joint2_max_accel);
	cfg.param("joint2_max_decel", joint2_max_decel, joint2_max_decel);
	p_joint_limits_current.first.has_acceleration_limits = true;
	p_joint_limits_current.first.max_acceleration = joint1_max_accel;
	p_joint_limits_current.first.has_velocity_limits = true;
	p_joint_limits_current.first.max_velocity = joint1_max_speed;
	p_joint_limits_current.second.has_acceleration_limits = true;
	p_joint_limits_current.second.max_acceleration = joint2_max_accel;
	p_joint_limits_current.second.has_velocity_limits = true;
	p_joint_limits_current.second.max_velocity = joint2_max_speed;
	p_motion_profile.getBody()->getPanTiltMotionProfileRec()->setJoint1MaxAccelerationRate(joint1_max_accel);
	p_motion_profile.getBody()->getPanTiltMotionProfileRec()->setJoint1MaxDecelerationRate(joint1_max_decel);
	p_motion_profile.getBody()->getPanTiltMotionProfileRec()->setJoint1MaxSpeed(joint1_max_speed);
	p_motion_profile.getBody()->getPanTiltMotionProfileRec()->setJoint2MaxAccelerationRate(joint2_max_accel);
	p_motion_profile.getBody()->getPanTiltMotionProfileRec()->setJoint2MaxDecelerationRate(joint2_max_decel);
	p_motion_profile.getBody()->getPanTiltMotionProfileRec()->setJoint2MaxSpeed(joint2_max_speed);
	p_has_profile = true;
	p_pub_joint1_limits = cfg.advertise<moveit_msgs::JointLimits>("joint1_limits", 10, true);
	p_pub_joint2_limits = cfg.advertise<moveit_msgs::JointLimits>("joint2_limits", 10, true);
	p_pub_joint1_limits.publish(p_joint_limits_current.first);
	p_pub_joint2_limits.publish(p_joint_limits_current.second);
}

void PanTiltMotionProfileService_ReceiveFSM::sendReportPanTiltMotionProfileAction(QueryPanTiltMotionProfile msg, Receive::Body::ReceiveRec transportData)
{
	/// Insert User Code HERE
	ROS_DEBUG_NAMED("PanTiltMotionProfileService", "send pantilt motion profile to %s", transportData.getAddress().str().c_str());
	sendJausMessage(p_motion_profile, transportData.getAddress());
}

void PanTiltMotionProfileService_ReceiveFSM::setPanTiltMotionProfileAction(SetPanTiltMotionProfile msg, Receive::Body::ReceiveRec transportData)
{
	/// Insert User Code HERE
	ROS_DEBUG_NAMED("PanTiltMotionProfileService", "set new pantilt motion profile from %s", transportData.getAddress().str().c_str());
	SetPanTiltMotionProfile::Body::PanTiltMotionProfileRec* rec = msg.getBody()->getPanTiltMotionProfileRec();
	p_motion_profile.getBody()->getPanTiltMotionProfileRec()->setJoint1MaxAccelerationRate(rec->getJoint1MaxAccelerationRate());
	p_motion_profile.getBody()->getPanTiltMotionProfileRec()->setJoint1MaxDecelerationRate(rec->getJoint1MaxDecelerationRate());
	p_motion_profile.getBody()->getPanTiltMotionProfileRec()->setJoint1MaxSpeed(rec->getJoint1MaxSpeed());
	p_motion_profile.getBody()->getPanTiltMotionProfileRec()->setJoint2MaxAccelerationRate(rec->getJoint2MaxAccelerationRate());
	p_motion_profile.getBody()->getPanTiltMotionProfileRec()->setJoint2MaxDecelerationRate(rec->getJoint2MaxDecelerationRate());
	p_motion_profile.getBody()->getPanTiltMotionProfileRec()->setJoint2MaxSpeed(rec->getJoint2MaxSpeed());
	p_joint_limits_current.first.max_acceleration = rec->getJoint1MaxAccelerationRate();
	p_joint_limits_current.first.max_velocity = rec->getJoint1MaxSpeed();
	p_joint_limits_current.second.max_acceleration = rec->getJoint2MaxAccelerationRate();
	p_joint_limits_current.second.max_velocity = rec->getJoint2MaxSpeed();
	p_pub_joint1_limits.publish(p_joint_limits_current.first);
	p_pub_joint2_limits.publish(p_joint_limits_current.second);
	pNotifyListeners(transportData.getAddress(), p_motion_profile);
}

void PanTiltMotionProfileService_ReceiveFSM::reset_motion_profile()
{
	ROS_DEBUG_NAMED("PanTiltMotionProfileService", "reset pantilt motion profile to defaults");
	p_motion_profile.getBody()->getPanTiltMotionProfileRec()->setJoint1MaxAccelerationRate(joint1_max_accel);
	p_motion_profile.getBody()->getPanTiltMotionProfileRec()->setJoint1MaxDecelerationRate(joint1_max_decel);
	p_motion_profile.getBody()->getPanTiltMotionProfileRec()->setJoint1MaxSpeed(joint1_max_speed);
	p_motion_profile.getBody()->getPanTiltMotionProfileRec()->setJoint2MaxAccelerationRate(joint2_max_accel);
	p_motion_profile.getBody()->getPanTiltMotionProfileRec()->setJoint2MaxDecelerationRate(joint2_max_decel);
	p_motion_profile.getBody()->getPanTiltMotionProfileRec()->setJoint2MaxSpeed(joint2_max_speed);
	p_joint_limits_current.first.has_acceleration_limits = true;
	p_joint_limits_current.first.max_acceleration = joint1_max_accel;
	p_joint_limits_current.first.has_velocity_limits = true;
	p_joint_limits_current.first.max_velocity = joint1_max_speed;
	p_joint_limits_current.second.has_acceleration_limits = true;
	p_joint_limits_current.second.max_acceleration = joint2_max_accel;
	p_joint_limits_current.second.has_velocity_limits = true;
	p_joint_limits_current.second.max_velocity = joint2_max_speed;
	p_pub_joint1_limits.publish(p_joint_limits_current.first);
	p_pub_joint2_limits.publish(p_joint_limits_current.second);
	pNotifyListeners(*this->jausRouter->getJausAddress(), p_motion_profile);
}

bool PanTiltMotionProfileService_ReceiveFSM::isControllingClient(Receive::Body::ReceiveRec transportData)
{
	//// By default, inherited guards call the parent function.
	//// This can be replaced or modified as needed.
	return pAccessControl_ReceiveFSM->isControllingClient(transportData );
}

bool PanTiltMotionProfileService_ReceiveFSM::panTiltMotionProfileExists()
{
	/// Insert User Code HERE
	return p_has_profile;
}

void PanTiltMotionProfileService_ReceiveFSM::add_listener(iop::PanTiltMotionProfileListenerInterface *listener)
{
	if (listener != NULL) {
		std::vector<iop::PanTiltMotionProfileListenerInterface*>::iterator res = std::find(p_motionp_listener.begin(), p_motionp_listener.end(), listener);
		if (res == p_motionp_listener.end()) {
			p_motionp_listener.push_back(listener);
		}
	}
}

void PanTiltMotionProfileService_ReceiveFSM::pNotifyListeners(JausAddress reporter, ReportPanTiltMotionProfile profile)
{
	for (unsigned int i = 0; i < p_motionp_listener.size(); i++) {
		p_motionp_listener[i]->motion_profile_received(reporter, profile);
	}
}

};
