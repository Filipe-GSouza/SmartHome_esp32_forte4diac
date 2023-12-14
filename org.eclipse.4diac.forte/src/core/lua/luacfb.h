/*******************************************************************************
 * Copyright (c) 2017 fortiss GmbH
 * This program and the accompanying materials are made available under the
 * terms of the Eclipse Public License 2.0 which is available at
 * http://www.eclipse.org/legal/epl-2.0.
 *
 * SPDX-License-Identifier: EPL-2.0
 *
 * Contributors:
 *   Monika Wenger
 *   - initial API and implementation and/or initial documentation
 *******************************************************************************/

#ifndef SRC_CORE_LUACFB_H_
#define SRC_CORE_LUACFB_H_

#include "cfb.h"
#include "luacfbtypeentry.h"

class CLuaCFB : public CCompositeFB {
  public:
    CLuaCFB(CStringDictionary::TStringId paInstanceNameId, const CLuaCFBTypeEntry* paTypeEntry, SCFB_FBNData *paFbnData, CResource *paResource);
    ~CLuaCFB() override;

    CStringDictionary::TStringId getFBTypeId() const override {
      return mTypeEntry->getTypeNameId();
    }

    bool initialize() override;

  protected:
    virtual void readInternal2InterfaceOutputData(TEventID paEOID);

  private:
    virtual void readInputData(TEventID paEIID);
    virtual void writeOutputData(TEventID paEO);

    const CLuaCFBTypeEntry* mTypeEntry;
};

#endif /* SRC_CORE_LUACFB_H_ */
