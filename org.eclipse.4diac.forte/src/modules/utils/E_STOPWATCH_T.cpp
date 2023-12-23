/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: E_STOPWATCH_T
 *** Description: FB for stopping time between events
 *** Version:
 ***     1.0: 2018-08-29/Ben Schneider - fortiss GmbH - initial API and implementation and/or initial documentation
 ***     1.1: 2020-05-24/alois Zoitl - Johannes Kepler University Linz - Changed to a full basic FB implementation utilizing the new NOW_MONOTONIC function
 *************************************************************************/

#include "E_STOPWATCH_T.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "E_STOPWATCH_T_gen.cpp"
#endif

#include "criticalregion.h"
#include "resource.h"
#include "forte_time.h"
#include "forte_bool.h"
#include "iec61131_functions.h"
#include "forte_array_common.h"
#include "forte_array.h"
#include "forte_array_fixed.h"
#include "forte_array_variable.h"

DEFINE_FIRMWARE_FB(FORTE_E_STOPWATCH_T, g_nStringIdE_STOPWATCH_T)

const CStringDictionary::TStringId FORTE_E_STOPWATCH_T::scmDataOutputNames[] = {g_nStringIdTD};
const CStringDictionary::TStringId FORTE_E_STOPWATCH_T::scmDataOutputTypeIds[] = {g_nStringIdTIME};
const TForteInt16 FORTE_E_STOPWATCH_T::scmEIWithIndexes[] = {-1, -1, -1, -1};
const CStringDictionary::TStringId FORTE_E_STOPWATCH_T::scmEventInputNames[] = {g_nStringIdSTART, g_nStringIdET, g_nStringIdSTOP, g_nStringIdRESET};
const TDataIOID FORTE_E_STOPWATCH_T::scmEOWith[] = {0, scmWithListDelimiter};
const TForteInt16 FORTE_E_STOPWATCH_T::scmEOWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_E_STOPWATCH_T::scmEventOutputNames[] = {g_nStringIdEO};
const SFBInterfaceSpec FORTE_E_STOPWATCH_T::scmFBInterfaceSpec = {
  4, scmEventInputNames, nullptr, scmEIWithIndexes,
  1, scmEventOutputNames, scmEOWith, scmEOWithIndexes,
  0, nullptr, nullptr,
  1, scmDataOutputNames, scmDataOutputTypeIds,
  0, nullptr,
  0, nullptr
};

const CStringDictionary::TStringId FORTE_E_STOPWATCH_T::scmInternalsNames[] = {g_nStringIdstartTime};
const CStringDictionary::TStringId FORTE_E_STOPWATCH_T::scmInternalsTypeIds[] = {g_nStringIdTIME};
const SInternalVarsInformation FORTE_E_STOPWATCH_T::scmInternalVars = {1, scmInternalsNames, scmInternalsTypeIds};

FORTE_E_STOPWATCH_T::FORTE_E_STOPWATCH_T(const CStringDictionary::TStringId paInstanceNameId, CResource *const paSrcRes) :
    CBasicFB(paSrcRes, &scmFBInterfaceSpec, paInstanceNameId, &scmInternalVars),
    var_conn_TD(var_TD),
    conn_EO(this, 0),
    conn_TD(this, 0, &var_conn_TD) {
}

void FORTE_E_STOPWATCH_T::setInitialValues() {
  var_startTime = 0_TIME;
  var_TD = 0_TIME;
}

void FORTE_E_STOPWATCH_T::executeEvent(TEventID paEIID, CEventChainExecutionThread *const paECET) {
  do {
    switch(mECCState) {
      case scmStateSTART:
        if(scmEventSTARTID == paEIID) enterStateMeasure(paECET);
        else
        if(scmEventRESETID == paEIID) enterStateRESET(paECET);
        else return; //no transition cleared
        break;
      case scmStateMeasure:
        if(scmEventSTOPID == paEIID) enterStateSTOP(paECET);
        else
        if(scmEventETID == paEIID) enterStateTrig(paECET);
        else
        if(scmEventRESETID == paEIID) enterStateRESET(paECET);
        else return; //no transition cleared
        break;
      case scmStateSTOP:
        if(1) enterStateSTART(paECET);
        else return; //no transition cleared
        break;
      case scmStateTrig:
        if(scmEventSTOPID == paEIID) enterStateSTOP(paECET);
        else
        if(scmEventETID == paEIID) enterStateTrig(paECET);
        else
        if(scmEventRESETID == paEIID) enterStateRESET(paECET);
        else return; //no transition cleared
        break;
      case scmStateRESET:
        if(1) enterStateSTART(paECET);
        else return; //no transition cleared
        break;
      default:
        DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 5.", mECCState.operator TForteUInt16 ());
        mECCState = 0; // 0 is always the initial state
        return;
    }
    paEIID = cgInvalidEventID; // we have to clear the event after the first check in order to ensure correct behavior
  } while(true);
}

void FORTE_E_STOPWATCH_T::enterStateSTART(CEventChainExecutionThread *const paECET) {
  mECCState = scmStateSTART;
}

void FORTE_E_STOPWATCH_T::enterStateMeasure(CEventChainExecutionThread *const paECET) {
  mECCState = scmStateMeasure;
  alg_captureStartTime();
}

void FORTE_E_STOPWATCH_T::enterStateSTOP(CEventChainExecutionThread *const paECET) {
  mECCState = scmStateSTOP;
  alg_calcDiff();
  sendOutputEvent(scmEventEOID, paECET);
}

void FORTE_E_STOPWATCH_T::enterStateTrig(CEventChainExecutionThread *const paECET) {
  mECCState = scmStateTrig;
  alg_calcDiff();
  sendOutputEvent(scmEventEOID, paECET);
}

void FORTE_E_STOPWATCH_T::enterStateRESET(CEventChainExecutionThread *const paECET) {
  mECCState = scmStateRESET;
  alg_reset();
  sendOutputEvent(scmEventEOID, paECET);
}

void FORTE_E_STOPWATCH_T::readInputData(TEventID) {
  // nothing to do
}

void FORTE_E_STOPWATCH_T::writeOutputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventEOID: {
      RES_DATA_CON_CRITICAL_REGION();
      writeData(0, var_TD, conn_TD);
      break;
    }
    default:
      break;
  }
}

CIEC_ANY *FORTE_E_STOPWATCH_T::getDI(size_t) {
  return nullptr;
}

CIEC_ANY *FORTE_E_STOPWATCH_T::getDO(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_TD;
  }
  return nullptr;
}

CIEC_ANY *FORTE_E_STOPWATCH_T::getDIO(size_t) {
  return nullptr;
}

CEventConnection *FORTE_E_STOPWATCH_T::getEOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_EO;
  }
  return nullptr;
}

CDataConnection **FORTE_E_STOPWATCH_T::getDIConUnchecked(TPortId) {
  return nullptr;
}

CDataConnection *FORTE_E_STOPWATCH_T::getDOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_TD;
  }
  return nullptr;
}

CInOutDataConnection **FORTE_E_STOPWATCH_T::getDIOInConUnchecked(TPortId) {
  return nullptr;
}

CInOutDataConnection *FORTE_E_STOPWATCH_T::getDIOOutConUnchecked(TPortId) {
  return nullptr;
}

CIEC_ANY *FORTE_E_STOPWATCH_T::getVarInternal(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_startTime;
  }
  return nullptr;
}

void FORTE_E_STOPWATCH_T::alg_captureStartTime(void) {

  #line 2 "E_STOPWATCH_T.fbt"
  var_startTime = func_NOW_MONOTONIC();
}

void FORTE_E_STOPWATCH_T::alg_calcDiff(void) {

  #line 6 "E_STOPWATCH_T.fbt"
  var_TD = func_SUB<CIEC_TIME>(func_NOW_MONOTONIC(), var_startTime);
}

void FORTE_E_STOPWATCH_T::alg_reset(void) {

  #line 10 "E_STOPWATCH_T.fbt"
  var_TD = 0_TIME;
}

