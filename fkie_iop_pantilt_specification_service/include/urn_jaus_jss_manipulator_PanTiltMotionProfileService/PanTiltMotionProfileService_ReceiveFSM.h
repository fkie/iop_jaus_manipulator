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


#ifndef PANTILTMOTIONPROFILESERVICE_RECEIVEFSM_H
#define PANTILTMOTIONPROFILESERVICE_RECEIVEFSM_H

#include "JausUtils.h"
#include "InternalEvents/InternalEventHandler.h"
#include "Transport/JausTransport.h"
#include "JTSStateMachine.h"
#include "urn_jaus_jss_manipulator_PanTiltMotionProfileService/Messages/MessageSet.h"
#include "urn_jaus_jss_manipulator_PanTiltMotionProfileService/InternalEvents/InternalEventsSet.h"

#include "InternalEvents/Receive.h"
#include "InternalEvents/Send.h"

#include <moveit_msgs/JointLimits.h>
#include "urn_jaus_jss_core_Transport/Transport_ReceiveFSM.h"
#include "urn_jaus_jss_core_Events/Events_ReceiveFSM.h"
#include "urn_jaus_jss_core_AccessControl/AccessControl_ReceiveFSM.h"
#include <fkie_iop_pantilt_specification_service/PanTiltMotionProfileListenerInterface.h>

#include "PanTiltMotionProfileService_ReceiveFSM_sm.h"

namespace urn_jaus_jss_manipulator_PanTiltMotionProfileService
{

class DllExport PanTiltMotionProfileService_ReceiveFSM : public JTS::StateMachine
{
public:
	PanTiltMotionProfileService_ReceiveFSM(urn_jaus_jss_core_Transport::Transport_ReceiveFSM* pTransport_ReceiveFSM, urn_jaus_jss_core_Events::Events_ReceiveFSM* pEvents_ReceiveFSM, urn_jaus_jss_core_AccessControl::AccessControl_ReceiveFSM* pAccessControl_ReceiveFSM);
	virtual ~PanTiltMotionProfileService_ReceiveFSM();

	/// Handle notifications on parent state changes
	virtual void setupNotifications();

	/// Action Methods
	virtual void sendReportPanTiltMotionProfileAction(QueryPanTiltMotionProfile msg, Receive::Body::ReceiveRec transportData);
	virtual void setPanTiltMotionProfileAction(SetPanTiltMotionProfile msg, Receive::Body::ReceiveRec transportData);


	/// Guard Methods
	virtual bool isControllingClient(Receive::Body::ReceiveRec transportData);
	virtual bool panTiltMotionProfileExists();

	void add_listener(iop::PanTiltMotionProfileListenerInterface *listener);
	ReportPanTiltMotionProfile get_current_motion_profile() { return p_motion_profile; }
	void reset_motion_profile();



	PanTiltMotionProfileService_ReceiveFSMContext *context;

protected:

    /// References to parent FSMs
	urn_jaus_jss_core_Transport::Transport_ReceiveFSM* pTransport_ReceiveFSM;
	urn_jaus_jss_core_Events::Events_ReceiveFSM* pEvents_ReceiveFSM;
	urn_jaus_jss_core_AccessControl::AccessControl_ReceiveFSM* pAccessControl_ReceiveFSM;

	ReportPanTiltMotionProfile p_motion_profile;
	std::vector<iop::PanTiltMotionProfileListenerInterface*> p_motionp_listener;
	bool p_has_profile;
	std::pair<moveit_msgs::JointLimits, moveit_msgs::JointLimits> p_joint_limits_defaults;
	std::pair<moveit_msgs::JointLimits, moveit_msgs::JointLimits> p_joint_limits_current;
	ros::Publisher p_pub_joint1_limits;
	ros::Publisher p_pub_joint2_limits;
	double joint1_max_speed;
	double joint1_max_accel;
	double joint1_max_decel;
	double joint2_max_speed;
	double joint2_max_accel;
	double joint2_max_decel;

	void pNotifyListeners(JausAddress reporter, ReportPanTiltMotionProfile profile);
};

};

#endif // PANTILTMOTIONPROFILESERVICE_RECEIVEFSM_H
