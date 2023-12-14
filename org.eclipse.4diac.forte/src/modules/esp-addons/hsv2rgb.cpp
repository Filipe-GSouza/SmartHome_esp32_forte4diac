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

#include "hsv2rgb.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "hsv2rgb_gen.cpp"
#endif

#include "criticalregion.h"
#include "resource.h"

DEFINE_FIRMWARE_FB(FORTE_hsv2rgb, g_nStringIdhsv2rgb)

const CStringDictionary::TStringId FORTE_hsv2rgb::scmDataInputNames[] = {g_nStringIdhue, g_nStringIdsaturation, g_nStringIdvalue};
const CStringDictionary::TStringId FORTE_hsv2rgb::scmDataInputTypeIds[] = {g_nStringIdUDINT, g_nStringIdUDINT, g_nStringIdUDINT};
const CStringDictionary::TStringId FORTE_hsv2rgb::scmDataOutputNames[] = {g_nStringIdr, g_nStringIdg, g_nStringIdb};
const CStringDictionary::TStringId FORTE_hsv2rgb::scmDataOutputTypeIds[] = {g_nStringIdUDINT, g_nStringIdUDINT, g_nStringIdUDINT};
const TDataIOID FORTE_hsv2rgb::scmEIWith[] = {0, 1, 2, scmWithListDelimiter};
const TForteInt16 FORTE_hsv2rgb::scmEIWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_hsv2rgb::scmEventInputNames[] = {g_nStringIdREQ};
const TDataIOID FORTE_hsv2rgb::scmEOWith[] = {0, 1, 2, scmWithListDelimiter};
const TForteInt16 FORTE_hsv2rgb::scmEOWithIndexes[] = {0};
const CStringDictionary::TStringId FORTE_hsv2rgb::scmEventOutputNames[] = {g_nStringIdCNF};
const SFBInterfaceSpec FORTE_hsv2rgb::scmFBInterfaceSpec = {
  1, scmEventInputNames, scmEIWith, scmEIWithIndexes,
  1, scmEventOutputNames, scmEOWith, scmEOWithIndexes,
  3, scmDataInputNames, scmDataInputTypeIds,
  3, scmDataOutputNames, scmDataOutputTypeIds,
  0, nullptr,
  0, nullptr
};

FORTE_hsv2rgb::FORTE_hsv2rgb(const CStringDictionary::TStringId paInstanceNameId, CResource *const paSrcRes) :
    CFunctionBlock(paSrcRes, &scmFBInterfaceSpec, paInstanceNameId),
    var_conn_r(var_r),
    var_conn_g(var_g),
    var_conn_b(var_b),
    conn_CNF(this, 0),
    conn_hue(nullptr),
    conn_saturation(nullptr),
    conn_value(nullptr),
    conn_r(this, 0, &var_conn_r),
    conn_g(this, 1, &var_conn_g),
    conn_b(this, 2, &var_conn_b) {
};

void FORTE_hsv2rgb::setInitialValues() {
  var_hue = 0_UDINT;
  var_saturation = 0_UDINT;
  var_value = 0_UDINT;
  var_r = 0_UDINT;
  var_g = 0_UDINT;
  var_b = 0_UDINT;
}

/**
 * @brief Simple helper function, converting HSV color space to RGB color space
 *
 * Wiki: https://en.wikipedia.org/wiki/HSL_and_HSV
 *
 */
void FORTE_hsv2rgb::executeEvent(const TEventID paEIID, CEventChainExecutionThread *const paECET) {
  switch(paEIID) {
    case scmEventREQID:
      uint32_t h = static_cast<uint32_t>(var_hue) % 360; // h -> [0,360]
      uint32_t rgb_max = static_cast<uint32_t>(var_value) * 2.55f;
      uint32_t rgb_min = rgb_max * (100 - static_cast<uint32_t>(var_saturation)) / 100.0f;

      uint32_t i = h / 60;
      uint32_t diff = h % 60;

      // RGB adjustment amount by hue
      uint32_t rgb_adj = (rgb_max - rgb_min) * diff / 60;

      switch (i) {
      case 0:
          var_r = static_cast<CIEC_UDINT>(rgb_max);
          var_g = static_cast<CIEC_UDINT>(rgb_min + rgb_adj);
          var_b = static_cast<CIEC_UDINT>(rgb_min);
          break;
      case 1:
          var_r = static_cast<CIEC_UDINT>(rgb_max - rgb_adj);
          var_g = static_cast<CIEC_UDINT>(rgb_max);
          var_b = static_cast<CIEC_UDINT>(rgb_min);
          break;
      case 2:
          var_r = static_cast<CIEC_UDINT>(rgb_min);
          var_g = static_cast<CIEC_UDINT>(rgb_max);
          var_b = static_cast<CIEC_UDINT>(rgb_min + rgb_adj);
          break;
      case 3:
          var_r = static_cast<CIEC_UDINT>(rgb_min);
          var_g = static_cast<CIEC_UDINT>(rgb_max - rgb_adj);
          var_b = static_cast<CIEC_UDINT>(rgb_max);
          break;
      case 4:
          var_r = static_cast<CIEC_UDINT>(rgb_min + rgb_adj);
          var_g = static_cast<CIEC_UDINT>(rgb_min);
          var_b = static_cast<CIEC_UDINT>(rgb_max);
          break;
      default:
          var_r = static_cast<CIEC_UDINT>(rgb_max);
          var_g = static_cast<CIEC_UDINT>(rgb_min);
          var_b = static_cast<CIEC_UDINT>(rgb_max - rgb_adj);
          break;
      }
      sendOutputEvent(scmEventCNFID);
      break;
  }
}

void FORTE_hsv2rgb::readInputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventREQID: {
      RES_DATA_CON_CRITICAL_REGION();
      readData(0, var_hue, conn_hue);
      readData(1, var_saturation, conn_saturation);
      readData(2, var_value, conn_value);
      break;
    }
    default:
      break;
  }
}

void FORTE_hsv2rgb::writeOutputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventCNFID: {
      RES_DATA_CON_CRITICAL_REGION();
      writeData(0, var_r, conn_r);
      writeData(1, var_g, conn_g);
      writeData(2, var_b, conn_b);
      break;
    }
    default:
      break;
  }
}

CIEC_ANY *FORTE_hsv2rgb::getDI(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_hue;
    case 1: return &var_saturation;
    case 2: return &var_value;
  }
  return nullptr;
}

CIEC_ANY *FORTE_hsv2rgb::getDO(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_r;
    case 1: return &var_g;
    case 2: return &var_b;
  }
  return nullptr;
}

CIEC_ANY *FORTE_hsv2rgb::getDIO(size_t) {
  return nullptr;
}

CEventConnection *FORTE_hsv2rgb::getEOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_CNF;
  }
  return nullptr;
}

CDataConnection **FORTE_hsv2rgb::getDIConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_hue;
    case 1: return &conn_saturation;
    case 2: return &conn_value;
  }
  return nullptr;
}

CDataConnection *FORTE_hsv2rgb::getDOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_r;
    case 1: return &conn_g;
    case 2: return &conn_b;
  }
  return nullptr;
}

CInOutDataConnection **FORTE_hsv2rgb::getDIOInConUnchecked(TPortId) {
  return nullptr;
}

CInOutDataConnection *FORTE_hsv2rgb::getDIOOutConUnchecked(TPortId) {
  return nullptr;
}

