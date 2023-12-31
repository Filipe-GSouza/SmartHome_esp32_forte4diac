/*******************************************************************************
 * Copyright (c) 2013, 2023 ACIN
 * This program and the accompanying materials are made available under the
 * terms of the Eclipse Public License 2.0 which is available at
 * http://www.eclipse.org/legal/epl-2.0.
 *
 * SPDX-License-Identifier: EPL-2.0
 *
 * Contributors:
 * Martin Melik Merkumians - initial API and implementation and/or initial documentation
 *                         - Change CIEC_STRING to std::string
 *******************************************************************************/

#ifndef MQTTCOMLAYER_H_
#define MQTTCOMLAYER_H_

#include "comlayer.h"
#include "../../core/datatypes/forte_string.h"

#include <memory>

#define MQTT_QOS 0

//raw[].mqtt[tcp://localhost:1883, ClientID, Topic]

class CMQTTClient;

using namespace forte::com_infra;


class MQTTComLayer: public forte::com_infra::CComLayer{
public:
  MQTTComLayer(CComLayer* paUpperLayer, CBaseCommFB * paFB);
  ~MQTTComLayer() override;

  EComResponse sendData(void* paData, unsigned int paSize) override;

  EComResponse recvData(const void *paData, unsigned int paSize) override;

  EComResponse processInterrupt() override;

  const std::string& getTopicName() const {
    return mTopicName;
  }

  std::shared_ptr<CMQTTClient> getClient() {
    return mClient;
  }

  void setClient(std::shared_ptr<CMQTTClient> paClient) {
    mClient = paClient;
  }

private:
  std::string mTopicName;

  std::shared_ptr<CMQTTClient> mClient;

  static const unsigned int mNoOfParameters = 3;
  static const unsigned int mBufferSize = 255;

  char mDataBuffer[mBufferSize];
  unsigned int mUsedBuffer;
  EComResponse mInterruptResp;

  EComResponse openConnection(char* paLayerParameter) override;
  void closeConnection() override;

  enum Parameters {
    Address,
    ClientID,
    Topic
  };

};
#endif /* MQTTCOMLAYER_H_ */
