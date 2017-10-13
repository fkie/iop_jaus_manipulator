

#include "urn_jaus_jss_manipulator_PrimitiveManipulator/PrimitiveManipulator_ReceiveFSM.h"
#include <iop_component_fkie/iop_component.h>
#include <iop_component_fkie/iop_config.h>
#include "urn_jaus_jss_manipulator_ManipulatorSpecificationService/ManipulatorSpecificationServiceService.h"



using namespace JTS;
using namespace urn_jaus_jss_manipulator_ManipulatorSpecificationService;

namespace urn_jaus_jss_manipulator_PrimitiveManipulator
{



PrimitiveManipulator_ReceiveFSM::PrimitiveManipulator_ReceiveFSM(urn_jaus_jss_core_Transport::Transport_ReceiveFSM* pTransport_ReceiveFSM, urn_jaus_jss_core_Events::Events_ReceiveFSM* pEvents_ReceiveFSM, urn_jaus_jss_core_AccessControl::AccessControl_ReceiveFSM* pAccessControl_ReceiveFSM, urn_jaus_jss_core_Management::Management_ReceiveFSM* pManagement_ReceiveFSM){

	/*
	 * If there are other variables, context must be constructed last so that all
	 * class variables are available if an EntryAction of the InitialState of the
	 * statemachine needs them.
	 */
	context = new PrimitiveManipulator_ReceiveFSMContext(*this);

	this->pTransport_ReceiveFSM = pTransport_ReceiveFSM;
	this->pEvents_ReceiveFSM = pEvents_ReceiveFSM;
	this->pAccessControl_ReceiveFSM = pAccessControl_ReceiveFSM;
	this->pManagement_ReceiveFSM = pManagement_ReceiveFSM;
}



PrimitiveManipulator_ReceiveFSM::~PrimitiveManipulator_ReceiveFSM()
{
	delete context;
}

void PrimitiveManipulator_ReceiveFSM::setupNotifications()
{
	pManagement_ReceiveFSM->registerNotification("Receiving_Ready_NotControlled_Init", ieHandler, "InternalStateChange_To_PrimitiveManipulator_ReceiveFSM_Receiving_Ready_NotControlled_Init", "Management_ReceiveFSM");
	pManagement_ReceiveFSM->registerNotification("Receiving_Ready_NotControlled_Standby", ieHandler, "InternalStateChange_To_PrimitiveManipulator_ReceiveFSM_Receiving_Ready_NotControlled_Standby", "Management_ReceiveFSM");
	pManagement_ReceiveFSM->registerNotification("Receiving_Ready_NotControlled_Failure", ieHandler, "InternalStateChange_To_PrimitiveManipulator_ReceiveFSM_Receiving_Ready_NotControlled_Failure", "Management_ReceiveFSM");
	pManagement_ReceiveFSM->registerNotification("Receiving_Ready_NotControlled_Shutdown", ieHandler, "InternalStateChange_To_PrimitiveManipulator_ReceiveFSM_Receiving_Ready_NotControlled_Shutdown", "Management_ReceiveFSM");
	pManagement_ReceiveFSM->registerNotification("Receiving_Ready_NotControlled_Emergency", ieHandler, "InternalStateChange_To_PrimitiveManipulator_ReceiveFSM_Receiving_Ready_NotControlled_Emergency", "Management_ReceiveFSM");
	pManagement_ReceiveFSM->registerNotification("Receiving_Ready_NotControlled", ieHandler, "InternalStateChange_To_PrimitiveManipulator_ReceiveFSM_Receiving_Ready_NotControlled_Standby", "Management_ReceiveFSM");
	pManagement_ReceiveFSM->registerNotification("Receiving_Ready_Controlled_Standby", ieHandler, "InternalStateChange_To_PrimitiveManipulator_ReceiveFSM_Receiving_Ready_Controlled_Standby", "Management_ReceiveFSM");
	pManagement_ReceiveFSM->registerNotification("Receiving_Ready_Controlled_Ready", ieHandler, "InternalStateChange_To_PrimitiveManipulator_ReceiveFSM_Receiving_Ready_Controlled_Ready", "Management_ReceiveFSM");
	pManagement_ReceiveFSM->registerNotification("Receiving_Ready_Controlled_Emergency", ieHandler, "InternalStateChange_To_PrimitiveManipulator_ReceiveFSM_Receiving_Ready_Controlled_Emergency", "Management_ReceiveFSM");
	pManagement_ReceiveFSM->registerNotification("Receiving_Ready_Controlled", ieHandler, "InternalStateChange_To_PrimitiveManipulator_ReceiveFSM_Receiving_Ready_Controlled_Standby", "Management_ReceiveFSM");
	pManagement_ReceiveFSM->registerNotification("Receiving_Ready", ieHandler, "InternalStateChange_To_PrimitiveManipulator_ReceiveFSM_Receiving_Ready_NotControlled_Standby", "Management_ReceiveFSM");
	pManagement_ReceiveFSM->registerNotification("Receiving", ieHandler, "InternalStateChange_To_PrimitiveManipulator_ReceiveFSM_Receiving_Ready_NotControlled_Standby", "Management_ReceiveFSM");
	registerNotification("Receiving_Ready_NotControlled_Standby", pManagement_ReceiveFSM->getHandler(), "InternalStateChange_To_Management_ReceiveFSM_Receiving_Ready_NotControlled_Standby", "PrimitiveManipulator_ReceiveFSM");
	registerNotification("Receiving_Ready_NotControlled_Init", pManagement_ReceiveFSM->getHandler(), "InternalStateChange_To_Management_ReceiveFSM_Receiving_Ready_NotControlled_Init", "PrimitiveManipulator_ReceiveFSM");
	registerNotification("Receiving_Ready_NotControlled_Failure", pManagement_ReceiveFSM->getHandler(), "InternalStateChange_To_Management_ReceiveFSM_Receiving_Ready_NotControlled_Failure", "PrimitiveManipulator_ReceiveFSM");
	registerNotification("Receiving_Ready_NotControlled_Shutdown", pManagement_ReceiveFSM->getHandler(), "InternalStateChange_To_Management_ReceiveFSM_Receiving_Ready_NotControlled_Shutdown", "PrimitiveManipulator_ReceiveFSM");
	registerNotification("Receiving_Ready_NotControlled_Emergency", pManagement_ReceiveFSM->getHandler(), "InternalStateChange_To_Management_ReceiveFSM_Receiving_Ready_NotControlled_Emergency", "PrimitiveManipulator_ReceiveFSM");
	registerNotification("Receiving_Ready_NotControlled", pManagement_ReceiveFSM->getHandler(), "InternalStateChange_To_Management_ReceiveFSM_Receiving_Ready_NotControlled", "PrimitiveManipulator_ReceiveFSM");
	registerNotification("Receiving_Ready_Controlled_Standby", pManagement_ReceiveFSM->getHandler(), "InternalStateChange_To_Management_ReceiveFSM_Receiving_Ready_Controlled_Standby", "PrimitiveManipulator_ReceiveFSM");
	registerNotification("Receiving_Ready_Controlled_Ready", pManagement_ReceiveFSM->getHandler(), "InternalStateChange_To_Management_ReceiveFSM_Receiving_Ready_Controlled_Ready", "PrimitiveManipulator_ReceiveFSM");
	registerNotification("Receiving_Ready_Controlled_Emergency", pManagement_ReceiveFSM->getHandler(), "InternalStateChange_To_Management_ReceiveFSM_Receiving_Ready_Controlled_Emergency", "PrimitiveManipulator_ReceiveFSM");
	registerNotification("Receiving_Ready_Controlled", pManagement_ReceiveFSM->getHandler(), "InternalStateChange_To_Management_ReceiveFSM_Receiving_Ready_Controlled", "PrimitiveManipulator_ReceiveFSM");
	registerNotification("Receiving_Ready", pManagement_ReceiveFSM->getHandler(), "InternalStateChange_To_Management_ReceiveFSM_Receiving_Ready", "PrimitiveManipulator_ReceiveFSM");
	registerNotification("Receiving", pManagement_ReceiveFSM->getHandler(), "InternalStateChange_To_Management_ReceiveFSM_Receiving", "PrimitiveManipulator_ReceiveFSM");

	iop::Component &cmp = iop::Component::get_instance();
	ManipulatorSpecificationServiceService *spec_srv = static_cast<ManipulatorSpecificationServiceService*>(cmp.get_service("ManipulatorSpecificationService"));
	if (spec_srv != NULL) {
		p_joint_names = spec_srv->pManipulatorSpecificationService_ReceiveFSM->getJointNames();
	} else {
		throw std::runtime_error("[PrimitiveManipulator] no ManipulatorSpecificationService in configuration found! Please include its plugin first (in the list)!");
	}
	for (unsigned int index = 0; index < p_joint_names.size(); index++) {
		p_joint_velocities[p_joint_names[index]] = 0.;
		p_joint_positions[p_joint_names[index]] = 0.;
	}
	iop::Config cfg("~PrimitiveManipulator");
	p_sub_jointstates = cfg.subscribe<sensor_msgs::JointState>("joint_states", 1, &PrimitiveManipulator_ReceiveFSM::pJoinStateCallback, this);
	p_pub_cmd_jointstates = cfg.advertise<sensor_msgs::JointState>("cmd_joint_velocities", 1, false);
	p_pub_cmd_vel = cfg.advertise<std_msgs::Float64MultiArray>("velocity_controller/command", 1, false);

}

void PrimitiveManipulator_ReceiveFSM::sendReportJointEffortAction(QueryJointEffort msg, Receive::Body::ReceiveRec transportData)
{
	/// Insert User Code HERE
	JausAddress sender = transportData.getAddress();
	ROS_DEBUG_NAMED("PrimitiveManipulator", "sendReportJointEffortAction to %s", sender.str().c_str());

	p_mutex.lock();
	ReportJointEffort response;
	std::map<std::string, float>::iterator it_ps;
	for (unsigned int index = 0; index < p_joint_names.size(); index++) {
		ReportJointEffort::Body::JointEffortList::JointEffortRec joint_effort;
		joint_effort.setJointEffort(p_joint_velocities[p_joint_names[index]]);
		response.getBody()->getJointEffortList()->addElement(joint_effort);
	}
	this->sendJausMessage(response, sender);
	p_mutex.unlock();
}

//void PrimitiveManipulator_ReceiveFSM::sendReportManipulatorSpecificationsAction(QueryManipulatorSpecifications msg, Receive::Body::ReceiveRec transportData)
//{
//	/// Insert User Code HERE
//	JausAddress sender = transportData.getAddress();
//	ROS_DEBUG_NAMED("PrimitiveManipulator", "sendReportManipulatorSpecificationsAction to %d.%d.%d", subsystem_id, node_id, component_id);
//	ReportManipulatorSpecifications response;
//	iop_manipulator_core_fkie::ReportManipulatorSpecification spec = p_urdf_reader.getManipulatorSpecification();
//	unsigned char bytes[spec.getSize()];
//	spec.encode(bytes);
//	response.getBody()->getReportManipulatorSpecification()->decode(bytes);
//	// we have set Y axes back to -30 to pass the CVT test, bug in CVT or JTS?
//	//  response.getBody()->getReportManipulatorSpecification()->getManipulatorCoordinateSystemRec()->setManipulatorCoordinateSysY(-30);
//	ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::ManipulatorCoordinateSystemRec *mcsr = response.getBody()->getReportManipulatorSpecification()->getManipulatorCoordinateSystemRec();
//	sendJausMessage(response, sender);
//}

void PrimitiveManipulator_ReceiveFSM::setJointEffortAction(SetJointEffort msg, Receive::Body::ReceiveRec transportData)
{
	p_mutex.lock();
	sensor_msgs::JointState ros_msg;
	ros_msg.header.stamp = ros::Time::now();
	std_msgs::Float64MultiArray ros_msg_vel;
	for (unsigned int index = 0; index < msg.getBody()->getJointEffortList()->getNumberOfElements(); index++) {
		if (index < p_joint_names.size()) {
			std::string joint_name = p_joint_names[index];
			double vel = msg.getBody()->getJointEffortList()->getElement(index)->getJointEffort();
			double vel_ok = (int)(vel*100)/100.;
			ros_msg.name.push_back(joint_name);
			ros_msg.velocity.push_back(vel_ok);
			ros_msg_vel.data.push_back(vel_ok);
		}
	}
	p_pub_cmd_jointstates.publish(ros_msg);
	p_pub_cmd_vel.publish(ros_msg_vel);
	p_mutex.unlock();
}

void PrimitiveManipulator_ReceiveFSM::stopMotionAction()
{
	ROS_DEBUG_NAMED("PrimitiveManipulator", "stop motion");
	p_mutex.lock();
	sensor_msgs::JointState ros_msg;
	ros_msg.header.stamp = ros::Time::now();
	std_msgs::Float64MultiArray ros_msg_vel;
	for (unsigned int index = 0; index < p_joint_names.size(); index++) {
		if (index < p_joint_names.size()) {
			std::string joint_name = p_joint_names[index];
			double vel = 0.0;
			double vel_ok = (int)(vel*100)/100.;
			ros_msg.name.push_back(joint_name);
			ros_msg.velocity.push_back(vel_ok);
			ros_msg_vel.data.push_back(vel_ok);
		}
	}
	p_pub_cmd_jointstates.publish(ros_msg);
	p_pub_cmd_vel.publish(ros_msg_vel);
	p_mutex.unlock();
}

bool PrimitiveManipulator_ReceiveFSM::isControllingClient(Receive::Body::ReceiveRec transportData)
{
	//// By default, inherited guards call the parent function.
	//// This can be replaced or modified as needed.
	return pAccessControl_ReceiveFSM->isControllingClient(transportData );
}

void PrimitiveManipulator_ReceiveFSM::pJoinStateCallback(const sensor_msgs::JointState::ConstPtr& joint_state)
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
			if (joint_state->position.size() > it_ids->second) {
				p_joint_positions[it_ids->first] = joint_state->position[it_ids->second];
			} else {
				p_joint_positions[it_ids->first] = 0.;
			}
			if (joint_state->velocity.size() > it_ids->second) {
				p_joint_velocities[it_ids->first] = joint_state->velocity[it_ids->second];
			} else {
				p_joint_velocities[it_ids->first] = 0.;
			}
		} else {
			p_joint_positions[it_ids->first] = 0.;
			p_joint_velocities[it_ids->first] = 0.;
		}
	}
	//  printf("[ManipulatorJointPositionSensor] positions:\n");
	//  std::map<std::string, float>::iterator it_ps;
	//  for (unsigned int index = 0; index < p_joint_names.size(); index++) {
	//    printf("  %s: %f\n",  p_joint_names[index].c_str(), p_joint_positions[p_joint_names[index]]);
	//  }
	p_mutex.unlock();
}


};
