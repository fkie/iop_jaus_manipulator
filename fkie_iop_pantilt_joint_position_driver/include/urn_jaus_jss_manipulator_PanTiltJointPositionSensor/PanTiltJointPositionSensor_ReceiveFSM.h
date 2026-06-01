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

#ifndef PANTILTJOINTPOSITIONSENSOR_RECEIVEFSM_H
#define PANTILTJOINTPOSITIONSENSOR_RECEIVEFSM_H

#include "InternalEvents/InternalEventHandler.h"
#include "JTSStateMachine.h"
#include "JausUtils.h"
#include "Transport/JausTransport.h"
#include "urn_jaus_jss_manipulator_PanTiltJointPositionSensor/InternalEvents/InternalEventsSet.h"
#include "urn_jaus_jss_manipulator_PanTiltJointPositionSensor/Messages/MessageSet.h"

#include "InternalEvents/Receive.h"
#include "InternalEvents/Send.h"

#include "urn_jaus_jss_core_Events/Events_ReceiveFSM.h"
#include "urn_jaus_jss_core_Transport/Transport_ReceiveFSM.h"

#include <geometry_msgs/msg/pose_stamped.h>
#include <sensor_msgs/msg/joint_state.h>
#include <std_msgs/msg/float32.h>
#include <std_msgs/msg/float64.h>
#include <tf2/transform_datatypes.hpp>
#include <tf2_ros/buffer.hpp>
#include <tf2_ros/transform_listener.hpp>

#include "PanTiltJointPositionSensor_ReceiveFSM_sm.h"
#include <fkie_iop_component/iop_component.hpp>
#include <rclcpp/rclcpp.hpp>
#include <urn_jaus_jss_manipulator_PanTiltJointPositionDriver/PanTiltJointPositionDriverService.h>

namespace urn_jaus_jss_manipulator_PanTiltJointPositionSensor {

class DllExport PanTiltJointPositionSensor_ReceiveFSM : public JTS::StateMachine {
public:
    PanTiltJointPositionSensor_ReceiveFSM(std::shared_ptr<iop::Component> cmp, urn_jaus_jss_core_Events::Events_ReceiveFSM* pEvents_ReceiveFSM, urn_jaus_jss_core_Transport::Transport_ReceiveFSM* pTransport_ReceiveFSM);
    virtual ~PanTiltJointPositionSensor_ReceiveFSM();
    /// Handle notifications on parent state changes
    virtual void setupNotifications();
    virtual void setupIopConfiguration();

    /// Action Methods
    virtual void sendReportPanTiltJointPositionsAction(QueryPanTiltJointPositions msg, Receive::Body::ReceiveRec transportData);

    /// Guard Methods

    PanTiltJointPositionSensor_ReceiveFSMContext* context;

protected:
    /// References to parent FSMs
    urn_jaus_jss_core_Events::Events_ReceiveFSM* pEvents_ReceiveFSM;
    urn_jaus_jss_core_Transport::Transport_ReceiveFSM* pTransport_ReceiveFSM;

    std::shared_ptr<iop::Component> cmp;
    rclcpp::Logger logger;

    std::recursive_mutex p_mutex;
    urn_jaus_jss_manipulator_PanTiltJointPositionDriver::PanTiltJointPositionDriver_ReceiveFSM* p_position_driver_service;
    ReportPanTiltJointPositions p_report_pantilt;
    std::string p_joint1_name;
    std::string p_joint2_name;
    double p_joint1_position;
    double p_joint2_position;
    rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr p_sub_pos_joints;
    rclcpp::Subscription<std_msgs::msg::Float64>::SharedPtr p_sub_pos_pan;
    rclcpp::Subscription<std_msgs::msg::Float64>::SharedPtr p_sub_pos_tilt;
    rclcpp::Subscription<std_msgs::msg::Float32>::SharedPtr p_sub_pos_pan32;
    rclcpp::Subscription<std_msgs::msg::Float32>::SharedPtr p_sub_pos_tilt32;
    rclcpp::Subscription<geometry_msgs::msg::PoseStamped>::SharedPtr p_sub_pos_stamped;
    bool p_use_posestamped;
    std::string p_tf_frame_pantilt;
    std::unique_ptr<tf2_ros::Buffer> p_tf_buffer;
    std::shared_ptr<tf2_ros::TransformListener> p_tf_listener;

    void pUpdatePosition(double pan, double tilt);
    void pJoinStateCallback(const sensor_msgs::msg::JointState::SharedPtr joint_state);
    void pPanFloatCallback(const std_msgs::msg::Float64::SharedPtr msg);
    void pTiltFloatCallback(const std_msgs::msg::Float64::SharedPtr msg);
    void pPanFloat32Callback(const std_msgs::msg::Float32::SharedPtr msg);
    void pTiltFloat32Callback(const std_msgs::msg::Float32::SharedPtr msg);
    urn_jaus_jss_manipulator_PanTiltJointPositionDriver::PanTiltJointPositionDriver_ReceiveFSM* pGetPostionDriver();
    void pPanTiltPoseStampedCallback(const geometry_msgs::msg::PoseStamped::SharedPtr msg);
};

};

#endif // PANTILTJOINTPOSITIONSENSOR_RECEIVEFSM_H
