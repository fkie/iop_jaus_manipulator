

#ifndef MANIPULATORJOINTPOSITIONSENSOR_RECEIVEFSM_H
#define MANIPULATORJOINTPOSITIONSENSOR_RECEIVEFSM_H

#include "JausUtils.h"
#include "InternalEvents/InternalEventHandler.h"
#include "Transport/JausTransport.h"
#include "JTSStateMachine.h"
#include "urn_jaus_jss_manipulator_ManipulatorJointPositionSensor/Messages/MessageSet.h"
#include "urn_jaus_jss_manipulator_ManipulatorJointPositionSensor/InternalEvents/InternalEventsSet.h"

#include "InternalEvents/Receive.h"
#include "InternalEvents/Send.h"

#include "urn_jaus_jss_core_Transport/Transport_ReceiveFSM.h"
#include "urn_jaus_jss_core_Events/Events_ReceiveFSM.h"


#include "ManipulatorJointPositionSensor_ReceiveFSM_sm.h"

#include <sensor_msgs/JointState.h>
#include <boost/thread/recursive_mutex.hpp>

namespace urn_jaus_jss_manipulator_ManipulatorJointPositionSensor
{

class DllExport ManipulatorJointPositionSensor_ReceiveFSM : public JTS::StateMachine
{
public:
	ManipulatorJointPositionSensor_ReceiveFSM(urn_jaus_jss_core_Transport::Transport_ReceiveFSM* pTransport_ReceiveFSM, urn_jaus_jss_core_Events::Events_ReceiveFSM* pEvents_ReceiveFSM);
	virtual ~ManipulatorJointPositionSensor_ReceiveFSM();

	/// Handle notifications on parent state changes
	virtual void setupNotifications();

	/// Action Methods
	virtual void sendQueryJointPositionsAction(QueryJointPositions msg, Receive::Body::ReceiveRec transportData);


	/// Guard Methods



	ManipulatorJointPositionSensor_ReceiveFSMContext *context;

protected:

    /// References to parent FSMs
	urn_jaus_jss_core_Transport::Transport_ReceiveFSM* pTransport_ReceiveFSM;
	urn_jaus_jss_core_Events::Events_ReceiveFSM* pEvents_ReceiveFSM;

	ReportJointPositions p_report_joint_positions;
	boost::recursive_mutex p_mutex;
	std::vector<std::string> p_joint_names;
	std::map<std::string, float> p_joint_positions;
	ros::Subscriber p_sub_jointstates;

	void pJoinStateCallback(const sensor_msgs::JointState::ConstPtr& joint_state);
};

};

#endif // MANIPULATORJOINTPOSITIONSENSOR_RECEIVEFSM_H
