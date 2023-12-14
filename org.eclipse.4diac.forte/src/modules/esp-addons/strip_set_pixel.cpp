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

#include "strip_set_pixel.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "strip_set_pixel_gen.cpp"
#endif

#include "criticalregion.h"
#include "resource.h"


#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "led_strip.h"
#include "led_strip_interface.h"

#if defined(FORTE_MODULE_HUTSCHIENENMOPED)
#include "hutschienenmoped_led_strip.h"
#endif //FORTE_MODULE_HUTSCHIENENMOPED


#define CONFIG_EXAMPLE_STRIP_LED_NUMBER 1  //M5 Stack Atom Lite.

struct FORTE_strip_set_pixel::Impl {
    static const gpio_num_t CONFIG_EXAMPLE_RMT_TX_GPIO = LED_IO; //M5 Stack Atom Lite.
    static led_strip_t *strip;
};

led_strip_t *FORTE_strip_set_pixel::Impl::strip = nullptr;
DEFINE_FIRMWARE_FB(FORTE_strip_set_pixel, g_nStringIdstrip_set_pixel)

const CStringDictionary::TStringId FORTE_strip_set_pixel::scmDataInputNames[] = {g_nStringIdindex, g_nStringIdred, g_nStringIdgreen, g_nStringIdblue};
const CStringDictionary::TStringId FORTE_strip_set_pixel::scmDataInputTypeIds[] = {g_nStringIdUDINT, g_nStringIdUDINT, g_nStringIdUDINT, g_nStringIdUDINT};
const CStringDictionary::TStringId FORTE_strip_set_pixel::scmDataOutputNames[] = {g_nStringIdset_pixel_return, g_nStringIdclear_return};
const CStringDictionary::TStringId FORTE_strip_set_pixel::scmDataOutputTypeIds[] = {g_nStringIdDINT, g_nStringIdDINT};
const TDataIOID FORTE_strip_set_pixel::scmEIWith[] = {0, 1, 2, 3, scmWithListDelimiter};
const TForteInt16 FORTE_strip_set_pixel::scmEIWithIndexes[] = {-1, 0, -1};
const CStringDictionary::TStringId FORTE_strip_set_pixel::scmEventInputNames[] = {g_nStringIdINIT, g_nStringIdset_pixel, g_nStringIdclear};
const TDataIOID FORTE_strip_set_pixel::scmEOWith[] = {0, scmWithListDelimiter, 1, scmWithListDelimiter};
const TForteInt16 FORTE_strip_set_pixel::scmEOWithIndexes[] = {-1, 0, 2};
const CStringDictionary::TStringId FORTE_strip_set_pixel::scmEventOutputNames[] = {g_nStringIdINITO, g_nStringIdset_pixel_CNF, g_nStringIdclear_CNF};
const SFBInterfaceSpec FORTE_strip_set_pixel::scmFBInterfaceSpec = {
  3, scmEventInputNames, scmEIWith, scmEIWithIndexes,
  3, scmEventOutputNames, scmEOWith, scmEOWithIndexes,
  4, scmDataInputNames, scmDataInputTypeIds,
  2, scmDataOutputNames, scmDataOutputTypeIds,
  0, nullptr,
  0, nullptr
};

FORTE_strip_set_pixel::FORTE_strip_set_pixel(const CStringDictionary::TStringId paInstanceNameId, CResource *const paSrcRes) :
    CFunctionBlock(paSrcRes, &scmFBInterfaceSpec, paInstanceNameId),
    var_conn_set_pixel_return(var_set_pixel_return),
    var_conn_clear_return(var_clear_return),
    conn_INITO(this, 0),
    conn_set_pixel_CNF(this, 1),
    conn_clear_CNF(this, 2),
    conn_index(nullptr),
    conn_red(nullptr),
    conn_green(nullptr),
    conn_blue(nullptr),
    conn_set_pixel_return(this, 0, &var_conn_set_pixel_return),
    conn_clear_return(this, 1, &var_conn_clear_return) {
};

void FORTE_strip_set_pixel::setInitialValues() {
  var_index = 0_UDINT;
  var_red = 0_UDINT;
  var_green = 0_UDINT;
  var_blue = 0_UDINT;
  var_set_pixel_return = 0_DINT;
  var_clear_return = 0_DINT;
}

void FORTE_strip_set_pixel::executeEvent(const TEventID paEIID, CEventChainExecutionThread *const paECET) {
  switch(paEIID) {
    case scmEventINITID:
      initStrip();
      sendOutputEvent(scmEventINITOID);
      break;
    case scmEventset_pixelID:
      setPixel();
      sendOutputEvent(scmEventset_pixel_CNFID);
      break;
    case scmEventclearID:
      clear();
      sendOutputEvent(scmEventclear_CNFID);
      break;
  }
}

void FORTE_strip_set_pixel::readInputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventset_pixelID: {
      RES_DATA_CON_CRITICAL_REGION();
      readData(0, var_index, conn_index);
      readData(1, var_red, conn_red);
      readData(2, var_green, conn_green);
      readData(3, var_blue, conn_blue);
      break;
    }
    default:
      break;
  }
}

void FORTE_strip_set_pixel::writeOutputData(const TEventID paEIID) {
  switch(paEIID) {
    case scmEventset_pixel_CNFID: {
      RES_DATA_CON_CRITICAL_REGION();
      writeData(0, var_set_pixel_return, conn_set_pixel_return);
      break;
    }
    case scmEventclear_CNFID: {
      RES_DATA_CON_CRITICAL_REGION();
      writeData(1, var_clear_return, conn_clear_return);
      break;
    }
    default:
      break;
  }
}

CIEC_ANY *FORTE_strip_set_pixel::getDI(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_index;
    case 1: return &var_red;
    case 2: return &var_green;
    case 3: return &var_blue;
  }
  return nullptr;
}

CIEC_ANY *FORTE_strip_set_pixel::getDO(const size_t paIndex) {
  switch(paIndex) {
    case 0: return &var_set_pixel_return;
    case 1: return &var_clear_return;
  }
  return nullptr;
}

CIEC_ANY *FORTE_strip_set_pixel::getDIO(size_t) {
  return nullptr;
}

CEventConnection *FORTE_strip_set_pixel::getEOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_INITO;
    case 1: return &conn_set_pixel_CNF;
    case 2: return &conn_clear_CNF;
  }
  return nullptr;
}

CDataConnection **FORTE_strip_set_pixel::getDIConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_index;
    case 1: return &conn_red;
    case 2: return &conn_green;
    case 3: return &conn_blue;
  }
  return nullptr;
}

CDataConnection *FORTE_strip_set_pixel::getDOConUnchecked(const TPortId paIndex) {
  switch(paIndex) {
    case 0: return &conn_set_pixel_return;
    case 1: return &conn_clear_return;
  }
  return nullptr;
}

CInOutDataConnection **FORTE_strip_set_pixel::getDIOInConUnchecked(TPortId) {
  return nullptr;
}

CInOutDataConnection *FORTE_strip_set_pixel::getDIOOutConUnchecked(TPortId) {
  return nullptr;
}

void FORTE_strip_set_pixel::initStrip() {
  if (!Impl::strip) {
    //continue
  } else {
    DEVLOG_ERROR("install WS2812 driver already done.");
    return;
  }


  /* LED strip initialization with the GPIO and pixels number*/
  led_strip_config_t strip_config = {
    .strip_gpio_num = Impl::CONFIG_EXAMPLE_RMT_TX_GPIO, // The GPIO that connected to the LED strip's data line
    .max_leds = CONFIG_EXAMPLE_STRIP_LED_NUMBER, // The number of LEDs in the strip
  };

  led_strip_rmt_config_t rmt_config = {
    .clk_src = RMT_CLK_SRC_DEFAULT, // different clock source can lead to different power consumption
    .resolution_hz = 10 * 1000 * 1000, // 10MHz
    //.flags.with_dma = false, // wether to enable the DMA feature
  };
  ESP_ERROR_CHECK(led_strip_new_rmt_device(&strip_config, &rmt_config, &Impl::strip));





}

void FORTE_strip_set_pixel::setPixel() {
  // Write RGB values to strip driver
  ESP_ERROR_CHECK(Impl::strip->set_pixel(Impl::strip, static_cast<uint32_t>(var_index), static_cast<uint32_t>(var_red), static_cast<uint32_t>(var_green), static_cast<uint32_t>(var_blue)));
  // Flush RGB values to LEDs
  ESP_ERROR_CHECK(Impl::strip->refresh(Impl::strip));
}

void FORTE_strip_set_pixel::clear() {
  ESP_ERROR_CHECK(Impl::strip->clear(Impl::strip));
}

