This package is part of [ROS/IOP Bridge](https://github.com/fkie/iop_core/blob/master/README.md).


## _iop_primitive_endeffector_fkie:_ PrimitiveEndEffector

Control an end effector by velocity commands. Currently we assume the effort is equal to the velocity. TODO: use max velocity to determine the velocity from effort.

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

