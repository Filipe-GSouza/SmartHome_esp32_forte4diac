/*
 * CNVSFunctionBlock.cpp
 *
 *  Created on: 23.09.2022
 *      Author: franz
 */

#include "CNVSFunctionBlock.h"


const CIEC_STRING CNVSFunctionBlock::scmOK                 = "OK"_STRING;
const CIEC_STRING CNVSFunctionBlock::scmNotInitialised     = "Not initialized"_STRING;
const CIEC_STRING CNVSFunctionBlock::scmInitialised        = "initialized"_STRING;
const CIEC_STRING CNVSFunctionBlock::scmERR                = "ERROR"_STRING; //Unknown Error
const CIEC_STRING CNVSFunctionBlock::scmERR_NVS_NOT_FOUND  = "ESP_ERR_NVS_NOT_FOUND"_STRING; //Unknown Error


std::shared_ptr<nvs::NVSHandle> CNVSFunctionBlock::handle;

CNVSFunctionBlock::CNVSFunctionBlock(CResource *pa_poSrcRes, const SFBInterfaceSpec *pa_pstInterfaceSpec,
        CStringDictionary::TStringId pa_nInstanceNameId) :
    CFunctionBlock( pa_poSrcRes, pa_pstInterfaceSpec, pa_nInstanceNameId) {
  key = nullptr;
};

CNVSFunctionBlock::~CNVSFunctionBlock() = default;

void CNVSFunctionBlock::executeInit() {
  // if handle == nullptr
  if (!handle)
  {
    esp_err_t result;
    handle = nvs::open_nvs_handle("storage", NVS_READWRITE, &result);
  }
}
