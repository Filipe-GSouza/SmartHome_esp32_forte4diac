/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: D_IN
 *** Description: Service Interface Function Block Type
 *** Version:
 ***     1.0: 2023-12-12/filipe -  -
 *************************************************************************/

#include "D_IN_fbt.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "D_IN_fbt_gen.cpp"
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>
#include "driver/gpio.h"


#include "criticalregion.h"
#include "resource.h"

DEFINE_FIRMWARE_FB(FORTE_D_IN, g_nStringIdD_IN)

const CIEC_WSTRING FORTE_D_IN::scmOK("OK");
const CIEC_WSTRING FORTE_D_IN::scmCouldNotWrite("Could not write");
const CIEC_WSTRING FORTE_D_IN::scmCouldNotRead("Could not read");
const CIEC_WSTRING FORTE_D_IN::scmError("Error");
const CIEC_WSTRING FORTE_D_IN::scmNotInitialised("FB not initialized");
const CIEC_WSTRING FORTE_D_IN::scmPinInUse("Pin already in use by other FB");

const CStringDictionary::TStringId FORTE_D_IN::scmDataInputNames[] = {g_nStringIdQI, g_nStringIdPARAMS};
const CStringDictionary::TStringId FORTE_D_IN::scmDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdWSTRING};
const CStringDictionary::TStringId FORTE_D_IN::scmDataOutputNames[] = {g_nStringIdQO, g_nStringIdSTATUS, g_nStringIdIN};
const CStringDictionary::TStringId FORTE_D_IN::scmDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdWSTRING, g_nStringIdBOOL};
const TDataIOID FORTE_D_IN::scmEIWith[] = {0, 1, scmWithListDelimiter, 0, scmWithListDelimiter};
const TForteInt16 FORTE_D_IN::scmEIWithIndexes[] = {0, 3};
const CStringDictionary::TStringId FORTE_D_IN::scmEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};
const TDataIOID FORTE_D_IN::scmEOWith[] = {0, 1, scmWithListDelimiter, 0, 1, 2, scmWithListDelimiter};
const TForteInt16 FORTE_D_IN::scmEOWithIndexes[] = {0, 3};
const CStringDictionary::TStringId FORTE_D_IN::scmEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};
const SFBInterfaceSpec FORTE_D_IN::scmFBInterfaceSpec = {
  2, scmEventInputNames, scmEIWith, scmEIWithIndexes,
  2, scmEventOutputNames, scmEOWith, scmEOWithIndexes,
  2, scmDataInputNames, scmDataInputTypeIds,
  3, scmDataOutputNames, scmDataOutputTypeIds,
  0, nullptr,
  0, nullptr
};

FORTE_D_IN::FORTE_D_IN(const CStringDictionary::TStringId paInstanceNameId, CResource *const paSrcRes) :
    CFunctionBlock(paSrcRes, &scmFBInterfaceSpec, paInstanceNameId),
    var_conn_QO(var_QO),
    var_conn_STATUS(var_STATUS),
    var_conn_IN(var_IN),
    conn_INITO(this, 0),
    conn_CNF(this, 1),
    conn_QI(nullptr),
    conn_PARAMS(nullptr),
    conn_QO(this, 0, &var_conn_QO),
    conn_STATUS(this, 1, &var_conn_STATUS),
    conn_IN(this, 2, &var_conn_IN) {
};

void FORTE_D_IN::setInitialValues() {
  var_QI = 0_BOOL;
  var_PARAMS = u""_WSTRING;
  var_QO = 0_BOOL;
  var_STATUS = u""_WSTRING;
  var_IN = 0_BOOL;
}

bool FORTE_D_IN::initialise(bool paIsInput) {
    bool retVal = false;
 
    int io_num = std::stoi(var_PARAMS.getValue());
  
    gpio_config_t io_conf = {};
    //disable interrupt
    io_conf.intr_type = GPIO_INTR_DISABLE;
   
    if(paIsInput) {
    io_conf.mode = GPIO_MODE_INPUT;
    io_conf.pull_up_en = GPIO_PULLUP_ENABLE;
    }else {
    io_conf.mode = GPIO_MODE_OUTPUT;
    io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
    io_conf.pull_up_en = GPIO_PULLUP_DISABLE;
    }
    //bit mask of the pins that you want to set,e.g.GPIO18/19
    io_conf.pin_bit_mask = (1ULL<<io_num);
    //configure GPIO with the given settings
    int configpin = gpio_config(&io_conf);

    if(!configpin){
      retVal = true;
    } else{
      DEVLOG_ERROR("[FORTE_D_IN::setConfig] - Parameter error ");
    }
  return retVal;
}


bool FORTE_D_IN::deinitialise() {
  bool retVal = false;
  int io_num = std::stoi(var_PARAMS.getValue());
  gpio_num_t pin = static_cast<gpio_num_t>(io_num);

  int result = gpio_reset_pin(pin);
    if(!result) {
      var_STATUS = scmOK;
      retVal = true;
    } else {
      var_STATUS = scmError;
      DEVLOG_ERROR("[FORTE_D_IN::deinitialise] - Error reseting PIN");
    }
  return retVal;
}


bool FORTE_D_IN::readPin() {
 bool retVal = false;
  int io_num = std::stoi(var_PARAMS.getValue());
  gpio_num_t pin = static_cast<gpio_num_t>(io_num);
  
  bool result = gpio_get_level(pin);
  var_STATUS = scmOK;
      
  return CIEC_BOOL(result);
}


void FORTE_D_IN::executeEvent(const TEventID paEIID, CEventChainExecutionThread *const paECET) {
  switch(paEIID) {
    case scmEventINITID:
     if (var_QI) {
        var_QO = CIEC_BOOL(initialise(true)); //initialise as input
      } else {
        var_QO = CIEC_BOOL(deinitialise());
      }
      sendOutputEvent(scmEventINITOID, paECET);
      break;
    case scmEventREQID:
      if (var_QI) {
        var_IN = CIEC_BOOL(readPin());
      } else {
        var_IN = false_BOOL;
      }
      sendOutputEvent(scmEventCNFID, paECET);
      break;
  }
}

void FORTE_D_IN::readInputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventINITID: {
      readData(0, var_QI, conn_QI);
      readData(1, var_PARAMS, conn_PARAMS);
      break;
    }
    case scmEventREQID: {
      readData(0, var_QI, conn_QI);
      break;
    }
    default:
      break;
  }
}

void FORTE_D_IN::writeOutputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventINITOID: {
      writeData(0, var_QO, conn_QO);
      writeData(1, var_STATUS, conn_STATUS);
      break;
    }
    case scmEventCNFID: {
      writeData(0, var_QO, conn_QO);
      writeData(1, var_STATUS, conn_STATUS);
      writeData(2, var_IN, conn_IN);
      break;
    }
    default:
      break;
  }
}

CIEC_ANY *FORTE_D_IN::getDI(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_QI;
    case 1: return &var_PARAMS;
  }
  return nullptr;
}

CIEC_ANY *FORTE_D_IN::getDO(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_QO;
    case 1: return &var_STATUS;
    case 2: return &var_IN;
  }
  return nullptr;
}

CEventConnection *FORTE_D_IN::getEOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_INITO;
    case 1: return &conn_CNF;
  }
  return nullptr;
}

CDataConnection **FORTE_D_IN::getDIConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_QI;
    case 1: return &conn_PARAMS;
  }
  return nullptr;
}

CDataConnection *FORTE_D_IN::getDOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_QO;
    case 1: return &conn_STATUS;
    case 2: return &conn_IN;
  }
  return nullptr;
}

