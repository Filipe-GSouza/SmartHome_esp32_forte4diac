#*******************************************************************************
# Copyright (c) 2013 fortiss GmbH
# This program and the accompanying materials are made available under the
# terms of the Eclipse Public License 2.0 which is available at
# http://www.eclipse.org/legal/epl-2.0.
#
# SPDX-License-Identifier: EPL-2.0
# 
# Contributors:
#    Alois Zoitl
# *   - initial API and implementation and/or initial documentation
# *******************************************************************************/
forte_add_include_directories(${CMAKE_CURRENT_SOURCE_DIR})
#############################################################################
# Tests for the standard Event FBs
#############################################################################
SET(SOURCE_GROUP ${SOURCE_GROUP}\\events)


if(FORTE_FUNCTIONBLOCK_TESTS)

forte_add_sourcefile_hcpp(F_EQ_TIME_tester F_GT_TIME_tester)

endif(FORTE_FUNCTIONBLOCK_TESTS)
