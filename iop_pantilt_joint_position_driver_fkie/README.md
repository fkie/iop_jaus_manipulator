This package is part of [ROS/IOP Bridge](https://github.com/fkie/iop_core/blob/master/README.md).


## _iop_pantilt_joint_position_driver_fkie:_ PanTiltJointPositionDriver

Control the pantil by position commands. To control the pantilt by JointState the names from [PanTiltSpecificationService](../iop_pantilt_specification_service_fkie/README.md#iop_pantilt_specification_service_fkie-pantiltspecificationservice) are used.

#### Parameter:

> see [PanTiltSpecificationService](../iop_pantilt_specification_service_fkie/README.md#iop_pantilt_specification_service_fkie-pantiltspecificationservice)

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

Reads the pantitl position and reports them by ReportPanTiltJointPositions. To read the pantilt positions from JointState the names from [PanTiltSpecificationService](../iop_pantilt_specification_service_fkie/README.md#iop_pantilt_specification_service_fkie-pantiltspecificationservice) are used.

#### Parameter:

> see [PanTiltSpecificationService](../iop_pantilt_specification_service_fkie/README.md#iop_pantilt_specification_service_fkie-pantiltspecificationservice)

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

