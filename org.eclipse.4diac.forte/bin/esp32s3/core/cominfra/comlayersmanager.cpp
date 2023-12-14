/*******************************************************************************
 * Copyright (c) 2010, 2011 ACIN and Profactor GmbH.
 *     
 * This program and the accompanying materials are made available under the
 * terms of the Eclipse Public License 2.0 which is available at
 * http://www.eclipse.org/legal/epl-2.0.
 *
 * SPDX-License-Identifier: EPL-2.0  
 *
 * Contributors:
 *    Alois Zoitl - initial implementation and rework communication infrastructure
 *    Ingo Hegny - moved encoding of adapter-event-ids to a single point
 *    Michael Hofmann - rework communication infrastructure
 *******************************************************************************/

#include "fortenew.h"
#include "comlayersmanager.h"
#include <string.h>

#include<ipcomlayer.h>
#include<fbdkasn1layer.h>
#include<localcomlayer.h>
#include<rawdatacomlayer.h>


using namespace forte::com_infra;

CComLayer* CComLayersManager::createCommunicationLayer(char *paLayerIdentifier, CComLayer* paUpperLayer, CBaseCommFB * paComFB){
  CComLayer* mNewLayer = nullptr;
  if(0 == strcmp("ip", paLayerIdentifier)){
    mNewLayer = new CIPComLayer(paUpperLayer, paComFB);
  }
  else if(0 == strcmp("fbdk", paLayerIdentifier)){
    mNewLayer = new CFBDKASN1ComLayer(paUpperLayer, paComFB);
  }
  else if(0 == strcmp("loc", paLayerIdentifier)){
    mNewLayer = new CLocalComLayer(paUpperLayer, paComFB);
  }
  else if(0 == strcmp("raw", paLayerIdentifier)){
    mNewLayer = new CRawDataComLayer(paUpperLayer, paComFB);
  }


  return mNewLayer;
}
