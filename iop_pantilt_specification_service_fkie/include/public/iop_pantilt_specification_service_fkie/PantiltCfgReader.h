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
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; or you can read the full license at
<http://www.gnu.de/documents/gpl-2.0.html>
*/

/** \author Alexander Tiderko */


#ifndef PANTILT_CFG_READER_H
#define PANTILT_CFG_READER_H

#include <string>
#include <moveit_msgs/JointLimits.h>
#include <ros/ros.h>
#include <sensor_msgs/JointState.h>
#include "urn_jaus_jss_manipulator_PanTiltSpecificationService/Messages/MessageSet.h"


typedef urn_jaus_jss_manipulator_PanTiltSpecificationService::ReportPanTiltSpecifications::Body::ReportPanTiltSpecificationsRec ReportPanTiltSpecificationsRec;

namespace iop
{

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
		std::pair<std::string, std::string> getJointNames();
		std::pair<moveit_msgs::JointLimits, moveit_msgs::JointLimits> getLimits();
		bool is_profile_valid();

		/** Retruns the configuration of the manipulator. */
		urn_jaus_jss_manipulator_PanTiltSpecificationService::ReportPanTiltSpecifications& getJausMsg();
		ReportPanTiltSpecificationsRec getPantiltSpecification();

		void p_print_spec();

	protected:
		std::map<std::string, float> p_joint_positions;
		urn_jaus_jss_manipulator_PanTiltSpecificationService::ReportPanTiltSpecifications p_jaus_msg;
		ReportPanTiltSpecificationsRec p_pantilt_specification;
		std::string p_joint1;
		std::string p_joint2;
		moveit_msgs::JointLimits p_joint1_limits;
		moveit_msgs::JointLimits p_joint2_limits;
		bool p_valid_joint1_profile;
		bool p_valid_joint2_profile;
	};

}
;

#endif // PANTILT_CFG_READER_H
