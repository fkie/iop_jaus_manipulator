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


#ifndef PANTILT_CFG_READER_H
#define PANTILT_CFG_READER_H

#include <string>
//#include <Eigen/Dense>
//#include <Eigen/Core>
#include <moveit_msgs/JointLimits.h>
#include <ros/ros.h>
#include <sensor_msgs/JointState.h>
#include "iop_manipulator_core_fkie/ReportPanTiltMotionProfile.h"
#include "iop_manipulator_core_fkie/ReportPanTiltSpecifications.h"

namespace iop_manipulator_core_fkie
{

typedef ReportPanTiltSpecifications::Body::ReportPanTiltSpecificationsRec ReportPanTiltSpecificationsRec;


class PantiltCfgReader
{
public:
  PantiltCfgReader();
  virtual ~PantiltCfgReader();
  /** Reads the parameter from ROS parameter server, parses there stored
   * robot_description and generates the JAUS specification for manipulator. */
  void readRosConfiguration();

  std::string get_joint1() { return p_joint1; }
  std::string get_joint2() { return p_joint2; }
  std::vector<std::string> getJointNames();

  /** Retruns the configuration of the manipulator. */
  ReportPanTiltSpecificationsRec getPantiltSpecification();

  void p_print_spec();

protected:
  std::map<std::string, float> p_joint_positions;
  ReportPanTiltSpecificationsRec p_pantilt_specification;
  std::string p_joint1;
  std::string p_joint2;
};

}
;

#endif // PANTILT_CFG_READER_H
