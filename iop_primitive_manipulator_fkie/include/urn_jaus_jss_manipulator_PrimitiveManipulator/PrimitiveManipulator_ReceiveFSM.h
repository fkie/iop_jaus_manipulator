

#ifndef PRIMITIVEMANIPULATOR_RECEIVEFSM_H
#define PRIMITIVEMANIPULATOR_RECEIVEFSM_H

#include "JausUtils.h"
#include "InternalEvents/InternalEventHandler.h"
#include "Transport/JausTransport.h"
#include "JTSStateMachine.h"
#include "urn_jaus_jss_manipulator_PrimitiveManipulator/Messages/MessageSet.h"
#include "urn_jaus_jss_manipulator_PrimitiveManipulator/InternalEvents/InternalEventsSet.h"

#include "InternalEvents/Receive.h"
#include "InternalEvents/Send.h"

#include "urn_jaus_jss_core_Transport/Transport_ReceiveFSM.h"
#include "urn_jaus_jss_core_Events/Events_ReceiveFSM.h"
#include "urn_jaus_jss_core_AccessControl/AccessControl_ReceiveFSM.h"
#include "urn_jaus_jss_core_Management/Management_ReceiveFSM.h"

#include <sensor_msgs/JointState.h>
#include <std_msgs/Float64MultiArray.h>
#include <boost/thread/recursive_mutex.hpp>

#include "PrimitiveManipulator_ReceiveFSM_sm.h"

namespace urn_jaus_jss_manipulator_PrimitiveManipulator
{

class DllExport PrimitiveManipulator_ReceiveFSM : public JTS::StateMachine
{
public:
	PrimitiveManipulator_ReceiveFSM(urn_jaus_jss_core_Transport::Transport_ReceiveFSM* pTransport_ReceiveFSM, urn_jaus_jss_core_Events::Events_ReceiveFSM* pEvents_ReceiveFSM, urn_jaus_jss_core_AccessControl::AccessControl_ReceiveFSM* pAccessControl_ReceiveFSM, urn_jaus_jss_core_Management::Management_ReceiveFSM* pManagement_ReceiveFSM);
	virtual ~PrimitiveManipulator_ReceiveFSM();

	/// Handle notifications on parent state changes
	virtual void setupNotifications();

	/// Action Methods
	virtual void sendReportJointEffortAction(QueryJointEffort msg, Receive::Body::ReceiveRec transportData);
	virtual void setJointEffortAction(SetJointEffort msg, Receive::Body::ReceiveRec transportData);
	virtual void stopMotionAction();


	/// Guard Methods
	virtual bool isControllingClient(Receive::Body::ReceiveRec transportData);



	PrimitiveManipulator_ReceiveFSMContext *context;

protected:

    /// References to parent FSMs
	urn_jaus_jss_core_Transport::Transport_ReceiveFSM* pTransport_ReceiveFSM;
	urn_jaus_jss_core_Events::Events_ReceiveFSM* pEvents_ReceiveFSM;
	urn_jaus_jss_core_AccessControl::AccessControl_ReceiveFSM* pAccessControl_ReceiveFSM;
	urn_jaus_jss_core_Management::Management_ReceiveFSM* pManagement_ReceiveFSM;

	ReportJointEffort p_joint_effort_report;
	boost::recursive_mutex p_mutex;
	std::vector<std::string> p_joint_names;
	std::map<std::string, float> p_joint_positions;
	std::map<std::string, float> p_joint_velocities;
	ros::Subscriber p_sub_jointstates;
	ros::Publisher p_pub_cmd_jointstates;
	ros::Publisher p_pub_cmd_vel;

	void pJoinStateCallback(const sensor_msgs::JointState::ConstPtr& joint_state);
};

};

#endif // PRIMITIVEMANIPULATOR_RECEIVEFSM_H
