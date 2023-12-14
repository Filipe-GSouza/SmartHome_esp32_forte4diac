/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x NG!
 ***
 *** Name: strip_set_pixel
 *** Description: Service Interface Function Block Type
 *** Version:
 ***     1.0: 2022-07-16/franz -  -
 *************************************************************************/

#pragma once

#include "funcbloc.h"
#include "forte_udint.h"
#include "forte_dint.h"
#include "iec61131_functions.h"
#include "forte_array_common.h"
#include "forte_array.h"
#include "forte_array_fixed.h"
#include "forte_array_variable.h"


class FORTE_strip_set_pixel final : public CFunctionBlock {
  DECLARE_FIRMWARE_FB(FORTE_strip_set_pixel)

private:
  static const CStringDictionary::TStringId scmDataInputNames[];
  static const CStringDictionary::TStringId scmDataInputTypeIds[];
  static const CStringDictionary::TStringId scmDataOutputNames[];
  static const CStringDictionary::TStringId scmDataOutputTypeIds[];
  static const TEventID scmEventINITID = 0;
  static const TEventID scmEventset_pixelID = 1;
  static const TEventID scmEventclearID = 2;
  static const TDataIOID scmEIWith[];
  static const TForteInt16 scmEIWithIndexes[];
  static const CStringDictionary::TStringId scmEventInputNames[];
  static const TEventID scmEventINITOID = 0;
  static const TEventID scmEventset_pixel_CNFID = 1;
  static const TEventID scmEventclear_CNFID = 2;
  static const TDataIOID scmEOWith[];
  static const TForteInt16 scmEOWithIndexes[];
  static const CStringDictionary::TStringId scmEventOutputNames[];

  static const SFBInterfaceSpec scmFBInterfaceSpec;

  void executeEvent(TEventID paEIID, CEventChainExecutionThread *const paECET) override;
  void initStrip();
  void setPixel();
  void clear();

  // Internal implementation class
  class Impl;
  
  void readInputData(TEventID paEIID) override;
  void writeOutputData(TEventID paEIID) override;
  void setInitialValues() override;

public:
  FORTE_strip_set_pixel(CStringDictionary::TStringId paInstanceNameId, CResource *paSrcRes);

  CIEC_UDINT var_index;
  CIEC_UDINT var_red;
  CIEC_UDINT var_green;
  CIEC_UDINT var_blue;

  CIEC_DINT var_set_pixel_return;
  CIEC_DINT var_clear_return;

  CIEC_DINT var_conn_set_pixel_return;
  CIEC_DINT var_conn_clear_return;

  CEventConnection conn_INITO;
  CEventConnection conn_set_pixel_CNF;
  CEventConnection conn_clear_CNF;

  CDataConnection *conn_index;
  CDataConnection *conn_red;
  CDataConnection *conn_green;
  CDataConnection *conn_blue;

  CDataConnection conn_set_pixel_return;
  CDataConnection conn_clear_return;

  CIEC_ANY *getDI(size_t) override;
  CIEC_ANY *getDO(size_t) override;
  CIEC_ANY *getDIO(size_t) override;
  CEventConnection *getEOConUnchecked(TPortId) override;
  CDataConnection **getDIConUnchecked(TPortId) override;
  CDataConnection *getDOConUnchecked(TPortId) override;
  CInOutDataConnection **getDIOInConUnchecked(TPortId) override;
  CInOutDataConnection *getDIOOutConUnchecked(TPortId) override;

  void evt_INIT(const CIEC_UDINT &paindex, const CIEC_UDINT &pared, const CIEC_UDINT &pagreen, const CIEC_UDINT &pablue, CIEC_DINT &paset_pixel_return, CIEC_DINT &paclear_return) {
    var_index = paindex;
    var_red = pared;
    var_green = pagreen;
    var_blue = pablue;
    receiveInputEvent(scmEventINITID, nullptr);
    paset_pixel_return = var_set_pixel_return;
    paclear_return = var_clear_return;
  }

  void evt_set_pixel(const CIEC_UDINT &paindex, const CIEC_UDINT &pared, const CIEC_UDINT &pagreen, const CIEC_UDINT &pablue, CIEC_DINT &paset_pixel_return, CIEC_DINT &paclear_return) {
    var_index = paindex;
    var_red = pared;
    var_green = pagreen;
    var_blue = pablue;
    receiveInputEvent(scmEventset_pixelID, nullptr);
    paset_pixel_return = var_set_pixel_return;
    paclear_return = var_clear_return;
  }

  void evt_clear(const CIEC_UDINT &paindex, const CIEC_UDINT &pared, const CIEC_UDINT &pagreen, const CIEC_UDINT &pablue, CIEC_DINT &paset_pixel_return, CIEC_DINT &paclear_return) {
    var_index = paindex;
    var_red = pared;
    var_green = pagreen;
    var_blue = pablue;
    receiveInputEvent(scmEventclearID, nullptr);
    paset_pixel_return = var_set_pixel_return;
    paclear_return = var_clear_return;
  }

  void operator()(const CIEC_UDINT &paindex, const CIEC_UDINT &pared, const CIEC_UDINT &pagreen, const CIEC_UDINT &pablue, CIEC_DINT &paset_pixel_return, CIEC_DINT &paclear_return) {
    evt_INIT(paindex, pared, pagreen, pablue, paset_pixel_return, paclear_return);
  }
};


