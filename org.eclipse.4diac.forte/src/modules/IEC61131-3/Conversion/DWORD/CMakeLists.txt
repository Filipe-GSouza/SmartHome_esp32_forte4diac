#*******************************************************************************
# Copyright (c) 2012 - 2013 ACIN, Profactor GmbH
# This program and the accompanying materials are made available under the
# terms of the Eclipse Public License 2.0 which is available at
# http://www.eclipse.org/legal/epl-2.0.
#
# SPDX-License-Identifier: EPL-2.0
# 
# Contributors:
#    Monika Wenger, Matthias Plasch
# *   - initial API and implementation and/or initial documentation
# *   Martin Melik-Merkumians - removing illegal casts
# *******************************************************************************/
forte_add_include_directories(${CMAKE_CURRENT_SOURCE_DIR})
#############################################################################
# DWORD_TO_xxx Conversion
#############################################################################
forte_add_sourcefile_hcpp(F_DWORD_TO_BYTE)
forte_add_sourcefile_hcpp(F_DWORD_TO_DINT)
forte_add_sourcefile_hcpp(F_DWORD_TO_INT)
forte_add_sourcefile_hcpp(F_DWORD_TO_SINT)
forte_add_sourcefile_hcpp(F_DWORD_TO_UDINT)
forte_add_sourcefile_hcpp(F_DWORD_TO_UINT)
forte_add_sourcefile_hcpp(F_DWORD_TO_USINT)
forte_add_sourcefile_hcpp(F_DWORD_TO_WORD)
forte_add_sourcefile_hcpp(F_DWORD_AS_STRING)
forte_add_sourcefile_hcpp(F_DWORD_TO_LINT)
forte_add_sourcefile_hcpp(F_DWORD_TO_LWORD)
forte_add_sourcefile_hcpp(F_DWORD_TO_ULINT)
forte_add_sourcefile_hcpp(F_DWORD_TO_REAL)

if(FORTE_USE_WSTRING_DATATYPE)
  forte_add_sourcefile_hcpp(F_DWORD_AS_WSTRING)
endif(FORTE_USE_WSTRING_DATATYPE)
