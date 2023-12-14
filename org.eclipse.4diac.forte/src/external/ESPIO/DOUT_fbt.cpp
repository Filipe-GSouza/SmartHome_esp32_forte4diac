/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: DOUT
 *** Description: Template for a Basic Function Block Type
 *** Version:
 ***     1.0: 2023-12-02/filipe -  -
 *************************************************************************/

#include "DOUT_fbt.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "DOUT_fbt_gen.cpp"
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>
#include "driver/gpio.h"


#include "criticalregion.h"
#include "resource.h"
#include "forte_udint.h"
#include "forte_bool.h"
#include "iec61131_functions.h"
#include "forte_array_common.h"
#include "forte_array.h"
#include "forte_array_fixed.h"
#include "forte_array_variable.h"

DEFINE_FIRMWARE_FB(FORTE_DOUT, g_nStringIdDOUT)

const CStringDictionary::TStringId FORTE_DOUT::scmDataInputNames[] = {g_nStringIdCHNL, g_nStringIdSTATUS};
const CStringDictionary::TStringId FORTE_DOUT::scmDataInputTypeIds[] = {g_nStringIdUDINT, g_nStringIdBOOL};
const CStringDictionary::TStringId FORTE_DOUT::scmDataOutputNames[] = {g_nStringIdQO};
const CStringDictionary::TStringId FORTE_DOUT::scmDataOutputTypeIds[] = {g_nStringIdBOOL};
const TDataIOID FORTE_DOUT::scmEIWith[] = {0, 1, scmWithListDelimiter, 1, scmWithListDelimiter};
const TForteInt16 FORTE_DOUT::scmEIWithIndexes[] = {0, 3};
const CStringDictionary::TStringId FORTE_DOUT::scmEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};
const TDataIOID FORTE_DOUT::scmEOWith[] = {0, scmWithListDelimiter, 0, scmWithListDelimiter};
const TForteInt16 FORTE_DOUT::scmEOWithIndexes[] = {0, 2};
const CStringDictionary::TStringId FORTE_DOUT::scmEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};
const SFBInterfaceSpec FORTE_DOUT::scmFBInterfaceSpec = {
  2, scmEventInputNames, scmEIWith, scmEIWithIndexes,
  2, scmEventOutputNames, scmEOWith, scmEOWithIndexes,
  2, scmDataInputNames, scmDataInputTypeIds,
  1, scmDataOutputNames, scmDataOutputTypeIds,
  0, nullptr,
  0, nullptr
};

FORTE_DOUT::FORTE_DOUT(const CStringDictionary::TStringId paInstanceNameId, CResource *const paSrcRes) :
    CBasicFB(paSrcRes, &scmFBInterfaceSpec, paInstanceNameId, nullptr),
    var_CHNL(0_UDINT),
    var_conn_QO(var_QO),
    conn_INITO(this, 0),
    conn_CNF(this, 1),
    conn_CHNL(nullptr),
    conn_STATUS(nullptr),
    conn_QO(this, 0, &var_conn_QO) {
}

void FORTE_DOUT::setInitialValues() {
  var_CHNL = 0_UDINT;
  var_STATUS = 0_BOOL;
  var_QO = 0_BOOL;
}

void FORTE_DOUT::executeEvent(TEventID paEIID, CEventChainExecutionThread *const paECET) {
  do {
    switch(mECCState) {
      case scmStateSTART:
        if(scmEventINITID == paEIID) enterStateInit(paECET);
        else return; //no transition cleared
        break;
      case scmStateInit:
        if(1) enterStateInitialized(paECET);
        else return; //no transition cleared
        break;
      case scmStateNormalOp:
        if(1) enterStateInitialized(paECET);
        else return; //no transition cleared
        break;
      case scmStateInitialized:
        if(scmEventREQID == paEIID) enterStateNormalOp(paECET);
        else
        if(scmEventINITID == paEIID) enterStateDeInit(paECET);
        else return; //no transition cleared
        break;
      case scmStateDeInit:
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

void FORTE_DOUT::enterStateSTART(CEventChainExecutionThread *const) {
  mECCState = scmStateSTART;
}

void FORTE_DOUT::enterStateInit(CEventChainExecutionThread *const paECET) {
  mECCState = scmStateInit;
  alg_initialize();
  sendOutputEvent(scmEventINITOID, paECET);
  
   uint32_t io_num = static_cast<uint32_t>(var_CHNL);

    //zero-initialize the config structure.
    gpio_config_t io_conf = {};
    //disable interrupt
    io_conf.intr_type = GPIO_INTR_DISABLE;
    //set as output mode
    io_conf.mode = GPIO_MODE_OUTPUT;
    //bit mask of the pins that you want to set,e.g.GPIO18/19
    io_conf.pin_bit_mask = (1ULL<<io_num);
    //disable pull-down mode
    io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
    //disable pull-up mode
    io_conf.pull_up_en = GPIO_PULLUP_DISABLE;
    //configure GPIO with the given settings
    gpio_config(&io_conf);
   

}

void FORTE_DOUT::enterStateNormalOp(CEventChainExecutionThread *const paECET) {
  mECCState = scmStateNormalOp;
  alg_normalOperation();
  sendOutputEvent(scmEventCNFID, paECET);
  
  uint32_t io_num = static_cast<uint32_t>(var_CHNL);
  int io_num_int = static_cast<int>(io_num);
  gpio_num_t pin = static_cast<gpio_num_t>(io_num_int);
  //gpio_set_level(pin,);
  bool status = static_cast<CIEC_BOOL>(var_STATUS);
  int result = gpio_set_level(pin,status%2);

  if (result==0){
  var_QO = static_cast<CIEC_BOOL>(status);
  }//else var_QO = static_cast<CIEC_BOOL>(status);
}

void FORTE_DOUT::enterStateInitialized(CEventChainExecutionThread *const) {
  mECCState = scmStateInitialized;
}

void FORTE_DOUT::enterStateDeInit(CEventChainExecutionThread *const paECET) {
  mECCState = scmStateDeInit;
  alg_deInitialize();
  sendOutputEvent(scmEventINITOID, paECET);
}

void FORTE_DOUT::readInputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventINITID: {
      readData(0, var_CHNL, conn_CHNL);
      readData(1, var_STATUS, conn_STATUS);
      break;
    }
    case scmEventREQID: {
      readData(1, var_STATUS, conn_STATUS);
      break;
    }
    default:
      break;
  }
}

void FORTE_DOUT::writeOutputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventINITOID: {
      writeData(0, var_QO, conn_QO);
      break;
    }
    case scmEventCNFID: {
      writeData(0, var_QO, conn_QO);
      break;
    }
    default:
      break;
  }
}

CIEC_ANY *FORTE_DOUT::getDI(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_CHNL;
    case 1: return &var_STATUS;
  }
  return nullptr;
}

CIEC_ANY *FORTE_DOUT::getDO(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_QO;
  }
  return nullptr;
}

CEventConnection *FORTE_DOUT::getEOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_INITO;
    case 1: return &conn_CNF;
  }
  return nullptr;
}

CDataConnection **FORTE_DOUT::getDIConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_CHNL;
    case 1: return &conn_STATUS;
  }
  return nullptr;
}

CDataConnection *FORTE_DOUT::getDOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_QO;
  }
  return nullptr;
}

CIEC_ANY *FORTE_DOUT::getVarInternal(size_t) {
  return nullptr;
}

void FORTE_DOUT::alg_initialize(void) {

}

void FORTE_DOUT::alg_deInitialize(void) {

}

void FORTE_DOUT::alg_normalOperation(void) {

}

