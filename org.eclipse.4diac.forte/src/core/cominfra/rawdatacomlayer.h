/*******************************************************************************
 * Copyright (c) 2013-2015 TU Wien ACIN and fortiss.
 * This program and the accompanying materials are made available under the
 * terms of the Eclipse Public License 2.0 which is available at
 * http://www.eclipse.org/legal/epl-2.0.
 *
 * SPDX-License-Identifier: EPL-2.0
 *
 * Contributors:
 *    Martin Melik Merkumians, Monika Wenger
 *     - initial implementation
 *******************************************************************************/
#ifndef RAWDATACOMLAYER_H_
#define RAWDATACOMLAYER_H_

#include "comlayer.h"
#include <commfb.h>

namespace forte {
  namespace com_infra {
    class CRawDataComLayer : public CComLayer{
      public:
        CRawDataComLayer(CComLayer* paUpperLayer, CBaseCommFB * paFB);
        ~CRawDataComLayer() override;
        EComResponse sendData(void *paData, unsigned int paSize) override;
        EComResponse recvData(const void *paData, unsigned int paSize) override;

      private:
        EComResponse openConnection(char *paLayerParameter) override;
        void closeConnection() override;
    };
  } /* namespace com_infra */
} /* namespace forte */
#endif /* RAWDATACOMLAYER_H_ */
