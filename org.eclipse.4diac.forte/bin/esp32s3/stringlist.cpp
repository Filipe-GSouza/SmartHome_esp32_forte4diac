/*******************************************************************************
 * Copyright (c) 2010 - 2012 ACIN, Profactor GmbH
 * This program and the accompanying materials are made available under the
 * terms of the Eclipse Public License 2.0 which is available at
 * http://www.eclipse.org/legal/epl-2.0.
 *
 * SPDX-License-Identifier: EPL-2.0
 *
 * Contributors:
 *   Michael Hofmann, Alois Zoitl, Ingo Hegny
 *     - initial API and implementation and/or initial documentation
 *******************************************************************************/

//!!!autogenerated code - DO NOT EDIT!!!
#include "stringlist.h"



#ifdef FORTE_STRING_DICT_FIXED_MEMORY
  CStringDictionary::TStringId CStringDictionary::scmIdList[cgFORTE_StringDictInitialMaxNrOfStrings]
#else
  const CStringDictionary::TStringId CStringDictionary::scmIdList[] 
#endif
  = {0, 4, 16, 24, 33, 43, 52, 65, 80, 88, 102, 110, 119, 130, 141, 154, 160, 170, 179, 184, 189, 199, 204, 214, 217, 221, 226, 230, 234, 237, 242, 246, 249, 253, 256, 258, 263, 277, 285, 290, 300, 304, 308, 311, 317, 329, 334, 340, 343, 347, 351, 355, 363, 366, 370, 374, 378, 382, 385, 391, 397, 404, 417, 425, 433, 441, 448, 457, 467, 475, 484, 493, 500, 510, 515, 526, 535, 544, 552, 557, 569, 581, 595, 604, 612, 619, 629, 639, 649, 651, 656, 672, 689, 700, 715, 727, 737, 747, 756, 768, 779, 796, 811, 820, 834, 851, 855, 860, 873, 890, 893, 896, 899, 902, 905, 909, 915, 920, 926, 930, 938, 947, 950, 953, 955, 959, 965, 968, 974, 989, 993, 997, 1002, 1008, 1020, 1023, 1029, 1042, 1047, 1053, 1057, 1064, 1071, 1073, 1083, 1092, 1096, 1112, 1122, 1129, 1136, 1146, 1149, 1151, 1154, 1157, 1160, 1163, 1166, 1169, 1172, 1175, 1177, 1182, 1192, 1196, 1202, 1207, 1215, 1218, 1223, 1227, 1229, 1234, 1238, 1243, 1256, 1273, 1278, 1288, 1294, 1300, 1307, 1317, 1322, 1329, 1343, 1355, 1357, 1360, 1375, 1380, 1390, 1402, 1405, 1409, 1417, 1431, 1437, 1449, 1454, 1464, 1470, 1476, 1488, 1492, 1498, 1505, 1510, 1516, 1521, 1531, 1539, 1555, 1560, 1565, 1571, 1585, 1595, 1602, 1613, 1620, 1630};

#ifdef FORTE_STRING_DICT_FIXED_MEMORY
  char CStringDictionary::scmConstStringBuf[cgFORTE_StringDictInitialStringBufSize]
#else
  const char CStringDictionary::scmConstStringBuf[] 
#endif
  = {"ANY\0ANY_ADAPTER\0ANY_BIT\0ANY_CHAR\0ANY_CHARS\0ANY_DATE\0ANY_DURATION\0ANY_ELEMENTARY\0ANY_INT\0ANY_MAGNITUDE\0ANY_NUM\0ANY_REAL\0ANY_SIGNED\0ANY_STRING\0ANY_UNSIGNED\0ARRAY\0ARTimeOut\0ATimeOut\0A_IN\0BOOL\0BOOL2BOOL\0BYTE\0BYTE2BYTE\0CD\0CDO\0CHAR\0CLK\0CNF\0CO\0COLD\0CTR\0CU\0CUO\0CV\0D\0DATE\0DATE_AND_TIME\0DEV_MGR\0DINT\0DINT2DINT\0DLY\0DST\0DT\0DWORD\0DWORD2DWORD\0D_IN\0D_OUT\0EI\0EI0\0EI1\0EI2\0EMB_RES\0EO\0EO0\0EO1\0EO2\0EO3\0ET\0E_CTD\0E_CTU\0E_CTUD\0E_CTUD_UDINT\0E_CYCLE\0E_DELAY\0E_DEMUX\0E_D_FF\0E_F_TRIG\0E_IMPULSE\0E_MERGE\0E_PERMIT\0E_RDELAY\0E_REND\0E_RESTART\0E_RS\0E_RTimeOut\0E_R_TRIG\0E_SELECT\0E_SPLIT\0E_SR\0E_SR_RETRIG\0E_STOPWATCH\0E_STOPWATCH_T\0E_SWITCH\0E_TRAIN\0E_T_FF\0E_TimeOut\0FB_RANDOM\0FILE_NAME\0G\0GATE\0GEN_ARRAY2ARRAY\0GEN_ARRAY2VALUES\0GEN_CLIENT\0GEN_CSV_WRITER\0GEN_E_DEMUX\0GEN_E_MUX\0GEN_F_MUX\0GEN_PUBL\0GEN_PUBLISH\0GEN_SERVER\0GEN_STRUCT_DEMUX\0GEN_STRUCT_MUX\0GEN_SUBL\0GEN_SUBSCRIBE\0GEN_VALUES2ARRAY\0GET\0GETO\0GET_AT_INDEX\0GET_STRUCT_VALUE\0IB\0ID\0IE\0IL\0IN\0IND\0INDEX\0INIT\0INITO\0INT\0INT2INT\0IN_ARRAY\0IW\0IX\0K\0KEY\0LABEL\0LD\0LDATE\0LDATE_AND_TIME\0LDO\0LDT\0LINT\0LREAL\0LREAL2LREAL\0LT\0LTIME\0LTIME_OF_DAY\0LTOD\0LWORD\0MGR\0MGR_FF\0MGR_ID\0N\0NVS_UDINT\0NVS_UINT\0OUT\0OUT_ANY_CONSOLE\0OUT_ARRAY\0PARAMS\0PERMIT\0PUBLISH_1\0PV\0Q\0QB\0QD\0QI\0QL\0QO\0QU\0QW\0QX\0R\0REAL\0REAL2REAL\0REQ\0RESET\0RESP\0RMT_RES\0RO\0RQST\0RSP\0S\0SEED\0SET\0SETO\0SET_AT_INDEX\0SET_STRUCT_VALUE\0SINT\0SINT2SINT\0START\0STATE\0STATUS\0STEST_END\0STOP\0STRING\0STRING2STRING\0SUBSCRIBE_1\0T\0TD\0TEST_CONDITION\0TIME\0TIME2TIME\0TIME_OF_DAY\0TM\0TOD\0TimeOut\0TimeOutSocket\0UDINT\0UDINT2UDINT\0UINT\0UINT2UINT\0ULINT\0USINT\0USINT2USINT\0VAL\0VALUE\0VALUEO\0WARM\0WCHAR\0WORD\0WORD2WORD\0WSTRING\0WSTRING2WSTRING\0_MAX\0_MIN\0check\0element_value\0in_struct\0member\0out_struct\0output\0startTime\0wARM\0"};

 
