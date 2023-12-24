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

#pragma once

#include "funcbloc.h"
#include "forte_bool.h"
#include "forte_wstring.h"
#include "forte_uint.h"
#include "forte_real.h"
#include "iec61131_functions.h"
#include "forte_array_common.h"
#include "forte_array.h"
#include "forte_array_fixed.h"
#include "forte_array_variable.h"

#define LEDC_MODE     LEDC_LOW_SPEED_MODE


class FORTE_A_OUT final : public CFunctionBlock {
  DECLARE_FIRMWARE_FB(FORTE_A_OUT)

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

    void executeEvent(TEventID paEIID, CEventChainExecutionThread *const paECET) override;

    void readInputData(TEventID paEIID) override;
    void writeOutputData(TEventID paEIID) override;
    void setInitialValues() override;
    
    void write_pwm();
    bool initialise();
    
  public:
    FORTE_A_OUT(CStringDictionary::TStringId paInstanceNameId, CResource *paSrcRes);

    CIEC_BOOL var_QI;
    CIEC_WSTRING var_PARAMS;
    CIEC_UINT var_FREQ;
    CIEC_REAL var_OUTPUT;

    CIEC_BOOL var_QO;
    CIEC_WSTRING var_STATUS;

    CIEC_BOOL var_conn_QO;
    CIEC_WSTRING var_conn_STATUS;

    CEventConnection conn_INITO;
    CEventConnection conn_CNF;

    CDataConnection *conn_QI;
    CDataConnection *conn_PARAMS;
    CDataConnection *conn_FREQ;
    CDataConnection *conn_OUTPUT;

    CDataConnection conn_QO;
    CDataConnection conn_STATUS;

    CIEC_ANY *getDI(size_t) override;
    CIEC_ANY *getDO(size_t) override;
    CEventConnection *getEOConUnchecked(TPortId) override;
    CDataConnection **getDIConUnchecked(TPortId) override;
    CDataConnection *getDOConUnchecked(TPortId) override;

    void evt_INIT(const CIEC_BOOL &paQI, const CIEC_WSTRING &paPARAMS, const CIEC_UINT &paFREQ, const CIEC_REAL &paOUTPUT, CIEC_BOOL &paQO, CIEC_WSTRING &paSTATUS) {
      var_QI = paQI;
      var_PARAMS = paPARAMS;
      var_FREQ = paFREQ;
      var_OUTPUT = paOUTPUT;
      executeEvent(scmEventINITID, nullptr);
      paQO = var_QO;
      paSTATUS = var_STATUS;
    }

    void evt_REQ(const CIEC_BOOL &paQI, const CIEC_WSTRING &paPARAMS, const CIEC_UINT &paFREQ, const CIEC_REAL &paOUTPUT, CIEC_BOOL &paQO, CIEC_WSTRING &paSTATUS) {
      var_QI = paQI;
      var_PARAMS = paPARAMS;
      var_FREQ = paFREQ;
      var_OUTPUT = paOUTPUT;
      executeEvent(scmEventREQID, nullptr);
      paQO = var_QO;
      paSTATUS = var_STATUS;
    }

    void operator()(const CIEC_BOOL &paQI, const CIEC_WSTRING &paPARAMS, const CIEC_UINT &paFREQ, const CIEC_REAL &paOUTPUT, CIEC_BOOL &paQO, CIEC_WSTRING &paSTATUS) {
      evt_INIT(paQI, paPARAMS, paFREQ, paOUTPUT, paQO, paSTATUS);
    }
};


