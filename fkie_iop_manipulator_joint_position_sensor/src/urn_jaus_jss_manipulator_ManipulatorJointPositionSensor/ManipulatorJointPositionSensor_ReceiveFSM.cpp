

#include "urn_jaus_jss_manipulator_ManipulatorJointPositionSensor/ManipulatorJointPositionSensor_ReceiveFSM.h"
#include <moveit/robot_model_loader/robot_model_loader.h>

#include <fkie_iop_component/iop_component.h>
#include <fkie_iop_component/iop_config.h>
#include "urn_jaus_jss_manipulator_ManipulatorSpecificationService/ManipulatorSpecificationServiceService.h"

using namespace JTS;
using namespace urn_jaus_jss_manipulator_ManipulatorSpecificationService;

namespace urn_jaus_jss_manipulator_ManipulatorJointPositionSensor
{



ManipulatorJointPositionSensor_ReceiveFSM::ManipulatorJointPositionSensor_ReceiveFSM(urn_jaus_jss_core_Transport::Transport_ReceiveFSM* pTransport_ReceiveFSM, urn_jaus_jss_core_Events::Events_ReceiveFSM* pEvents_ReceiveFSM)
{

	/*
	 * If there are other variables, context must be constructed last so that all
	 * class variables are available if an EntryAction of the InitialState of the
	 * statemachine needs them.
	 */
	context = new ManipulatorJointPositionSensor_ReceiveFSMContext(*this);

	this->pTransport_ReceiveFSM = pTransport_ReceiveFSM;
	this->pEvents_ReceiveFSM = pEvents_ReceiveFSM;
}



ManipulatorJointPositionSensor_ReceiveFSM::~ManipulatorJointPositionSensor_ReceiveFSM()
{
	delete context;
}

void ManipulatorJointPositionSensor_ReceiveFSM::setupNotifications()
{
	pEvents_ReceiveFSM->registerNotification("Receiving_Ready", ieHandler, "InternalStateChange_To_ManipulatorJointPositionSensor_ReceiveFSM_Receiving_Ready", "Events_ReceiveFSM");
	pEvents_ReceiveFSM->registerNotification("Receiving", ieHandler, "InternalStateChange_To_ManipulatorJointPositionSensor_ReceiveFSM_Receiving_Ready", "Events_ReceiveFSM");
	registerNotification("Receiving_Ready", pEvents_ReceiveFSM->getHandler(), "InternalStateChange_To_Events_ReceiveFSM_Receiving_Ready", "ManipulatorJointPositionSensor_ReceiveFSM");
	registerNotification("Receiving", pEvents_ReceiveFSM->getHandler(), "InternalStateChange_To_Events_ReceiveFSM_Receiving", "ManipulatorJointPositionSensor_ReceiveFSM");

	iop::Component &cmp = iop::Component::get_instance();
	ManipulatorSpecificationServiceService *spec_srv = static_cast<ManipulatorSpecificationServiceService*>(cmp.get_service("ManipulatorSpecificationService"));
	if (spec_srv != NULL) {
		p_joint_names = spec_srv->pManipulatorSpecificationService_ReceiveFSM->getJointNames();
	} else {
		throw std::runtime_error("[PrimitiveManipulator] no ManipulatorSpecificationService in configuration found! Please include its plugin first (in the list)!");
	}
	for (unsigned int index = 0; index < p_joint_names.size(); index++) {
		p_joint_positions[p_joint_names[index]] = 0.;
	}
	iop::Config cfg("~PrimitiveManipulator");
	p_sub_jointstates = cfg.subscribe<sensor_msgs::JointState>("joint_states", 1, &ManipulatorJointPositionSensor_ReceiveFSM::pJoinStateCallback, this);
	pEvents_ReceiveFSM->get_event_handler().register_query(QueryJointPositions::ID);
}

void ManipulatorJointPositionSensor_ReceiveFSM::sendQueryJointPositionsAction(QueryJointPositions msg, Receive::Body::ReceiveRec transportData)
{
	/// Insert User Code HERE
	JausAddress sender = transportData.getAddress();
	ROS_DEBUG_NAMED("ManipulatorJointPositionSensor", "sendReportJointPositionAction to %s", sender.str().c_str());
	p_mutex.lock();
	this->sendJausMessage(p_report_joint_positions, sender);
	p_mutex.unlock();
}

void ManipulatorJointPositionSensor_ReceiveFSM::pJoinStateCallback(const sensor_msgs::JointState::ConstPtr& joint_state)
{
	// create index map
	p_mutex.lock();
	std::map<std::string, int> indexes;
	std::vector<std::string>::iterator it_jn;
	for (it_jn=p_joint_names.begin(); it_jn != p_joint_names.end(); ++it_jn) {
		int index = -1;
		for (unsigned int i = 0; i < joint_state->name.size(); i++) {
			if (it_jn->compare(joint_state->name[i]) == 0) {
				index = i;
				break;
			}
		}
		indexes[*it_jn] = index;
	}
	// get joint positions from joint_state
	std::map<std::string, int>::iterator it_ids;
	for (it_ids=indexes.begin(); it_ids != indexes.end(); ++it_ids) {
		if (it_ids->second > -1) {
			p_joint_positions[it_ids->first] = joint_state->position[it_ids->second];
		} else {
			p_joint_positions[it_ids->first] = 0.;
		}
	}
//  std::map<std::string, float>::iterator it_ps;
//  for (unsigned int index = 0; index < p_joint_names.size(); index++) {
//      printf("  %s: %f\n",  p_joint_names[index].c_str(), p_joint_positions[p_joint_names[index]]);
//  }
    // delete all positions first
	while (p_report_joint_positions.getBody()->getJointPositionList()->getNumberOfElements() > 0) {
		p_report_joint_positions.getBody()->getJointPositionList()->deleteLastElement();
	}
	std::map<std::string, float>::iterator it_ps;
	for (unsigned int index = 0; index < p_joint_names.size(); index++) {
		ReportJointPositions::Body::JointPositionList::JointPositionRec joint_position;
		// TODO: read from config the type of the joint and use radians or meters
		joint_position.getJointPosition()->setRadianAsUnsignedIntegerAt0(p_joint_positions[p_joint_names[index]]);
		p_report_joint_positions.getBody()->getJointPositionList()->addElement(joint_position);
	}
	pEvents_ReceiveFSM->get_event_handler().set_report(QueryJointPositions::ID, &p_report_joint_positions);
	p_mutex.unlock();
}



};
