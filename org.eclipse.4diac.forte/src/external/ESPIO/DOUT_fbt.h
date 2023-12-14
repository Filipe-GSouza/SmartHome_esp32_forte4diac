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

#pragma once

#include "basicfb.h"
#include "forte_udint.h"
#include "forte_bool.h"
#include "iec61131_functions.h"
#include "forte_array_common.h"
#include "forte_array.h"
#include "forte_array_fixed.h"
#include "forte_array_variable.h"


class FORTE_DOUT final : public CBasicFB {
  DECLARE_FIRMWARE_FB(FORTE_DOUT)

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

    CIEC_ANY *getVarInternal(size_t) override;

    void alg_initialize(void);
    void alg_deInitialize(void);
    void alg_normalOperation(void);

    static const TForteInt16 scmStateSTART = 0;
    static const TForteInt16 scmStateInit = 1;
    static const TForteInt16 scmStateNormalOp = 2;
    static const TForteInt16 scmStateInitialized = 3;
    static const TForteInt16 scmStateDeInit = 4;

    void enterStateSTART(CEventChainExecutionThread *const paECET);
    void enterStateInit(CEventChainExecutionThread *const paECET);
    void enterStateNormalOp(CEventChainExecutionThread *const paECET);
    void enterStateInitialized(CEventChainExecutionThread *const paECET);
    void enterStateDeInit(CEventChainExecutionThread *const paECET);

    void executeEvent(TEventID paEIID, CEventChainExecutionThread *const paECET) override;

    void readInputData(TEventID paEIID) override;
    void writeOutputData(TEventID paEIID) override;
    void setInitialValues() override;

  public:
    FORTE_DOUT(CStringDictionary::TStringId paInstanceNameId, CResource *paSrcRes);

    CIEC_UDINT var_CHNL;
    CIEC_BOOL var_STATUS;

    CIEC_BOOL var_QO;

    CIEC_BOOL var_conn_QO;

    CEventConnection conn_INITO;
    CEventConnection conn_CNF;

    CDataConnection *conn_CHNL;
    CDataConnection *conn_STATUS;

    CDataConnection conn_QO;

    CIEC_ANY *getDI(size_t) override;
    CIEC_ANY *getDO(size_t) override;
    CEventConnection *getEOConUnchecked(TPortId) override;
    CDataConnection **getDIConUnchecked(TPortId) override;
    CDataConnection *getDOConUnchecked(TPortId) override;

    void evt_INIT(const CIEC_UDINT &paCHNL, const CIEC_BOOL &paSTATUS, CIEC_BOOL &paQO) {
      var_CHNL = paCHNL;
      var_STATUS = paSTATUS;
      executeEvent(scmEventINITID, nullptr);
      paQO = var_QO;
    }

    void evt_REQ(const CIEC_UDINT &paCHNL, const CIEC_BOOL &paSTATUS, CIEC_BOOL &paQO) {
      var_CHNL = paCHNL;
      var_STATUS = paSTATUS;
      executeEvent(scmEventREQID, nullptr);
      paQO = var_QO;
    }

    void operator()(const CIEC_UDINT &paCHNL, const CIEC_BOOL &paSTATUS, CIEC_BOOL &paQO) {
      evt_INIT(paCHNL, paSTATUS, paQO);
    }
};


