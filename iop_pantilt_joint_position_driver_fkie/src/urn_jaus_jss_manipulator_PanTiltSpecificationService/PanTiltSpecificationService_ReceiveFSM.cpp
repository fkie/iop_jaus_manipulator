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


#include "urn_jaus_jss_manipulator_PanTiltSpecificationService/PanTiltSpecificationService_ReceiveFSM.h"




using namespace JTS;

namespace urn_jaus_jss_manipulator_PanTiltSpecificationService
{



PanTiltSpecificationService_ReceiveFSM::PanTiltSpecificationService_ReceiveFSM(urn_jaus_jss_core_Transport::Transport_ReceiveFSM* pTransport_ReceiveFSM, urn_jaus_jss_core_Events::Events_ReceiveFSM* pEvents_ReceiveFSM)
{

	/*
	 * If there are other variables, context must be constructed last so that all
	 * class variables are available if an EntryAction of the InitialState of the
	 * statemachine needs them.
	 */
	context = new PanTiltSpecificationService_ReceiveFSMContext(*this);

	this->pTransport_ReceiveFSM = pTransport_ReceiveFSM;
	this->pEvents_ReceiveFSM = pEvents_ReceiveFSM;
}



PanTiltSpecificationService_ReceiveFSM::~PanTiltSpecificationService_ReceiveFSM()
{
	delete context;
}

void PanTiltSpecificationService_ReceiveFSM::setupNotifications()
{
	pEvents_ReceiveFSM->registerNotification("Receiving_Ready", ieHandler, "InternalStateChange_To_PanTiltSpecificationService_ReceiveFSM_Receiving_Ready", "Events_ReceiveFSM");
	pEvents_ReceiveFSM->registerNotification("Receiving", ieHandler, "InternalStateChange_To_PanTiltSpecificationService_ReceiveFSM_Receiving_Ready", "Events_ReceiveFSM");
	registerNotification("Receiving_Ready", pEvents_ReceiveFSM->getHandler(), "InternalStateChange_To_Events_ReceiveFSM_Receiving_Ready", "PanTiltSpecificationService_ReceiveFSM");
	registerNotification("Receiving", pEvents_ReceiveFSM->getHandler(), "InternalStateChange_To_Events_ReceiveFSM_Receiving", "PanTiltSpecificationService_ReceiveFSM");
	p_cfg_reader.readRosConfiguration();
	p_cfg_reader.p_print_spec();
}

void PanTiltSpecificationService_ReceiveFSM::sendReportPanTiltSpecificationsAction(QueryPanTiltSpecifications msg, Receive::Body::ReceiveRec transportData)
{
	uint16_t subsystem_id = transportData.getSrcSubsystemID();
	uint8_t node_id = transportData.getSrcNodeID();
	uint8_t component_id = transportData.getSrcComponentID();
	JausAddress sender(subsystem_id, node_id, component_id);
	ROS_DEBUG_NAMED("PanTiltSpecificationService", "ReportPanTiltSpecifications to %d.%d.%d", subsystem_id, node_id, component_id);
	ReportPanTiltSpecifications response;
	iop_manipulator_core_fkie::ReportPanTiltSpecificationsRec spec = p_cfg_reader.getPantiltSpecification();
	unsigned char bytes[spec.getSize()];
	spec.encode(bytes);
	response.getBody()->getReportPanTiltSpecificationsRec()->decode(bytes);
	sendJausMessage(response, sender);
}





};
