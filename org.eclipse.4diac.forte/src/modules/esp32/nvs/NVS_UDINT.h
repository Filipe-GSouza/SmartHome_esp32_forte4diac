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

#pragma once

#include "CNVSFunctionBlock.h"
#include "forte_bool.h"
#include "forte_string.h"
#include "forte_udint.h"
#include "iec61131_functions.h"
#include "forte_array_common.h"
#include "forte_array.h"
#include "forte_array_fixed.h"
#include "forte_array_variable.h"




#include "nvs_flash.h"
#include "nvs.h"
#include "nvs_handle.hpp"



class FORTE_NVS_UDINT final : public CNVSFunctionBlock {
  DECLARE_FIRMWARE_FB(FORTE_NVS_UDINT)

private:
  static const CStringDictionary::TStringId scmDataInputNames[];
  static const CStringDictionary::TStringId scmDataInputTypeIds[];
  static const CStringDictionary::TStringId scmDataOutputNames[];
  static const CStringDictionary::TStringId scmDataOutputTypeIds[];
  static const TEventID scmEventINITID = 0;
  static const TEventID scmEventSETID = 1;
  static const TEventID scmEventGETID = 2;
  static const TDataIOID scmEIWith[];
  static const TForteInt16 scmEIWithIndexes[];
  static const CStringDictionary::TStringId scmEventInputNames[];
  static const TEventID scmEventINITOID = 0;
  static const TEventID scmEventSETOID = 1;
  static const TEventID scmEventGETOID = 2;
  static const TDataIOID scmEOWith[];
  static const TForteInt16 scmEOWithIndexes[];
  static const CStringDictionary::TStringId scmEventOutputNames[];

  static const SFBInterfaceSpec scmFBInterfaceSpec;

  void executeEvent(TEventID paEIID, CEventChainExecutionThread *const paECET) override;
  void executeSet();
  void executeGet();

  void readInputData(TEventID paEIID) override;
  void writeOutputData(TEventID paEIID) override;
  void setInitialValues() override;

public:
  FORTE_NVS_UDINT(CStringDictionary::TStringId paInstanceNameId, CResource *paSrcRes);

  CIEC_BOOL var_QI;
  CIEC_STRING var_KEY;
  CIEC_UDINT var_VALUE;

  CIEC_BOOL var_QO;
  CIEC_STRING var_STATUS;
  CIEC_UDINT var_VALUEO;

  CIEC_BOOL var_conn_QO;
  CIEC_STRING var_conn_STATUS;
  CIEC_UDINT var_conn_VALUEO;

  CEventConnection conn_INITO;
  CEventConnection conn_SETO;
  CEventConnection conn_GETO;

  CDataConnection *conn_QI;
  CDataConnection *conn_KEY;
  CDataConnection *conn_VALUE;

  CDataConnection conn_QO;
  CDataConnection conn_STATUS;
  CDataConnection conn_VALUEO;

  CIEC_ANY *getDI(size_t) override;
  CIEC_ANY *getDO(size_t) override;
  CIEC_ANY *getDIO(size_t) override;
  CEventConnection *getEOConUnchecked(TPortId) override;
  CDataConnection **getDIConUnchecked(TPortId) override;
  CDataConnection *getDOConUnchecked(TPortId) override;
  CInOutDataConnection **getDIOInConUnchecked(TPortId) override;
  CInOutDataConnection *getDIOOutConUnchecked(TPortId) override;

  void evt_INIT(const CIEC_BOOL &paQI, const CIEC_STRING &paKEY, const CIEC_UDINT &paVALUE, CIEC_BOOL &paQO, CIEC_STRING &paSTATUS, CIEC_UDINT &paVALUEO) {
    var_QI = paQI;
    var_KEY = paKEY;
    var_VALUE = paVALUE;
    receiveInputEvent(scmEventINITID, nullptr);
    paQO = var_QO;
    paSTATUS = var_STATUS;
    paVALUEO = var_VALUEO;
  }

  void evt_SET(const CIEC_BOOL &paQI, const CIEC_STRING &paKEY, const CIEC_UDINT &paVALUE, CIEC_BOOL &paQO, CIEC_STRING &paSTATUS, CIEC_UDINT &paVALUEO) {
    var_QI = paQI;
    var_KEY = paKEY;
    var_VALUE = paVALUE;
    receiveInputEvent(scmEventSETID, nullptr);
    paQO = var_QO;
    paSTATUS = var_STATUS;
    paVALUEO = var_VALUEO;
  }

  void evt_GET(const CIEC_BOOL &paQI, const CIEC_STRING &paKEY, const CIEC_UDINT &paVALUE, CIEC_BOOL &paQO, CIEC_STRING &paSTATUS, CIEC_UDINT &paVALUEO) {
    var_QI = paQI;
    var_KEY = paKEY;
    var_VALUE = paVALUE;
    receiveInputEvent(scmEventGETID, nullptr);
    paQO = var_QO;
    paSTATUS = var_STATUS;
    paVALUEO = var_VALUEO;
  }

  void operator()(const CIEC_BOOL &paQI, const CIEC_STRING &paKEY, const CIEC_UDINT &paVALUE, CIEC_BOOL &paQO, CIEC_STRING &paSTATUS, CIEC_UDINT &paVALUEO) {
    evt_INIT(paQI, paKEY, paVALUE, paQO, paSTATUS, paVALUEO);
  }
};


