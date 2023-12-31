/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: E_SR_RETRIG
 *** Description: Event-driven bistable
 *** Version:
 ***     1.0: 2017-09-22/Alois Zoitl - fortiss GmbH - initial API and implementation and/or initial documentation
 *************************************************************************/

#pragma once

#include "basicfb.h"
#include "forte_bool.h"
#include "iec61131_functions.h"
#include "forte_array_common.h"
#include "forte_array.h"
#include "forte_array_fixed.h"
#include "forte_array_variable.h"


class FORTE_E_SR_RETRIG final : public CBasicFB {
  DECLARE_FIRMWARE_FB(FORTE_E_SR_RETRIG)

private:
  static const CStringDictionary::TStringId scmDataOutputNames[];
  static const CStringDictionary::TStringId scmDataOutputTypeIds[];
  static const TEventID scmEventSID = 0;
  static const TEventID scmEventRID = 1;
  static const TForteInt16 scmEIWithIndexes[];
  static const CStringDictionary::TStringId scmEventInputNames[];
  static const TEventID scmEventEOID = 0;
  static const TDataIOID scmEOWith[];
  static const TForteInt16 scmEOWithIndexes[];
  static const CStringDictionary::TStringId scmEventOutputNames[];

  static const SFBInterfaceSpec scmFBInterfaceSpec;

  CIEC_ANY *getVarInternal(size_t) override;

  void alg_SET(void);
  void alg_RESET(void);

  static const TForteInt16 scmStateSTART = 0;
  static const TForteInt16 scmStateSET = 1;
  static const TForteInt16 scmStateRESET = 2;

  void enterStateSTART(CEventChainExecutionThread *const paECET);
  void enterStateSET(CEventChainExecutionThread *const paECET);
  void enterStateRESET(CEventChainExecutionThread *const paECET);

  void executeEvent(TEventID paEIID, CEventChainExecutionThread *const paECET) override;

  void readInputData(TEventID paEIID) override;
  void writeOutputData(TEventID paEIID) override;
  void setInitialValues() override;

public:
  FORTE_E_SR_RETRIG(CStringDictionary::TStringId paInstanceNameId, CResource *paSrcRes);

  CIEC_BOOL var_Q;

  CIEC_BOOL var_conn_Q;

  CEventConnection conn_EO;

  CDataConnection conn_Q;

  CIEC_ANY *getDI(size_t) override;
  CIEC_ANY *getDO(size_t) override;
  CIEC_ANY *getDIO(size_t) override;
  CEventConnection *getEOConUnchecked(TPortId) override;
  CDataConnection **getDIConUnchecked(TPortId) override;
  CDataConnection *getDOConUnchecked(TPortId) override;
  CInOutDataConnection **getDIOInConUnchecked(TPortId) override;
  CInOutDataConnection *getDIOOutConUnchecked(TPortId) override;

  void evt_S(CIEC_BOOL &paQ) {
    receiveInputEvent(scmEventSID, nullptr);
    paQ = var_Q;
  }

  void evt_R(CIEC_BOOL &paQ) {
    receiveInputEvent(scmEventRID, nullptr);
    paQ = var_Q;
  }

  void operator()(CIEC_BOOL &paQ) {
    evt_S(paQ);
  }
};


