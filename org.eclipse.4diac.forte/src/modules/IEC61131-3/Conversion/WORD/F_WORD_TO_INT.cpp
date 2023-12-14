/*******************************************************************************
 * Copyright (c) 2023 Martin Erich Jobst
 *
 * This program and the accompanying materials are made available under the
 * terms of the Eclipse Public License 2.0 which is available at
 * http://www.eclipse.org/legal/epl-2.0.
 *
 * SPDX-License-Identifier: EPL-2.0
 *
 * Contributors:
 *   Martin Jobst
 *     - initial API and implementation and/or initial documentation
 *******************************************************************************/

#include "F_WORD_TO_INT.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "F_WORD_TO_INT_gen.cpp"
#endif

#include "criticalregion.h"
#include "resource.h"
#include "forte_int.h"
#include "forte_word.h"
#include "iec61131_functions.h"
#include "forte_array_common.h"
#include "forte_array.h"
#include "forte_array_fixed.h"
#include "forte_array_variable.h"

DEFINE_FIRMWARE_FB(FORTE_F_WORD_TO_INT, g_nStringIdF_WORD_TO_INT)

const CStringDictionary::TStringId FORTE_F_WORD_TO_INT::scmDataInputNames[] = {g_nStringIdIN};

const CStringDictionary::TStringId FORTE_F_WORD_TO_INT::scmDataInputTypeIds[] = {g_nStringIdWORD};

const CStringDictionary::TStringId FORTE_F_WORD_TO_INT::scmDataOutputNames[] = {g_nStringIdOUT};

const CStringDictionary::TStringId FORTE_F_WORD_TO_INT::scmDataOutputTypeIds[] = {g_nStringIdINT};

const TDataIOID FORTE_F_WORD_TO_INT::scmEIWith[] = {0, scmWithListDelimiter};
const TForteInt16 FORTE_F_WORD_TO_INT::scmEIWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_F_WORD_TO_INT::scmEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_F_WORD_TO_INT::scmEOWith[] = {0, scmWithListDelimiter};
const TForteInt16 FORTE_F_WORD_TO_INT::scmEOWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_F_WORD_TO_INT::scmEventOutputNames[] = {g_nStringIdCNF};


const SFBInterfaceSpec FORTE_F_WORD_TO_INT::scmFBInterfaceSpec = {
  1, scmEventInputNames, scmEIWith, scmEIWithIndexes,
  1, scmEventOutputNames, scmEOWith, scmEOWithIndexes,
  1, scmDataInputNames, scmDataInputTypeIds,
  1, scmDataOutputNames, scmDataOutputTypeIds,
  0, nullptr,
  0, nullptr
};


FORTE_F_WORD_TO_INT::FORTE_F_WORD_TO_INT(CStringDictionary::TStringId paInstanceNameId, CResource *paSrcRes) :
    CSimpleFB(paSrcRes, &scmFBInterfaceSpec, paInstanceNameId, nullptr),
    var_IN(CIEC_WORD(0)),
    var_OUT(CIEC_INT(0)),
    var_conn_OUT(var_OUT),
    conn_CNF(this, 0),
    conn_IN(nullptr),
    conn_OUT(this, 0, &var_conn_OUT) {
}

void FORTE_F_WORD_TO_INT::alg_REQ(void) {
  
  var_OUT = func_WORD_TO_INT(var_IN);
}


void FORTE_F_WORD_TO_INT::executeEvent(TEventID paEIID){
  switch(paEIID) {
    case scmEventREQID:
      alg_REQ();
      break;
    default:
      break;
  }
  sendOutputEvent(scmEventCNFID);
}

void FORTE_F_WORD_TO_INT::readInputData(TEventID paEIID) {
  switch(paEIID) {
    case scmEventREQID: {
      RES_DATA_CON_CRITICAL_REGION();
      readData(0, var_IN, conn_IN);
      break;
    }
    default:
      break;
  }
}

void FORTE_F_WORD_TO_INT::writeOutputData(TEventID paEIID) {
  switch(paEIID) {
    case scmEventCNFID: {
      RES_DATA_CON_CRITICAL_REGION();
      writeData(0, var_OUT, conn_OUT);
      break;
    }
    default:
      break;
  }
}

CIEC_ANY *FORTE_F_WORD_TO_INT::getDI(size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_IN;
  }
  return nullptr;
}

CIEC_ANY *FORTE_F_WORD_TO_INT::getDO(size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_OUT;
  }
  return nullptr;
}

CEventConnection *FORTE_F_WORD_TO_INT::getEOConUnchecked(TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_CNF;
  }
  return nullptr;
}

CDataConnection **FORTE_F_WORD_TO_INT::getDIConUnchecked(TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_IN;
  }
  return nullptr;
}

CDataConnection *FORTE_F_WORD_TO_INT::getDOConUnchecked(TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_OUT;
  }
  return nullptr;
}

CIEC_ANY *FORTE_F_WORD_TO_INT::getVarInternal(size_t) {
  return nullptr;
}


