/*******************************************************************************
 * Copyright (c) 2008 - 2015 nxtControl GmbH, ACIN, fortiss GmbH
 *
 * This program and the accompanying materials are made available under the
 * terms of the Eclipse Public License 2.0 which is available at
 * http://www.eclipse.org/legal/epl-2.0.
 *
 * SPDX-License-Identifier: EPL-2.0
 *
 * Contributors:
 *    Stanislav Meduna, Alois Zoitl, Martin Melik Merkumians, Monika Wenger
 *      - initial implementation and rework communication infrastructure
  *******************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "forte_ldate_and_time.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "forte_ldate_and_time_gen.cpp"
#endif
#include "forte_ldate.h"
#include "forte_ltime_of_day.h"
#include "../../arch/timerha.h"
#include <forte_printer.h>

DEFINE_FIRMWARE_DATATYPE(LDATE_AND_TIME, g_nStringIdLDATE_AND_TIME)

int CIEC_LDATE_AND_TIME::fromString(const char *paValue){
  // 2007-12-21-15:00:00.000
  int nRetVal = -1;
  char *acBuffer = const_cast<char*>(paValue);

  if('l' == tolower(*acBuffer)){
    if (('d' == tolower(acBuffer[1])) && ('t' == tolower(acBuffer[2])))
    {
      acBuffer += 3;
    }
    else{
      //TODO maybe allow to turn this check of for small devices
      if((0 == strncmp("ldate_and_time", acBuffer, 14))
          || (0 == strncmp("LDATE_AND_TIME", acBuffer, 14))){
        acBuffer += 14;
      }
    }

    if('#' != *acBuffer){
      return -1;
    }
    acBuffer++;
  }

  struct tm tm;
  unsigned int msec = 0;

  memset(&tm, 0, sizeof(tm));

  //Duplicate code the same as in forte date
  if('\0' != *acBuffer){
    tm.tm_year = static_cast<int>(forte::core::util::strtoul(acBuffer, &acBuffer, 10) - 1900);
    if('-' == *acBuffer){
      ++acBuffer;
      tm.tm_mon = static_cast<int>(forte::core::util::strtoul(acBuffer, &acBuffer, 10) - 1);
      if('-' == *acBuffer){
        ++acBuffer;
        tm.tm_mday = static_cast<int>(forte::core::util::strtoul(acBuffer, &acBuffer, 10));

        if('-' == *acBuffer){
          ++acBuffer;
          //duplicate code this one can be find in time of day
          tm.tm_hour = static_cast<int>(forte::core::util::strtoul(acBuffer, &acBuffer, 10));
          if(':' == *acBuffer){
            ++acBuffer;
            tm.tm_min = static_cast<int>(forte::core::util::strtoul(acBuffer, &acBuffer, 10));
            if(':' == *acBuffer){
              ++acBuffer;
              tm.tm_sec = static_cast<int>(forte::core::util::strtoul(acBuffer, &acBuffer, 10));
              if('.' == *acBuffer){
                unsigned int nNums = 0;
                ++acBuffer;
                while(isdigit(*acBuffer)){
                  msec = 10 * msec + forte::core::util::charDigitToInt(*acBuffer);
                  ++acBuffer;
                  ++nNums;
                }

                if(nNums < 3) {
                  for(unsigned int i = nNums; i < 3; ++i) {
                    msec *= 10;
                  }
                } else {
                  for(unsigned int i = 0; i < (nNums - 3); ++i) {
                    msec /= 10;
                  }
                }
              }
              nRetVal = static_cast<int>(acBuffer - paValue);
            }
          }
        }
      }
    }
  }

  if(-1 != nRetVal && !setDateAndTime(tm, msec)) {
    nRetVal = -1;
  }

  return nRetVal;
}

int CIEC_LDATE_AND_TIME::toString(char* paValue, size_t paBufferSize) const {
  int nRetVal = -1;

  struct tm ptm;

  if(nullptr != getTimeStruct(&ptm)){
    nRetVal = forte_snprintf(paValue, paBufferSize, "LDT#%04d-%02d-%02d-%02d:%02d:%02d.%03u", 1900 + ptm.tm_year, ptm.tm_mon + 1, ptm.tm_mday, ptm.tm_hour, ptm.tm_min, ptm.tm_sec, getMilliSeconds());
    if((nRetVal < -1) || (nRetVal >= static_cast<int>(paBufferSize))) {
      nRetVal = -1;
    }
  }
  return nRetVal;
}

int CIEC_LDATE_AND_TIME::toGMTString(char* paValue, unsigned int paBufferSize) const{
  return toString(paValue, paBufferSize);
}

size_t CIEC_LDATE_AND_TIME::getToStringBufferSize() const {
  return sizeof("LDT#1970-01-01-00:00:00.000");
}