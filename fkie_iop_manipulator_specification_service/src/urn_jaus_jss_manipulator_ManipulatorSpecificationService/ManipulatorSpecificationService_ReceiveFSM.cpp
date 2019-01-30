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



#include "urn_jaus_jss_manipulator_ManipulatorSpecificationService/ManipulatorSpecificationService_ReceiveFSM.h"




using namespace JTS;

namespace urn_jaus_jss_manipulator_ManipulatorSpecificationService
{



ManipulatorSpecificationService_ReceiveFSM::ManipulatorSpecificationService_ReceiveFSM(urn_jaus_jss_core_Transport::Transport_ReceiveFSM* pTransport_ReceiveFSM, urn_jaus_jss_core_Events::Events_ReceiveFSM* pEvents_ReceiveFSM)
{

	/*
	 * If there are other variables, context must be constructed last so that all
	 * class variables are available if an EntryAction of the InitialState of the
	 * statemachine needs them.
	 */
	context = new ManipulatorSpecificationService_ReceiveFSMContext(*this);

	this->pTransport_ReceiveFSM = pTransport_ReceiveFSM;
	this->pEvents_ReceiveFSM = pEvents_ReceiveFSM;
}



ManipulatorSpecificationService_ReceiveFSM::~ManipulatorSpecificationService_ReceiveFSM()
{
	delete context;
}

void ManipulatorSpecificationService_ReceiveFSM::setupNotifications()
{
	pEvents_ReceiveFSM->registerNotification("Receiving_Ready", ieHandler, "InternalStateChange_To_ManipulatorSpecificationService_ReceiveFSM_Receiving_Ready", "Events_ReceiveFSM");
	pEvents_ReceiveFSM->registerNotification("Receiving", ieHandler, "InternalStateChange_To_ManipulatorSpecificationService_ReceiveFSM_Receiving_Ready", "Events_ReceiveFSM");
	registerNotification("Receiving_Ready", pEvents_ReceiveFSM->getHandler(), "InternalStateChange_To_Events_ReceiveFSM_Receiving_Ready", "ManipulatorSpecificationService_ReceiveFSM");
	registerNotification("Receiving", pEvents_ReceiveFSM->getHandler(), "InternalStateChange_To_Events_ReceiveFSM_Receiving", "ManipulatorSpecificationService_ReceiveFSM");
	p_urdf_reader.readRosConfiguration();
}

void ManipulatorSpecificationService_ReceiveFSM::sendReportManipulatorSpecificationsAction(QueryManipulatorSpecifications msg, Receive::Body::ReceiveRec transportData)
{
	JausAddress sender = transportData.getAddress();
	ROS_DEBUG_NAMED("ManipulatorSpecificationService", "sendReportManipulatorSpecificationsAction to %s", sender.str().c_str());
//	ReportManipulatorSpecifications response;
//	iop_manipulator_core_fkie::ReportManipulatorSpecification spec = p_urdf_reader.getManipulatorSpecification();
//	unsigned char bytes[spec.getSize()];
//	spec.encode(bytes);
//	response.getBody()->getReportManipulatorSpecification()->decode(bytes);
	// we have set Y axes back to -30 to pass the CVT test, bug in CVT or JTS?
	//  response.getBody()->getReportManipulatorSpecification()->getManipulatorCoordinateSystemRec()->setManipulatorCoordinateSysY(-30);
//	ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::ManipulatorCoordinateSystemRec *mcsr = response.getBody()->getReportManipulatorSpecification()->getManipulatorCoordinateSystemRec();
	sendJausMessage(p_urdf_reader.getJausMsg(), sender);
}

std::vector<std::string> ManipulatorSpecificationService_ReceiveFSM::getJointNames()
{
	return p_urdf_reader.getJointNames();
}




};

