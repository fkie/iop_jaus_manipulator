This package is part of [ROS/IOP Bridge](https://github.com/fkie/iop_core/blob/master/README.md).


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

