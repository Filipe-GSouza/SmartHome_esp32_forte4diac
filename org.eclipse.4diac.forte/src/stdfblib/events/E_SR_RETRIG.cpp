/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: E_SR_RETRIG
 *** Description: Event-driven bistable
 *** Version:
 ***     1.0: 2017-09-22/Alois Zoitl - fortiss GmbH - initial API and implementation and/or initial documentation
 *************************************************************************/

#include "E_SR_RETRIG.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "E_SR_RETRIG_gen.cpp"
#endif

#include "criticalregion.h"
#include "resource.h"
#include "forte_bool.h"
#include "iec61131_functions.h"
#include "forte_array_common.h"
#include "forte_array.h"
#include "forte_array_fixed.h"
#include "forte_array_variable.h"

DEFINE_FIRMWARE_FB(FORTE_E_SR_RETRIG, g_nStringIdE_SR_RETRIG)

const CStringDictionary::TStringId FORTE_E_SR_RETRIG::scmDataOutputNames[] = {g_nStringIdQ};
const CStringDictionary::TStringId FORTE_E_SR_RETRIG::scmDataOutputTypeIds[] = {g_nStringIdBOOL};
const TForteInt16 FORTE_E_SR_RETRIG::scmEIWithIndexes[] = {-1, -1};
const CStringDictionary::TStringId FORTE_E_SR_RETRIG::scmEventInputNames[] = {g_nStringIdS, g_nStringIdR};
const TDataIOID FORTE_E_SR_RETRIG::scmEOWith[] = {0, scmWithListDelimiter};
const TForteInt16 FORTE_E_SR_RETRIG::scmEOWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_E_SR_RETRIG::scmEventOutputNames[] = {g_nStringIdEO};
const SFBInterfaceSpec FORTE_E_SR_RETRIG::scmFBInterfaceSpec = {
  2, scmEventInputNames, nullptr, scmEIWithIndexes,
  1, scmEventOutputNames, scmEOWith, scmEOWithIndexes,
  0, nullptr, nullptr,
  1, scmDataOutputNames, scmDataOutputTypeIds,
  0, nullptr,
  0, nullptr
};

FORTE_E_SR_RETRIG::FORTE_E_SR_RETRIG(const CStringDictionary::TStringId paInstanceNameId, CResource *const paSrcRes) :
    CBasicFB(paSrcRes, &scmFBInterfaceSpec, paInstanceNameId, nullptr),
    var_conn_Q(var_Q),
    conn_EO(this, 0),
    conn_Q(this, 0, &var_conn_Q) {
}

void FORTE_E_SR_RETRIG::setInitialValues() {
  var_Q = 0_BOOL;
}

void FORTE_E_SR_RETRIG::executeEvent(TEventID paEIID, CEventChainExecutionThread *const paECET) {
  do {
    switch(mECCState) {
      case scmStateSTART:
        if(scmEventSID == paEIID) enterStateSET(paECET);
        else
        if(scmEventRID == paEIID) enterStateRESET(paECET);
        else return; //no transition cleared
        break;
      case scmStateSET:
        if(scmEventRID == paEIID) enterStateRESET(paECET);
        else return; //no transition cleared
        break;
      case scmStateRESET:
        if(scmEventSID == paEIID) enterStateSET(paECET);
        else return; //no transition cleared
        break;
      default:
        DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 3.", mECCState.operator TForteUInt16 ());
        mECCState = 0; // 0 is always the initial state
        return;
    }
    paEIID = cgInvalidEventID; // we have to clear the event after the first check in order to ensure correct behavior
  } while(true);
}

void FORTE_E_SR_RETRIG::enterStateSTART(CEventChainExecutionThread *const paECET) {
  mECCState = scmStateSTART;
}

void FORTE_E_SR_RETRIG::enterStateSET(CEventChainExecutionThread *const paECET) {
  mECCState = scmStateSET;
  alg_SET();
  sendOutputEvent(scmEventEOID, paECET);
}

void FORTE_E_SR_RETRIG::enterStateRESET(CEventChainExecutionThread *const paECET) {
  mECCState = scmStateRESET;
  alg_RESET();
  sendOutputEvent(scmEventEOID, paECET);
}

void FORTE_E_SR_RETRIG::readInputData(TEventID) {
  // nothing to do
}

void FORTE_E_SR_RETRIG::writeOutputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventEOID: {
      RES_DATA_CON_CRITICAL_REGION();
      writeData(0, var_Q, conn_Q);
      break;
    }
    default:
      break;
  }
}

CIEC_ANY *FORTE_E_SR_RETRIG::getDI(size_t) {
  return nullptr;
}

CIEC_ANY *FORTE_E_SR_RETRIG::getDO(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_Q;
  }
  return nullptr;
}

CIEC_ANY *FORTE_E_SR_RETRIG::getDIO(size_t) {
  return nullptr;
}

CEventConnection *FORTE_E_SR_RETRIG::getEOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_EO;
  }
  return nullptr;
}

CDataConnection **FORTE_E_SR_RETRIG::getDIConUnchecked(TPortId) {
  return nullptr;
}

CDataConnection *FORTE_E_SR_RETRIG::getDOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_Q;
  }
  return nullptr;
}

CInOutDataConnection **FORTE_E_SR_RETRIG::getDIOInConUnchecked(TPortId) {
  return nullptr;
}

CInOutDataConnection *FORTE_E_SR_RETRIG::getDIOOutConUnchecked(TPortId) {
  return nullptr;
}

CIEC_ANY *FORTE_E_SR_RETRIG::getVarInternal(size_t) {
  return nullptr;
}

void FORTE_E_SR_RETRIG::alg_SET(void) {

  #line 2 "E_SR_RETRIG.fbt"
  var_Q = true_BOOL;
}

void FORTE_E_SR_RETRIG::alg_RESET(void) {

  #line 6 "E_SR_RETRIG.fbt"
  var_Q = false_BOOL;
}

