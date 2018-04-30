This package is part of [ROS/IOP Bridge](https://github.com/fkie/iop_core/blob/master/README.md).


## _iop_primitive_manipulator_fkie:_ PrimitiveManipulator

Control a manipulator by velocity commands. The joint names are readed by [ManipulatorSpecificationService](../iop_manipulator_specification_service_fkie/README.md).
Currently we assume the effort is equal to the velocity. TODO: use max velocity to determine the velocity from effort.

#### Parameter:

> see [ManipulatorSpecificationService](../iop_manipulator_specification_service_fkie/README.md#iop_manipulator_specification_service_fkie-manipulatorspecificationservice)

#### Publisher:

_cmd_joint_velocities (sensor_msgs::JointState)_

> Velocity commands for specified joints.

_velocity_controller/command (std_msgs::Float64MultiArray)_

> Velocity commands as an array.

#### Subscriber:

_joint_states (sensor_msgs::JointState)_

> Translate joint velocities to ReportJointEffort.
