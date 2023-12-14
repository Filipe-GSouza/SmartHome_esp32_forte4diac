/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: FIELDBUS_WORD_TO_PERCENT
 *** Description: convert a hexadecimal Percent to a REAL
 *** Version:
 ***     1.0: 2023-06-06/Franz Höpfinger - HR Agrartechnik GmbH -
 *************************************************************************/

#pragma once

#include "simplefb.h"
#include "forte_bool.h"
#include "forte_word.h"
#include "forte_real.h"
#include "iec61131_functions.h"
#include "forte_array_common.h"
#include "forte_array.h"
#include "forte_array_fixed.h"
#include "forte_array_variable.h"


class FORTE_signalprocessing__FIELDBUS_WORD_TO_PERCENT final : public CSimpleFB {
  DECLARE_FIRMWARE_FB(FORTE_signalprocessing__FIELDBUS_WORD_TO_PERCENT)

private:
  static const CStringDictionary::TStringId scmDataInputNames[];
  static const CStringDictionary::TStringId scmDataInputTypeIds[];
  static const CStringDictionary::TStringId scmDataOutputNames[];
  static const CStringDictionary::TStringId scmDataOutputTypeIds[];
  static const TEventID scmEventREQID = 0;
  static const TDataIOID scmEIWith[];
  static const TForteInt16 scmEIWithIndexes[];
  static const CStringDictionary::TStringId scmEventInputNames[];
  static const TEventID scmEventCNFID = 0;
  static const TDataIOID scmEOWith[];
  static const TForteInt16 scmEOWithIndexes[];
  static const CStringDictionary::TStringId scmEventOutputNames[];

  static const SFBInterfaceSpec scmFBInterfaceSpec;

  static const CIEC_WORD var_const_ISO_VALID_SIGNAL_W;

  CIEC_ANY *getVarInternal(size_t) override;

  void alg_REQ(void);

  void executeEvent(TEventID paEIID, CEventChainExecutionThread *const paECET) override;

  void readInputData(TEventID paEIID) override;
  void writeOutputData(TEventID paEIID) override;
  void setInitialValues() override;

public:
  FORTE_signalprocessing__FIELDBUS_WORD_TO_PERCENT(CStringDictionary::TStringId paInstanceNameId, CResource *paSrcRes);

  CIEC_BOOL var_QI;
  CIEC_WORD var_WI;

  CIEC_BOOL var_QO;
  CIEC_REAL var_RO;
  CIEC_WORD var_WO;

  CIEC_BOOL var_conn_QO;
  CIEC_REAL var_conn_RO;
  CIEC_WORD var_conn_WO;

  CEventConnection conn_CNF;

  CDataConnection *conn_QI;
  CDataConnection *conn_WI;

  CDataConnection conn_QO;
  CDataConnection conn_RO;
  CDataConnection conn_WO;

  CIEC_ANY *getDI(size_t) override;
  CIEC_ANY *getDO(size_t) override;
  CIEC_ANY *getDIO(size_t) override;
  CEventConnection *getEOConUnchecked(TPortId) override;
  CDataConnection **getDIConUnchecked(TPortId) override;
  CDataConnection *getDOConUnchecked(TPortId) override;
  CInOutDataConnection **getDIOInConUnchecked(TPortId) override;
  CInOutDataConnection *getDIOOutConUnchecked(TPortId) override;

  void evt_REQ(const CIEC_BOOL &paQI, const CIEC_WORD &paWI, CIEC_BOOL &paQO, CIEC_REAL &paRO, CIEC_WORD &paWO) {
    var_QI = paQI;
    var_WI = paWI;
    receiveInputEvent(scmEventREQID, nullptr);
    paQO = var_QO;
    paRO = var_RO;
    paWO = var_WO;
  }

  void operator()(const CIEC_BOOL &paQI, const CIEC_WORD &paWI, CIEC_BOOL &paQO, CIEC_REAL &paRO, CIEC_WORD &paWO) {
    evt_REQ(paQI, paWI, paQO, paRO, paWO);
  }
};


