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


#ifndef MANIPULATORJOINTPOSITIONSENSORPLUGIN_H
#define MANIPULATORJOINTPOSITIONSENSORPLUGIN_H

#include "urn_jaus_jss_manipulator_ManipulatorJointPositionSensor/ManipulatorJointPositionSensorService.h"
#include "urn_jaus_jss_core_Events/EventsService.h"
#include "urn_jaus_jss_core_Transport/TransportService.h"

#include <fkie_iop_component/iop_plugin_interface.h>

namespace iop
{

class DllExport ManipulatorJointPositionSensorPlugin : public PluginInterface
{
public:
	ManipulatorJointPositionSensorPlugin();

	JTS::Service* get_service();
	void create_service(JTS::JausRouter* jaus_router);

protected:
	urn_jaus_jss_manipulator_ManipulatorJointPositionSensor::ManipulatorJointPositionSensorService *p_my_service;
	urn_jaus_jss_core_Events::EventsService *p_base_service;
	urn_jaus_jss_core_Transport::TransportService *p_transport_service;

};

};

#endif
