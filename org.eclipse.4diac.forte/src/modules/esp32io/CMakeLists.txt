#*******************************************************************************
# Copyright (c) 2015 fortiss GmbH
# This program and the accompanying materials are made available under the
# terms of the Eclipse Public License 2.0 which is available at
# http://www.eclipse.org/legal/epl-2.0.
#
# SPDX-License-Identifier: EPL-2.0
# 
# Contributors:
#     Waldemar Eisenmenger - initial API and implementation and/or initial documentation
# *******************************************************************************/ 
 
if ("${FORTE_ARCHITECTURE}" STREQUAL "FreeRTOSLwIP")

forte_add_module(ESP32IO OFF "Interacting with GPIOs of esp32 devices via ESP-IDF V5.1")

forte_add_include_directories(${CMAKE_CURRENT_SOURCE_DIR})
#######################################################
# esp32io
#######################################################

forte_add_handler(CEsp32ProcessInterface::CIOHandler esp32io)
forte_add_sourcefile_hcpp(esp32io)
forte_set_process_interface("esp32io" IX QX)
forte_add_sourcefile_h(processinterface.h)

endif ("${FORTE_ARCHITECTURE}" STREQUAL "FreeRTOSLwIP")
