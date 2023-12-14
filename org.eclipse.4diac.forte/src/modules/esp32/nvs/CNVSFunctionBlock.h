/*
 * CNVSFunctionBlock.h
 *
 *  Created on: 23.09.2022
 *      Author: franz
 */

#ifndef SRC_MODULES_ESP32_NVS_CNVSFUNCTIONBLOCK_H_
#define SRC_MODULES_ESP32_NVS_CNVSFUNCTIONBLOCK_H_

#include "funcbloc.h"

#include "nvs_flash.h"
#include "nvs.h"
#include "nvs_handle.hpp"

class CNVSFunctionBlock : public CFunctionBlock {



public:
    CNVSFunctionBlock(CResource *pa_poSrcRes, const SFBInterfaceSpec *pa_pstInterfaceSpec,
            CStringDictionary::TStringId pa_nInstanceNameId);

    ~CNVSFunctionBlock() override;

protected:

    // Handle will automatically close when going out of scope or when it's reset.
    static std::shared_ptr<nvs::NVSHandle> handle;

    const char *key;

    void executeInit();


    static const CIEC_STRING scmOK;
    static const CIEC_STRING scmNotInitialised;
    static const CIEC_STRING scmInitialised;
    static const CIEC_STRING scmERR;
    static const CIEC_STRING scmERR_NVS_NOT_FOUND;
};




#endif /* SRC_MODULES_ESP32_NVS_CNVSFUNCTIONBLOCK_H_ */
