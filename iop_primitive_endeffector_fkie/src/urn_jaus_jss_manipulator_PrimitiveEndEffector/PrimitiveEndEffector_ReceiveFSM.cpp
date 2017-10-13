

#include "urn_jaus_jss_manipulator_PrimitiveEndEffector/PrimitiveEndEffector_ReceiveFSM.h"
#include <iop_component_fkie/iop_config.h>

#include <boost/algorithm/string.hpp>
#include <ros/console.h>

using namespace JTS;

namespace urn_jaus_jss_manipulator_PrimitiveEndEffector
{



PrimitiveEndEffector_ReceiveFSM::PrimitiveEndEffector_ReceiveFSM(urn_jaus_jss_core_Transport::Transport_ReceiveFSM* pTransport_ReceiveFSM, urn_jaus_jss_core_Events::Events_ReceiveFSM* pEvents_ReceiveFSM, urn_jaus_jss_core_AccessControl::AccessControl_ReceiveFSM* pAccessControl_ReceiveFSM, urn_jaus_jss_core_Management::Management_ReceiveFSM* pManagement_ReceiveFSM)
{

	/*
	 * If there are other variables, context must be constructed last so that all
	 * class variables are available if an EntryAction of the InitialState of the
	 * statemachine needs them.
	 */
	context = new PrimitiveEndEffector_ReceiveFSMContext(*this);

	this->pTransport_ReceiveFSM = pTransport_ReceiveFSM;
	this->pEvents_ReceiveFSM = pEvents_ReceiveFSM;
	this->pAccessControl_ReceiveFSM = pAccessControl_ReceiveFSM;
	this->pManagement_ReceiveFSM = pManagement_ReceiveFSM;
	this->p_gripper_joint = "gripperWidth_joint";
}



PrimitiveEndEffector_ReceiveFSM::~PrimitiveEndEffector_ReceiveFSM()
{
	delete context;
}

void PrimitiveEndEffector_ReceiveFSM::setupNotifications()
{
	pManagement_ReceiveFSM->registerNotification("Receiving_Ready_NotControlled_Init", ieHandler, "InternalStateChange_To_PrimitiveEndEffector_ReceiveFSM_Receiving_Ready_NotControlled_Init", "Management_ReceiveFSM");
	pManagement_ReceiveFSM->registerNotification("Receiving_Ready_NotControlled_Standby", ieHandler, "InternalStateChange_To_PrimitiveEndEffector_ReceiveFSM_Receiving_Ready_NotControlled_Standby", "Management_ReceiveFSM");
	pManagement_ReceiveFSM->registerNotification("Receiving_Ready_NotControlled_Failure", ieHandler, "InternalStateChange_To_PrimitiveEndEffector_ReceiveFSM_Receiving_Ready_NotControlled_Failure", "Management_ReceiveFSM");
	pManagement_ReceiveFSM->registerNotification("Receiving_Ready_NotControlled_Shutdown", ieHandler, "InternalStateChange_To_PrimitiveEndEffector_ReceiveFSM_Receiving_Ready_NotControlled_Shutdown", "Management_ReceiveFSM");
	pManagement_ReceiveFSM->registerNotification("Receiving_Ready_NotControlled_Emergency", ieHandler, "InternalStateChange_To_PrimitiveEndEffector_ReceiveFSM_Receiving_Ready_NotControlled_Emergency", "Management_ReceiveFSM");
	pManagement_ReceiveFSM->registerNotification("Receiving_Ready_NotControlled", ieHandler, "InternalStateChange_To_PrimitiveEndEffector_ReceiveFSM_Receiving_Ready_NotControlled_Standby", "Management_ReceiveFSM");
	pManagement_ReceiveFSM->registerNotification("Receiving_Ready_Controlled_Standby", ieHandler, "InternalStateChange_To_PrimitiveEndEffector_ReceiveFSM_Receiving_Ready_Controlled_Standby", "Management_ReceiveFSM");
	pManagement_ReceiveFSM->registerNotification("Receiving_Ready_Controlled_Ready", ieHandler, "InternalStateChange_To_PrimitiveEndEffector_ReceiveFSM_Receiving_Ready_Controlled_Ready", "Management_ReceiveFSM");
	pManagement_ReceiveFSM->registerNotification("Receiving_Ready_Controlled_Emergency", ieHandler, "InternalStateChange_To_PrimitiveEndEffector_ReceiveFSM_Receiving_Ready_Controlled_Emergency", "Management_ReceiveFSM");
	pManagement_ReceiveFSM->registerNotification("Receiving_Ready_Controlled", ieHandler, "InternalStateChange_To_PrimitiveEndEffector_ReceiveFSM_Receiving_Ready_Controlled_Standby", "Management_ReceiveFSM");
	pManagement_ReceiveFSM->registerNotification("Receiving_Ready", ieHandler, "InternalStateChange_To_PrimitiveEndEffector_ReceiveFSM_Receiving_Ready_NotControlled_Standby", "Management_ReceiveFSM");
	pManagement_ReceiveFSM->registerNotification("Receiving", ieHandler, "InternalStateChange_To_PrimitiveEndEffector_ReceiveFSM_Receiving_Ready_NotControlled_Standby", "Management_ReceiveFSM");
	registerNotification("Receiving_Ready_NotControlled_Standby", pManagement_ReceiveFSM->getHandler(), "InternalStateChange_To_Management_ReceiveFSM_Receiving_Ready_NotControlled_Standby", "PrimitiveEndEffector_ReceiveFSM");
	registerNotification("Receiving_Ready_NotControlled_Init", pManagement_ReceiveFSM->getHandler(), "InternalStateChange_To_Management_ReceiveFSM_Receiving_Ready_NotControlled_Init", "PrimitiveEndEffector_ReceiveFSM");
	registerNotification("Receiving_Ready_NotControlled_Failure", pManagement_ReceiveFSM->getHandler(), "InternalStateChange_To_Management_ReceiveFSM_Receiving_Ready_NotControlled_Failure", "PrimitiveEndEffector_ReceiveFSM");
	registerNotification("Receiving_Ready_NotControlled_Shutdown", pManagement_ReceiveFSM->getHandler(), "InternalStateChange_To_Management_ReceiveFSM_Receiving_Ready_NotControlled_Shutdown", "PrimitiveEndEffector_ReceiveFSM");
	registerNotification("Receiving_Ready_NotControlled_Emergency", pManagement_ReceiveFSM->getHandler(), "InternalStateChange_To_Management_ReceiveFSM_Receiving_Ready_NotControlled_Emergency", "PrimitiveEndEffector_ReceiveFSM");
	registerNotification("Receiving_Ready_NotControlled", pManagement_ReceiveFSM->getHandler(), "InternalStateChange_To_Management_ReceiveFSM_Receiving_Ready_NotControlled", "PrimitiveEndEffector_ReceiveFSM");
	registerNotification("Receiving_Ready_Controlled_Standby", pManagement_ReceiveFSM->getHandler(), "InternalStateChange_To_Management_ReceiveFSM_Receiving_Ready_Controlled_Standby", "PrimitiveEndEffector_ReceiveFSM");
	registerNotification("Receiving_Ready_Controlled_Ready", pManagement_ReceiveFSM->getHandler(), "InternalStateChange_To_Management_ReceiveFSM_Receiving_Ready_Controlled_Ready", "PrimitiveEndEffector_ReceiveFSM");
	registerNotification("Receiving_Ready_Controlled_Emergency", pManagement_ReceiveFSM->getHandler(), "InternalStateChange_To_Management_ReceiveFSM_Receiving_Ready_Controlled_Emergency", "PrimitiveEndEffector_ReceiveFSM");
	registerNotification("Receiving_Ready_Controlled", pManagement_ReceiveFSM->getHandler(), "InternalStateChange_To_Management_ReceiveFSM_Receiving_Ready_Controlled", "PrimitiveEndEffector_ReceiveFSM");
	registerNotification("Receiving_Ready", pManagement_ReceiveFSM->getHandler(), "InternalStateChange_To_Management_ReceiveFSM_Receiving_Ready", "PrimitiveEndEffector_ReceiveFSM");
	registerNotification("Receiving", pManagement_ReceiveFSM->getHandler(), "InternalStateChange_To_Management_ReceiveFSM_Receiving", "PrimitiveEndEffector_ReceiveFSM");
	iop::Config cfg("~PrimitiveEndEffector");
	std::string manipulator_id;
	cfg.param("gripper_joint", p_gripper_joint, p_gripper_joint);
	cfg.param("manipulator_id", manipulator_id, manipulator_id);
	if (!manipulator_id.empty()) {
		std::vector<std::string> strs;
		boost::split(strs, manipulator_id, boost::is_any_of(".:"));
		if (strs.size() != 3) {
			throw new std::string("Invalid manipulator_id parameter: "+ manipulator_id + "\n");
		} else {
			try {
				std::string::size_type sz;
				p_manipulator_id.setSubsystemID(atoi(strs[0].c_str()));
				p_manipulator_id.setNodeID(atoi(strs[1].c_str()));
				p_manipulator_id.setComponentID(atoi(strs[2].c_str()));
			} catch (...) {
			}
		}
	} else {
		ROS_WARN("empty manipulator_id -> no manipulator for this end effector specified");
	}
	p_mutex.lock();
	p_joint_names.push_back(p_gripper_joint);
	for (unsigned int index = 0; index < p_joint_names.size(); index++) {
		p_joint_velocities[p_joint_names[index]] = 0.;
		p_joint_positions[p_joint_names[index]] = 0.;
	}
	p_sub_jointstates = cfg.subscribe<sensor_msgs::JointState>("joint_states", 1, &PrimitiveEndEffector_ReceiveFSM::pJoinStateCallback, this);
	p_pub_cmd_jointstates = cfg.advertise<sensor_msgs::JointState>("cmd_joint_velocities", 1, false);
	p_pub_cmd_vel = cfg.advertise<std_msgs::Float64>("gripper_velocity_controller/command", 1, false);
	p_mutex.unlock();

}

void PrimitiveEndEffector_ReceiveFSM::sendReportEndEffectorEffortAction(QueryEndEffectorEffort msg, Receive::Body::ReceiveRec transportData)
{
	/// Insert User Code HERE
	JausAddress sender = transportData.getAddress();
	ROS_DEBUG_NAMED("PrimitiveEndEffector", "sendReportEndEffectorEffortAction to %s", sender.str().c_str());

	p_mutex.lock();
	ReportEndEffectorEffort response;
	std::map<std::string, float>::iterator it_ps;
	for (unsigned int index = 0; index < p_joint_names.size(); index++) {
		response.getBody()->getEndEffectorEffortRec()->setEndEffectorEffort(p_joint_velocities[p_joint_names[index]]);
	}
	this->sendJausMessage(response, sender);
	p_mutex.unlock();
}

void PrimitiveEndEffector_ReceiveFSM::sendReportEndEffectorSpecificationAction(QueryEndEffectorSpecification msg, Receive::Body::ReceiveRec transportData)
{
	/// Insert User Code HERE
	JausAddress sender = transportData.getAddress();
	ROS_DEBUG_NAMED("PrimitiveEndEffector", "sendReportEndEffectorSpecificationAction to %s", sender.str().c_str());
	ReportEndEffectorSpecification response;
	response.getBody()->getReportEndEffectorSpecificationRec()->setParentId(p_manipulator_id.get());
	sendJausMessage(response, sender);
}

void PrimitiveEndEffector_ReceiveFSM::setEndEffectorEffortAction(SetEndEffectorEffort msg, Receive::Body::ReceiveRec transportData)
{
	/// Insert User Code HERE
	ROS_DEBUG_NAMED("PrimitiveEndEffector", "setEndEffectorEffortAction to %f", msg.getBody()->getEndEffectorEffortRec()->getEndEffectorEffort());
	p_mutex.lock();
	sensor_msgs::JointState ros_msg_joints;
	ros_msg_joints.header.stamp = ros::Time::now();
	std_msgs::Float64 ros_cmd_vel;
	double gripper_vel = msg.getBody()->getEndEffectorEffortRec()->getEndEffectorEffort();
	gripper_vel = (int)(gripper_vel*100)/100.;
	ros_msg_joints.name.push_back(p_gripper_joint);
	ros_msg_joints.velocity.push_back(gripper_vel);
	ros_cmd_vel.data = gripper_vel;
	p_pub_cmd_jointstates.publish(ros_msg_joints);
	p_pub_cmd_vel.publish(ros_cmd_vel);
	p_mutex.unlock();
}

void PrimitiveEndEffector_ReceiveFSM::stopMotionAction()
{
	ROS_DEBUG_NAMED("PrimitiveEndEffector", "stopMotionAction");
	p_mutex.lock();
	sensor_msgs::JointState ros_msg_joints;
	ros_msg_joints.header.stamp = ros::Time::now();
	std_msgs::Float64 ros_cmd_vel;
	double gripper_vel = 0.0;
	gripper_vel = (int)(gripper_vel*100)/100.;
	ros_msg_joints.name.push_back(p_gripper_joint);
	ros_msg_joints.velocity.push_back(gripper_vel);
	ros_cmd_vel.data = gripper_vel;
	p_pub_cmd_jointstates.publish(ros_msg_joints);
	p_pub_cmd_vel.publish(ros_cmd_vel);
	p_mutex.unlock();
}

bool PrimitiveEndEffector_ReceiveFSM::isControllingClient(Receive::Body::ReceiveRec transportData)
{
	//// By default, inherited guards call the parent function.
	//// This can be replaced or modified as needed.
	return pAccessControl_ReceiveFSM->isControllingClient(transportData );
}

void PrimitiveEndEffector_ReceiveFSM::pJoinStateCallback(const sensor_msgs::JointState::ConstPtr& joint_state)
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
