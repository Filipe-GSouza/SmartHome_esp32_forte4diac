#*******************************************************************************
# Copyright (c) 2015 fortiss GmbH
# This program and the accompanying materials are made available under the
# terms of the Eclipse Public License 2.0 which is available at
# http://www.eclipse.org/legal/epl-2.0.
#
# SPDX-License-Identifier: EPL-2.0
# 
# Contributors:
#     Franz Hoepfinger - initial API and implementation and/or initial documentation
# *******************************************************************************/ 

#############################################################################
# DATAPANEL J1939  integration.
#############################################################################

# option to enable DATAPANEL with cmake
forte_add_module(DATAPANEL OFF "Enable DATAPANEL communication layer")

forte_add_include_directories(${CMAKE_CURRENT_SOURCE_DIR})

if (FORTE_MODULE_DATAPANEL)
  forte_add_custom_configuration("#cmakedefine FORTE_MODULE_DATAPANEL")
endif (FORTE_MODULE_DATAPANEL)