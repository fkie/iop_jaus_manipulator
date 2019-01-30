

#ifndef PRIMITIVEENDEFFECTOR_RECEIVEFSM_H
#define PRIMITIVEENDEFFECTOR_RECEIVEFSM_H

#include "JausUtils.h"
#include "InternalEvents/InternalEventHandler.h"
#include "Transport/JausTransport.h"
#include "JTSStateMachine.h"
#include "urn_jaus_jss_manipulator_PrimitiveEndEffector/Messages/MessageSet.h"
#include "urn_jaus_jss_manipulator_PrimitiveEndEffector/InternalEvents/InternalEventsSet.h"

#include "InternalEvents/Receive.h"
#include "InternalEvents/Send.h"

#include "urn_jaus_jss_core_Transport/Transport_ReceiveFSM.h"
#include "urn_jaus_jss_core_Events/Events_ReceiveFSM.h"
#include "urn_jaus_jss_core_AccessControl/AccessControl_ReceiveFSM.h"
#include "urn_jaus_jss_core_Management/Management_ReceiveFSM.h"

#include <sensor_msgs/JointState.h>
#include <std_msgs/Float64.h>
#include <boost/thread/recursive_mutex.hpp>

#include "PrimitiveEndEffector_ReceiveFSM_sm.h"

namespace urn_jaus_jss_manipulator_PrimitiveEndEffector
{

class DllExport PrimitiveEndEffector_ReceiveFSM : public JTS::StateMachine
{
public:
	PrimitiveEndEffector_ReceiveFSM(urn_jaus_jss_core_Transport::Transport_ReceiveFSM* pTransport_ReceiveFSM, urn_jaus_jss_core_Events::Events_ReceiveFSM* pEvents_ReceiveFSM, urn_jaus_jss_core_AccessControl::AccessControl_ReceiveFSM* pAccessControl_ReceiveFSM, urn_jaus_jss_core_Management::Management_ReceiveFSM* pManagement_ReceiveFSM);
	virtual ~PrimitiveEndEffector_ReceiveFSM();

	/// Handle notifications on parent state changes
	virtual void setupNotifications();

	/// Action Methods
	virtual void sendReportEndEffectorEffortAction(QueryEndEffectorEffort msg, Receive::Body::ReceiveRec transportData);
	virtual void sendReportEndEffectorSpecificationAction(QueryEndEffectorSpecification msg, Receive::Body::ReceiveRec transportData);
	virtual void setEndEffectorEffortAction(SetEndEffectorEffort msg, Receive::Body::ReceiveRec transportData);
	virtual void stopMotionAction();


	/// Guard Methods
	virtual bool isControllingClient(Receive::Body::ReceiveRec transportData);



	PrimitiveEndEffector_ReceiveFSMContext *context;

protected:

    /// References to parent FSMs
	urn_jaus_jss_core_Transport::Transport_ReceiveFSM* pTransport_ReceiveFSM;
	urn_jaus_jss_core_Events::Events_ReceiveFSM* pEvents_ReceiveFSM;
	urn_jaus_jss_core_AccessControl::AccessControl_ReceiveFSM* pAccessControl_ReceiveFSM;
	urn_jaus_jss_core_Management::Management_ReceiveFSM* pManagement_ReceiveFSM;

	ReportEndEffectorEffort p_joint_effort_report;
	boost::recursive_mutex p_mutex;
	JausAddress p_manipulator_id;
	std::string p_gripper_joint;
	std::vector<std::string> p_joint_names;
	std::map<std::string, float> p_joint_positions;
	std::map<std::string, float> p_joint_velocities;
	ros::Subscriber p_sub_jointstates;
	ros::Publisher p_pub_cmd_jointstates;
	ros::Publisher p_pub_cmd_vel;

	void pJoinStateCallback(const sensor_msgs::JointState::ConstPtr& joint_state);

};

};

#endif // PRIMITIVEENDEFFECTOR_RECEIVEFSM_H
