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


#ifndef PANTILTJOINTPOSITIONDRIVER_RECEIVEFSM_H
#define PANTILTJOINTPOSITIONDRIVER_RECEIVEFSM_H

#include "JausUtils.h"
#include "InternalEvents/InternalEventHandler.h"
#include "Transport/JausTransport.h"
#include "JTSStateMachine.h"
#include "urn_jaus_jss_manipulator_PanTiltJointPositionDriver/Messages/MessageSet.h"
#include "urn_jaus_jss_manipulator_PanTiltJointPositionDriver/InternalEvents/InternalEventsSet.h"

#include "InternalEvents/Receive.h"
#include "InternalEvents/Send.h"

#include "urn_jaus_jss_core_Transport/Transport_ReceiveFSM.h"
#include "urn_jaus_jss_core_Events/Events_ReceiveFSM.h"
#include "urn_jaus_jss_core_AccessControl/AccessControl_ReceiveFSM.h"
#include "urn_jaus_jss_core_Management/Management_ReceiveFSM.h"

#include <sensor_msgs/JointState.h>
#include <std_msgs/Float32.h>
#include <std_msgs/Float64.h>
#include <boost/thread/recursive_mutex.hpp>
#include "iop_manipulator_core_fkie/PantiltCfgReader.h"

#include "PanTiltJointPositionDriver_ReceiveFSM_sm.h"

namespace urn_jaus_jss_manipulator_PanTiltJointPositionDriver
{

class DllExport PanTiltJointPositionDriver_ReceiveFSM : public JTS::StateMachine
{
public:
	PanTiltJointPositionDriver_ReceiveFSM(urn_jaus_jss_core_Transport::Transport_ReceiveFSM* pTransport_ReceiveFSM, urn_jaus_jss_core_Events::Events_ReceiveFSM* pEvents_ReceiveFSM, urn_jaus_jss_core_AccessControl::AccessControl_ReceiveFSM* pAccessControl_ReceiveFSM, urn_jaus_jss_core_Management::Management_ReceiveFSM* pManagement_ReceiveFSM);
	virtual ~PanTiltJointPositionDriver_ReceiveFSM();

	/// Handle notifications on parent state changes
	virtual void setupNotifications();

	/// Action Methods
	virtual void sendReportCommandedPanTiltJointPositionsAction(QueryCommandedPanTiltJointPositions msg, Receive::Body::ReceiveRec transportData);
	virtual void setPanTiltJointEffortsAction(SetPanTiltJointPositions msg);
	virtual void stopMotionAction();


	/// Guard Methods
	virtual bool isControllingClient(Receive::Body::ReceiveRec transportData);
	virtual bool panTiltMotionProfileExists();

	void set_current_position(double pan_position, double tilt_position);

	PanTiltJointPositionDriver_ReceiveFSMContext *context;

protected:

    /// References to parent FSMs
	urn_jaus_jss_core_Transport::Transport_ReceiveFSM* pTransport_ReceiveFSM;
	urn_jaus_jss_core_Events::Events_ReceiveFSM* pEvents_ReceiveFSM;
	urn_jaus_jss_core_AccessControl::AccessControl_ReceiveFSM* pAccessControl_ReceiveFSM;
	urn_jaus_jss_core_Management::Management_ReceiveFSM* pManagement_ReceiveFSM;

	boost::recursive_mutex p_mutex;
	iop_manipulator_core_fkie::PantiltCfgReader p_cfg_reader;
	std::string p_joint1_name;
	std::string p_joint2_name;
	double p_joint1_cmd_position;
	double p_joint2_cmd_position;
	double p_joint1_position;
	double p_joint2_position;
	ros::Publisher p_pub_cmd_pos_joints;
	ros::Publisher p_pub_cmd_pos_pan;
	ros::Publisher p_pub_cmd_pos_tilt;
	ros::Publisher p_pub_cmd_pos_pan32;
	ros::Publisher p_pub_cmd_pos_tilt32;


};

};

#endif // PANTILTJOINTPOSITIONDRIVER_RECEIVEFSM_H
