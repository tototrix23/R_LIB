/*
 * h_return_codes.h
 *
 *  Created on: Aug 28, 2023
 *      Author: Christophe
 */

#ifndef HAL_H_RETURN_CODES_H_
#define HAL_H_RETURN_CODES_H_

#define X_RET_ERROR_SERIAL_OPEN                  -1000
#define X_RET_ERROR_SERIAL_FLUSH                 -1001
#define X_RET_ERROR_SERIAL_CONFIGURE             -1002
#define X_RET_ERROR_SERIAL_GENERIC               -1003
#define X_RET_ERROR_SERIAL_READ                  -1004
#define X_RET_ERROR_SERIAL_WRITE                 -1005

#define X_RET_ERROR_AT_TIMEOUT                   -1110
#define X_RET_ERROR_AT                           -1111
#define X_RET_ERROR_AT_BAD_HEADER                -1112
#define X_RET_ERROR_AT_BUSY                      -1113
#define X_RET_ERROR_AT_PARSING_VAR               -1114
#define X_RET_ERROR_AT_VAR_COUNT                 -1115
#define X_RET_ERROR_AT_VAR_STRING_SIZE           -1116
#define X_RET_ERROR_AT_VAR_PARSING_INT           -1117
#define X_RET_ERROR_AT_VAR_PARSING_UINT          -1118
#define X_RET_ERROR_AT_VAR_PARSING_FLOAT         -1119
#define X_RET_ERROR_AT_VAR_BAD_RANGE             -1120
#define X_RET_ERROR_AT_VAR_PARSING_EMPTY         -1121

#define X_RET_ERROR_GSM_INITIALISE               -1150
#define X_RET_ERROR_GSM_MODEL_NOT_SUPPORTED      -1151
#define X_RET_ERROR_GSM_READ_MANUFACTURER        -1152
#define X_RET_ERROR_GSM_READ_MODEL               -1153
#define X_RET_ERROR_GSM_READ_VERSION             -1154
#define X_RET_ERROR_GSM_READ_CCID                -1155
#define X_RET_ERROR_GSM_READ_IMEI                -1156
#define X_RET_ERROR_GSM_NO_OPERATOR              -1157
#define X_RET_ERROR_GSM_UNSUPPORTED_NETWORK      -1158
#define X_RET_ERROR_GSM_ATTACH_NETWORK           -1159
#define X_RET_ERROR_GSM_DETACH_NETWORK           -1160
#define X_RET_ERROR_GSM_READING_OPERATOR         -1161
#define X_RET_ERROR_GSM_GETTING_RSSI             -1162
#define X_RET_ERROR_GSM_SOCKET_CONFIG            -1163
#define X_RET_ERROR_GSM_SOCKET_CONNECT           -1164
#define X_RET_ERROR_GSM_SOCKET_SEND              -1165
#define X_RET_ERROR_GSM_SOCKET_READ              -1166
#define X_RET_ERROR_GSM_SOCKET_ALREADY_OPENED    -1167
#define X_RET_ERROR_GSM_SOCKET_ALREADY_CLOSED    -1168
#define X_RET_ERROR_GSM_NETWORK_ALREADY_ATTACHED -1169
#define X_RET_ERROR_GSM_NETWORK_ALREADY_DETACHED -1170
#define X_RET_ERROR_GSM_NETWORK_NOT_ATTACHED     -1171
#define X_RET_ERROR_GSM_GENERIC                  -1172
#define X_RET_ERROR_GSM_RESPONSE_REFUSED         -1173

#define X_RET_ERROR_GSM_SOCKET_NOT_OPENED        -1180
#define X_RET_ERROR_GSM_SOCKET_DISCONNECT        -1181
#define X_RET_ERROR_GSM_NO_CALLBACK              -1182
#define X_RET_ERROR_GSM_RESET                    -1183
#define X_RET_ERROR_GSM_GPS_POWER_ON             -1184
#define X_RET_ERROR_GSM_GPS_READ                 -1185
#define X_RET_ERROR_GSM_CCLKMODE                 -1186
#define X_RET_ERROR_GSM_CCLK                     -1187
#define X_RET_ERROR_GSM_NTP                      -1188

#define X_RET_ERROR_COM_BAD_ADDR                 -1200
#define X_RET_ERROR_COM_TIMEOUT                  -1201
#define X_RET_ERROR_COM_HEADER                   -1202
#define X_RET_ERROR_COM_CRC                      -1203

#endif /* HAL_H_RETURN_CODES_H_ */
