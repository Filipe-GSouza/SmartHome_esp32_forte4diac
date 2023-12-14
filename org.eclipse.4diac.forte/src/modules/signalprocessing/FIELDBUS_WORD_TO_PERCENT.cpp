/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: FIELDBUS_WORD_TO_PERCENT
 *** Description: convert a hexadecimal Percent to a REAL
 *** Version:
 ***     1.0: 2023-06-06/Franz Höpfinger - HR Agrartechnik GmbH -
 *************************************************************************/

#include "FIELDBUS_WORD_TO_PERCENT.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "signalprocessing/FIELDBUS_WORD_TO_PERCENT_gen.cpp"
#endif

#include "criticalregion.h"
#include "resource.h"
#include "forte_word.h"
#include "forte_bool.h"
#include "forte_real.h"
#include "forte_udint.h"
#include "iec61131_functions.h"
#include "forte_array_common.h"
#include "forte_array.h"
#include "forte_array_fixed.h"
#include "forte_array_variable.h"

DEFINE_FIRMWARE_FB(FORTE_signalprocessing__FIELDBUS_WORD_TO_PERCENT, g_nStringIdsignalprocessing__FIELDBUS_WORD_TO_PERCENT)

const CStringDictionary::TStringId FORTE_signalprocessing__FIELDBUS_WORD_TO_PERCENT::scmDataInputNames[] = {g_nStringIdQI, g_nStringIdWI};
const CStringDictionary::TStringId FORTE_signalprocessing__FIELDBUS_WORD_TO_PERCENT::scmDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdWORD};
const CStringDictionary::TStringId FORTE_signalprocessing__FIELDBUS_WORD_TO_PERCENT::scmDataOutputNames[] = {g_nStringIdQO, g_nStringIdRO, g_nStringIdWO};
const CStringDictionary::TStringId FORTE_signalprocessing__FIELDBUS_WORD_TO_PERCENT::scmDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdREAL, g_nStringIdWORD};
const TDataIOID FORTE_signalprocessing__FIELDBUS_WORD_TO_PERCENT::scmEIWith[] = {0, 1, scmWithListDelimiter};
const TForteInt16 FORTE_signalprocessing__FIELDBUS_WORD_TO_PERCENT::scmEIWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_signalprocessing__FIELDBUS_WORD_TO_PERCENT::scmEventInputNames[] = {g_nStringIdREQ};
const TDataIOID FORTE_signalprocessing__FIELDBUS_WORD_TO_PERCENT::scmEOWith[] = {0, 1, 2, scmWithListDelimiter};
const TForteInt16 FORTE_signalprocessing__FIELDBUS_WORD_TO_PERCENT::scmEOWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_signalprocessing__FIELDBUS_WORD_TO_PERCENT::scmEventOutputNames[] = {g_nStringIdCNF};
const SFBInterfaceSpec FORTE_signalprocessing__FIELDBUS_WORD_TO_PERCENT::scmFBInterfaceSpec = {
  1, scmEventInputNames, scmEIWith, scmEIWithIndexes,
  1, scmEventOutputNames, scmEOWith, scmEOWithIndexes,
  2, scmDataInputNames, scmDataInputTypeIds,
  3, scmDataOutputNames, scmDataOutputTypeIds,
  0, nullptr,
  0, nullptr
};

const CIEC_WORD FORTE_signalprocessing__FIELDBUS_WORD_TO_PERCENT::var_const_ISO_VALID_SIGNAL_W = 64255_WORD;


FORTE_signalprocessing__FIELDBUS_WORD_TO_PERCENT::FORTE_signalprocessing__FIELDBUS_WORD_TO_PERCENT(const CStringDictionary::TStringId paInstanceNameId, CResource *const paSrcRes) :
    CSimpleFB(paSrcRes, &scmFBInterfaceSpec, paInstanceNameId, nullptr),
    var_conn_QO(var_QO),
    var_conn_RO(var_RO),
    var_conn_WO(var_WO),
    conn_CNF(this, 0),
    conn_QI(nullptr),
    conn_WI(nullptr),
    conn_QO(this, 0, &var_conn_QO),
    conn_RO(this, 1, &var_conn_RO),
    conn_WO(this, 2, &var_conn_WO) {
}

void FORTE_signalprocessing__FIELDBUS_WORD_TO_PERCENT::setInitialValues() {
  var_QI = 0_BOOL;
  var_WI = 0_WORD;
  var_QO = 0_BOOL;
  var_RO = 0_REAL;
  var_WO = 0_WORD;
}

void FORTE_signalprocessing__FIELDBUS_WORD_TO_PERCENT::executeEvent(const TEventID paEIID, CEventChainExecutionThread *const paECET) {
  switch(paEIID) {
    case scmEventREQID:
      alg_REQ();
      break;
    default:
      break;
  }
  sendOutputEvent(scmEventCNFID, paECET);
}

void FORTE_signalprocessing__FIELDBUS_WORD_TO_PERCENT::readInputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventREQID: {
      RES_DATA_CON_CRITICAL_REGION();
      readData(0, var_QI, conn_QI);
      readData(1, var_WI, conn_WI);
      break;
    }
    default:
      break;
  }
}

void FORTE_signalprocessing__FIELDBUS_WORD_TO_PERCENT::writeOutputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventCNFID: {
      RES_DATA_CON_CRITICAL_REGION();
      writeData(0, var_QO, conn_QO);
      writeData(1, var_RO, conn_RO);
      writeData(2, var_WO, conn_WO);
      break;
    }
    default:
      break;
  }
}

CIEC_ANY *FORTE_signalprocessing__FIELDBUS_WORD_TO_PERCENT::getDI(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_QI;
    case 1: return &var_WI;
  }
  return nullptr;
}

CIEC_ANY *FORTE_signalprocessing__FIELDBUS_WORD_TO_PERCENT::getDO(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_QO;
    case 1: return &var_RO;
    case 2: return &var_WO;
  }
  return nullptr;
}

CIEC_ANY *FORTE_signalprocessing__FIELDBUS_WORD_TO_PERCENT::getDIO(size_t) {
  return nullptr;
}

CEventConnection *FORTE_signalprocessing__FIELDBUS_WORD_TO_PERCENT::getEOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_CNF;
  }
  return nullptr;
}

CDataConnection **FORTE_signalprocessing__FIELDBUS_WORD_TO_PERCENT::getDIConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_QI;
    case 1: return &conn_WI;
  }
  return nullptr;
}

CDataConnection *FORTE_signalprocessing__FIELDBUS_WORD_TO_PERCENT::getDOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_QO;
    case 1: return &conn_RO;
    case 2: return &conn_WO;
  }
  return nullptr;
}

CInOutDataConnection **FORTE_signalprocessing__FIELDBUS_WORD_TO_PERCENT::getDIOInConUnchecked(TPortId) {
  return nullptr;
}

CInOutDataConnection *FORTE_signalprocessing__FIELDBUS_WORD_TO_PERCENT::getDIOOutConUnchecked(TPortId) {
  return nullptr;
}

CIEC_ANY *FORTE_signalprocessing__FIELDBUS_WORD_TO_PERCENT::getVarInternal(size_t) {
  return nullptr;
}

void FORTE_signalprocessing__FIELDBUS_WORD_TO_PERCENT::alg_REQ(void) {

  #line 2 "FIELDBUS_WORD_TO_PERCENT.fbt"
  var_QO = var_QI;
  #line 3 "FIELDBUS_WORD_TO_PERCENT.fbt"
  if (func_EQ(true_BOOL, var_QI)) {
    #line 4 "FIELDBUS_WORD_TO_PERCENT.fbt"
    if (func_LE(var_WI, var_const_ISO_VALID_SIGNAL_W)) {
      #line 5 "FIELDBUS_WORD_TO_PERCENT.fbt"
      var_WO = var_WI;
      #line 6 "FIELDBUS_WORD_TO_PERCENT.fbt"
      var_RO = func_DIV<CIEC_REAL>(func_UDINT_TO_REAL(func_WORD_TO_UDINT(var_WO)), func_UDINT_TO_REAL(func_WORD_TO_UDINT(var_const_ISO_VALID_SIGNAL_W)));
    }
  }
}

