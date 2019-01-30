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


#include <math.h>
#include <ros/console.h>
#include <tf/transform_datatypes.h>
#include <fkie_iop_component/iop_config.h>
#include "fkie_iop_pantilt_specification_service/PantiltCfgReader.h"

using namespace urn_jaus_jss_manipulator_PanTiltSpecificationService;
using namespace iop;

PantiltCfgReader::PantiltCfgReader()
{
	p_valid_joint1_profile = false;
	p_valid_joint2_profile = false;
	p_joint1_limits.has_acceleration_limits = false;
	p_joint1_limits.has_position_limits = false;
	p_joint1_limits.has_velocity_limits = false;
	p_joint2_limits.has_acceleration_limits = false;
	p_joint2_limits.has_position_limits = false;
	p_joint2_limits.has_velocity_limits = false;
}
PantiltCfgReader::~PantiltCfgReader()
{
}

void PantiltCfgReader::readRosConfiguration()
{

	/**
	<!-- the position of the pantilt on the robot [x y z roll pitch yaw] -->
	<param name="origin" type="str" value="0 0 0 0 0 0" />
	<!-- the ROS name of the first joint and movement specifications [name (optional: minValue maxValue maxSpeed)] -->
	<param name="joint1" type="str" value="joint_name -3.14 3.14 1.57" />
	<!-- the ROS name of the second joint and movement specifications [name (optional: minValue maxValue maxSpeed)] -->
	<param name="joint2" type="str" value="joint_name -3.14 3.14 1.57" />
	**/
	ReportPanTiltSpecificationsRec pspec;
	iop::Config cfg("~PanTiltSpecificationService");
	std::string origin = "0 0 0 0 0 0";
	cfg.param("origin", origin, origin, true, false);
	double x, y, z, roll, pitch, yaw = 0;
	int scan_result = std::sscanf(origin.c_str(), "%lf %lf %lf %lf %lf %lf", &x, &y, &z, &roll, &pitch, &yaw);
	if (scan_result == 6) {
		pspec.setPanTiltCoordinateSysX(x);
		pspec.setPanTiltCoordinateSysY(y);
		pspec.setPanTiltCoordinateSysZ(z);
		tf::Quaternion q = tf::createQuaternionFromRPY(roll, pitch, yaw);
		pspec.setAComponentOfUnitQuaternionQ(q.x());
		pspec.setBComponentOfUnitQuaternionQ(q.y());
		pspec.setCComponentOfUnitQuaternionQ(q.z());
		pspec.setDComponentOfUnitQuaternionQ(q.w());
	} else {
		ROS_WARN("invalid format in ~origin[str]: %s, should be x y z roll pitch yaw", origin.c_str());
	}
	std::string joint1 = "pan_joint_name";
	cfg.param("joint1", joint1, joint1, true, false);
	char joint_name[256];
	double min_value = -3.14;
	double max_value = 3.14;
	double max_speed = 1.57;
	scan_result = std::sscanf(joint1.c_str(), "%s %lf %lf %lf", joint_name, &min_value, &max_value, &max_speed);
	if (scan_result == 4) {
		p_joint1 = std::string(joint_name);
		pspec.setJoint1MinValue(min_value);
		pspec.setJoint1MaxValue(max_value);
		pspec.setJoint1MaxSpeed(max_speed);
	} else if (scan_result == 1) {
		p_joint1 = std::string(joint_name);
	} else {
	  throw std::runtime_error(std::string("invalid format in ~joint1[str]. Should be joint_name min_value max_value max_speed, got: ") + joint1.c_str());
	}
	p_joint1_limits.joint_name = p_joint1;
	p_joint1_limits.has_position_limits = true;
	p_joint1_limits.max_position = max_value;
	p_joint1_limits.min_position = min_value;
	p_joint1_limits.has_velocity_limits = true;
	p_joint1_limits.max_velocity = max_speed;
	p_valid_joint1_profile = true;

	std::string joint2 = "tilt_joint_name";
	cfg.param("joint2", joint2, joint2, true, false);
	min_value = -3.14;
	max_value = 3.14;
	max_speed = 1.57;
	scan_result = std::sscanf(joint2.c_str(), "%s %lf %lf %lf", joint_name, &min_value, &max_value, &max_speed);
	if (scan_result == 4) {
		p_joint2 = std::string(joint_name);
		pspec.setJoint2MinValue(min_value);
		pspec.setJoint2MaxValue(max_value);
		pspec.setJoint2MaxSpeed(max_speed);
	} else if (scan_result == 1) {
		p_joint2 = std::string(joint_name);
	} else {
	  throw std::runtime_error(std::string("invalid format in ~joint2[str]. Should be joint_name min_value max_value max_speed, got: ") + joint2.c_str());
	}
	p_joint2_limits.joint_name = p_joint2;
	p_joint2_limits.has_position_limits = true;
	p_joint2_limits.max_position = max_value;
	p_joint2_limits.min_position = min_value;
	p_joint2_limits.has_velocity_limits = true;
	p_joint2_limits.max_velocity = max_speed;
	p_valid_joint2_profile = true;
	p_pantilt_specification = pspec;
	p_jaus_msg.getBody()->setReportPanTiltSpecificationsRec(pspec);
}

std::pair<std::string, std::string> PantiltCfgReader::getJointNames()
{
	return std::make_pair(p_joint1, p_joint2);
}

std::pair<moveit_msgs::JointLimits, moveit_msgs::JointLimits> PantiltCfgReader::getLimits()
{
	return std::make_pair(p_joint1_limits, p_joint2_limits);
}

bool PantiltCfgReader::is_profile_valid()
{
	return (p_valid_joint1_profile && p_valid_joint2_profile);
}

ReportPanTiltSpecifications& PantiltCfgReader::getJausMsg()
{
	return p_jaus_msg;
}

ReportPanTiltSpecifications::Body::ReportPanTiltSpecificationsRec PantiltCfgReader::getPantiltSpecification()
{
	return p_pantilt_specification;
}

void PantiltCfgReader::p_print_spec()
{
	ROS_INFO_NAMED("PantiltCfgReader", "Specification");
	ROS_INFO_NAMED("PantiltCfgReader", "  Coordinate system: %.3f, %.3f , %.3f",
				   p_pantilt_specification.getPanTiltCoordinateSysX(), p_pantilt_specification.getPanTiltCoordinateSysY(),
				   p_pantilt_specification.getPanTiltCoordinateSysZ());
	tf::Quaternion q(p_pantilt_specification.getAComponentOfUnitQuaternionQ(), p_pantilt_specification.getBComponentOfUnitQuaternionQ(),
					 p_pantilt_specification.getCComponentOfUnitQuaternionQ(), p_pantilt_specification.getDComponentOfUnitQuaternionQ());
	tf::Matrix3x3 m(q);
	double p_yaw, p_pitch, p_roll;
	m.getRPY(p_roll, p_pitch, p_yaw);
	ROS_INFO_NAMED("PantiltCfgReader", "  Orientation RPY: %.3f, %.3f , %.3f", p_roll, p_pitch, p_yaw);
	if (!p_joint1.empty()) {
		ROS_INFO_NAMED("PantiltCfgReader", "  FirstJoint:");
		ROS_INFO_NAMED("PantiltCfgReader", "    name: %s", p_joint1.c_str());
		ROS_INFO_NAMED("PantiltCfgReader", "    minValue: %.3f", p_pantilt_specification.getJoint1MinValue());
		ROS_INFO_NAMED("PantiltCfgReader", "    maxValue: %.3f", p_pantilt_specification.getJoint1MaxValue());
		ROS_INFO_NAMED("PantiltCfgReader", "    maxSpeed: %.3f", p_pantilt_specification.getJoint1MaxSpeed());
	}
	if (!p_joint2.empty()) {
		ROS_INFO_NAMED("PantiltCfgReader", "  SecondJoint:");
		ROS_INFO_NAMED("PantiltCfgReader", "    name: %s", p_joint2.c_str());
		ROS_INFO_NAMED("PantiltCfgReader", "    minValue: %.3f", p_pantilt_specification.getJoint2MinValue());
		ROS_INFO_NAMED("PantiltCfgReader", "    maxValue: %.3f", p_pantilt_specification.getJoint2MaxValue());
		ROS_INFO_NAMED("PantiltCfgReader", "    maxSpeed: %.3f", p_pantilt_specification.getJoint2MaxSpeed());
	}
}

