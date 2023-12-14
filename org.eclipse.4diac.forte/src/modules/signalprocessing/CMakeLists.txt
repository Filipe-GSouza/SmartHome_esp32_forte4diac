#*******************************************************************************
# Copyright (c) 2023 HR Agrartechnik GmbH
# This program and the accompanying materials are made available under the
# terms of the Eclipse Public License 2.0 which is available at
# http://www.eclipse.org/legal/epl-2.0.
#
# SPDX-License-Identifier: EPL-2.0
# 
# Contributors:
#     Franz Hoepfinger - initial API and implementation and/or initial documentation
# *******************************************************************************/ 
 
forte_add_module(signalprocessing OFF "signalprocessing")

forte_add_include_directories(${CMAKE_CURRENT_SOURCE_DIR})

#######################################################
# signalprocessing
#######################################################


forte_add_sourcefile_hcpp(DualHysteresis)
forte_add_sourcefile_hcpp(FIELDBUS_WORD_TO_PERCENT)

