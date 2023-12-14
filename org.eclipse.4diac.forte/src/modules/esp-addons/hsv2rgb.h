/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: hsv2rgb
 *** Description: Simple helper function, converting HSV color space to RGB color space
 *** Version:
 ***     1.0: 2022-07-16/franz -  -
 *************************************************************************/

#pragma once

#include "funcbloc.h"
#include "forte_udint.h"
#include "iec61131_functions.h"
#include "forte_array_common.h"
#include "forte_array.h"
#include "forte_array_fixed.h"
#include "forte_array_variable.h"


class FORTE_hsv2rgb final : public CFunctionBlock {
  DECLARE_FIRMWARE_FB(FORTE_hsv2rgb)

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

  void executeEvent(TEventID paEIID, CEventChainExecutionThread *const paECET) override;

  void readInputData(TEventID paEIID) override;
  void writeOutputData(TEventID paEIID) override;
  void setInitialValues() override;

public:
  FORTE_hsv2rgb(CStringDictionary::TStringId paInstanceNameId, CResource *paSrcRes);

  CIEC_UDINT var_hue;
  CIEC_UDINT var_saturation;
  CIEC_UDINT var_value;

  CIEC_UDINT var_r;
  CIEC_UDINT var_g;
  CIEC_UDINT var_b;

  CIEC_UDINT var_conn_r;
  CIEC_UDINT var_conn_g;
  CIEC_UDINT var_conn_b;

  CEventConnection conn_CNF;

  CDataConnection *conn_hue;
  CDataConnection *conn_saturation;
  CDataConnection *conn_value;

  CDataConnection conn_r;
  CDataConnection conn_g;
  CDataConnection conn_b;

  CIEC_ANY *getDI(size_t) override;
  CIEC_ANY *getDO(size_t) override;
  CIEC_ANY *getDIO(size_t) override;
  CEventConnection *getEOConUnchecked(TPortId) override;
  CDataConnection **getDIConUnchecked(TPortId) override;
  CDataConnection *getDOConUnchecked(TPortId) override;
  CInOutDataConnection **getDIOInConUnchecked(TPortId) override;
  CInOutDataConnection *getDIOOutConUnchecked(TPortId) override;

  void evt_REQ(const CIEC_UDINT &pahue, const CIEC_UDINT &pasaturation, const CIEC_UDINT &pavalue, CIEC_UDINT &par, CIEC_UDINT &pag, CIEC_UDINT &pab) {
    var_hue = pahue;
    var_saturation = pasaturation;
    var_value = pavalue;
    receiveInputEvent(scmEventREQID, nullptr);
    par = var_r;
    pag = var_g;
    pab = var_b;
  }

  void operator()(const CIEC_UDINT &pahue, const CIEC_UDINT &pasaturation, const CIEC_UDINT &pavalue, CIEC_UDINT &par, CIEC_UDINT &pag, CIEC_UDINT &pab) {
    evt_REQ(pahue, pasaturation, pavalue, par, pag, pab);
  }
};


