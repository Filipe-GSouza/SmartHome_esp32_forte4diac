/*******************************************************************************
 * Copyright (c) 2005 - 2013 Profactor GmbH, ACIN
 *
 * This program and the accompanying materials are made available under the
 * terms of the Eclipse Public License 2.0 which is available at
 * http://www.eclipse.org/legal/epl-2.0.
 *
 * SPDX-License-Identifier: EPL-2.0
 *
 * Contributors:
 *    Thomas Strasser, Ingomar Müller, Alois Zoitl,
 *    Ingo Hegny, Monika Wenger
 *      - initial implementation and rework communication infrastructure
 *******************************************************************************/
#include "forte_sint.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "forte_sint_gen.cpp"
#endif

DEFINE_FIRMWARE_DATATYPE(SINT, g_nStringIdSINT)

const CIEC_SINT::TValueType CIEC_SINT::scmMinVal = std::numeric_limits<CIEC_SINT::TValueType>::min();
const CIEC_SINT::TValueType CIEC_SINT::scmMaxVal = std::numeric_limits<CIEC_SINT::TValueType>::max();

template CIEC_SINT &CIEC_SINT::operator=<>(const CIEC_ANY_INT &paValue);

size_t CIEC_SINT::getToStringBufferSize() const {
  return sizeof("-128");
}

