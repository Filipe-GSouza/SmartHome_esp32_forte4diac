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
 
forte_add_module(esp-addons OFF "Additional Modules for ESP32")

forte_add_include_directories(${CMAKE_CURRENT_SOURCE_DIR})

#######################################################
# hsv2rgb
#######################################################


forte_add_sourcefile_hcpp(hsv2rgb)
forte_add_sourcefile_hcpp(strip_set_pixel)

