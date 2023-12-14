/*******************************************************************************
 * Copyright (c) 2005 - 2014 ACIN, Profactor GmbH, fortiss GmbH
 * This program and the accompanying materials are made available under the
 * terms of the Eclipse Public License 2.0 which is available at
 * http://www.eclipse.org/legal/epl-2.0.
 *
 * SPDX-License-Identifier: EPL-2.0
 *
 * Contributors:
 *   Alois Zoitl, Martin Melik Merkumians, Ingo Hegny, Michael Hofmann 
 *     - initial API and implementation and/or initial documentation
 *******************************************************************************/
#ifndef _CONFIG_H_
#define _CONFIG_H_


#include <datatype.h>

/*!Define the number of times the CTimerHandler will be called per second.
 *
 * FORTE will use this information to calculate time values.
 */
const TForteUInt32 cgForteTicksPerSecond = 1000;

/*! Define the initial size of the event chain list used in the event chain execution thread.
 *
 */
const unsigned int cgEventChainEventListSize = 256;


/*! Define the initial size of the event chain's external event list.
 */
const unsigned int cgEventChainExternalEventListSize = 16;


/*! Defines the number of pending communication messages can be handled by a communication function block
 *
 */
const unsigned int cgCommunicationInterruptQueueSize = 10;


/*! Buffer size in bytes to be used by the ip layer as receive buffer.
 *
 */
const unsigned int cgIPLayerRecvBufferSize = 20000;

/*! \brief Define the management encapsulation protocol
 *
 * Currently two protocols are supported:
 *   # DEV_MGR for FBDK compliant XML encoded commands
 *   # WBXML_DEV_MGR for WAP Binary XML encoded commands
 */
#define FORTE_MGM_COMMAND_PROTOCOL   

//! Max supported hierarchy that can be provided in a management commands
#define FORTE_MGM_MAX_SUPPORTED_NAME_HIERARCHY   30

/*! \brief FORTE string dict's initial string buffer size
 * 
 * Depending on the FORTE_STRING_DICT_FIXED_MEMORY flag the string dict will reallocate if necessary.
 */
const TForteUInt32 cgStringDictInitialStringBufSize = 8000;


/*! \brief FORTE string initial size
 * 
 * 
 */
const TForteUInt32 cgStringInitialSize = 128;

/*! \brief FORTE string dict's initial max nr of strings
 *
 * Depending on the FORTE_STRING_DICT_FIXED_MEMORY flag the string dict will reallocate if necessary.
 */
const TForteUInt32 cgStringDictInitialMaxNrOfStrings = 300;

const TForteUInt32 cgNumberOfHandlers = 2;

#define FORTE_BOOT_FILE_LOCATION "/data/test_FORTE_PC.fboot"

extern char* gCommandLineBootFile;

#define FORTE_SUPPORT_MONITORING

#define configMINIMAL_STACK_SIZE_FORTE 15000

#define FORTE_LOGGER_BUFFER_SIZE 300

#define FORTE_MODULE_ESP32



#endif
