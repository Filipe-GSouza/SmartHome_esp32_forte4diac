/*******************************************************************************
 * Copyright (c) 2015 fortiss GmbH
 * This program and the accompanying materials are made available under the
 * terms of the Eclipse Public License 2.0 which is available at
 * http://www.eclipse.org/legal/epl-2.0.
 *
 * SPDX-License-Identifier: EPL-2.0
 *
 * Contributors:
 *    Filipe Gomes - this was adapted from sysfs module to use on esp32 module
 *******************************************************************************/

#ifndef _SYSFSPROCINT_H_
#define _SYSFSPROCINT_H_

#include "../../stdfblib/io/processinterfacebase.h"
#include <forte_thread.h>
#include <extevhan.h>
#include <fstream>

class CEsp32ProcessInterface : public CProcessInterfaceBase {

  public:
    CEsp32ProcessInterface(CResource *paSrcRes, const SFBInterfaceSpec *paInterfaceSpec, const CStringDictionary::TStringId paInstanceNameId);
    ~CEsp32ProcessInterface() override;

    class CIOHandler : public CExternalEventHandler, public CThread {
      DECLARE_HANDLER(CIOHandler)
        ;
      public:
        void run() override;
        void updateReadData();
        
        /* functions needed for the external event handler interface */
        void enableHandler() override;
        void disableHandler() override;
        void setPriority(int paPriority) override;
        int getPriority() const override;
    };

  protected:
    bool initialise(bool paIsInput);
    bool deinitialise();
    bool write();
    bool read();

  private:

    bool setConfig(bool paIsInput);
    bool unexportIO();

    static const char * const scmOK;
    static const char * const scmPinInUse;
    static const char * const scmNotInitialised;
    static const char * const scmError;
    static const char * const scmCouldNotRead;
    static const char * const scmCouldNotWrite;
};

#endif /* PROCESSINTERFACE_H_ */
