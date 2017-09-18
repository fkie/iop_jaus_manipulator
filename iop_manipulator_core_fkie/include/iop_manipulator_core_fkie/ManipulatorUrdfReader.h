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


#ifndef MANIPULATOR_URDF_READER_H
#define MANIPULATOR_URDF_READER_H

#include <string>
//#include <Eigen/Dense>
#include <Eigen/Core>
#include <moveit/robot_model_loader/robot_model_loader.h>
#include <moveit_msgs/JointLimits.h>
#include <ros/ros.h>
#include <sensor_msgs/JointState.h>
#include "iop_manipulator_core_fkie/ReportManipulatorSpecifications.h"

namespace iop_manipulator_core_fkie
{
typedef ReportManipulatorSpecifications::Body::ReportManipulatorSpecification ReportManipulatorSpecification;
typedef ReportManipulatorSpecification::FirstJointParameters::RevoluteJoint1OffsetRec RevoluteJoint1OffsetRec;
typedef ReportManipulatorSpecification::FirstJointParameters::PrismaticJoint1AngleRec PrismaticJoint1AngleRec;
typedef ReportManipulatorSpecification::JointSpecificationList JointSpecificationList;
typedef JointSpecificationList::JointSpecifications JointSpecifications;
typedef JointSpecifications::RevoluteJointSpecificationRec RevoluteJointSpecificationRec;
typedef JointSpecifications::PrismaticJointSpecificationRec PrismaticJointSpecificationRec;

class ManipulatorUrdfReader
{
public:
  ManipulatorUrdfReader();
  virtual ~ManipulatorUrdfReader();
  /** Reads the parameter from ROS parameter server, parses there stored
   * robot_description and generates the JAUS specification for manipulator. */
  void readRosConfiguration();
  /** Reads the parameter from ROS parameter server, parses there stored
    * list for joint names and return these. The result is also stored in this reader and
    * can be accessed by getJointNames() */
  std::vector<std::string> read_joint_names(std::string param_name="joint_names");
  /** Returns the vector with joint names. The end effector is not included. */
  std::vector<std::string> getJointNames();

  /** Retruns the configuration of the manipulator. */
  ReportManipulatorSpecification getManipulatorSpecification();

protected:
  std::vector<std::string> p_joint_names;
  std::map<std::string, float> p_joint_positions;
  ReportManipulatorSpecification p_manipulator_specification;
  /** return the axis by joint
   * -1 := undefined
   * 0 := no Axis
   * 1 := x Axis
   * 2 := y Axis
   * 3 := x+y Axis
   * 4 := z Axis
   * 5 := x+z Axis
   * 6 := y+z Axis
   * 7 := x+y+z Axis*/
  Eigen::Vector3d p_get_axis(const moveit::core::JointModel* joint);

  void p_set_limits(RevoluteJoint1OffsetRec *rjoint1, PrismaticJoint1AngleRec *pjoint1,
                    RevoluteJointSpecificationRec *rjoint, PrismaticJointSpecificationRec *pjoint,
                    const std::vector<moveit_msgs::JointLimits> &bounds);
  void p_get_euler_angles(Eigen::Affine3d &t, double &roll, double &pitch, double &yaw);
  void p_print_spec();
};

}
;

#endif // MANIPULATOR_URDF_READER_H
