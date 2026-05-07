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

#ifndef PANTILTJOINTPOSITIONDRIVER_RECEIVEFSM_H
#define PANTILTJOINTPOSITIONDRIVER_RECEIVEFSM_H

#include "InternalEvents/InternalEventHandler.h"
#include "JTSStateMachine.h"
#include "JausUtils.h"
#include "Transport/JausTransport.h"
#include "urn_jaus_jss_manipulator_PanTiltJointPositionDriver/InternalEvents/InternalEventsSet.h"
#include "urn_jaus_jss_manipulator_PanTiltJointPositionDriver/Messages/MessageSet.h"
#include "urn_jaus_jss_manipulator_PanTiltMotionProfile/Messages/MessageSet.h"

#include "InternalEvents/Receive.h"
#include "InternalEvents/Send.h"

#include "urn_jaus_jss_core_AccessControl/AccessControl_ReceiveFSM.h"
#include "urn_jaus_jss_core_Events/Events_ReceiveFSM.h"
#include "urn_jaus_jss_core_Management/Management_ReceiveFSM.h"
#include "urn_jaus_jss_core_Transport/Transport_ReceiveFSM.h"

#include <fkie_iop_pantilt_specification_service/PanTiltMotionProfileListenerInterface.h>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <sensor_msgs/msg/joint_state.hpp>
#include <std_msgs/msg/float32.hpp>
#include <std_msgs/msg/float64.hpp>
#include <tf2/transform_datatypes.hpp>
#include <tf2_ros/transform_listener.hpp>

#include "PanTiltJointPositionDriver_ReceiveFSM_sm.h"
#include <fkie_iop_component/iop_component.hpp>
#include <rclcpp/rclcpp.hpp>

namespace urn_jaus_jss_manipulator_PanTiltJointPositionDriver {

class DllExport PanTiltJointPositionDriver_ReceiveFSM : public JTS::StateMachine {
public:
    PanTiltJointPositionDriver_ReceiveFSM(std::shared_ptr<iop::Component> cmp, urn_jaus_jss_core_Management::Management_ReceiveFSM* pManagement_ReceiveFSM, urn_jaus_jss_core_AccessControl::AccessControl_ReceiveFSM* pAccessControl_ReceiveFSM, urn_jaus_jss_core_Events::Events_ReceiveFSM* pEvents_ReceiveFSM, urn_jaus_jss_core_Transport::Transport_ReceiveFSM* pTransport_ReceiveFSM);
    virtual ~PanTiltJointPositionDriver_ReceiveFSM();
    /// Handle notifications on parent state changes
    virtual void setupNotifications();
    virtual void setupIopConfiguration();

    /// Action Methods
    virtual void sendReportCommandedPanTiltJointPositionsAction(QueryCommandedPanTiltJointPositions msg, Receive::Body::ReceiveRec transportData);
    virtual void setPanTiltJointEffortsAction(SetPanTiltJointPositions msg);
    virtual void stopMotionAction();

    /// Guard Methods
    virtual bool isControllingClient(Receive::Body::ReceiveRec transportData);
    virtual bool panTiltMotionProfileExists();

    PanTiltJointPositionDriver_ReceiveFSMContext* context;

    virtual void motion_profile_received(JausAddress reporter, urn_jaus_jss_manipulator_PanTiltMotionProfile::ReportPanTiltMotionProfile profile);
    void set_current_position(double pan_position, double tilt_position);

protected:
    /// References to parent FSMs
    urn_jaus_jss_core_Management::Management_ReceiveFSM* pManagement_ReceiveFSM;
    urn_jaus_jss_core_AccessControl::AccessControl_ReceiveFSM* pAccessControl_ReceiveFSM;
    urn_jaus_jss_core_Events::Events_ReceiveFSM* pEvents_ReceiveFSM;
    urn_jaus_jss_core_Transport::Transport_ReceiveFSM* pTransport_ReceiveFSM;

    std::shared_ptr<iop::Component> cmp;
    rclcpp::Logger logger;

    std::recursive_mutex p_mutex;
    std::string p_joint1_name;
    std::string p_joint2_name;
    double p_joint1_cmd_position;
    double p_joint2_cmd_position;
    double p_joint1_position;
    double p_joint2_position;
    rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr p_pub_cmd_pos_joints;
    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr p_pub_cmd_pos_pan;
    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr p_pub_cmd_pos_tilt;
    rclcpp::Publisher<std_msgs::msg::Float32>::SharedPtr p_pub_cmd_pos_pan32;
    rclcpp::Publisher<std_msgs::msg::Float32>::SharedPtr p_pub_cmd_pos_tilt32;
    rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr p_pub_pos_stamped;
    bool p_use_posestamped;
    std::string p_tf_frame_pantilt;
};

};

#endif // PANTILTJOINTPOSITIONDRIVER_RECEIVEFSM_H
