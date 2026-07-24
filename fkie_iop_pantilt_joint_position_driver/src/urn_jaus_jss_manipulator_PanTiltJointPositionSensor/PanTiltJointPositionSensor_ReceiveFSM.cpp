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

#include "urn_jaus_jss_manipulator_PanTiltJointPositionSensor/PanTiltJointPositionSensor_ReceiveFSM.h"
#include <fkie_iop_component/iop_component.hpp>
#include <fkie_iop_component/iop_config.hpp>

#include <fkie_iop_pantilt_specification_service/urn_jaus_jss_manipulator_PanTiltSpecification/PanTiltSpecificationService.h>

using namespace JTS;
using namespace urn_jaus_jss_manipulator_PanTiltJointPositionDriver;
using namespace urn_jaus_jss_manipulator_PanTiltSpecification;

namespace urn_jaus_jss_manipulator_PanTiltJointPositionSensor {

PanTiltJointPositionSensor_ReceiveFSM::PanTiltJointPositionSensor_ReceiveFSM(std::shared_ptr<iop::Component> cmp, urn_jaus_jss_core_Events::Events_ReceiveFSM* pEvents_ReceiveFSM, urn_jaus_jss_core_Transport::Transport_ReceiveFSM* pTransport_ReceiveFSM)
    : logger(cmp->get_logger().get_child("PanTiltJointPositionSensor"))
{

    /*
     * If there are other variables, context must be constructed last so that all
     * class variables are available if an EntryAction of the InitialState of the
     * statemachine needs them.
     */
    context = new PanTiltJointPositionSensor_ReceiveFSMContext(*this);

    this->pEvents_ReceiveFSM = pEvents_ReceiveFSM;
    this->pTransport_ReceiveFSM = pTransport_ReceiveFSM;
    this->cmp = cmp;
    p_position_driver_service = NULL;
    p_joint1_name = "";
    p_joint2_name = "";
    p_joint1_position = 0.0;
    p_joint2_position = 0.0;
    p_use_posestamped = false;
    p_tf_frame_pantilt = "";
    p_tf_buffer = NULL;
    p_tf_listener = NULL;
}

PanTiltJointPositionSensor_ReceiveFSM::~PanTiltJointPositionSensor_ReceiveFSM()
{
    delete context;
}

void PanTiltJointPositionSensor_ReceiveFSM::setupNotifications()
{
    pEvents_ReceiveFSM->registerNotification("Receiving_Ready", ieHandler, "InternalStateChange_To_PanTiltJointPositionSensor_ReceiveFSM_Receiving_Ready", "Events_ReceiveFSM");
    pEvents_ReceiveFSM->registerNotification("Receiving", ieHandler, "InternalStateChange_To_PanTiltJointPositionSensor_ReceiveFSM_Receiving_Ready", "Events_ReceiveFSM");
    registerNotification("Receiving_Ready", pEvents_ReceiveFSM->getHandler(), "InternalStateChange_To_Events_ReceiveFSM_Receiving_Ready", "PanTiltJointPositionSensor_ReceiveFSM");
    registerNotification("Receiving", pEvents_ReceiveFSM->getHandler(), "InternalStateChange_To_Events_ReceiveFSM_Receiving", "PanTiltJointPositionSensor_ReceiveFSM");
}

void PanTiltJointPositionSensor_ReceiveFSM::setupIopConfiguration()
{
    pEvents_ReceiveFSM->get_event_handler().register_query(QueryPanTiltJointPositions::ID);

    PanTiltSpecificationService* spec_srv = static_cast<PanTiltSpecificationService*>(cmp->get_service("PanTiltSpecificationService"));
    if (spec_srv != NULL) {
        std::pair<std::string, std::string> joint_names = spec_srv->pPanTiltSpecification_ReceiveFSM->getJointNames();
        p_joint1_name = joint_names.first;
        p_joint2_name = joint_names.second;
    } else {
        throw std::runtime_error("[PanTiltJointPositionSensor] no PanTiltSpecificationService in configuration found! Please include its plugin first (in the list)!");
    }

    iop::Config cfg(cmp, "PanTiltJointPositionSensor");
    cfg.param<bool>("use_posestamped", p_use_posestamped, p_use_posestamped, true,
        rcl_interfaces::msg::ParameterType::PARAMETER_BOOL,
        "Adds support for geometry_msgs::msg::PoseStamped message",
        "Default: false");
    if (p_use_posestamped) {
        cfg.param<std::string>("tf_frame_pantilt", p_tf_frame_pantilt, p_tf_frame_pantilt, true,
            rcl_interfaces::msg::ParameterType::PARAMETER_STRING,
            "Only if ```use_posestamped``` is true. Sets the given frame_id in ROS message header before send to ROS",
            "Default: ''");
        if (!p_tf_frame_pantilt.empty()) {
            p_tf_buffer = std::make_unique<tf2_ros::Buffer>(cmp->get_clock());
            p_tf_listener = std::make_shared<tf2_ros::TransformListener>(*p_tf_buffer);
        }
        p_sub_pos_stamped = cfg.create_subscription<geometry_msgs::msg::PoseStamped>("pos_pantilt", 5, std::bind(&PanTiltJointPositionSensor_ReceiveFSM::pPanTiltPoseStampedCallback, this, std::placeholders::_1));
    }
    p_sub_pos_joints = cfg.create_subscription<sensor_msgs::msg::JointState>("pos_joints", 1, std::bind(&PanTiltJointPositionSensor_ReceiveFSM::pJoinStateCallback, this, std::placeholders::_1));
    p_sub_pos_pan = cfg.create_subscription<std_msgs::msg::Float64>("pos_pan", 1, std::bind(&PanTiltJointPositionSensor_ReceiveFSM::pPanFloatCallback, this, std::placeholders::_1));
    p_sub_pos_tilt = cfg.create_subscription<std_msgs::msg::Float64>("pos_tilt", 1, std::bind(&PanTiltJointPositionSensor_ReceiveFSM::pTiltFloatCallback, this, std::placeholders::_1));
    p_sub_pos_pan32 = cfg.create_subscription<std_msgs::msg::Float32>("pos_pan32", 1, std::bind(&PanTiltJointPositionSensor_ReceiveFSM::pPanFloat32Callback, this, std::placeholders::_1));
    p_sub_pos_tilt32 = cfg.create_subscription<std_msgs::msg::Float32>("pos_tilt32", 1, std::bind(&PanTiltJointPositionSensor_ReceiveFSM::pTiltFloat32Callback, this, std::placeholders::_1));
}

void PanTiltJointPositionSensor_ReceiveFSM::sendReportPanTiltJointPositionsAction(QueryPanTiltJointPositions msg, Receive::Body::ReceiveRec transportData)
{
    uint16_t subsystem_id = transportData.getSrcSubsystemID();
    uint8_t node_id = transportData.getSrcNodeID();
    uint8_t component_id = transportData.getSrcComponentID();
    JausAddress sender(subsystem_id, node_id, component_id);
    RCLCPP_DEBUG(logger, "ReportPanTiltJointPositions (%.2lf, %.2lf) to %d.%d.%d", p_joint1_position, p_joint2_position, subsystem_id, node_id, component_id);
    p_mutex.lock();
    sendJausMessage(p_report_pantilt, sender);
    p_mutex.unlock();
}

void PanTiltJointPositionSensor_ReceiveFSM::pUpdatePosition(double pan, double tilt)
{
    p_mutex.lock();
    bool updated = false;
    if (p_joint1_position != pan) {
        p_joint1_position = pan;
        updated = true;
    }
    if (p_joint2_position != tilt) {
        p_joint2_position = tilt;
        updated = true;
    }
    if (updated) {
        // set event handling
        p_report_pantilt.getBody()->getPanTiltJointPositionRec()->setJoint1Position(p_joint1_position);
        p_report_pantilt.getBody()->getPanTiltJointPositionRec()->setJoint2Position(p_joint2_position);
        pEvents_ReceiveFSM->get_event_handler().set_report(QueryPanTiltJointPositions::ID, &p_report_pantilt);
    }
    p_mutex.unlock();
    // forward position to the driver
    if (updated && pGetPostionDriver() != NULL) {
        pGetPostionDriver()->set_current_position(p_joint1_position, p_joint2_position);
    }
}

void PanTiltJointPositionSensor_ReceiveFSM::pJoinStateCallback(const sensor_msgs::msg::JointState::SharedPtr joint_state)
{
    // create index map
    p_mutex.lock();
    double pan, tilt = 0.0;
    for (unsigned int index = 0; index < joint_state->name.size(); index++) {
        if (!p_joint1_name.empty() && p_joint1_name.compare(joint_state->name[index]) == 0) {
            if (joint_state->position.size() > index) {
                pan = joint_state->position[index];
            }
        }
        if (!p_joint2_name.empty() && p_joint2_name.compare(joint_state->name[index]) == 0) {
            if (joint_state->position.size() > index) {
                tilt = joint_state->position[index];
            }
        }
    }
    p_mutex.unlock();
    pUpdatePosition(pan, tilt);
}

void PanTiltJointPositionSensor_ReceiveFSM::pPanFloatCallback(const std_msgs::msg::Float64::SharedPtr msg)
{
    pUpdatePosition(msg->data, p_joint2_position);
}

void PanTiltJointPositionSensor_ReceiveFSM::pTiltFloatCallback(const std_msgs::msg::Float64::SharedPtr msg)
{
    pUpdatePosition(p_joint1_position, msg->data);
}

void PanTiltJointPositionSensor_ReceiveFSM::pPanFloat32Callback(const std_msgs::msg::Float32::SharedPtr msg)
{
    pUpdatePosition(msg->data, p_joint2_position);
}

void PanTiltJointPositionSensor_ReceiveFSM::pTiltFloat32Callback(const std_msgs::msg::Float32::SharedPtr msg)
{
    pUpdatePosition(p_joint1_position, msg->data);
}

PanTiltJointPositionDriver_ReceiveFSM* PanTiltJointPositionSensor_ReceiveFSM::pGetPostionDriver()
{
    if (p_position_driver_service == NULL) {
        PanTiltJointPositionDriverService* ptpd_srv = static_cast<PanTiltJointPositionDriverService*>(cmp->get_service("PanTiltJointPositionDriver"));
        if (ptpd_srv != NULL) {
            p_position_driver_service = ptpd_srv->pPanTiltJointPositionDriver_ReceiveFSM;
        } else {
            RCLCPP_WARN_ONCE(logger, "no PanTiltJointPositionDriver found! Please include its plugin first (in the list), if you needs one!");
        }
    }
    return p_position_driver_service;
}

void PanTiltJointPositionSensor_ReceiveFSM::pPanTiltPoseStampedCallback(const geometry_msgs::msg::PoseStamped::SharedPtr msg)
{
    try {
        geometry_msgs::msg::PoseStamped pose_in = *msg;
        auto pose_out = geometry_msgs::msg::PoseStamped();
        if (p_tf_buffer != nullptr) {
            p_tf_buffer->lookupTransform(p_tf_frame_pantilt, pose_in.header.frame_id, pose_in.header.stamp, rclcpp::Duration::from_seconds(0.3));
            p_tf_buffer->transform(pose_in, pose_out, p_tf_frame_pantilt);
        } else {
            pose_out = pose_in;
        }
        double roll, pitch, yaw;
        tf2::Quaternion quat(pose_out.pose.orientation.x, pose_out.pose.orientation.y, pose_out.pose.orientation.z, pose_out.pose.orientation.w);
        tf2::Matrix3x3(quat).getRPY(roll, pitch, yaw);
        if (!isnan(yaw) && !isnan(pitch)) {
            RCLCPP_DEBUG(logger, "new pantilt position from ros pan: %.2f, tilt: %.2f", yaw, pitch);
            pUpdatePosition(yaw, pitch);
        }
    } catch (tf2::TransformException& ex) {
        printf("Failure %s\n", ex.what()); // Print exception which was caught
    }
}

};
