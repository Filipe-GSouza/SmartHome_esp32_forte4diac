/*******************************************************************************
 * Copyright (c) 2010 - 2018 ACIN, Profactor GmbH, fortiss GmbH
 * This program and the accompanying materials are made available under the
 * terms of the Eclipse Public License 2.0 which is available at
 * http://www.eclipse.org/legal/epl-2.0.
 *
 * SPDX-License-Identifier: EPL-2.0
 *
 * Contributors:
 *  Alois Zoitl, Ingo Hegny, Gerhard Ebenhofer - initial API and implementation and/or initial documentation
 *  Alois Zoitl - cleaned up main, inserted new architecture initilasation api
 *******************************************************************************/
#include "../forte_architecture.h"
#include "../devlog.h"
#include "../startuphook.h"
#include "../../stdfblib/ita/RMT_DEV.h"
#include "../utils/mainparam_utils.h"

#include <stdio.h>
#include <signal.h>

//this keeps away a lot of rtti and exception handling stuff
#ifndef __cpp_exceptions
extern "C" void __cxa_pure_virtual(void){
  //TODO maybe add some reporting here
  //Although we should never get here
  //if we are here something very very bad has happened e.g., stack overflow or other memory corruption

}
#endif

RMT_DEV *poDev = 0;

void endForte(int paSig){
  (void) paSig;
  if(0 != poDev){
    poDev->changeFBExecutionState(EMGMCommandType::Kill);
  }
}

/*!\brief Creates the Device-Object
 * \param paMGRID A string containing IP and Port like [IP]:[Port]
 */
void createDev(const char *paMGRID){

  signal(SIGINT, endForte);
  signal(SIGTERM, endForte);

  poDev = new RMT_DEV;
  poDev->initialize();

#ifdef FORTE_FBTESTS
  CFBTestsManager::getInstance().runAllTests();
#endif

  poDev->setMGR_ID(paMGRID);
  poDev->startDevice();
  DEVLOG_INFO("FORTE is up and running\n");
  poDev->MGR.joinResourceThread();
  DEVLOG_INFO("FORTE finished\n");
  delete poDev;
}

int main(int argc, char *arg[]){

  if(CForteArchitecture::initialize()){

    startupHook(argc, arg);

    const char *pIpPort = parseCommandLineArguments(argc, arg);
    if((0 != strlen(pIpPort)) && (nullptr != strchr(pIpPort, ':'))){
      createDev(pIpPort);
    }
    else{ //! Lists the help for FORTE
      listHelp();
    }

    CForteArchitecture::deinitialize();

  }
  else{
    DEVLOG_ERROR("Architecture could not be initialized\n");
  }
  return 0;
}
