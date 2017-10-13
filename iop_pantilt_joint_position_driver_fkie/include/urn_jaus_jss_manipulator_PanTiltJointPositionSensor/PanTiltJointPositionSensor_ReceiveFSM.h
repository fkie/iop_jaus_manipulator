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


#ifndef PANTILTJOINTPOSITIONSENSOR_RECEIVEFSM_H
#define PANTILTJOINTPOSITIONSENSOR_RECEIVEFSM_H

#include "JausUtils.h"
#include "InternalEvents/InternalEventHandler.h"
#include "Transport/JausTransport.h"
#include "JTSStateMachine.h"
#include "urn_jaus_jss_manipulator_PanTiltJointPositionSensor/Messages/MessageSet.h"
#include "urn_jaus_jss_manipulator_PanTiltJointPositionSensor/InternalEvents/InternalEventsSet.h"

#include "InternalEvents/Receive.h"
#include "InternalEvents/Send.h"

#include "urn_jaus_jss_core_Transport/Transport_ReceiveFSM.h"
#include "urn_jaus_jss_core_Events/Events_ReceiveFSM.h"

#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <sensor_msgs/JointState.h>
#include <std_msgs/Float32.h>
#include <std_msgs/Float64.h>
#include <boost/thread/recursive_mutex.hpp>

#include <urn_jaus_jss_manipulator_PanTiltJointPositionDriver/PanTiltJointPositionDriverService.h>
#include "PanTiltJointPositionSensor_ReceiveFSM_sm.h"

namespace urn_jaus_jss_manipulator_PanTiltJointPositionSensor
{

class DllExport PanTiltJointPositionSensor_ReceiveFSM : public JTS::StateMachine
{
public:
	PanTiltJointPositionSensor_ReceiveFSM(urn_jaus_jss_core_Transport::Transport_ReceiveFSM* pTransport_ReceiveFSM, urn_jaus_jss_core_Events::Events_ReceiveFSM* pEvents_ReceiveFSM);
	virtual ~PanTiltJointPositionSensor_ReceiveFSM();

	/// Handle notifications on parent state changes
	virtual void setupNotifications();

	/// Action Methods
	virtual void sendReportPanTiltJointPositionsAction(QueryPanTiltJointPositions msg, Receive::Body::ReceiveRec transportData);

	/// Guard Methods



	PanTiltJointPositionSensor_ReceiveFSMContext *context;

protected:

    /// References to parent FSMs
	urn_jaus_jss_core_Transport::Transport_ReceiveFSM* pTransport_ReceiveFSM;
	urn_jaus_jss_core_Events::Events_ReceiveFSM* pEvents_ReceiveFSM;

	boost::recursive_mutex p_mutex;
	urn_jaus_jss_manipulator_PanTiltJointPositionDriver::PanTiltJointPositionDriver_ReceiveFSM *p_position_driver_service;
	ReportPanTiltJointPositions p_report_pantilt;
	std::string p_joint1_name;
	std::string p_joint2_name;
	double p_joint1_position;
	double p_joint2_position;
	ros::Subscriber p_sub_pos_joints;
	ros::Subscriber p_sub_pos_pan;
	ros::Subscriber p_sub_pos_tilt;
	ros::Subscriber p_sub_pos_pan32;
	ros::Subscriber p_sub_pos_tilt32;

	void pUpdatePosition(double pan, double tilt);
	void pJoinStateCallback(const sensor_msgs::JointState::ConstPtr& joint_state);
	void pPanFloatCallback(const std_msgs::Float64::ConstPtr& msg);
	void pTiltFloatCallback(const std_msgs::Float64::ConstPtr& msg);
	void pPanFloat32Callback(const std_msgs::Float32::ConstPtr& msg);
	void pTiltFloat32Callback(const std_msgs::Float32::ConstPtr& msg);
	urn_jaus_jss_manipulator_PanTiltJointPositionDriver::PanTiltJointPositionDriver_ReceiveFSM *pGetPostionDriver();
};

};

#endif // PANTILTJOINTPOSITIONSENSOR_RECEIVEFSM_H
