This package is part of [ROS/IOP Bridge](https://github.com/fkie/iop_core/blob/master/README.md).


## _iop_primitive_pantilt_fkie:_ PrimitivePanTilt

Control the pantil by velocity commands. To control the pantilt by JointState the names from [PanTiltSpecificationService](../iop_pantilt_specification_service_fkie/README.md#iop_pantilt_specification_service_fkie-pantiltspecificationservice) are used. Since by IOP the command uses effort values, the velocity published to ROS is percentage of _max_velocity_ specified in limits.

#### Parameter:

> see [PanTiltSpecificationService](../iop_pantilt_specification_service_fkie/README.md#iop_pantilt_specification_service_fkie-pantiltspecificationservice)

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
