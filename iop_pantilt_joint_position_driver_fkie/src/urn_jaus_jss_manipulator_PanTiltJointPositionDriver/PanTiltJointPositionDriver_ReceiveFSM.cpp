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


#include "urn_jaus_jss_manipulator_PanTiltJointPositionDriver/PanTiltJointPositionDriver_ReceiveFSM.h"

#include <iop_component_fkie/iop_component.h>
#include <iop_component_fkie/iop_config.h>
#include "urn_jaus_jss_manipulator_PanTiltSpecificationService/PanTiltSpecificationServiceService.h"



using namespace JTS;
using namespace urn_jaus_jss_manipulator_PanTiltSpecificationService;
using namespace urn_jaus_jss_manipulator_PanTiltMotionProfileService;

namespace urn_jaus_jss_manipulator_PanTiltJointPositionDriver
{



PanTiltJointPositionDriver_ReceiveFSM::PanTiltJointPositionDriver_ReceiveFSM(urn_jaus_jss_core_Transport::Transport_ReceiveFSM* pTransport_ReceiveFSM, urn_jaus_jss_core_Events::Events_ReceiveFSM* pEvents_ReceiveFSM, urn_jaus_jss_core_AccessControl::AccessControl_ReceiveFSM* pAccessControl_ReceiveFSM, urn_jaus_jss_core_Management::Management_ReceiveFSM* pManagement_ReceiveFSM)
{

	/*
	 * If there are other variables, context must be constructed last so that all
	 * class variables are available if an EntryAction of the InitialState of the
	 * statemachine needs them.
	 */
	context = new PanTiltJointPositionDriver_ReceiveFSMContext(*this);

	this->pTransport_ReceiveFSM = pTransport_ReceiveFSM;
	this->pEvents_ReceiveFSM = pEvents_ReceiveFSM;
	this->pAccessControl_ReceiveFSM = pAccessControl_ReceiveFSM;
	this->pManagement_ReceiveFSM = pManagement_ReceiveFSM;
	p_joint1_name = "";
	p_joint2_name = "";
	p_joint1_cmd_position = 0.0;
	p_joint2_cmd_position = 0.0;
	p_joint1_position = 0.0;
	p_joint2_position = 0.0;
}



PanTiltJointPositionDriver_ReceiveFSM::~PanTiltJointPositionDriver_ReceiveFSM()
{
	delete context;
}

void PanTiltJointPositionDriver_ReceiveFSM::setupNotifications()
{
	pManagement_ReceiveFSM->registerNotification("Receiving_Ready_NotControlled_Init", ieHandler, "InternalStateChange_To_PanTiltJointPositionDriver_ReceiveFSM_Receiving_Ready_NotControlled_Init", "Management_ReceiveFSM");
	pManagement_ReceiveFSM->registerNotification("Receiving_Ready_NotControlled_Standby", ieHandler, "InternalStateChange_To_PanTiltJointPositionDriver_ReceiveFSM_Receiving_Ready_NotControlled_Standby", "Management_ReceiveFSM");
	pManagement_ReceiveFSM->registerNotification("Receiving_Ready_NotControlled_Failure", ieHandler, "InternalStateChange_To_PanTiltJointPositionDriver_ReceiveFSM_Receiving_Ready_NotControlled_Failure", "Management_ReceiveFSM");
	pManagement_ReceiveFSM->registerNotification("Receiving_Ready_NotControlled_Shutdown", ieHandler, "InternalStateChange_To_PanTiltJointPositionDriver_ReceiveFSM_Receiving_Ready_NotControlled_Shutdown", "Management_ReceiveFSM");
	pManagement_ReceiveFSM->registerNotification("Receiving_Ready_NotControlled_Emergency", ieHandler, "InternalStateChange_To_PanTiltJointPositionDriver_ReceiveFSM_Receiving_Ready_NotControlled_Emergency", "Management_ReceiveFSM");
	pManagement_ReceiveFSM->registerNotification("Receiving_Ready_NotControlled", ieHandler, "InternalStateChange_To_PanTiltJointPositionDriver_ReceiveFSM_Receiving_Ready_NotControlled_Standby", "Management_ReceiveFSM");
	pManagement_ReceiveFSM->registerNotification("Receiving_Ready_Controlled_Standby", ieHandler, "InternalStateChange_To_PanTiltJointPositionDriver_ReceiveFSM_Receiving_Ready_Controlled_Standby", "Management_ReceiveFSM");
	pManagement_ReceiveFSM->registerNotification("Receiving_Ready_Controlled_Ready", ieHandler, "InternalStateChange_To_PanTiltJointPositionDriver_ReceiveFSM_Receiving_Ready_Controlled_Ready", "Management_ReceiveFSM");
	pManagement_ReceiveFSM->registerNotification("Receiving_Ready_Controlled_Emergency", ieHandler, "InternalStateChange_To_PanTiltJointPositionDriver_ReceiveFSM_Receiving_Ready_Controlled_Emergency", "Management_ReceiveFSM");
	pManagement_ReceiveFSM->registerNotification("Receiving_Ready_Controlled", ieHandler, "InternalStateChange_To_PanTiltJointPositionDriver_ReceiveFSM_Receiving_Ready_Controlled_Standby", "Management_ReceiveFSM");
	pManagement_ReceiveFSM->registerNotification("Receiving_Ready", ieHandler, "InternalStateChange_To_PanTiltJointPositionDriver_ReceiveFSM_Receiving_Ready_NotControlled_Standby", "Management_ReceiveFSM");
	pManagement_ReceiveFSM->registerNotification("Receiving", ieHandler, "InternalStateChange_To_PanTiltJointPositionDriver_ReceiveFSM_Receiving_Ready_NotControlled_Standby", "Management_ReceiveFSM");
	registerNotification("Receiving_Ready_NotControlled_Standby", pManagement_ReceiveFSM->getHandler(), "InternalStateChange_To_Management_ReceiveFSM_Receiving_Ready_NotControlled_Standby", "PanTiltJointPositionDriver_ReceiveFSM");
	registerNotification("Receiving_Ready_NotControlled_Init", pManagement_ReceiveFSM->getHandler(), "InternalStateChange_To_Management_ReceiveFSM_Receiving_Ready_NotControlled_Init", "PanTiltJointPositionDriver_ReceiveFSM");
	registerNotification("Receiving_Ready_NotControlled_Failure", pManagement_ReceiveFSM->getHandler(), "InternalStateChange_To_Management_ReceiveFSM_Receiving_Ready_NotControlled_Failure", "PanTiltJointPositionDriver_ReceiveFSM");
	registerNotification("Receiving_Ready_NotControlled_Shutdown", pManagement_ReceiveFSM->getHandler(), "InternalStateChange_To_Management_ReceiveFSM_Receiving_Ready_NotControlled_Shutdown", "PanTiltJointPositionDriver_ReceiveFSM");
	registerNotification("Receiving_Ready_NotControlled_Emergency", pManagement_ReceiveFSM->getHandler(), "InternalStateChange_To_Management_ReceiveFSM_Receiving_Ready_NotControlled_Emergency", "PanTiltJointPositionDriver_ReceiveFSM");
	registerNotification("Receiving_Ready_NotControlled", pManagement_ReceiveFSM->getHandler(), "InternalStateChange_To_Management_ReceiveFSM_Receiving_Ready_NotControlled", "PanTiltJointPositionDriver_ReceiveFSM");
	registerNotification("Receiving_Ready_Controlled_Standby", pManagement_ReceiveFSM->getHandler(), "InternalStateChange_To_Management_ReceiveFSM_Receiving_Ready_Controlled_Standby", "PanTiltJointPositionDriver_ReceiveFSM");
	registerNotification("Receiving_Ready_Controlled_Ready", pManagement_ReceiveFSM->getHandler(), "InternalStateChange_To_Management_ReceiveFSM_Receiving_Ready_Controlled_Ready", "PanTiltJointPositionDriver_ReceiveFSM");
	registerNotification("Receiving_Ready_Controlled_Emergency", pManagement_ReceiveFSM->getHandler(), "InternalStateChange_To_Management_ReceiveFSM_Receiving_Ready_Controlled_Emergency", "PanTiltJointPositionDriver_ReceiveFSM");
	registerNotification("Receiving_Ready_Controlled", pManagement_ReceiveFSM->getHandler(), "InternalStateChange_To_Management_ReceiveFSM_Receiving_Ready_Controlled", "PanTiltJointPositionDriver_ReceiveFSM");
	registerNotification("Receiving_Ready", pManagement_ReceiveFSM->getHandler(), "InternalStateChange_To_Management_ReceiveFSM_Receiving_Ready", "PanTiltJointPositionDriver_ReceiveFSM");
	registerNotification("Receiving", pManagement_ReceiveFSM->getHandler(), "InternalStateChange_To_Management_ReceiveFSM_Receiving", "PanTiltJointPositionDriver_ReceiveFSM");

	iop::Component &cmp = iop::Component::get_instance();
	PanTiltSpecificationServiceService *spec_srv = static_cast<PanTiltSpecificationServiceService*>(cmp.get_service("PanTiltSpecificationService"));
	if (spec_srv != NULL) {
		std::pair<std::string, std::string> joint_names = spec_srv->pPanTiltSpecificationService_ReceiveFSM->getJointNames();
		p_joint1_name = joint_names.first;
		p_joint2_name = joint_names.second;
	} else {
		throw std::runtime_error("[PanTiltJointPositionDriver] no PanTiltSpecificationService in configuration found! Please include this plugin first (in the list)!");
	}

	iop::Config cfg("~PanTiltJointPositionDriver");
	p_pub_cmd_pos_joints = cfg.advertise<sensor_msgs::JointState>("cmd_pos_joints", 1, false);
	p_pub_cmd_pos_pan = cfg.advertise<std_msgs::Float64>("cmd_pos_pan", 1, false);
	p_pub_cmd_pos_tilt = cfg.advertise<std_msgs::Float64>("cmd_pos_tilt", 1, false);
	p_pub_cmd_pos_pan32 = cfg.advertise<std_msgs::Float32>("cmd_pos_pan32", 1, false);
	p_pub_cmd_pos_tilt32 = cfg.advertise<std_msgs::Float32>("cmd_pos_tilt32", 1, false);
}

void PanTiltJointPositionDriver_ReceiveFSM::sendReportCommandedPanTiltJointPositionsAction(QueryCommandedPanTiltJointPositions msg, Receive::Body::ReceiveRec transportData)
{
	uint16_t subsystem_id = transportData.getSrcSubsystemID();
	uint8_t node_id = transportData.getSrcNodeID();
	uint8_t component_id = transportData.getSrcComponentID();
	JausAddress sender(subsystem_id, node_id, component_id);
	ROS_DEBUG_NAMED("PanTiltJointPositionDriver", "ReportCommandedPanTiltJointPositionsAction (%.2f, %.2f) to %d.%d.%d", p_joint1_cmd_position, p_joint2_cmd_position, subsystem_id, node_id, component_id);
	ReportCommandedPanTiltJointPositions response;
	response.getBody()->getPanTiltJointPositionRec()->setJoint1Position(p_joint1_cmd_position);
	response.getBody()->getPanTiltJointPositionRec()->setJoint2Position(p_joint2_cmd_position);
	sendJausMessage(response, sender);
}

void PanTiltJointPositionDriver_ReceiveFSM::setPanTiltJointEffortsAction(SetPanTiltJointPositions msg)
{

	p_joint1_cmd_position = msg.getBody()->getPanTiltJointPositionRec()->getJoint1Position();
	p_joint2_cmd_position = msg.getBody()->getPanTiltJointPositionRec()->getJoint2Position();
	ROS_DEBUG_NAMED("PanTiltJointPositionDriver", "setPanTiltJointEffortAction (%.2f, %.2f)", p_joint1_cmd_position, p_joint2_cmd_position);
	sensor_msgs::JointState cmd_joint_state;
	if (!p_joint1_name.empty()) {
		cmd_joint_state.name.push_back(p_joint1_name);
		cmd_joint_state.position.push_back(p_joint1_cmd_position);
	}
	if (!p_joint2_name.empty()) {
		cmd_joint_state.name.push_back(p_joint2_name);
		cmd_joint_state.position.push_back(p_joint2_cmd_position);
	}
	p_pub_cmd_pos_joints.publish(cmd_joint_state);
	// send cmd to Float64 topics
	std_msgs::Float64 cmd_pos_pan;
	cmd_pos_pan.data = p_joint1_cmd_position;
	p_pub_cmd_pos_pan.publish(cmd_pos_pan);
	std_msgs::Float64 cmd_pos_tilt;
	cmd_pos_tilt.data = p_joint2_cmd_position;
	p_pub_cmd_pos_tilt.publish(cmd_pos_tilt);
	// send cmd to Float32 topics
	std_msgs::Float32 cmd_pos_pan32;
	cmd_pos_pan32.data = p_joint1_cmd_position;
	p_pub_cmd_pos_pan32.publish(cmd_pos_pan32);
	std_msgs::Float32 cmd_pos_tilt32;
	cmd_pos_tilt32.data = p_joint2_cmd_position;
	p_pub_cmd_pos_tilt32.publish(cmd_pos_tilt32);
}

void PanTiltJointPositionDriver_ReceiveFSM::stopMotionAction()
{
	/// Insert User Code HERE
	// how to stop the motion, if we use only the position to command the pantilt?
	// we try to send the current position... and zero velocity in joint states
	ROS_DEBUG_NAMED("PanTiltJointPositionDriver", "stopMotionAction");
	p_joint1_cmd_position = p_joint1_position;
	p_joint2_cmd_position = p_joint2_position;
	sensor_msgs::JointState cmd_joint_state;
	if (!p_joint1_name.empty()) {
		cmd_joint_state.name.push_back(p_joint1_name);
		cmd_joint_state.position.push_back(p_joint1_position);
		cmd_joint_state.velocity.push_back(0.0);
	}
	if (!p_joint2_name.empty()) {
		cmd_joint_state.name.push_back(p_joint2_name);
		cmd_joint_state.position.push_back(p_joint2_position);
		cmd_joint_state.velocity.push_back(0.0);
	}
	p_pub_cmd_pos_joints.publish(cmd_joint_state);
	// send cmd to Float64 topics
	std_msgs::Float64 cmd_pos_pan;
	cmd_pos_pan.data = p_joint1_position;
	p_pub_cmd_pos_pan.publish(cmd_pos_pan);
	std_msgs::Float64 cmd_pos_tilt;
	cmd_pos_tilt.data = p_joint2_position;
	p_pub_cmd_pos_tilt.publish(cmd_pos_tilt);
	// send cmd to Float32 topics
	std_msgs::Float32 cmd_pos_pan32;
	cmd_pos_pan32.data = p_joint1_position;
	p_pub_cmd_pos_pan32.publish(cmd_pos_pan32);
	std_msgs::Float32 cmd_pos_tilt32;
	cmd_pos_tilt32.data = p_joint2_position;
	p_pub_cmd_pos_tilt32.publish(cmd_pos_tilt32);
}

void PanTiltJointPositionDriver_ReceiveFSM::motion_profile_received(JausAddress reporter, urn_jaus_jss_manipulator_PanTiltMotionProfileService::ReportPanTiltMotionProfile profile)
{
	// TODO: handle motion profile
	ROS_DEBUG_NAMED("PanTiltJointPositionDriver", "motion_profile received from %s", reporter.str().c_str());
}

bool PanTiltJointPositionDriver_ReceiveFSM::isControllingClient(Receive::Body::ReceiveRec transportData)
{
	//// By default, inherited guards call the parent function.
	//// This can be replaced or modified as needed.
	return pAccessControl_ReceiveFSM->isControllingClient(transportData );
}
bool PanTiltJointPositionDriver_ReceiveFSM::panTiltMotionProfileExists()
{
	/// Insert User Code HERE
	return true;
}

void PanTiltJointPositionDriver_ReceiveFSM::set_current_position(double pan_position, double tilt_position)
{
	p_joint1_position = pan_position;
	p_joint2_position = tilt_position;
}

};
