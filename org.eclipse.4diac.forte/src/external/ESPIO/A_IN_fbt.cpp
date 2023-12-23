/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: A_IN
 *** Description: Service Interface Function Block Type to ESP32 Module
 *** Version:
 ***     1.0: 2023-12-13/Filipe Gomes -  -
 *************************************************************************/

#include "A_IN_fbt.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "A_IN_fbt_gen.cpp"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "soc/soc_caps.h"
#include "esp_log.h"
#include "hal/adc_types.h"
#include "esp_adc/adc_oneshot.h"
#include "esp_adc/adc_cali.h"
#include "esp_adc/adc_cali_scheme.h"

#include "criticalregion.h"
#include "resource.h"

static int adc_raw;
static int value;
bool do_calibration_chan;
adc_oneshot_unit_handle_t adc1_handle;
adc_cali_handle_t handle = NULL;
static bool adc_calibration_init(adc_unit_t unit, adc_channel_t channel, adc_atten_t atten, adc_cali_handle_t *out_handle);
static void adc_calibration_deinit(adc_cali_handle_t handle);

DEFINE_FIRMWARE_FB(FORTE_A_IN, g_nStringIdA_IN)

const CIEC_WSTRING FORTE_A_IN::scmOK("OK");
const CIEC_WSTRING FORTE_A_IN::scmCouldNotWrite("Could not write");
const CIEC_WSTRING FORTE_A_IN::scmCouldNotRead("Could not read");
const CIEC_WSTRING FORTE_A_IN::scmError("Error");
const CIEC_WSTRING FORTE_A_IN::scmNotInitialised("FB not initialized");
const CIEC_WSTRING FORTE_A_IN::scmPinInUse("Pin already in use by other FB");

const CStringDictionary::TStringId FORTE_A_IN::scmDataInputNames[] = {g_nStringIdQI, g_nStringIdPARAMS, g_nStringId_MAX, g_nStringId_MIN};
const CStringDictionary::TStringId FORTE_A_IN::scmDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdWSTRING, g_nStringIdREAL, g_nStringIdREAL};
const CStringDictionary::TStringId FORTE_A_IN::scmDataOutputNames[] = {g_nStringIdQO, g_nStringIdSTATUS, g_nStringIdIN};
const CStringDictionary::TStringId FORTE_A_IN::scmDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdWSTRING, g_nStringIdREAL};
const TDataIOID FORTE_A_IN::scmEIWith[] = {0, 1, scmWithListDelimiter, 0, 2, 3, scmWithListDelimiter};
const TForteInt16 FORTE_A_IN::scmEIWithIndexes[] = {0, 3};
const CStringDictionary::TStringId FORTE_A_IN::scmEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};
const TDataIOID FORTE_A_IN::scmEOWith[] = {0, 1, scmWithListDelimiter, 0, 1, 2, scmWithListDelimiter};
const TForteInt16 FORTE_A_IN::scmEOWithIndexes[] = {0, 3};
const CStringDictionary::TStringId FORTE_A_IN::scmEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};
const SFBInterfaceSpec FORTE_A_IN::scmFBInterfaceSpec = {
  2, scmEventInputNames, scmEIWith, scmEIWithIndexes,
  2, scmEventOutputNames, scmEOWith, scmEOWithIndexes,
  4, scmDataInputNames, scmDataInputTypeIds,
  3, scmDataOutputNames, scmDataOutputTypeIds,
  0, nullptr,
  0, nullptr
};

FORTE_A_IN::FORTE_A_IN(const CStringDictionary::TStringId paInstanceNameId, CResource *const paSrcRes) :
    CFunctionBlock(paSrcRes, &scmFBInterfaceSpec, paInstanceNameId),
    var_QI(false_BOOL),
    var_PARAMS(u""_WSTRING),
    var__MAX(0_SINT),
    var__MIN(0_SINT),
    var_QO(false_BOOL),
    var_STATUS(u""_WSTRING),
    var_IN(0_SINT),
    var_conn_QO(var_QO),
    var_conn_STATUS(var_STATUS),
    var_conn_IN(var_IN),
    conn_INITO(this, 0),
    conn_CNF(this, 1),
    conn_QI(nullptr),
    conn_PARAMS(nullptr),
    conn__MAX(nullptr),
    conn__MIN(nullptr),
    conn_QO(this, 0, &var_conn_QO),
    conn_STATUS(this, 1, &var_conn_STATUS),
    conn_IN(this, 2, &var_conn_IN) {
};

void FORTE_A_IN::setInitialValues() {
  var_QI = false_BOOL;
  var_PARAMS = u""_WSTRING;
  var__MAX = 0.0_REAL;
  var__MIN = 0.0_REAL;
  var_QO = false_BOOL;
  var_STATUS = u""_WSTRING;
  var_IN = 0.0_REAL;
}

bool FORTE_A_IN::initialise() {
    bool retVal =false;
    bool res_1,res_2;

  //-------------ADC1 Init---------------//
    adc_oneshot_unit_init_cfg_t init_config1 = {
        .unit_id = ADC_UNIT_1,
    };
    res_1 = ESP_ERROR_CHECK_WITHOUT_ABORT(adc_oneshot_new_unit(&init_config1, &adc1_handle));

    //-------------ADC1 Config---------------//
    adc_oneshot_chan_cfg_t config = {
        
        .atten = ADC_ATTEN_DB_11,
        .bitwidth = ADC_BITWIDTH_DEFAULT,
   
    };

    int io_num = std::stoi(var_PARAMS.getValue());
    adc_channel_t pinAI = static_cast<adc_channel_t>(io_num);

    res_2 = ESP_ERROR_CHECK_WITHOUT_ABORT(adc_oneshot_config_channel(adc1_handle, pinAI, &config));
    
    //-------------ADC1 Calibration Init---------------//
    adc_cali_handle_t adc1_cali_chan_handle = NULL;
    do_calibration_chan = adc_calibration_init(ADC_UNIT_1, pinAI, ADC_ATTEN_DB_2_5, &adc1_cali_chan_handle);

    if((!res_1)&&(!res_2)){
      //&&(do_calibration_chan)
      retVal = true;
    } else{
      var_STATUS = scmError;
      DEVLOG_ERROR("[FORTE_A_IN::setConfig] - Parameter error ");
    }
  return retVal;
}
/*---------------------------------------------------------------
        ADC Calibration
---------------------------------------------------------------*/
static bool adc_calibration_init(adc_unit_t unit, adc_channel_t channel, adc_atten_t atten, adc_cali_handle_t *out_handle)
{ 
    esp_err_t ret = ESP_FAIL;
    bool calibrated = false;

    if (!calibrated) {
        adc_cali_curve_fitting_config_t cali_config = {
            .unit_id = unit,
            .chan = channel,
            .atten = atten,
            .bitwidth = ADC_BITWIDTH_DEFAULT,
        };
        ret = adc_cali_create_scheme_curve_fitting(&cali_config, &handle);
        if (ret == ESP_OK) {
            calibrated = true;
        }
    }
    *out_handle = handle;
    if (ret == ESP_OK) {
         DEVLOG_ERROR("Calibration Success");
    } else if (ret == ESP_ERR_NOT_SUPPORTED || !calibrated) {
         DEVLOG_ERROR("eFuse not burnt, skip software calibration");
    } else {
         DEVLOG_ERROR("Invalid arg or no memory");
    }
    return calibrated;
}

bool FORTE_A_IN::deinitialise() {
  bool retVal = false;
    bool res_3 = ESP_ERROR_CHECK_WITHOUT_ABORT(adc_oneshot_del_unit(adc1_handle));
    if (do_calibration_chan) {
      if(!res_3 && !ESP_ERROR_CHECK_WITHOUT_ABORT(adc_cali_delete_scheme_curve_fitting(handle)));
          retVal = true; 
       }
  return retVal;
}

float FORTE_A_IN::read_adc() {
  
  int io_num = std::stoi(var_PARAMS.getValue());
  adc_channel_t pinAI = static_cast<adc_channel_t>(io_num);

  bool res_4 = ESP_ERROR_CHECK_WITHOUT_ABORT(adc_oneshot_read(adc1_handle, pinAI, &adc_raw));
  float value = 0;

  if (!res_4 && do_calibration_chan) {

        int original_max = 4095;
        float nova_min = static_cast<float>(var__MIN);
        float nova_max = static_cast<float>(var__MAX);
        float a = (nova_max - nova_min) / 4095;
        value =  a * adc_raw + nova_min;
        //value = adc_raw;
        var_STATUS = scmOK;

      } else var_STATUS = scmCouldNotRead; 

      //vTaskDelay(pdMS_TO_TICKS(1000));
      //deinitialise();
      //DEVLOG_ERROR("%f\n",value);

  return value;
}

void FORTE_A_IN::executeEvent(const TEventID paEIID, CEventChainExecutionThread *const paECET) {
  switch(paEIID) {
    case scmEventINITID:

      if (var_QI) {
        var_QO = CIEC_BOOL(initialise()); //initialise as input
      } else {
        var_QO = CIEC_BOOL(deinitialise());
      }
      sendOutputEvent(scmEventINITOID, paECET);
      break;

    case scmEventREQID:     
       if (var_QI) {
        var_IN = CIEC_REAL(read_adc());
      } else {
        var_IN = CIEC_REAL(deinitialise());
      }
      sendOutputEvent(scmEventCNFID, paECET);
      break;
  }
}

void FORTE_A_IN::readInputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventINITID: {
      readData(0, var_QI, conn_QI);
      readData(1, var_PARAMS, conn_PARAMS);
      break;
    }
    case scmEventREQID: {
      readData(0, var_QI, conn_QI);
      readData(2, var__MAX, conn__MAX);
      readData(3, var__MIN, conn__MIN);
      break;
    }
    default:
      break;
  }
}

void FORTE_A_IN::writeOutputData(const TEventID paEIID) {
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

CIEC_ANY *FORTE_A_IN::getDI(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_QI;
    case 1: return &var_PARAMS;
    case 2: return &var__MAX;
    case 3: return &var__MIN;
  }
  return nullptr;
}

CIEC_ANY *FORTE_A_IN::getDO(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_QO;
    case 1: return &var_STATUS;
    case 2: return &var_IN;
  }
  return nullptr;
}

CEventConnection *FORTE_A_IN::getEOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_INITO;
    case 1: return &conn_CNF;
  }
  return nullptr;
}

CDataConnection **FORTE_A_IN::getDIConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_QI;
    case 1: return &conn_PARAMS;
    case 2: return &conn__MAX;
    case 3: return &conn__MIN;
  }
  return nullptr;
}

CDataConnection *FORTE_A_IN::getDOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_QO;
    case 1: return &conn_STATUS;
    case 2: return &conn_IN;
  }
  return nullptr;
}

