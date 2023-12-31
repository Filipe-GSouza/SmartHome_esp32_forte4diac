#*******************************************************************************
# Copyright (c) 2012, 2021 AIT, ACIN, fortiss GmbH, Hit robot group
# This program and the accompanying materials are made available under the
# terms of the Eclipse Public License 2.0 which is available at
# http://www.eclipse.org/legal/epl-2.0.
#
# SPDX-License-Identifier: EPL-2.0
# 
# Contributors:
#    Filip Andren, Alois Zoitl - initial API and implementation and/or initial documentation
#    Tibalt Zhao - Ease the workload to compile OPC DA
# *******************************************************************************/
#############################################################################
# OPC Com Layer
#############################################################################

if("${FORTE_ARCHITECTURE}" STREQUAL "Win32")
forte_add_network_layer(OPC OFF "opc" COpcComLayer opccomlayer "Enable OPC communication")

if(FORTE_COM_OPC)  
  SET(FORTE_COM_OPC_LIB_ROOT "" CACHE PATH "Path to OPC library root directory")
  SET(FORTE_COM_OPC_BOOST_ROOT "" CACHE PATH "Path to Boost library root directory")

  forte_add_include_directories(${CMAKE_CURRENT_SOURCE_DIR})
  
  forte_add_handler(COpcEventHandler opceventhandler)

  forte_add_sourcefile_hcpp( opcconnection opcconnectionhandler opceventhandler
                 opcconnectionimpl opcprocessvar Cmd_AddConnection
                 Cmd_AddOPCProcessVar Cmd_SetProcessVarValue )

  forte_add_include_directories( ${FORTE_COM_OPC_BOOST_ROOT} )

  forte_add_include_directories( ${FORTE_COM_OPC_LIB_ROOT}/include )
  forte_add_link_directories( ${FORTE_COM_OPC_LIB_ROOT}/lib )

  forte_add_link_library( OPCClientToolKit.lib )
endif(FORTE_COM_OPC)
endif("${FORTE_ARCHITECTURE}" STREQUAL "Win32")