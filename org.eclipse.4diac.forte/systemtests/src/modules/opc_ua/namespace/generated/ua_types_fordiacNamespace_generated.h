/**********************************
 * Autogenerated -- do not modify *
 **********************************/

#ifndef UA_TYPES_FORDIACNAMESPACE_GENERATED_H_
#define UA_TYPES_FORDIACNAMESPACE_GENERATED_H_

#if 1
#include "open62541.h"
#else
#include <open62541/types.h>
#include <open62541/types_generated.h>

#endif



_UA_BEGIN_DECLS


/**
 * Every type is assigned an index in an array containing the type descriptions.
 * These descriptions are used during type handling (copying, deletion,
 * binary encoding, ...). */
#define UA_UA_TYPES_FORDIACNAMESPACE_COUNT 1
extern UA_EXPORT const UA_DataType UA_UA_TYPES_FORDIACNAMESPACE[UA_UA_TYPES_FORDIACNAMESPACE_COUNT];

/**
 * DatatypeTest
 * ^^^^^^^^^^^^
 */
typedef struct {
    UA_String name;
    UA_SByte age;
    UA_Boolean isRegistered;
} UA_DatatypeTest;

#define UA_UA_TYPES_FORDIACNAMESPACE_DATATYPETEST 0


_UA_END_DECLS

#endif /* UA_TYPES_FORDIACNAMESPACE_GENERATED_H_ */
