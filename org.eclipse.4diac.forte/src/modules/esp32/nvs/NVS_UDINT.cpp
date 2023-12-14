/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: NVS_UDINT
 *** Description: Service Interface Function Block Type
 *** Version:
 ***     1.0: 2022-09-23/franz -  -
 *************************************************************************/

#include "NVS_UDINT.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "NVS_UDINT_gen.cpp"
#endif

#include "criticalregion.h"
#include "resource.h"

DEFINE_FIRMWARE_FB(FORTE_NVS_UDINT, g_nStringIdNVS_UDINT)

const CStringDictionary::TStringId FORTE_NVS_UDINT::scmDataInputNames[] = {g_nStringIdQI, g_nStringIdKEY, g_nStringIdVALUE};
const CStringDictionary::TStringId FORTE_NVS_UDINT::scmDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdSTRING, g_nStringIdUDINT};
const CStringDictionary::TStringId FORTE_NVS_UDINT::scmDataOutputNames[] = {g_nStringIdQO, g_nStringIdSTATUS, g_nStringIdVALUEO};
const CStringDictionary::TStringId FORTE_NVS_UDINT::scmDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdSTRING, g_nStringIdUDINT};
const TDataIOID FORTE_NVS_UDINT::scmEIWith[] = {0, 1, 2, scmWithListDelimiter, 2, scmWithListDelimiter, 2, scmWithListDelimiter};
const TForteInt16 FORTE_NVS_UDINT::scmEIWithIndexes[] = {0, 4, 6};
const CStringDictionary::TStringId FORTE_NVS_UDINT::scmEventInputNames[] = {g_nStringIdINIT, g_nStringIdSET, g_nStringIdGET};
const TDataIOID FORTE_NVS_UDINT::scmEOWith[] = {0, 1, 2, scmWithListDelimiter, 0, 1, 2, scmWithListDelimiter, 0, 1, 2, scmWithListDelimiter};
const TForteInt16 FORTE_NVS_UDINT::scmEOWithIndexes[] = {0, 4, 8};
const CStringDictionary::TStringId FORTE_NVS_UDINT::scmEventOutputNames[] = {g_nStringIdINITO, g_nStringIdSETO, g_nStringIdGETO};
const SFBInterfaceSpec FORTE_NVS_UDINT::scmFBInterfaceSpec = {
  3, scmEventInputNames, scmEIWith, scmEIWithIndexes,
  3, scmEventOutputNames, scmEOWith, scmEOWithIndexes,
  3, scmDataInputNames, scmDataInputTypeIds,
  3, scmDataOutputNames, scmDataOutputTypeIds,
  0, nullptr,
  0, nullptr
};

FORTE_NVS_UDINT::FORTE_NVS_UDINT(const CStringDictionary::TStringId paInstanceNameId, CResource *const paSrcRes) :
	CNVSFunctionBlock(paSrcRes, &scmFBInterfaceSpec, paInstanceNameId),
    var_conn_QO(var_QO),
    var_conn_STATUS(var_STATUS),
    var_conn_VALUEO(var_VALUEO),
    conn_INITO(this, 0),
    conn_SETO(this, 1),
    conn_GETO(this, 2),
    conn_QI(nullptr),
    conn_KEY(nullptr),
    conn_VALUE(nullptr),
    conn_QO(this, 0, &var_conn_QO),
    conn_STATUS(this, 1, &var_conn_STATUS),
    conn_VALUEO(this, 2, &var_conn_VALUEO) {
};

void FORTE_NVS_UDINT::setInitialValues() {
  var_QI = 0_BOOL;
  var_KEY = ""_STRING;
  var_VALUE = 0_UDINT;
  var_QO = 0_BOOL;
  var_STATUS = ""_STRING;
  var_VALUEO = 0_UDINT;
}

void FORTE_NVS_UDINT::executeEvent(const TEventID paEIID, CEventChainExecutionThread *const paECET) {
  switch(paEIID) {
    case scmEventINITID:
      key = var_KEY.c_str();
      executeInit();
      var_STATUS = scmInitialised;
      var_QO = var_QI;
      sendOutputEvent(scmEventINITOID);

      break;
    case scmEventSETID:
      executeSet();
      sendOutputEvent(scmEventSETOID);

      break;
    case scmEventGETID:
      executeGet();
      sendOutputEvent(scmEventGETOID);
      break;
  }
}

void FORTE_NVS_UDINT::readInputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventINITID: {
      RES_DATA_CON_CRITICAL_REGION();
      readData(0, var_QI, conn_QI);
      readData(1, var_KEY, conn_KEY);
      readData(2, var_VALUE, conn_VALUE);
      break;
    }
    case scmEventSETID: {
      RES_DATA_CON_CRITICAL_REGION();
      readData(2, var_VALUE, conn_VALUE);
      break;
    }
    case scmEventGETID: {
      RES_DATA_CON_CRITICAL_REGION();
      readData(2, var_VALUE, conn_VALUE);
      break;
    }
    default:
      break;
  }
}

void FORTE_NVS_UDINT::writeOutputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventINITOID: {
      RES_DATA_CON_CRITICAL_REGION();
      writeData(0, var_QO, conn_QO);
      writeData(1, var_STATUS, conn_STATUS);
      writeData(2, var_VALUEO, conn_VALUEO);
      break;
    }
    case scmEventSETOID: {
      RES_DATA_CON_CRITICAL_REGION();
      writeData(0, var_QO, conn_QO);
      writeData(1, var_STATUS, conn_STATUS);
      writeData(2, var_VALUEO, conn_VALUEO);
      break;
    }
    case scmEventGETOID: {
      RES_DATA_CON_CRITICAL_REGION();
      writeData(0, var_QO, conn_QO);
      writeData(1, var_STATUS, conn_STATUS);
      writeData(2, var_VALUEO, conn_VALUEO);
      break;
    }
    default:
      break;
  }
}

CIEC_ANY *FORTE_NVS_UDINT::getDI(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_QI;
    case 1: return &var_KEY;
    case 2: return &var_VALUE;
  }
  return nullptr;
}

CIEC_ANY *FORTE_NVS_UDINT::getDO(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_QO;
    case 1: return &var_STATUS;
    case 2: return &var_VALUEO;
  }
  return nullptr;
}

CIEC_ANY *FORTE_NVS_UDINT::getDIO(size_t) {
  return nullptr;
}

CEventConnection *FORTE_NVS_UDINT::getEOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_INITO;
    case 1: return &conn_SETO;
    case 2: return &conn_GETO;
  }
  return nullptr;
}

CDataConnection **FORTE_NVS_UDINT::getDIConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_QI;
    case 1: return &conn_KEY;
    case 2: return &conn_VALUE;
  }
  return nullptr;
}

CDataConnection *FORTE_NVS_UDINT::getDOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_QO;
    case 1: return &conn_STATUS;
    case 2: return &conn_VALUEO;
  }
  return nullptr;
}

CInOutDataConnection **FORTE_NVS_UDINT::getDIOInConUnchecked(TPortId) {
  return nullptr;
}

CInOutDataConnection *FORTE_NVS_UDINT::getDIOOutConUnchecked(TPortId) {
  return nullptr;
}

void FORTE_NVS_UDINT::executeSet() {
  esp_err_t err = ESP_FAIL;
  err = handle->set_item(key, (uint32_t)var_VALUE);
  switch (err) {
    case ESP_OK:
      var_VALUEO = var_VALUE;
      var_STATUS = scmOK;
      break;
    default :
      var_STATUS = scmERR;
      break;
  }
}

void FORTE_NVS_UDINT::executeGet() {
  esp_err_t err = ESP_FAIL;
  uint32_t value_out;
  err = handle->get_item(key, value_out);
  switch (err) {
    case ESP_OK:
      var_VALUEO = static_cast<CIEC_UDINT>(value_out);
      var_STATUS = scmOK;
      break;
    case ESP_ERR_NVS_NOT_FOUND:
      var_STATUS = scmERR_NVS_NOT_FOUND;
      break;
    default :
      var_STATUS = scmERR;
      break;
  }
}

