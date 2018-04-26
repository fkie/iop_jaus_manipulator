

#include "urn_jaus_jss_manipulator_PrimitivePanTilt/PrimitivePanTilt_ReceiveFSM.h"
#include <iop_component_fkie/iop_component.h>
#include <iop_component_fkie/iop_config.h>
#include "urn_jaus_jss_manipulator_PanTiltSpecificationService/PanTiltSpecificationServiceService.h"



using namespace JTS;
using namespace urn_jaus_jss_manipulator_PanTiltSpecificationService;

namespace urn_jaus_jss_manipulator_PrimitivePanTilt
{



PrimitivePanTilt_ReceiveFSM::PrimitivePanTilt_ReceiveFSM(urn_jaus_jss_core_Transport::Transport_ReceiveFSM* pTransport_ReceiveFSM, urn_jaus_jss_core_Events::Events_ReceiveFSM* pEvents_ReceiveFSM, urn_jaus_jss_core_AccessControl::AccessControl_ReceiveFSM* pAccessControl_ReceiveFSM, urn_jaus_jss_core_Management::Management_ReceiveFSM* pManagement_ReceiveFSM) {
	/*
	 * If there are other variables, context must be constructed last so that all
	 * class variables are available if an EntryAction of the InitialState of the
	 * statemachine needs them.
	 */
	context = new PrimitivePanTilt_ReceiveFSMContext(*this);

	this->pTransport_ReceiveFSM = pTransport_ReceiveFSM;
	this->pEvents_ReceiveFSM = pEvents_ReceiveFSM;
	this->pAccessControl_ReceiveFSM = pAccessControl_ReceiveFSM;
	this->pManagement_ReceiveFSM = pManagement_ReceiveFSM;
	p_joint1_name = "joint1";
	p_joint2_name = "joint1";
	p_joint1_cmd_effort = 0.0;
	p_joint2_cmd_effort = 0.0;
}



PrimitivePanTilt_ReceiveFSM::~PrimitivePanTilt_ReceiveFSM()
{
	delete context;
}

void PrimitivePanTilt_ReceiveFSM::setupNotifications()
{
	pManagement_ReceiveFSM->registerNotification("Receiving_Ready_NotControlled_Init", ieHandler, "InternalStateChange_To_PrimitivePanTilt_ReceiveFSM_Receiving_Ready_NotControlled_Init", "Management_ReceiveFSM");
	pManagement_ReceiveFSM->registerNotification("Receiving_Ready_NotControlled_Standby", ieHandler, "InternalStateChange_To_PrimitivePanTilt_ReceiveFSM_Receiving_Ready_NotControlled_Standby", "Management_ReceiveFSM");
	pManagement_ReceiveFSM->registerNotification("Receiving_Ready_NotControlled_Failure", ieHandler, "InternalStateChange_To_PrimitivePanTilt_ReceiveFSM_Receiving_Ready_NotControlled_Failure", "Management_ReceiveFSM");
	pManagement_ReceiveFSM->registerNotification("Receiving_Ready_NotControlled_Shutdown", ieHandler, "InternalStateChange_To_PrimitivePanTilt_ReceiveFSM_Receiving_Ready_NotControlled_Shutdown", "Management_ReceiveFSM");
	pManagement_ReceiveFSM->registerNotification("Receiving_Ready_NotControlled_Emergency", ieHandler, "InternalStateChange_To_PrimitivePanTilt_ReceiveFSM_Receiving_Ready_NotControlled_Emergency", "Management_ReceiveFSM");
	pManagement_ReceiveFSM->registerNotification("Receiving_Ready_NotControlled", ieHandler, "InternalStateChange_To_PrimitivePanTilt_ReceiveFSM_Receiving_Ready_NotControlled_Standby", "Management_ReceiveFSM");
	pManagement_ReceiveFSM->registerNotification("Receiving_Ready_Controlled_Standby", ieHandler, "InternalStateChange_To_PrimitivePanTilt_ReceiveFSM_Receiving_Ready_Controlled_Standby", "Management_ReceiveFSM");
	pManagement_ReceiveFSM->registerNotification("Receiving_Ready_Controlled_Ready", ieHandler, "InternalStateChange_To_PrimitivePanTilt_ReceiveFSM_Receiving_Ready_Controlled_Ready", "Management_ReceiveFSM");
	pManagement_ReceiveFSM->registerNotification("Receiving_Ready_Controlled_Emergency", ieHandler, "InternalStateChange_To_PrimitivePanTilt_ReceiveFSM_Receiving_Ready_Controlled_Emergency", "Management_ReceiveFSM");
	pManagement_ReceiveFSM->registerNotification("Receiving_Ready_Controlled", ieHandler, "InternalStateChange_To_PrimitivePanTilt_ReceiveFSM_Receiving_Ready_Controlled_Standby", "Management_ReceiveFSM");
	pManagement_ReceiveFSM->registerNotification("Receiving_Ready", ieHandler, "InternalStateChange_To_PrimitivePanTilt_ReceiveFSM_Receiving_Ready_NotControlled_Standby", "Management_ReceiveFSM");
	pManagement_ReceiveFSM->registerNotification("Receiving", ieHandler, "InternalStateChange_To_PrimitivePanTilt_ReceiveFSM_Receiving_Ready_NotControlled_Standby", "Management_ReceiveFSM");
	registerNotification("Receiving_Ready_NotControlled_Standby", pManagement_ReceiveFSM->getHandler(), "InternalStateChange_To_Management_ReceiveFSM_Receiving_Ready_NotControlled_Standby", "PrimitivePanTilt_ReceiveFSM");
	registerNotification("Receiving_Ready_NotControlled_Init", pManagement_ReceiveFSM->getHandler(), "InternalStateChange_To_Management_ReceiveFSM_Receiving_Ready_NotControlled_Init", "PrimitivePanTilt_ReceiveFSM");
	registerNotification("Receiving_Ready_NotControlled_Failure", pManagement_ReceiveFSM->getHandler(), "InternalStateChange_To_Management_ReceiveFSM_Receiving_Ready_NotControlled_Failure", "PrimitivePanTilt_ReceiveFSM");
	registerNotification("Receiving_Ready_NotControlled_Shutdown", pManagement_ReceiveFSM->getHandler(), "InternalStateChange_To_Management_ReceiveFSM_Receiving_Ready_NotControlled_Shutdown", "PrimitivePanTilt_ReceiveFSM");
	registerNotification("Receiving_Ready_NotControlled_Emergency", pManagement_ReceiveFSM->getHandler(), "InternalStateChange_To_Management_ReceiveFSM_Receiving_Ready_NotControlled_Emergency", "PrimitivePanTilt_ReceiveFSM");
	registerNotification("Receiving_Ready_NotControlled", pManagement_ReceiveFSM->getHandler(), "InternalStateChange_To_Management_ReceiveFSM_Receiving_Ready_NotControlled", "PrimitivePanTilt_ReceiveFSM");
	registerNotification("Receiving_Ready_Controlled_Standby", pManagement_ReceiveFSM->getHandler(), "InternalStateChange_To_Management_ReceiveFSM_Receiving_Ready_Controlled_Standby", "PrimitivePanTilt_ReceiveFSM");
	registerNotification("Receiving_Ready_Controlled_Ready", pManagement_ReceiveFSM->getHandler(), "InternalStateChange_To_Management_ReceiveFSM_Receiving_Ready_Controlled_Ready", "PrimitivePanTilt_ReceiveFSM");
	registerNotification("Receiving_Ready_Controlled_Emergency", pManagement_ReceiveFSM->getHandler(), "InternalStateChange_To_Management_ReceiveFSM_Receiving_Ready_Controlled_Emergency", "PrimitivePanTilt_ReceiveFSM");
	registerNotification("Receiving_Ready_Controlled", pManagement_ReceiveFSM->getHandler(), "InternalStateChange_To_Management_ReceiveFSM_Receiving_Ready_Controlled", "PrimitivePanTilt_ReceiveFSM");
	registerNotification("Receiving_Ready", pManagement_ReceiveFSM->getHandler(), "InternalStateChange_To_Management_ReceiveFSM_Receiving_Ready", "PrimitivePanTilt_ReceiveFSM");
	registerNotification("Receiving", pManagement_ReceiveFSM->getHandler(), "InternalStateChange_To_Management_ReceiveFSM_Receiving", "PrimitivePanTilt_ReceiveFSM");
	pEvents_ReceiveFSM->get_event_handler().register_query(QueryPanTiltJointEffort::ID);
	iop::Component &cmp = iop::Component::get_instance();
	PanTiltSpecificationServiceService *spec_srv = static_cast<PanTiltSpecificationServiceService*>(cmp.get_service("PanTiltSpecificationService"));
	if (spec_srv != NULL) {
		std::pair<std::string, std::string> joint_names = spec_srv->pPanTiltSpecificationService_ReceiveFSM->getJointNames();
		p_limits = spec_srv->pPanTiltSpecificationService_ReceiveFSM->getLimits();
		p_joint1_name = joint_names.first;
		p_joint2_name = joint_names.second;
	} else {
		throw std::runtime_error("[PanTiltJointPositionDriver] no PanTiltSpecificationService in configuration found! Please include this plugin first (in the list)!");
	}

	iop::Config cfg("~PrimitivePanTilt");
	p_pub_cmd_vel_joints = cfg.advertise<sensor_msgs::JointState>("cmd_vel_joints", 3, false);
	p_pub_cmd_vel_pan = cfg.advertise<std_msgs::Float64>("cmd_vel_pan", 3, false);
	p_pub_cmd_vel_tilt = cfg.advertise<std_msgs::Float64>("cmd_vel_tilt", 3, false);
	p_pub_cmd_vel_pan32 = cfg.advertise<std_msgs::Float32>("cmd_vel_pan32", 3, false);
	p_pub_cmd_vel_tilt32 = cfg.advertise<std_msgs::Float32>("cmd_vel_tilt32", 3, false);
	p_pub_cmd_vel_twist = cfg.advertise<geometry_msgs::TwistStamped>("cmd_vel_twist", 3, false);
}

void PrimitivePanTilt_ReceiveFSM::sendReportPanTiltJointEffortAction(QueryPanTiltJointEffort msg, Receive::Body::ReceiveRec transportData)
{
	JausAddress sender = transportData.getAddress();
	ROS_DEBUG_NAMED("PrimitivePanTilt", "sendReportPanTiltJointEffortAction to %s", sender.str().c_str());
	p_mutex.lock();
	ReportPanTiltJointEffort response;
	// TODO: convert velocity back to effort using max velocity
	response.getBody()->getPanTiltJointEffortRec()->setJoint1Effort(p_joint1_cmd_effort);
	response.getBody()->getPanTiltJointEffortRec()->setJoint2Effort(p_joint2_cmd_effort);
	this->sendJausMessage(response, sender);
	p_mutex.unlock();
}

void PrimitivePanTilt_ReceiveFSM::setPanTiltJointEffortAction(SetPanTiltJointEffort msg)
{
	p_mutex.lock();
	sensor_msgs::JointState ros_msg;
	ros_msg.header.stamp = ros::Time::now();
	p_joint1_cmd_effort = msg.getBody()->getPanTiltJointEffortRec()->getJoint1Effort() / 100.0 * p_limits.first.max_velocity;
	p_joint2_cmd_effort = msg.getBody()->getPanTiltJointEffortRec()->getJoint2Effort() / 100.0 * p_limits.second.max_velocity;
	p_report_effort.getBody()->getPanTiltJointEffortRec()->setJoint1Effort(msg.getBody()->getPanTiltJointEffortRec()->getJoint1Effort());
	p_report_effort.getBody()->getPanTiltJointEffortRec()->setJoint2Effort(msg.getBody()->getPanTiltJointEffortRec()->getJoint2Effort());
	pEvents_ReceiveFSM->get_event_handler().set_report(QueryPanTiltJointEffort::ID, &p_report_effort);
	ros_msg.name.push_back(p_joint1_name);
	ros_msg.velocity.push_back(p_joint1_cmd_effort);
	ros_msg.name.push_back(p_joint2_name);
	ros_msg.velocity.push_back(p_joint2_cmd_effort);
	p_pub_cmd_vel_joints.publish(ros_msg);
	std_msgs::Float64 ros_pan_msg;
	ros_pan_msg.data = p_joint1_cmd_effort;
	p_pub_cmd_vel_pan.publish(ros_pan_msg);
	std_msgs::Float64 ros_tilt_msg;
	ros_tilt_msg.data = p_joint2_cmd_effort;
	p_pub_cmd_vel_tilt.publish(ros_tilt_msg);
	std_msgs::Float32 ros_pan_msg32;
	ros_pan_msg32.data = p_joint1_cmd_effort;
	p_pub_cmd_vel_pan32.publish(ros_pan_msg32);
	std_msgs::Float32 ros_tilt_msg32;
	ros_tilt_msg32.data = p_joint2_cmd_effort;
	p_pub_cmd_vel_tilt32.publish(ros_tilt_msg32);
	geometry_msgs::TwistStamped ros_twist;
	ros_twist.header.stamp = ros_msg.header.stamp;
	ros_twist.twist.angular.y = p_joint2_cmd_effort;
	ros_twist.twist.angular.z = p_joint1_cmd_effort;
	p_pub_cmd_vel_twist.publish(ros_twist);
	p_mutex.unlock();
}

void PrimitivePanTilt_ReceiveFSM::stopMotionAction()
{
	ROS_DEBUG_NAMED("PrimitivePanTilt", "stop motion");
	p_mutex.lock();
	sensor_msgs::JointState ros_msg;
	ros_msg.header.stamp = ros::Time::now();
	p_joint1_cmd_effort = 0.0;
	p_joint2_cmd_effort = 0.0;
	p_report_effort.getBody()->getPanTiltJointEffortRec()->setJoint1Effort(0);
	p_report_effort.getBody()->getPanTiltJointEffortRec()->setJoint2Effort(0);
	pEvents_ReceiveFSM->get_event_handler().set_report(QueryPanTiltJointEffort::ID, &p_report_effort);
	ros_msg.name.push_back(p_joint1_name);
	ros_msg.velocity.push_back(p_joint1_cmd_effort);
	ros_msg.name.push_back(p_joint2_name);
	ros_msg.velocity.push_back(p_joint2_cmd_effort);
	p_pub_cmd_vel_joints.publish(ros_msg);
	std_msgs::Float64 ros_pan_msg;
	ros_pan_msg.data = p_joint1_cmd_effort;
	p_pub_cmd_vel_pan.publish(ros_pan_msg);
	std_msgs::Float64 ros_tilt_msg;
	ros_tilt_msg.data = p_joint2_cmd_effort;
	p_pub_cmd_vel_tilt.publish(ros_tilt_msg);
	std_msgs::Float32 ros_pan_msg32;
	ros_pan_msg32.data = p_joint1_cmd_effort;
	p_pub_cmd_vel_pan32.publish(ros_pan_msg32);
	std_msgs::Float32 ros_tilt_msg32;
	ros_tilt_msg32.data = p_joint2_cmd_effort;
	p_pub_cmd_vel_tilt32.publish(ros_tilt_msg32);
	geometry_msgs::TwistStamped ros_twist;
	ros_twist.header.stamp = ros_msg.header.stamp;
	ros_twist.twist.angular.y = p_joint2_cmd_effort;
	ros_twist.twist.angular.z = p_joint1_cmd_effort;
	p_pub_cmd_vel_twist.publish(ros_twist);
	p_mutex.unlock();
}

bool PrimitivePanTilt_ReceiveFSM::isControllingClient(Receive::Body::ReceiveRec transportData)
{
	//// By default, inherited guards call the parent function.
	//// This can be replaced or modified as needed.
	return pAccessControl_ReceiveFSM->isControllingClient(transportData );
}


};
