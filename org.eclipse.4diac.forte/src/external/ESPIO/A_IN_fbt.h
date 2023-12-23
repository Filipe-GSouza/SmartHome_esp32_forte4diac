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

#pragma once

#include "funcbloc.h"
#include "forte_bool.h"
#include "forte_wstring.h"
#include "forte_real.h"
#include "iec61131_functions.h"
#include "forte_array_common.h"
#include "forte_array.h"
#include "forte_array_fixed.h"
#include "forte_array_variable.h"


class FORTE_A_IN final : public CFunctionBlock {
  DECLARE_FIRMWARE_FB(FORTE_A_IN)

  private:
    static const CStringDictionary::TStringId scmDataInputNames[];
    static const CStringDictionary::TStringId scmDataInputTypeIds[];
    static const CStringDictionary::TStringId scmDataOutputNames[];
    static const CStringDictionary::TStringId scmDataOutputTypeIds[];
    static const TEventID scmEventINITID = 0;
    static const TEventID scmEventREQID = 1;
    static const TDataIOID scmEIWith[];
    static const TForteInt16 scmEIWithIndexes[];
    static const CStringDictionary::TStringId scmEventInputNames[];
    static const TEventID scmEventINITOID = 0;
    static const TEventID scmEventCNFID = 1;
    static const TDataIOID scmEOWith[];
    static const TForteInt16 scmEOWithIndexes[];
    static const CStringDictionary::TStringId scmEventOutputNames[];

    static const SFBInterfaceSpec scmFBInterfaceSpec;
    
    static const CIEC_WSTRING scmOK;
    static const CIEC_WSTRING scmCouldNotWrite;
    static const CIEC_WSTRING scmCouldNotRead;
    static const CIEC_WSTRING scmError;
    static const CIEC_WSTRING scmNotInitialised;
    static const CIEC_WSTRING scmPinInUse;

    void executeEvent(TEventID paEIID, CEventChainExecutionThread *const paECET) override;

    void readInputData(TEventID paEIID) override;
    void writeOutputData(TEventID paEIID) override;
    void setInitialValues() override;

    bool initialise();
    bool deinitialise();
    float read_adc();

  public:
    FORTE_A_IN(CStringDictionary::TStringId paInstanceNameId, CResource *paSrcRes);

    CIEC_BOOL var_QI;
    CIEC_WSTRING var_PARAMS;
    CIEC_REAL var__MAX;
    CIEC_REAL var__MIN;

    CIEC_BOOL var_QO;
    CIEC_WSTRING var_STATUS;
    CIEC_REAL var_IN;

    CIEC_BOOL var_conn_QO;
    CIEC_WSTRING var_conn_STATUS;
    CIEC_REAL var_conn_IN;

    CEventConnection conn_INITO;
    CEventConnection conn_CNF;

    CDataConnection *conn_QI;
    CDataConnection *conn_PARAMS;
    CDataConnection *conn__MAX;
    CDataConnection *conn__MIN;

    CDataConnection conn_QO;
    CDataConnection conn_STATUS;
    CDataConnection conn_IN;

    CIEC_ANY *getDI(size_t) override;
    CIEC_ANY *getDO(size_t) override;
    CEventConnection *getEOConUnchecked(TPortId) override;
    CDataConnection **getDIConUnchecked(TPortId) override;
    CDataConnection *getDOConUnchecked(TPortId) override;

    void evt_INIT(const CIEC_BOOL &paQI, const CIEC_WSTRING &paPARAMS, const CIEC_REAL &pa_MAX, const CIEC_REAL &pa_MIN, CIEC_BOOL &paQO, CIEC_WSTRING &paSTATUS, CIEC_REAL &paIN) {
      var_QI = paQI;
      var_PARAMS = paPARAMS;
      var__MAX = pa_MAX;
      var__MIN = pa_MIN;
      executeEvent(scmEventINITID, nullptr);
      paQO = var_QO;
      paSTATUS = var_STATUS;
      paIN = var_IN;
    }

    void evt_REQ(const CIEC_BOOL &paQI, const CIEC_WSTRING &paPARAMS, const CIEC_REAL &pa_MAX, const CIEC_REAL &pa_MIN, CIEC_BOOL &paQO, CIEC_WSTRING &paSTATUS, CIEC_REAL &paIN) {
      var_QI = paQI;
      var_PARAMS = paPARAMS;
      var__MAX = pa_MAX;
      var__MIN = pa_MIN;
      executeEvent(scmEventREQID, nullptr);
      paQO = var_QO;
      paSTATUS = var_STATUS;
      paIN = var_IN;
    }

    void operator()(const CIEC_BOOL &paQI, const CIEC_WSTRING &paPARAMS, const CIEC_REAL &pa_MAX, const CIEC_REAL &pa_MIN, CIEC_BOOL &paQO, CIEC_WSTRING &paSTATUS, CIEC_REAL &paIN) {
      evt_INIT(paQI, paPARAMS, pa_MAX, pa_MIN, paQO, paSTATUS, paIN);
    }
};


