/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: A_OUT
 *** Description: Service Interface Function Block Type to ESP32 Module
 *** Version:
 ***     1.0: 2023-12-20/Filipe Gomes -  -
 *************************************************************************/

#include "A_OUT_fbt.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "A_OUT_fbt_gen.cpp"
#endif

#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
#include "driver/ledc.h"
#include "esp_err.h"
#include <cmath>


#include "criticalregion.h"
#include "resource.h"

// Variáveis para armazenar cada informação
int pin, tim, chnl, res, duty;
uint32_t freq;
ledc_channel_t channel;
ledc_timer_bit_t resol;
ledc_timer_t timer;

DEFINE_FIRMWARE_FB(FORTE_A_OUT, g_nStringIdA_OUT)

const CStringDictionary::TStringId FORTE_A_OUT::scmDataInputNames[] = {g_nStringIdQI, g_nStringIdPARAMS, g_nStringIdOUTPUT};
const CStringDictionary::TStringId FORTE_A_OUT::scmDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdWSTRING, g_nStringIdREAL};
const CStringDictionary::TStringId FORTE_A_OUT::scmDataOutputNames[] = {g_nStringIdQO, g_nStringIdSTATUS};
const CStringDictionary::TStringId FORTE_A_OUT::scmDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdWSTRING};
const TDataIOID FORTE_A_OUT::scmEIWith[] = {0, 1, scmWithListDelimiter, 0, 2, scmWithListDelimiter};
const TForteInt16 FORTE_A_OUT::scmEIWithIndexes[] = {0, 3};
const CStringDictionary::TStringId FORTE_A_OUT::scmEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};
const TDataIOID FORTE_A_OUT::scmEOWith[] = {0, 1, scmWithListDelimiter, 0, 1, scmWithListDelimiter};
const TForteInt16 FORTE_A_OUT::scmEOWithIndexes[] = {0, 3};
const CStringDictionary::TStringId FORTE_A_OUT::scmEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};
const SFBInterfaceSpec FORTE_A_OUT::scmFBInterfaceSpec = {
  2, scmEventInputNames, scmEIWith, scmEIWithIndexes,
  2, scmEventOutputNames, scmEOWith, scmEOWithIndexes,
  3, scmDataInputNames, scmDataInputTypeIds,
  2, scmDataOutputNames, scmDataOutputTypeIds,
  0, nullptr,
  0, nullptr
};

FORTE_A_OUT::FORTE_A_OUT(const CStringDictionary::TStringId paInstanceNameId, CResource *const paSrcRes) :
    CFunctionBlock(paSrcRes, &scmFBInterfaceSpec, paInstanceNameId),
    var_conn_QO(var_QO),
    var_conn_STATUS(var_STATUS),
    conn_INITO(this, 0),
    conn_CNF(this, 1),
    conn_QI(nullptr),
    conn_PARAMS(nullptr),
    conn_OUTPUT(nullptr),
    conn_QO(this, 0, &var_conn_QO),
    conn_STATUS(this, 1, &var_conn_STATUS) {
};

void FORTE_A_OUT::setInitialValues() {
  var_QI = 0_BOOL;
  var_PARAMS = u""_WSTRING;
  var_OUTPUT = 0_REAL;
  var_QO = 0_BOOL;
  var_STATUS = u""_WSTRING;
}

bool FORTE_A_OUT::initialise() {
    bool retVal =false;

    std::string params_pwm = var_PARAMS.getValue();
 // Stream para ler a string
    std::stringstream stream(params_pwm);
// Extrair informações
    char delimiter;
    stream >> pin >> delimiter >> tim >> delimiter >> chnl >> delimiter >> res >> delimiter >> freq;

    channel = static_cast<ledc_channel_t>(chnl);
    resol = static_cast<ledc_timer_bit_t>(res);
    timer = static_cast<ledc_timer_t>(tim);

// Prepara e aplica as configuracoes do timer
    ledc_timer_config_t ledc_timer = {
        .speed_mode       = LEDC_MODE,
        .duty_resolution  = resol,
        .timer_num        = timer,
        .freq_hz          = freq,  // Set output frequency
        .clk_cfg          = LEDC_AUTO_CLK
    };
    ESP_ERROR_CHECK(ledc_timer_config(&ledc_timer));

    // Prepara e aplica as configuracoes do canal LEDC PWM 
    ledc_channel_config_t ledc_channel = {
        
        .gpio_num       = pin,
        .speed_mode     = LEDC_MODE,
        .channel        = channel,
        .intr_type      = LEDC_INTR_DISABLE,
        .timer_sel      = timer,
        .duty           = 0, // Set duty to 0%
        .hpoint         = 0
    };
    
    ESP_ERROR_CHECK_WITHOUT_ABORT(ledc_channel_config(&ledc_channel));

 return retVal;

}

void FORTE_A_OUT::write_pwm() {

  int resultado = std::pow(2, res) - 1;
  int percent_duty = static_cast<int>(var_OUTPUT);
  int ledc_duty = (resultado*percent_duty)/100; 
  ESP_ERROR_CHECK_WITHOUT_ABORT(ledc_set_duty(LEDC_MODE,channel,ledc_duty));  
    // Update duty to apply the new value
  ESP_ERROR_CHECK_WITHOUT_ABORT(ledc_update_duty(LEDC_MODE,channel));
}



void FORTE_A_OUT::executeEvent(const TEventID paEIID, CEventChainExecutionThread *const paECET) {
  switch(paEIID) {
    case scmEventINITID:

       if (var_QI) {
        var_QO = CIEC_BOOL(initialise()); //initialise as input
      } else {
        
      }
      sendOutputEvent(scmEventINITOID, paECET);
      break;

    case scmEventREQID:
     if (var_QI) {
        write_pwm();
      } else {
        
      }
      sendOutputEvent(scmEventCNFID, paECET);
      break;
  }
}

void FORTE_A_OUT::readInputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventINITID: {
      readData(0, var_QI, conn_QI);
      readData(1, var_PARAMS, conn_PARAMS);
      break;
    }
    case scmEventREQID: {
      readData(0, var_QI, conn_QI);
      readData(2, var_OUTPUT, conn_OUTPUT);
      break;
    }
    default:
      break;
  }
}

void FORTE_A_OUT::writeOutputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventINITOID: {
      writeData(0, var_QO, conn_QO);
      writeData(1, var_STATUS, conn_STATUS);
      break;
    }
    case scmEventCNFID: {
      writeData(0, var_QO, conn_QO);
      writeData(1, var_STATUS, conn_STATUS);
      break;
    }
    default:
      break;
  }
}

CIEC_ANY *FORTE_A_OUT::getDI(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_QI;
    case 1: return &var_PARAMS;
    case 2: return &var_OUTPUT;
  }
  return nullptr;
}

CIEC_ANY *FORTE_A_OUT::getDO(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_QO;
    case 1: return &var_STATUS;
  }
  return nullptr;
}

CEventConnection *FORTE_A_OUT::getEOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_INITO;
    case 1: return &conn_CNF;
  }
  return nullptr;
}

CDataConnection **FORTE_A_OUT::getDIConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_QI;
    case 1: return &conn_PARAMS;
    case 2: return &conn_OUTPUT;
  }
  return nullptr;
}

CDataConnection *FORTE_A_OUT::getDOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_QO;
    case 1: return &conn_STATUS;
  }
  return nullptr;
}

