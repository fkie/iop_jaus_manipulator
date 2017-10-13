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

#include <math.h>
#include <ros/console.h>
#include <tf/transform_datatypes.h>
#include <iop_component_fkie/iop_config.h>
#include "iop_manipulator_specification_service_fkie/ManipulatorUrdfReader.h"

using namespace urn_jaus_jss_manipulator_ManipulatorSpecificationService;
using namespace iop;

ManipulatorUrdfReader::ManipulatorUrdfReader()
{
}
ManipulatorUrdfReader::~ManipulatorUrdfReader()
{
}

std::vector<std::string> ManipulatorUrdfReader::read_joint_names(std::string param_name)
{
	Config cfg("~ManipulatorSpecificationService");
	XmlRpc::XmlRpcValue v;
	cfg.param(param_name, v, v);
	p_joint_names.clear();
	for(int i = 0; i < v.size(); i++) {
		if (v[i].getType() == XmlRpc::XmlRpcValue::TypeString) {
			std::string joint_name = v[i];
			ROS_INFO_NAMED("ManipulatorSpecificationService", "	%s", joint_name.c_str());
			p_joint_names.push_back(joint_name);
		} else if (v[i].getType() == XmlRpc::XmlRpcValue::TypeStruct) {
			for(XmlRpc::XmlRpcValue::ValueStruct::iterator iterator = v[i].begin(); iterator != v[i].end(); iterator++) {
				std::string joint_name = iterator->first;
				std::string joint_type = iterator->second;
				ROS_INFO_NAMED("ManipulatorSpecificationService", "	%s: %s", joint_name.c_str(), joint_type.c_str());
				p_joint_names.push_back(joint_name);
			}
		}
	}
	return p_joint_names;
}

void ManipulatorUrdfReader::readRosConfiguration()
{
	ReportManipulatorSpecification mspec;
	Config cfg("~ManipulatorSpecificationService");
	std::string manipulator_base_link, manipulator_tip_link, robot_description;
	cfg.param("robot_description", robot_description, std::string("robot_description"));
	cfg.param("manipulator_base_link", manipulator_base_link, std::string("manipulator_base_link"));
	cfg.param("manipulator_tip_link", manipulator_tip_link, std::string("gripperTurn_link"));
	robot_model_loader::RobotModelLoader robot_model_loader(robot_description, false);
	robot_model::RobotModelPtr robot_model = robot_model_loader.getModel(); // can we use moveit::planning_interface::getSharedRobotModel() here?
	if (!robot_model)
		throw std::runtime_error("Could not load robot model.");

	const moveit::core::LinkModel* link = robot_model->getLinkModel(manipulator_tip_link);
	if (!link)
	{
		std::stringstream sstr;
		ROS_ERROR("'%s' not found in robot model.", manipulator_tip_link.c_str());
		throw std::runtime_error(sstr.str());
	}
	p_joint_names.clear();
//	p_joint_names.reserve();

	Eigen::Vector3d last_axis(0., 0., 0.);
	// get only joints on path from `manipulator_tip_link` to `manipulator_base_link`
	// create also the ReportManipulatorSpecification
	std::vector < JointSpecifications > iop_joints;
	std::vector < JointName > iop_joints_names;
	double zoffset = 0.;
	while (link && (link->getName() != manipulator_base_link))
	{
		// read the URDF configuration. Tested only with telemax URDF. The joints of this URDF are at the end of this file!
		const moveit::core::JointModel* joint = link->getParentJointModel();
		// we take only revolute or prismatic joints
		if (joint->getType() == moveit::core::JointModel::REVOLUTE
				or joint->getType() == moveit::core::JointModel::PRISMATIC)
		{
			Eigen::Vector3d axis = p_get_axis(joint);
			Eigen::Affine3d origin = link->getJointOriginTransform();
//			double oroll, opitch, oyaw;
//			p_get_euler_angles(origin, oroll, opitch, oyaw);
			const std::vector<moveit_msgs::JointLimits> &bounds = joint->getVariableBoundsMsg();
			double jointoffset = origin.translation()[0];
			double linklen = origin.translation()[1];
			if (axis.y() > 0)
			{
				// rotation is in Y axis, switch the link length and joint offset
				jointoffset = origin.translation()[1];
				linklen = origin.translation()[0];
			}
			// the Z axis adds the z axis value of preview joint
			if (axis.z() > 0)
				jointoffset += zoffset;
			zoffset = origin.translation()[2];
			// create new JAUS joint
			JointSpecifications joint_spec = JointSpecifications();
			if (joint->getType() == moveit::core::JointModel::REVOLUTE)
			{
				RevoluteJointSpecificationRec rjoint;
				p_set_limits(NULL, NULL, &rjoint, NULL, bounds);
				rjoint.setLinkLength(linklen);
				rjoint.setJointOffset(jointoffset);
				// the twist angle can be changed by next joint, see "update the twist angle of last joint"
				rjoint.setTwistAngle(0.);
				joint_spec.setRevoluteJointSpecificationRec(rjoint);
			}
			if (joint->getType() == moveit::core::JointModel::PRISMATIC)
			{
				PrismaticJointSpecificationRec pjoint;
				p_set_limits(NULL, NULL, NULL, &pjoint, bounds);
				pjoint.setLinkLength(linklen);
				// the twist angle can be changed by next joint, see "update the twist angle of last joint"
				pjoint.setTwistAngle(0.);
				double jointangle = 0.;
				if (iop_joints.size() > 0)
				{
					// set joint angle depending on axis of this and preview axis
					if (last_axis.x() > axis.x())
						jointangle = M_PI / 2.0;
					else
						jointangle = -M_PI / 2.0;
				}
				pjoint.setJointAngle(jointangle);
				if (iop_joints.size() > 0)
				{
					JointSpecifications& js_fist = iop_joints[0];
					if (js_fist.getFieldValue() == 0)
					{
						// add jointoffset to preview revolute joint
						jointoffset += js_fist.getRevoluteJointSpecificationRec()->getJointOffset();
						js_fist.getRevoluteJointSpecificationRec()->setJointOffset(jointoffset);
					}
				}
				joint_spec.setPrismaticJointSpecificationRec(pjoint);
				joint_spec.setFieldValue(1);
			}
			// update the twist angle of last joint
			if (iop_joints.size() > 0 and (last_axis.x() != axis.x() or last_axis.y() != axis.y()))
			{
			JointSpecifications& js_fist = iop_joints[0];
				if (js_fist.getFieldValue() == 0)
				{
					double twistangle = M_PI / 2.0;
					if (js_fist.getRevoluteJointSpecificationRec()->getJointOffset() > 0)
					{
						twistangle *= -1.0;
					}
					js_fist.getRevoluteJointSpecificationRec()->setTwistAngle(twistangle);
					if (joint->getType() == moveit::core::JointModel::PRISMATIC)
					{
						// add jointoffset to preview revolute joint
						jointoffset += js_fist.getRevoluteJointSpecificationRec()->getJointOffset();
						js_fist.getRevoluteJointSpecificationRec()->setJointOffset(jointoffset);
					}
				}
				else
				{
//					printf("prismatic joint\n");
					// what happens with prismatic joints?
				}
			}
			// add the joints in reverse order because we go in URDF from gripper to the base
			iop_joints.insert(iop_joints.begin(), joint_spec);
			JointName joint_name = JointName();
			joint_name.setDescription(joint->getName());
			iop_joints_names.insert(iop_joints_names.begin(), joint_name);
			last_axis = axis;
		}
		// store joint names
		p_joint_names.push_back(joint->getName());
		link = joint->getParentLinkModel();
	}

	// determinate the origin of the manipulator -> we assume it is the manipulator_base_link
	if (link && (link->getName() == manipulator_base_link))
	{
		const Eigen::Affine3d &aff = link->getJointOriginTransform();
		ROS_DEBUG_NAMED("ManipulatorUrdfReader", "ManipulatorCoordinateSystemPose: %f, %f , %f", aff.translation()[0],
										aff.translation()[1], aff.translation()[2]);
		Eigen::Quaterniond q = (Eigen::Quaterniond)aff.linear();
		ROS_DEBUG_NAMED("ManipulatorUrdfReader", "ManipulatorCoordinateSystemQuaternion: %f, %f , %f, %f", q.x(), q.y(),
										q.z(), q.w());
		// set the manipulator coordinate system
		ReportManipulatorSpecification::ManipulatorCoordinateSystemRec *mcsr = mspec.getManipulatorCoordinateSystemRec();
		mcsr->setAComponentOfUnitQuaternionQ(q.x());
		mcsr->setBComponentOfUnitQuaternionQ(q.y());
		mcsr->setCComponentOfUnitQuaternionQ(q.z());
		mcsr->setDComponentOfUnitQuaternionQ(q.w());
		mcsr->setManipulatorCoordinateSysX(aff.translation()[0]);
		mcsr->setManipulatorCoordinateSysY(aff.translation()[1]);
		mcsr->setManipulatorCoordinateSysZ(aff.translation()[2]);
	}

	// add the joints to the joint specification list
	for (unsigned int i = 0; i < iop_joints.size(); i++)
	{
		JointSpecifications& js = iop_joints[i];
		if (i == 0)
		{
			// create first joint from first joint
			ReportManipulatorSpecification::FirstJointParameters *fjp = mspec.getFirstJointParameters();
			if (js.getFieldValue() == 0)
			{
				RevoluteJoint1OffsetRec rjoint1;
				rjoint1.setJoint1Offset(js.getRevoluteJointSpecificationRec()->getJointOffset());
				if (js.getRevoluteJointSpecificationRec()->isMinValueValid())
					rjoint1.setJoint1MinValue(js.getRevoluteJointSpecificationRec()->getMinValue());
				if (js.getRevoluteJointSpecificationRec()->isMaxValueValid())
					rjoint1.setJoint1MaxValue(js.getRevoluteJointSpecificationRec()->getMaxValue());
				if (js.getRevoluteJointSpecificationRec()->isMaxSpeedValid())
					rjoint1.setJoint1MaxSpeed(js.getRevoluteJointSpecificationRec()->getMaxSpeed());
				if (js.getRevoluteJointSpecificationRec()->isMaxTorqueValid())
					rjoint1.setJoint1MaxTorque(js.getRevoluteJointSpecificationRec()->getMaxTorque());
				fjp->setRevoluteJoint1OffsetRec(rjoint1);
			}
			else
			{
				PrismaticJoint1AngleRec pjoint1;
				pjoint1.setJoint1Angle(js.getPrismaticJointSpecificationRec()->getJointAngle());
				pjoint1.setJoint1MinValue(js.getPrismaticJointSpecificationRec()->getMinValue());
				pjoint1.setJoint1MaxValue(js.getPrismaticJointSpecificationRec()->getMaxValue());
				if (js.getPrismaticJointSpecificationRec()->isMaxSpeedValid())
					pjoint1.setJoint1MaxSpeed(js.getPrismaticJointSpecificationRec()->getMaxSpeed());
				if (js.getPrismaticJointSpecificationRec()->isMaxForceValid())
					pjoint1.setJoint1MaxForce(js.getPrismaticJointSpecificationRec()->getMaxForce());
				fjp->setPrismaticJoint1AngleRec(pjoint1);
				fjp->setFieldValue(1);
			}
		}
		else
			mspec.getJointSpecificationList()->addElement(js);
		JointName& joint_name = iop_joints_names[i];
		mspec.getJointNamesList()->addElement(joint_name);
	}
	// print configuration
	std::reverse(p_joint_names.begin(), p_joint_names.end());
	ROS_DEBUG_NAMED("ManipulatorUrdfReader", "Got %lu joints:", p_joint_names.size());
	for (unsigned int index = 0; index < p_joint_names.size(); index++)
	{
		ROS_DEBUG_NAMED("ManipulatorUrdfReader", "	%d: %s", index, p_joint_names[index].c_str());
	}
	p_manipulator_specification = mspec;
	p_jaus_msg.getBody()->setReportManipulatorSpecification(mspec);
	p_print_spec();
}

std::vector<std::string> ManipulatorUrdfReader::getJointNames()
{
	return p_joint_names;
}

ReportManipulatorSpecifications& ManipulatorUrdfReader::getJausMsg()
{
	return p_jaus_msg;
}


ReportManipulatorSpecifications::Body::ReportManipulatorSpecification ManipulatorUrdfReader::getManipulatorSpecification()
{
	return p_manipulator_specification;
}

Eigen::Vector3d ManipulatorUrdfReader::p_get_axis(const moveit::core::JointModel* joint)
{
// create the first JAUS joint
	Eigen::Vector3d axis(0, 0, 0);
	if (joint->getType() == moveit::core::JointModel::REVOLUTE) {
		axis = static_cast<const robot_model::RevoluteJointModel *>(joint)->getAxis();
	}
	if (joint->getType() == moveit::core::JointModel::PRISMATIC) {
		axis = static_cast<const robot_model::PrismaticJointModel *>(joint)->getAxis();
	}
	return axis;
}

void ManipulatorUrdfReader::p_set_limits(RevoluteJoint1OffsetRec *rjoint1, PrismaticJoint1AngleRec *pjoint1,
		RevoluteJointSpecificationRec *rjoint, PrismaticJointSpecificationRec *pjoint,
		const std::vector<moveit_msgs::JointLimits> &bounds)
{
	if (bounds.size() > 0)
	{
		// set the joint limits
		if (bounds[0].has_position_limits)
		{
			if (rjoint1 != NULL)
			{
				printf("set position limits\n");
				rjoint1->setJoint1MaxValue(bounds[0].max_position);
				rjoint1->setJoint1MinValue(bounds[0].min_position);
			}
			if (pjoint1 != NULL)
			{
				pjoint1->setJoint1MaxValue(bounds[0].max_position);
				pjoint1->setJoint1MinValue(bounds[0].min_position);
			}
			if (rjoint != NULL)
			{
				rjoint->setMaxValue(bounds[0].max_position);
				rjoint->setMinValue(bounds[0].min_position);
			}
			if (pjoint != NULL)
			{
				pjoint->setMaxValue(bounds[0].max_position);
				pjoint->setMinValue(bounds[0].min_position);
			}
		}
		if (bounds[0].has_velocity_limits)
		{
			if (rjoint1 != NULL)
				rjoint1->setJoint1MaxSpeed(bounds[0].max_velocity);
			if (pjoint1 != NULL)
				pjoint1->setJoint1MaxSpeed(bounds[0].max_velocity);
			if (rjoint != NULL)
				rjoint->setMaxSpeed(bounds[0].max_velocity);
			if (pjoint != NULL)
				pjoint->setMaxSpeed(bounds[0].max_velocity);
		}
		if (bounds[0].has_acceleration_limits)
		{
//			if (rjoint1 != NULL)
//				rjoint1->setJoint1MaxTorque(bounds[0].max_acceleration);
		}
	}
}

void ManipulatorUrdfReader::p_get_euler_angles(Eigen::Affine3d &t, double &roll, double &pitch, double &yaw)
{
	roll = atan2(t(2, 1), t(2, 2));
	pitch = asin(-t(2, 0));
	yaw = atan2(t(1, 0), t(0, 0));
}

void ManipulatorUrdfReader::p_print_spec()
{
// print the configuration
	ROS_INFO_NAMED("ManipulatorUrdfReader", "Specification");
	ReportManipulatorSpecification::ManipulatorCoordinateSystemRec *mcsr = p_manipulator_specification.getManipulatorCoordinateSystemRec();
	ROS_INFO_NAMED("ManipulatorUrdfReader", "	Coordinate system: %.3f, %.3f , %.3f",
								 mcsr->getManipulatorCoordinateSysX(), mcsr->getManipulatorCoordinateSysY(),
								 mcsr->getManipulatorCoordinateSysZ());
	ReportManipulatorSpecification::FirstJointParameters *fjp = p_manipulator_specification.getFirstJointParameters();
	std::string joint_name;
	if (p_manipulator_specification.getJointNamesList()->getNumberOfElements() > 0) {
		joint_name = p_manipulator_specification.getJointNamesList()->getElement(0)->getDescription();
	}
	if (fjp->getFieldValue() == 0)
	{
		ROS_INFO_NAMED("ManipulatorUrdfReader", "	FirstJoint (%s): Revolute", joint_name.c_str());
		RevoluteJoint1OffsetRec * rjoint1 = fjp->getRevoluteJoint1OffsetRec();
		ROS_INFO_NAMED("ManipulatorUrdfReader", "		jointOffset: %.3f", rjoint1->getJoint1Offset());
		if (rjoint1->checkPresenceVector(0))
			ROS_INFO_NAMED("ManipulatorUrdfReader", "		minValue: %.3f", rjoint1->getJoint1MinValue());
		if (rjoint1->checkPresenceVector(1))
			ROS_INFO_NAMED("ManipulatorUrdfReader", "		maxValue: %.3f", rjoint1->getJoint1MaxValue());
		if (rjoint1->checkPresenceVector(2))
			ROS_INFO_NAMED("ManipulatorUrdfReader", "		maxSpeed: %.3f", rjoint1->getJoint1MaxSpeed());
		if (rjoint1->checkPresenceVector(3))
			ROS_INFO_NAMED("ManipulatorUrdfReader", "		maxTorque: %.3f", rjoint1->getJoint1MaxTorque());
	}
	else if (fjp->getFieldValue() == 1)
	{
		ROS_INFO_NAMED("ManipulatorUrdfReader", "	FirstJoint (%s): Prismatic", joint_name.c_str());
		PrismaticJoint1AngleRec * pjoint1 = fjp->getPrismaticJoint1AngleRec();
		ROS_INFO_NAMED("ManipulatorUrdfReader", "		jointAngle: %.3f", pjoint1->getJoint1Angle());
		if (pjoint1->checkPresenceVector(0))
			ROS_INFO_NAMED("ManipulatorUrdfReader", "		minValue: %.3f", pjoint1->getJoint1MinValue());
		if (pjoint1->checkPresenceVector(1))
			ROS_INFO_NAMED("ManipulatorUrdfReader", "		maxValue: %.3f", pjoint1->getJoint1MaxValue());
		if (pjoint1->checkPresenceVector(2))
			ROS_INFO_NAMED("ManipulatorUrdfReader", "		maxSpeed: %.3f", pjoint1->getJoint1MaxSpeed());
		if (pjoint1->checkPresenceVector(3))
			ROS_INFO_NAMED("ManipulatorUrdfReader", "		maxForce: %.3f", pjoint1->getJoint1MaxForce());
	}
	unsigned int joints_count = p_manipulator_specification.getJointSpecificationList()->getNumberOfElements();
	ROS_INFO_NAMED("ManipulatorUrdfReader", "	Count joints: %d", joints_count);
	for (unsigned int i = 0; i < joints_count; i++)
	{
		std::string joint_name;
		if (p_manipulator_specification.getJointNamesList()->getNumberOfElements() > i + 1) {
			joint_name = p_manipulator_specification.getJointNamesList()->getElement(i + 1)->getDescription();
		}
		JointSpecifications *jspec = p_manipulator_specification.getJointSpecificationList()->getElement(i);
		if (jspec->getFieldValue() == 0)
		{
			ROS_INFO_NAMED("ManipulatorUrdfReader", "	%d. %s: Revolute", i + 1, joint_name.c_str());
			RevoluteJointSpecificationRec * rjoint = jspec->getRevoluteJointSpecificationRec();
			ROS_INFO_NAMED("ManipulatorUrdfReader", "		linkLength: %.3f", rjoint->getLinkLength());
			ROS_INFO_NAMED("ManipulatorUrdfReader", "		twistAngle: %.3f", rjoint->getTwistAngle());
			ROS_INFO_NAMED("ManipulatorUrdfReader", "		jointOffset: %.3f", rjoint->getJointOffset());
			if (rjoint->isMinValueValid())
				ROS_INFO_NAMED("ManipulatorUrdfReader", "		minValue: %.3f", rjoint->getMinValue());
			if (rjoint->isMinValueValid())
				ROS_INFO_NAMED("ManipulatorUrdfReader", "		maxValue: %.3f", rjoint->getMaxValue());
			if (rjoint->isMaxSpeedValid())
				ROS_INFO_NAMED("ManipulatorUrdfReader", "		maxSpeed: %.3f", rjoint->getMaxSpeed());
			if (rjoint->isMaxTorqueValid())
				ROS_INFO_NAMED("ManipulatorUrdfReader", "		maxTorque: %.3f", rjoint->getMaxTorque());
		}
		else if (jspec->getFieldValue() == 1)
		{
			ROS_INFO_NAMED("ManipulatorUrdfReader", "	%d. %s: Prismatic", i + 1, joint_name.c_str());
			PrismaticJointSpecificationRec * pjoint = jspec->getPrismaticJointSpecificationRec();
			ROS_INFO_NAMED("ManipulatorUrdfReader", "		linkLength: %.3f", pjoint->getLinkLength());
			ROS_INFO_NAMED("ManipulatorUrdfReader", "		twistAngle: %.3f", pjoint->getTwistAngle());
			ROS_INFO_NAMED("ManipulatorUrdfReader", "		jointAngle: %.3f", pjoint->getJointAngle());
			ROS_INFO_NAMED("ManipulatorUrdfReader", "		minValue: %.3f", pjoint->getMinValue());
			ROS_INFO_NAMED("ManipulatorUrdfReader", "		maxValue: %.3f", pjoint->getMaxValue());
			if (pjoint->isMaxSpeedValid())
				ROS_INFO_NAMED("ManipulatorUrdfReader", "		maxSpeed: %.3f", pjoint->getMaxSpeed());
			if (pjoint->isMaxForceValid())
				ROS_INFO_NAMED("ManipulatorUrdfReader", "		maxForce: %.3f", pjoint->getMaxForce());
		}
	}
}

// Telemax Manipulator URDF joints:
//
//		<joint name="gripperTurn_joint" type="continuous">
//		<parent link="gripperTilt_link"/>
//		<child link="gripperTurn_link"/>
//		<origin rpy="0 0 0" xyz="0.109 0.0 0.0"/>
//		<axis xyz="1 0 0"/>
//		<limit effort="0.0174532925199" lower="-9999" upper="9999" velocity="1.3962634016"/>
//		</joint>
//
//		<joint name="gripperTilt_joint" type="revolute">
//		<parent link="lowerArmTurn_link"/>
//		<child link="gripperTilt_link"/>
//		<origin rpy="0 0 0" xyz="0.464 0.0 0.0"/>
//		<axis xyz="0 1 0"/>
//		<limit effort="0.0174532925199" lower="-2.26892802759" upper="2.26892802759" velocity="1.3962634016"/>
//		</joint>
//
//		<joint name="lowerArmTurn_joint" type="revolute">
//		<parent link="lowerArmTilt_link"/>
//		<child link="lowerArmTurn_link"/>
//		<origin rpy="0 0 0" xyz="0.1646 0.0 0.0"/>
//		<axis xyz="1 0 0"/>
//		<limit effort="0.0174532925199" lower="-3.66519142919" upper="3.66519142919" velocity="1.3962634016"/>
//		</joint>
//
//		<joint name="lowerArmTilt_joint" type="revolute">
//		<parent link="upperArm_link"/>
//		<child link="lowerArmTilt_link"/>
//		<origin rpy="0 0 0" xyz="0.532 0.081 0.0"/>
//		<axis xyz="0 1 0"/>
//		<limit effort="0.0174532925199" lower="-2.96705972839" upper="2.96705972839" velocity="0.628318530718"/>
//		</joint>
//
//		<joint name="telescope_joint" type="prismatic">
//		<parent link="shoulder_link"/>
//		<child link="upperArm_link"/>
//		<origin rpy="0 0 0" xyz="0.089 0.0 0.0"/>
//		<axis xyz="1 0 0"/>
//		<limit effort="1.0" lower="-0.0005" upper="0.2905" velocity="0.065"/>
//		</joint>
//
//		<joint name="upperArmTilt_joint" type="revolute">
//		<parent link="turret_link"/>
//		<child link="shoulder_link"/>
//		<origin rpy="0 0 0" xyz="0.06 -0.081 0.155"/>
//		<axis xyz="0 1 0"/>
//		<limit effort="0.0174532925199" lower="-2.72271363311" upper="1.0471975512" velocity="0.418879020479"/>
//		</joint>
//
//		<joint name="turretTurn_joint" type="revolute">
//		<parent link="manipulator_base_link"/>
//		<child link="turret_link"/>
//		<origin rpy="0 0 0" xyz="0 0 0"/>
//		<axis xyz="0 0 1"/>
//		<limit effort="0.0174532925199" lower="-3.66519142919" upper="3.66519142919" velocity="0.628318530718"/>
//		</joint>
