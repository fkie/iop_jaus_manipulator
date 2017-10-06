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


#include "urn_jaus_jss_manipulator_PanTiltJointPositionSensor/PanTiltJointPositionSensor_ReceiveFSM.h"

#include <iop_component_fkie/iop_component.h>


using namespace JTS;
using namespace urn_jaus_jss_manipulator_PanTiltJointPositionDriver;

namespace urn_jaus_jss_manipulator_PanTiltJointPositionSensor
{



PanTiltJointPositionSensor_ReceiveFSM::PanTiltJointPositionSensor_ReceiveFSM(urn_jaus_jss_core_Transport::Transport_ReceiveFSM* pTransport_ReceiveFSM, urn_jaus_jss_core_Events::Events_ReceiveFSM* pEvents_ReceiveFSM)
{

	/*
	 * If there are other variables, context must be constructed last so that all
	 * class variables are available if an EntryAction of the InitialState of the
	 * statemachine needs them.
	 */
	context = new PanTiltJointPositionSensor_ReceiveFSMContext(*this);

	this->pTransport_ReceiveFSM = pTransport_ReceiveFSM;
	this->pEvents_ReceiveFSM = pEvents_ReceiveFSM;
	p_position_driver_service = NULL;
	p_joint1_name = "";
	p_joint2_name = "";
	p_joint1_position = 0.0;
	p_joint2_position = 0.0;
}



PanTiltJointPositionSensor_ReceiveFSM::~PanTiltJointPositionSensor_ReceiveFSM()
{
	delete context;
}

void PanTiltJointPositionSensor_ReceiveFSM::setupNotifications()
{
	pEvents_ReceiveFSM->registerNotification("Receiving_Ready", ieHandler, "InternalStateChange_To_PanTiltJointPositionSensor_ReceiveFSM_Receiving_Ready", "Events_ReceiveFSM");
	pEvents_ReceiveFSM->registerNotification("Receiving", ieHandler, "InternalStateChange_To_PanTiltJointPositionSensor_ReceiveFSM_Receiving_Ready", "Events_ReceiveFSM");
	registerNotification("Receiving_Ready", pEvents_ReceiveFSM->getHandler(), "InternalStateChange_To_Events_ReceiveFSM_Receiving_Ready", "PanTiltJointPositionSensor_ReceiveFSM");
	registerNotification("Receiving", pEvents_ReceiveFSM->getHandler(), "InternalStateChange_To_Events_ReceiveFSM_Receiving", "PanTiltJointPositionSensor_ReceiveFSM");
	pEvents_ReceiveFSM->get_event_handler().register_query(QueryPanTiltJointPositions::ID);
	p_cfg_reader.readRosConfiguration();
	std::vector<std::string> joint_names = p_cfg_reader.getJointNames();
	if (joint_names.size() > 0) {
		p_joint1_name = joint_names[0];
	}
	if (joint_names.size() > 1) {
		p_joint2_name = joint_names[1];
	}
	ros::NodeHandle nh;
	p_sub_pos_joints = nh.subscribe<sensor_msgs::JointState>("pos_joints", 1, &PanTiltJointPositionSensor_ReceiveFSM::pJoinStateCallback, this);
	p_sub_pos_pan = nh.subscribe<std_msgs::Float64>("pos_pan", 1, &PanTiltJointPositionSensor_ReceiveFSM::pPanFloatCallback, this);
	p_sub_pos_tilt = nh.subscribe<std_msgs::Float64>("pos_tilt", 1, &PanTiltJointPositionSensor_ReceiveFSM::pTiltFloatCallback, this);
	p_sub_pos_pan32 = nh.subscribe<std_msgs::Float32>("pos_pan32", 1, &PanTiltJointPositionSensor_ReceiveFSM::pPanFloat32Callback, this);
	p_sub_pos_tilt32 = nh.subscribe<std_msgs::Float32>("pos_tilt32", 1, &PanTiltJointPositionSensor_ReceiveFSM::pTiltFloat32Callback, this);
}

void PanTiltJointPositionSensor_ReceiveFSM::sendReportPanTiltJointPositionsAction(QueryPanTiltJointPositions msg, Receive::Body::ReceiveRec transportData)
{
	uint16_t subsystem_id = transportData.getSrcSubsystemID();
	uint8_t node_id = transportData.getSrcNodeID();
	uint8_t component_id = transportData.getSrcComponentID();
	JausAddress sender(subsystem_id, node_id, component_id);
	ROS_DEBUG_NAMED("PanTiltJointPositionSensor", "ReportPanTiltJointPositions (%.2lf, %.2lf) to %d.%d.%d", p_joint1_position, p_joint2_position, subsystem_id, node_id, component_id);
	p_mutex.lock();
	sendJausMessage(p_report_pantilt, sender);
	p_mutex.unlock();
}

void PanTiltJointPositionSensor_ReceiveFSM::pUpdatePosition(double pan, double tilt)
{
	p_mutex.lock();
	bool updated = false;
	if (p_joint1_position != pan) {
		p_joint1_position = pan;
		updated = true;
	}
	if (p_joint2_position != tilt) {
		p_joint2_position = tilt;
		updated = true;
	}
	if (updated) {
		// set event handling
		p_report_pantilt.getBody()->getPanTiltJointPositionRec()->setJoint1Position(p_joint1_position);
		p_report_pantilt.getBody()->getPanTiltJointPositionRec()->setJoint2Position(p_joint2_position);
		pEvents_ReceiveFSM->get_event_handler().set_report(QueryPanTiltJointPositions::ID, &p_report_pantilt);
	}
	p_mutex.unlock();
	// forward position to the driver
	if (updated && pGetPostionDriver() != NULL) {
		pGetPostionDriver()->set_current_position(p_joint1_position, p_joint2_position);
	}
}

void PanTiltJointPositionSensor_ReceiveFSM::pJoinStateCallback(const sensor_msgs::JointState::ConstPtr& joint_state)
{
  // create index map
	p_mutex.lock();
	double pan, tilt = 0.0;
	for (unsigned int index = 0; index < joint_state->name.size(); index++) {
		if (!p_joint1_name.empty() && p_joint1_name.compare(joint_state->name[index]) == 0) {
			if (joint_state->position.size() > index) {
			  pan = joint_state->position[index];
			}
		}
		if (!p_joint2_name.empty() && p_joint2_name.compare(joint_state->name[index]) == 0) {
			if (joint_state->position.size() > index) {
			  tilt = joint_state->position[index];
			}
		}
	}
	p_mutex.unlock();
	pUpdatePosition(pan, tilt);
}

void PanTiltJointPositionSensor_ReceiveFSM::pPanFloatCallback(const std_msgs::Float64::ConstPtr& msg)
{
	pUpdatePosition(msg->data, p_joint2_position);
}

void PanTiltJointPositionSensor_ReceiveFSM::pTiltFloatCallback(const std_msgs::Float64::ConstPtr& msg)
{
	pUpdatePosition(p_joint1_position, msg->data);
}

void PanTiltJointPositionSensor_ReceiveFSM::pPanFloat32Callback(const std_msgs::Float32::ConstPtr& msg)
{
	pUpdatePosition(msg->data, p_joint2_position);
}

void PanTiltJointPositionSensor_ReceiveFSM::pTiltFloat32Callback(const std_msgs::Float32::ConstPtr& msg)
{
	pUpdatePosition(p_joint1_position, msg->data);
}


PanTiltJointPositionDriver_ReceiveFSM *PanTiltJointPositionSensor_ReceiveFSM::pGetPostionDriver()
{
	if (p_position_driver_service == NULL) {
		iop::Component &cmp = iop::Component::get_instance();
		PanTiltJointPositionDriverService *ptpd_srv = static_cast<PanTiltJointPositionDriverService*>(cmp.get_service("PanTiltJointPositionDriver"));
		if (ptpd_srv != NULL) {
			p_position_driver_service = ptpd_srv->pPanTiltJointPositionDriver_ReceiveFSM;
		} else {
			ROS_WARN_ONCE_NAMED("Slave", "no PanTiltJointPositionDriver found! Please include its plugin first (in the list), if you needs one!");
		}
	}
	return p_position_driver_service;
}


};
