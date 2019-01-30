This package is part of [ROS/IOP Bridge](https://github.com/fkie/iop_core/blob/master/README.md).


## _fkie_iop_pantilt_joint_position_driver:_ PanTiltJointPositionDriver

Control the pantil by position commands. To control the pantilt by JointState the names from [PanTiltSpecificationService](../fkie_iop_pantilt_specification_service/README.md#fkie_iop_pantilt_specification_service-pantiltspecificationservice) are used.

#### Parameter:

> see [PanTiltSpecificationService](../fkie_iop_pantilt_specification_service/README.md#fkie_iop_pantilt_specification_service-pantiltspecificationservice)

_use_posestamped (bool_ Default: "false")

> Adds support for geometry_msgs::PoseStamped message.

_tf_frame_pantilt (str_ Default: "")

> only if ```use_posestamped``` is true. Sets the given frame_id in ROS message header before send to ROS.

#### Publisher:

_cmd_pos_joints (sensor_msgs::JointState)_

> Position commands for specified joints.

_cmd_pos_pan (std_msgs::Float64)_
_cmd_pos_pan32 (std_msgs::Float32)_

> Pan position.

_cmd_pos_tilt (std_msgs::Float64)_
_cmd_pos_tilt32 (std_msgs::Float32)_

> Tils position.

_cmd_pos_pantilt (geometry_msgs::PoseStamped)_

> only if ```use_posestamped``` is true.

#### Subscriber:

> None


## _fkie_iop_pantilt_joint_position_driver:_ PanTiltJointPositionSensor

Reads the pantitl position and reports them by ReportPanTiltJointPositions. To read the pantilt positions from JointState the names from [PanTiltSpecificationService](../fkie_iop_pantilt_specification_service/README.md#fkie_iop_pantilt_specification_service-pantiltspecificationservice) are used.

#### Parameter:

> see [PanTiltSpecificationService](../fkie_iop_pantilt_specification_service/README.md#fkie_iop_pantilt_specification_service-pantiltspecificationservice)

_use_posestamped (bool_ Default: "false")

> Adds support for geometry_msgs::PoseStamped message.

_tf_frame_pantilt (str_ Default: "")

> only if ```use_posestamped``` is true. Transfrom the resceived pose into given tf frame before send to IOP.

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

_pos_pantilt (geometry_msgs::PoseStamped)_

> only if ```use_posestamped``` is true.

