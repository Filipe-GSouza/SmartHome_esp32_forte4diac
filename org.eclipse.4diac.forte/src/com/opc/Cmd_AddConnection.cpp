/*******************************************************************************
 * Copyright (c) 2012 AIT
 * This program and the accompanying materials are made available under the
 * terms of the Eclipse Public License 2.0 which is available at
 * http://www.eclipse.org/legal/epl-2.0.
 *
 * SPDX-License-Identifier: EPL-2.0
 *
 * Contributors:
 *   Filip Andren - initial API and implementation and/or initial documentation
 *******************************************************************************/
#include "Cmd_AddConnection.h"
#include "opcconnectionimpl.h"

CCmd_AddConnection::CCmd_AddConnection(COpcConnectionImpl *paConnection) :
    mConnection(paConnection){
}

CCmd_AddConnection::~CCmd_AddConnection(){
}

void CCmd_AddConnection::runCommand(){
  mConnection->connect();
}
const char* CCmd_AddConnection::getCommandName() const{
  return "Cmd_AddConnection";
}
