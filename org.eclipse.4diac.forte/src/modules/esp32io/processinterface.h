/*******************************************************************************
 * Copyright (c) 2016 fortiss GmbH
 * This program and the accompanying materials are made available under the
 * terms of the Eclipse Public License 2.0 which is available at
 * http://www.eclipse.org/legal/epl-2.0.
 *
 * SPDX-License-Identifier: EPL-2.0
 *
 * Contributors:
 *    Alois Zoitl - initial API and implementation and/or initial documentation
 *    Filipe Gomes - this was adapted from sysfs module to use on esp32 module
 *******************************************************************************/
#ifndef _PROCESSINTERFACE_H_
#define _PROCESSINTERFACE_H_

#include "esp32io.h"

//tell the IX and QX FB that this is the process interface to be used
typedef CEsp32ProcessInterface CProcessInterface;

#endif
