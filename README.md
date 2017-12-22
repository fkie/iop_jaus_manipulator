See [iop_core](https://github.com/fkie/iop_core/blob/master/README.md) for use instructions.

This code is currently highly experimental!

# Interfaces

List of service plugins in this repository:

[iop_manipulator_joint_position_sensor_fkie: ManipulatorJointPositionSensor](#iop_manipulator_joint_position_sensor_fkie-manipulatorjointpositionsensor)  
[iop_manipulator_specification_service_fkie: ManipulatorSpecificationService](#iop_manipulator_specification_service_fkie-manipulatorspecificationservice)  
[iop_pantilt_joint_position_driver_fkie: PanTiltJointPositionDriver](#iop_pantilt_joint_position_driver_fkie-pantiltjointpositiondriver)  
[iop_pantilt_joint_position_driver_fkie: PanTiltJointPositionSensor](#iop_pantilt_joint_position_driver_fkie-pantiltjointpositionSensor)  

[iop_pantilt_specification_service_fkie: PanTiltMotionProfileService](#iop_pantilt_specification_service_fkie-pantiltmotionprofileservice)  
[iop_pantilt_specification_service_fkie: PanTiltSpecificationService](#iop_pantilt_specification_service_fkie-pantiltspecificationservice)  
[iop_primitive_endeffector_fkie: PrimitiveEndEffector](#iop_primitive_endeffector_fkie-primitiveendeffector)  
[iop_primitive_manipulator_fkie: PrimitiveManipulator](#iop_primitive_manipulator_fkie-primitivemanipulator)  
[iop_primitive_pantilt_fkie: PrimitivePanTilt](#iop_primitive_pantilt_fkie-primitivepantilt)  


## _iop_manipulator_joint_position_sensor_fkie:_ ManipulatorJointPositionSensor

Sensor for reporting the positions of the manipulator joints. The joint names are readed by [ManipulatorSpecificationService](#iop_manipulator_specification_service_fkie-manipulatorspecificationservice).

#### Parameter:

> None

#### Publisher:

> None

#### Subscriber:

_joint_states (sensor_msgs::JointState)_

> Translate the manipulator joint positions to ReportJointPositions.


## _iop_manipulator_specification_service_fkie:_ ManipulatorSpecificationService

Read and hold the manipouplator configuration. This service is also used by ```ManipulatorJointPositionSensor``` and ```PrimitiveManipulator```.

#### Parameter:

_robot_description (str_, Default: "robot_description")

> Urdf with manipulator description.

_manipulator_base_link (str_, Default: "manipulator_base_link")

> The name of the start joint of the manipulator. The urdf must contain this link.

_manipulator_tip_link (str_, Default: "manipulator_tip_link")

> The name of the last joint of the manipulator. The endeffector has it's own service!

#### Publisher:

> None

#### Subscriber:

> None


## _iop_pantilt_joint_position_driver_fkie:_ PanTiltJointPositionDriver

Control the pantil by position commands. To control the pantilt by JointState the names from [PanTiltSpecificationService](#iop_pantilt_specification_service_fkie-pantiltspecificationservice) are used.

#### Parameter:

> see [PanTiltSpecificationService](#iop_pantilt_specification_service_fkie-pantiltspecificationservice)

#### Publisher:

_cmd_pos_joints (sensor_msgs::JointState)_

> Position commands for specified joints.

_cmd_pos_pan (std_msgs::Float64)_
_cmd_pos_pan32 (std_msgs::Float32)_

> Pan position.

_cmd_pos_tilt (std_msgs::Float64)_
_cmd_pos_tilt32 (std_msgs::Float32)_

> Tils position.

#### Subscriber:

> None


## _iop_pantilt_joint_position_driver_fkie:_ PanTiltJointPositionSensor

Reads the pantitl position and reports them by ReportPanTiltJointPositions. To read the pantilt positions from JointState the names from [PanTiltSpecificationService](#iop_pantilt_specification_service_fkie-pantiltspecificationservice) are used.

#### Parameter:

> see [PanTiltSpecificationService](#iop_pantilt_specification_service_fkie-pantiltspecificationservice)

#### Publisher:

> None

#### Subscriber:

_pos_joints (sensor_msgs::JointState)_

> Position for specified joints.

_pos_pan (std_msgs::Float64)_
_pos_pan32 (std_msgs::Float32)_

> Pan position.

_pos_tilt (std_msgs::Float64)_
_pos_tilt32 (std_msgs::Float32)_

> Tils position.


## _iop_pantilt_specification_service_fkie:_ PanTiltMotionProfileService

Holds the motion profile for pantilt. The most limits are read from [PanTiltSpecificationService](#iop_pantilt_specification_service_fkie-pantiltspecificationservice). The own parameter overwrites thes from specification service. The motion profile can also be changed by controller.

#### Parameter:

> see [PanTiltSpecificationService](#iop_pantilt_specification_service_fkie-pantiltspecificationservice)

_joint1_max_speed (double_, Default: 1.5)

> Maximal speed of first joint.

_joint1_max_accel (double_, Default: 1.5)

> Maximal acceleration of first joint.

_joint1_max_decel (double_, Default: 1.5)

> Maximal deceleration of first joint.

_joint2_max_speed (double_, Default: 1.5)

> Maximal speed of second joint.

_joint2_max_accel (double_, Default: 1.5)

> Maximal acceleration of second joint.

_joint2_max_decel (double_, Default: 1.5)

> Maximal deceleration of second joint.

#### Publisher:

_joint1_limits (moveit_msgs::JointLimits)_

> Publishes the limits for first joint.

_joint2_limits (moveit_msgs::JointLimits)_

> Publishes the limits for second joint.

#### Subscriber:

> None


## _iop_pantilt_specification_service_fkie:_ PanTiltSpecificationService

Holds the configuration for pantilt. This configuration is used by other pantilt services.

#### Parameter:

_origin (str_, Default: "0 0 0 0 0 0")

> The position of the pantilt on the robot [x y z roll pitch yaw]

_joint1 (double_, Default: 1.5)

> Maximal acceleration of first joint.

_joint1_max_decel (double_, Default: 1.5)

> Maximal deceleration of first joint.

_joint2_max_speed (double_, Default: 1.5)

> Maximal speed of second joint.

_joint2_max_accel (double_, Default: 1.5)

> Maximal acceleration of second joint.

_joint2_max_decel (double_, Default: 1.5)

> Maximal deceleration of second joint.

#### Publisher:

_joint1_limits (moveit_msgs::JointLimits)_

> Publishes the limits for first joint.

_joint2_limits (moveit_msgs::JointLimits)_

> Publishes the limits for second joint.

#### Subscriber:

> None


## _iop_primitive_endeffector_fkie:_ PrimitiveEndEffector

Control an end effector by velocity commands.

#### Parameter:

_gripper_joint (str_, Default: "gripperWidth_joint")

> The joint name of the gripper.

_manipulator_id (str_, Default: "")

> The JausAddress of the manipulator service. This is used only to report it to the controller in specification report.

#### Publisher:

_cmd_joint_velocities (sensor_msgs::JointState)_

> Velocity command for specified gripper joint.

_gripper_velocity_controller/command (std_msgs::Float64)_

> Velocity command.

#### Subscriber:

_joint_states (sensor_msgs::JointState)_

> Translate joint velocity of the gripper to ReportEndEffectorEffort.


## _iop_primitive_manipulator_fkie:_ PrimitiveManipulator

Control a manipulator by velocity commands. The joint names are readed by [ManipulatorSpecificationService](#iop_manipulator_specification_service_fkie-manipulatorspecificationservice).

#### Parameter:

> see [ManipulatorSpecificationService](#iop_manipulator_specification_service_fkie-manipulatorspecificationservice)

#### Publisher:

_cmd_joint_velocities (sensor_msgs::JointState)_

> Velocity commands for specified joints.

_velocity_controller/command (std_msgs::Float64MultiArray)_

> Velocity commands as an array.

#### Subscriber:

_joint_states (sensor_msgs::JointState)_

> Translate joint velocities to ReportJointEffort.


## _iop_primitive_pantilt_fkie:_ PrimitivePanTilt

Control the pantil by velocity commands. To control the pantilt by JointState the names from [PanTiltSpecificationService](#iop_pantilt_specification_service_fkie-pantiltspecificationservice) are used. Since by IOP the command uses effort values, the velocity published to ROS is percentage of _max_velocity_ specified in limits.

#### Parameter:

> see [PanTiltSpecificationService](#iop_pantilt_specification_service_fkie-pantiltspecificationservice)

#### Publisher:

_cmd_vel_joints (sensor_msgs::JointState)_

> Velocity commands for specified joints.

_cmd_vel_pan (std_msgs::Float64)_
_cmd_vel_pan32 (std_msgs::Float32)_

> Pan velocity.

_cmd_vel_tilt (std_msgs::Float64)_
_cmd_vel_tilt32 (std_msgs::Float32)_

> Tils velocity.

#### Subscriber:

_joint_states (sensor_msgs::JointState)_

> Translate joint velocities to ReportJointEffort.
