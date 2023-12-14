/*******************************************************************************
 * Copyright (c) 2015 fortiss GmbH
 * This program and the accompanying materials are made available under the
 * terms of the Eclipse Public License 2.0 which is available at
 * http://www.eclipse.org/legal/epl-2.0.
 *
 * SPDX-License-Identifier: EPL-2.0
 *
 * Contributors:
 *   Martin Jobst
 *   - initial API and implementation and/or initial documentation
 *******************************************************************************/

#include "luabfb.h"
#include "resource.h"
#include "luaengine.h"
#include "../adapter.h"
#include "criticalregion.h"

extern "C" {
#include <lualib.h>
}

// write variable to lua engine
int CLuaFB_index(lua_State *paLuaState) {
  CLuaBFB* luaFB = CLuaEngine::luaGetObject<CLuaBFB>(paLuaState, 1);
  TForteUInt32 id = static_cast<TForteUInt32>(luaL_checkinteger(paLuaState, 2));
  CIEC_ANY* var = luaFB->getVariable(id);
  CLuaEngine::luaPushAny(paLuaState, *var);
  return 1;
}

// get variables from lua engine
int CLuaFB_newindex(lua_State *paLuaState) {
  CLuaBFB* luaFB = CLuaEngine::luaGetObject<CLuaBFB>(paLuaState, 1);
  TForteUInt32 id = static_cast<TForteUInt32>(luaL_checkinteger(paLuaState, 2));
  CIEC_ANY* var = luaFB->getVariable(id);
  CLuaEngine::luaGetAny(paLuaState, *var, 3);
  return 0;
}

int CLuaFB_call(lua_State *paLuaState) {
  CLuaBFB* luaFB = CLuaEngine::luaGetObject<CLuaBFB>(paLuaState, 1);
  TForteUInt32 id = static_cast<TForteUInt32>(luaL_checkinteger(paLuaState, 2));
  if((id & CLuaBFB::LUA_FB_AD_FLAG) != 0) {
    luaFB->sendAdapterEvent((id >> 16) & CLuaBFB::LUA_AD_VAR_MAX, id & CLuaBFB::LUA_FB_VAR_MAX);
  } else {
    luaFB->sendOutputEvent(id);
  }
  return 0;
}

const char CLuaBFB::LUA_NAME[] = "FORTE_CLuaFB";
const luaL_Reg CLuaBFB::LUA_FUNCS[] = { { "__index", CLuaFB_index }, { "__newindex", CLuaFB_newindex }, { "__call", CLuaFB_call }, { nullptr, nullptr } };

CLuaBFB::CLuaBFB(CStringDictionary::TStringId paInstanceNameId, const CLuaBFBTypeEntry* paTypeEntry, CResource *paResource) :
    CBasicFB(paResource, paTypeEntry->getInterfaceSpec(), paInstanceNameId, paTypeEntry->getInternalVarsInformation()),
        mTypeEntry(paTypeEntry) {
  CLuaEngine *luaEngine = getResource().getLuaEngine();
  luaEngine->registerType<CLuaBFB>();
  luaEngine->pushObject<CLuaBFB>(this);
  luaEngine->store(this);
}

CLuaBFB::~CLuaBFB() = default;

bool CLuaBFB::initialize() {
  //before calling super we need to configure the interface of the FB
  setupFBInterface(getFBInterfaceSpec());
  return CBasicFB::initialize();
}

void CLuaBFB::executeEvent(TEventID paEIID) {
  CLuaEngine *luaEngine = getResource().getLuaEngine();
  luaEngine->load(mTypeEntry);
  luaEngine->load(this);
  luaEngine->pushInteger(paEIID > 255 ? recalculateID(paEIID) : paEIID);
  if(!luaEngine->call(2, 0)) {
    DEVLOG_ERROR("Error calling function executeEvent for instance %s\n", getInstanceName());
  }
}

CIEC_ANY* CLuaBFB::getVariable(TForteUInt32 paId) {
  if(CLuaBFB::LUA_FB_STATE == paId) {
    return &mECCState;
  }
  if((paId & CLuaBFB::LUA_FB_IN_FLAG) != 0) {
    return getVarInternal(paId & CLuaBFB::LUA_FB_VAR_MAX);
  }
  if((paId & CLuaBFB::LUA_FB_AD_FLAG) != 0) {
    if((paId & CLuaBFB::LUA_FB_DO_FLAG) != 0) {
      return mAdapters[(paId >> 16) & CLuaBFB::LUA_AD_VAR_MAX]->getDO(paId & CLuaBFB::LUA_FB_VAR_MAX);
    }
    if((paId & CLuaBFB::LUA_FB_DI_FLAG) != 0) {
      return mAdapters[(paId >> 16) & CLuaBFB::LUA_AD_VAR_MAX]->getDI(paId & CLuaBFB::LUA_FB_VAR_MAX);
    }
    return nullptr;
  }
  if((paId & CLuaBFB::LUA_FB_DI_FLAG) != 0) {
    return getDI(paId & CLuaBFB::LUA_FB_VAR_MAX);
  }
  if((paId & CLuaBFB::LUA_FB_DO_FLAG) != 0) {
    return getDO(paId & CLuaBFB::LUA_FB_VAR_MAX);
  }
  return nullptr;
}

void CLuaBFB::readInputData(TEventID paEIID) {
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

void CLuaBFB::writeOutputData(TEventID paEO) {
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
