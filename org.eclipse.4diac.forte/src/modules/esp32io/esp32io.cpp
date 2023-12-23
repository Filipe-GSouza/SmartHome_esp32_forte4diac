/*******************************************************************************
 * Copyright (c) 2015 fortiss GmbH
 * This program and the accompanying materials are made available under the
 * terms of the Eclipse Public License 2.0 which is available at
 * http://www.eclipse.org/legal/epl-2.0.
 *
 * SPDX-License-Identifier: EPL-2.0
 *
 * Contributors:
 *     Filipe Gomes - this was adapted from sysfs module to use on esp32 module
 *******************************************************************************/

#include "esp32io.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>
#include "driver/gpio.h"

#include "../../arch/devlog.h"
#include <extevhandlerhelper.h>
#include <criticalregion.h>
#include <string>

const char * const CEsp32ProcessInterface::scmOK = "OK";
const char * const CEsp32ProcessInterface::scmPinInUse = "Pin already in use by other FB";
const char * const CEsp32ProcessInterface::scmNotInitialised = "FB not initialized";
const char * const CEsp32ProcessInterface::scmError = "Error";
const char * const CEsp32ProcessInterface::scmCouldNotRead = "Could not read";
const char * const CEsp32ProcessInterface::scmCouldNotWrite = "Could not write";

CEsp32ProcessInterface::CEsp32ProcessInterface(CResource *paSrcRes, const SFBInterfaceSpec *paInterfaceSpec,
    const CStringDictionary::TStringId paInstanceNameId) :
    CProcessInterfaceBase(paSrcRes, paInterfaceSpec, paInstanceNameId) {
   STATUS().fromString(scmNotInitialised);
}

CEsp32ProcessInterface::~CEsp32ProcessInterface() {
  unexportIO(); // em teste.
}

bool CEsp32ProcessInterface::setConfig(bool paIsInput) {
    bool retVal = false;
 
    int io_num = std::stoi(PARAMS().getValue());
  
    gpio_config_t io_conf = {};
    //disable interrupt
    io_conf.intr_type = GPIO_INTR_DISABLE;
   
    if(paIsInput) {
    io_conf.mode = GPIO_MODE_INPUT;
    io_conf.pull_up_en = GPIO_PULLUP_ENABLE;
    }else {
    io_conf.mode = GPIO_MODE_OUTPUT;
    io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
    io_conf.pull_up_en = GPIO_PULLUP_DISABLE;
    }
    //bit mask of the pins that was set
    io_conf.pin_bit_mask = (1ULL<<io_num);
    //configure GPIO with the given settings
    int configpin = gpio_config(&io_conf);

    if(!configpin){
      retVal = true;
    } else{
      DEVLOG_ERROR("[CEsp32ProcessInterface::setConfig] - Parameter error ");
    }
  return retVal;
}

bool CEsp32ProcessInterface::initialise(bool paIsInput) {
  bool retVal = false;
    if(CEsp32ProcessInterface::setConfig(paIsInput)) {
      CThread::sleepThread(250);
        if(paIsInput) {
          if(!getExtEvHandler<CEsp32ProcessInterface::CIOHandler>(*this).isAlive()) {
            getExtEvHandler<CEsp32ProcessInterface::CIOHandler>(*this).start();
          }
        }
        DEVLOG_DEBUG("[CEsp32ProcessInterface::initialise] Pin with PARAM() %s was properly initialized.\n", PARAMS().getValue());
        STATUS().fromString(scmOK);
        retVal = true;
    }

  STATUS().fromString(scmNotInitialised); 
  return retVal;
}

bool CEsp32ProcessInterface::unexportIO() {
  bool retVal = false;
  
  int io_num = std::stoi(PARAMS().getValue());
  gpio_num_t pin = static_cast<gpio_num_t>(io_num);
  int result = gpio_reset_pin(pin);
    if(!result) {
      STATUS().fromString(scmOK);
      retVal = true;
    } else {
      STATUS().fromString(scmError);
      DEVLOG_ERROR("[CEsp32ProcessInterface::deinitialise] - Error reseting PIN");
    }

  return retVal;
}

bool CEsp32ProcessInterface::deinitialise() {
  return unexportIO();
}

bool CEsp32ProcessInterface::readPin() {
  bool retVal = false;
  int io_num = std::stoi(PARAMS().getValue());
  gpio_num_t pin = static_cast<gpio_num_t>(io_num);
  
  bool result = gpio_get_level(pin);
  if(result != IN_X()) {
      IN_X() = CIEC_BOOL(result);
      STATUS().fromString(scmOK);
      retVal = true;
  }
  return retVal;
}

bool CEsp32ProcessInterface::writePin() {
  bool retVal = false;
  unsigned int val = (false != OUT_X()) ? 1 : 0; 
  
  int io_num = std::stoi(PARAMS().getValue());
  gpio_num_t pin = static_cast<gpio_num_t>(io_num);

  int result = gpio_set_level(pin,val);
  if (!result){
    STATUS().fromString(scmOK);
    retVal = true;
  } else {
      DEVLOG_ERROR("[CEsp32ProcessInterface::writePin Could not write %u to output pin\n", val);
      STATUS().fromString(scmCouldNotWrite);
    }
  return retVal;
}



