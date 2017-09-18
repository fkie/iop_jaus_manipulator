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


#ifndef PANTILTSPECIFICATIONSERVICE_RECEIVEFSM_H
#define PANTILTSPECIFICATIONSERVICE_RECEIVEFSM_H

#include "JausUtils.h"
#include "InternalEvents/InternalEventHandler.h"
#include "Transport/JausTransport.h"
#include "JTSStateMachine.h"
#include "urn_jaus_jss_manipulator_PanTiltSpecificationService/Messages/MessageSet.h"
#include "urn_jaus_jss_manipulator_PanTiltSpecificationService/InternalEvents/InternalEventsSet.h"

#include "InternalEvents/Receive.h"
#include "InternalEvents/Send.h"

#include "urn_jaus_jss_core_Transport/Transport_ReceiveFSM.h"
#include "urn_jaus_jss_core_Events/Events_ReceiveFSM.h"

#include "iop_manipulator_core_fkie/PantiltCfgReader.h"

#include "PanTiltSpecificationService_ReceiveFSM_sm.h"

namespace urn_jaus_jss_manipulator_PanTiltSpecificationService
{

class DllExport PanTiltSpecificationService_ReceiveFSM : public JTS::StateMachine
{
public:
	PanTiltSpecificationService_ReceiveFSM(urn_jaus_jss_core_Transport::Transport_ReceiveFSM* pTransport_ReceiveFSM, urn_jaus_jss_core_Events::Events_ReceiveFSM* pEvents_ReceiveFSM);
	virtual ~PanTiltSpecificationService_ReceiveFSM();

	/// Handle notifications on parent state changes
	virtual void setupNotifications();

	/// Action Methods
	virtual void sendReportPanTiltSpecificationsAction(QueryPanTiltSpecifications msg, Receive::Body::ReceiveRec transportData);


	/// Guard Methods



	PanTiltSpecificationService_ReceiveFSMContext *context;

protected:

    /// References to parent FSMs
	urn_jaus_jss_core_Transport::Transport_ReceiveFSM* pTransport_ReceiveFSM;
	urn_jaus_jss_core_Events::Events_ReceiveFSM* pEvents_ReceiveFSM;
	iop_manipulator_core_fkie::PantiltCfgReader p_cfg_reader;


};

};

#endif // PANTILTSPECIFICATIONSERVICE_RECEIVEFSM_H
