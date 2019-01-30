This package is part of [ROS/IOP Bridge](https://github.com/fkie/iop_core/blob/master/README.md).


## _fkie_iop_manipulator_specification_service:_ ManipulatorSpecificationService

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

