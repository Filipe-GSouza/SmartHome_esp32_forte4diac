/*******************************************************************************
 * Copyright (c) 2017 fortiss GmbH
 * This program and the accompanying materials are made available under the
 * terms of the Eclipse Public License 2.0 which is available at
 * http://www.eclipse.org/legal/epl-2.0.
 *
 * SPDX-License-Identifier: EPL-2.0
 *
 * Contributors:
 *   Monika Wenger
 *   - initial API and implementation and/or initial documentation
 *******************************************************************************/

#include "luaadapter.h"
#include "resource.h"
#include "criticalregion.h"

CLuaAdapter::CLuaAdapter(CStringDictionary::TStringId paInstanceNameId, const CLuaAdapterTypeEntry* paTypeEntry, bool paIsPlug, CResource *paResource) :
    CAdapter(paResource, paTypeEntry->getSocketInterfaceSpec(), paInstanceNameId, paTypeEntry->getPlugInterfaceSpec(), paIsPlug),
        mTypeEntry(paTypeEntry) {
}

CLuaAdapter::~CLuaAdapter() = default;

bool CLuaAdapter::initialize() {
  //before calling super we need to configure the interface of the FB
  setupFBInterface(getFBInterfaceSpec());
  return CAdapter::initialize();
}


void CLuaAdapter::readInputData(TEventID paEIID) {
  if(nullptr != mInterfaceSpec->mEIWithIndexes && scmNoDataAssociated != mInterfaceSpec->mEIWithIndexes[paEIID]) {
    const TDataIOID *eiWithStart = &(mInterfaceSpec->mEIWith[mInterfaceSpec->mEIWithIndexes[paEIID]]);

    // TODO think on this lock
    RES_DATA_CON_CRITICAL_REGION();
    for(size_t i = 0; eiWithStart[i] != scmWithListDelimiter; ++i) {
      TDataIOID diNum = eiWithStart[i];
      readData(diNum, *getDI(diNum), *getDIConUnchecked(diNum));
    }
  }
}

void CLuaAdapter::writeOutputData(TEventID paEO) {
  if (nullptr != mInterfaceSpec->mEOWithIndexes && -1 != mInterfaceSpec->mEOWithIndexes[paEO]) {
    const TDataIOID *eiWithStart = &(mInterfaceSpec->mEOWith[mInterfaceSpec->mEOWithIndexes[paEO]]);
    //TODO think on this lock
    RES_DATA_CON_CRITICAL_REGION();
    for (size_t i = 0; eiWithStart[i] != scmWithListDelimiter; ++i) {
      TDataIOID doNum = eiWithStart[i];
      writeData(doNum, *getDO(doNum), *getDOConUnchecked(doNum));
    }
  }
}
