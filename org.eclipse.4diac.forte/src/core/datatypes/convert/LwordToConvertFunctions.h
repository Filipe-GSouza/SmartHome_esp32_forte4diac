/*******************************************************************************
 * Copyright (c) 2010 - 2015 TU Vienna/ACIN, Profactor GmbH, fortiss GmbH,
 *    2018-2019 TU Vienna/ACIN
 * This program and the accompanying materials are made available under the
 * terms of the Eclipse Public License 2.0 which is available at
 * http://www.eclipse.org/legal/epl-2.0.
 *
 * SPDX-License-Identifier: EPL-2.0
 *
 * Contributors:
 *    Alois Zoitl, Ingo Hegny, Monika Wenger, Carolyn Oates, Patrick Smejkal,
 *    Matthias Plasch,
 *      - initial implementation and rework communication infrastructure
 *    Martin Melik-Merkumians - fixes DT_TO_TOD
 *    Martin Melik-Merkumians - removes invalid casts, update implementation
 *     to use new cast function
 *******************************************************************************/

#ifndef SRC_CORE_DATATYPES_CONVERT_LWORDTOCONVERTFUNCTIONS_H_
#define SRC_CORE_DATATYPES_CONVERT_LWORDTOCONVERTFUNCTIONS_H_

//********************************************************************************************
//   LWORD_TO_*  functions
//********************************************************************************************

inline const CIEC_DWORD func_LWORD_TO_DWORD(const CIEC_LWORD &paVal){
  return CIEC_ANY::cast<CIEC_DWORD>(paVal);
}

inline const CIEC_WORD func_LWORD_TO_WORD(const CIEC_LWORD &paVal){
  return CIEC_ANY::cast<CIEC_WORD>(paVal);
}

inline const CIEC_BYTE func_LWORD_TO_BYTE(const CIEC_LWORD &paVal){
  return CIEC_ANY::cast<CIEC_BYTE>(paVal);
}

inline const CIEC_BOOL func_LWORD_TO_BOOL(const CIEC_LWORD &paVal){
  return CIEC_ANY::cast<CIEC_BOOL>(paVal);
}

inline const CIEC_LREAL func_LWORD_TO_LREAL(const CIEC_LWORD &paVal){
  return CIEC_ANY::cast<CIEC_LREAL>(paVal);
}

inline const CIEC_LINT func_LWORD_TO_LINT(const CIEC_LWORD &paVal){
  return CIEC_ANY::cast<CIEC_LINT>(paVal);
}

inline const CIEC_DINT func_LWORD_TO_DINT(const CIEC_LWORD &paVal){
  return CIEC_ANY::cast<CIEC_DINT>(paVal);
}

inline const CIEC_INT func_LWORD_TO_INT(const CIEC_LWORD &paVal){
  return CIEC_ANY::cast<CIEC_INT>(paVal);
}

inline const CIEC_SINT func_LWORD_TO_SINT(const CIEC_LWORD &paVal){
  return CIEC_ANY::cast<CIEC_SINT>(paVal);
}

inline const CIEC_ULINT func_LWORD_TO_ULINT(const CIEC_LWORD &paVal){
  return CIEC_ANY::cast<CIEC_ULINT>(paVal);
}

inline const CIEC_UDINT func_LWORD_TO_UDINT(const CIEC_LWORD &paVal){
  return CIEC_ANY::cast<CIEC_UDINT>(paVal);
}

inline const CIEC_UINT func_LWORD_TO_UINT(const CIEC_LWORD &paVal){
  return CIEC_ANY::cast<CIEC_UINT>(paVal);
}

inline const CIEC_USINT func_LWORD_TO_USINT(const CIEC_LWORD &paVal){
  return CIEC_ANY::cast<CIEC_USINT>(paVal);
}

inline const CIEC_STRING func_LWORD_AS_STRING(const CIEC_LWORD &paVal){
  CIEC_STRING string;
  stringConverter(string, paVal);
  return string;
}

#ifdef FORTE_USE_WSTRING_DATATYPE
inline const CIEC_WSTRING func_LWORD_AS_WSTRING(const CIEC_LWORD &paVal){
  CIEC_WSTRING string;
  stringConverter(string, paVal);
  return string;
}
#endif

#endif /* SRC_CORE_DATATYPES_CONVERT_LWORDTOCONVERTFUNCTIONS_H_ */
