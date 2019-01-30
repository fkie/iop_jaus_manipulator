

#ifndef PRIMITIVEPANTILT_RECEIVEFSM_H
#define PRIMITIVEPANTILT_RECEIVEFSM_H

#include "JausUtils.h"
#include "InternalEvents/InternalEventHandler.h"
#include "Transport/JausTransport.h"
#include "JTSStateMachine.h"
#include "urn_jaus_jss_manipulator_PrimitivePanTilt/Messages/MessageSet.h"
#include "urn_jaus_jss_manipulator_PrimitivePanTilt/InternalEvents/InternalEventsSet.h"

#include "InternalEvents/Receive.h"
#include "InternalEvents/Send.h"

#include "urn_jaus_jss_core_Transport/Transport_ReceiveFSM.h"
#include "urn_jaus_jss_core_Events/Events_ReceiveFSM.h"
#include "urn_jaus_jss_core_AccessControl/AccessControl_ReceiveFSM.h"
#include "urn_jaus_jss_core_Management/Management_ReceiveFSM.h"

#include <geometry_msgs/TwistStamped.h>
#include <moveit_msgs/JointLimits.h>
#include <sensor_msgs/JointState.h>
#include <sensor_msgs/JointState.h>
#include <std_msgs/Float32.h>
#include <std_msgs/Float64.h>
#include <boost/thread/recursive_mutex.hpp>

#include "PrimitivePanTilt_ReceiveFSM_sm.h"

namespace urn_jaus_jss_manipulator_PrimitivePanTilt
{

class DllExport PrimitivePanTilt_ReceiveFSM : public JTS::StateMachine
{
public:
	PrimitivePanTilt_ReceiveFSM(urn_jaus_jss_core_Transport::Transport_ReceiveFSM* pTransport_ReceiveFSM, urn_jaus_jss_core_Events::Events_ReceiveFSM* pEvents_ReceiveFSM, urn_jaus_jss_core_AccessControl::AccessControl_ReceiveFSM* pAccessControl_ReceiveFSM, urn_jaus_jss_core_Management::Management_ReceiveFSM* pManagement_ReceiveFSM);
	virtual ~PrimitivePanTilt_ReceiveFSM();

	/// Handle notifications on parent state changes
	virtual void setupNotifications();

	/// Action Methods
	virtual void sendReportPanTiltJointEffortAction(QueryPanTiltJointEffort msg, Receive::Body::ReceiveRec transportData);
	virtual void setPanTiltJointEffortAction(SetPanTiltJointEffort msg);
	virtual void stopMotionAction();


	/// Guard Methods
	virtual bool isControllingClient(Receive::Body::ReceiveRec transportData);



	PrimitivePanTilt_ReceiveFSMContext *context;

protected:

    /// References to parent FSMs
	urn_jaus_jss_core_Transport::Transport_ReceiveFSM* pTransport_ReceiveFSM;
	urn_jaus_jss_core_Events::Events_ReceiveFSM* pEvents_ReceiveFSM;
	urn_jaus_jss_core_AccessControl::AccessControl_ReceiveFSM* pAccessControl_ReceiveFSM;
	urn_jaus_jss_core_Management::Management_ReceiveFSM* pManagement_ReceiveFSM;

	ReportPanTiltJointEffort p_report_effort;
	boost::recursive_mutex p_mutex;
	std::pair<moveit_msgs::JointLimits, moveit_msgs::JointLimits> p_limits;
	std::string p_joint1_name;
	std::string p_joint2_name;
	double p_joint1_cmd_effort;
	double p_joint2_cmd_effort;
	ros::Publisher p_pub_cmd_vel_joints;
	ros::Publisher p_pub_cmd_vel_pan;
	ros::Publisher p_pub_cmd_vel_tilt;
	ros::Publisher p_pub_cmd_vel_pan32;
	ros::Publisher p_pub_cmd_vel_tilt32;
	ros::Publisher p_pub_cmd_vel_twist;
};

};

#endif // PRIMITIVEPANTILT_RECEIVEFSM_H
