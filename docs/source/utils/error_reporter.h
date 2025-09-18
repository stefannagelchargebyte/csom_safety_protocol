/*====================================================================*
 * Copyright (c) 2023 chargebyte GmbH
 *--------------------------------------------------------------------*/

/**
 * @file
 * @brief error reporter (header)
 *
 * Module provides functions to report an error in memory and over UART
 */

#ifndef ERROR_REPORTER_H_
#define ERROR_REPORTER_H_

#include <stdint.h>
#include <stdbool.h>
#include "common_com.h"

#define ERR_REP_NO_ADDITIONAL_DATA UINT16_MAX

/**
 * @brief modules, in which an error can occur
 */
typedef enum
{
    ERR_REP_MOD_DEFAULT = 0,
    ERR_REP_MOD_APP_TASK,
    ERR_REP_MOD_APP_COMM,
    ERR_REP_MOD_APP_SAFETY,
    ERR_REP_MOD_APP_CP_PP,
    ERR_REP_MOD_APP_TEMP,
    ERR_REP_MOD_APP_SYSTEM,
    ERR_REP_MOD_MW_ADC,
    ERR_REP_MOD_MW_I2C,
    ERR_REP_MOD_MW_PIN,
    ERR_REP_MOD_MW_PWM,
    ERR_REP_MOD_MW_UART,
    ERR_REP_MOD_MW_PARAM,

    ERR_REP_NUM_OF_MODULES

} err_rep_modules_t;




/**
 * @brief This is just a struct for generating the documentation
typedef struct
{
    err_codes_task_t err_codes_task;
    err_codes_comm_t err_codes_comm;
    err_codes_safety_t err_codes_safety;
    err_codes_cp_pp_t err_codes_cp_pp;
    err_codes_temp_t err_codes_temp;
    err_codes_system_t err_codes_system;
    err_codes_adc_t err_codes_adc;
    err_codes_pwm_t err_codes_pwm;
    err_codes_uart_t err_codes_uart;
    err_codes_param_t err_codes_param;
} err_rep_modules_documentationt_t;

 */




//--------------------------------------application modules--------------------------------------
//                                            comment [ additional data 1, additional data 2 ]

typedef enum
{
    ERR_CODES_TASK_DEFAULT = 0,
    ERR_CODES_TASK_NOT_EXECUTED, ///< task was not executed in time [task id, -]

    ERR_CODES_TASK_NUM_OF_CODES
} err_codes_task_t;

typedef enum
{
    ERR_CODES_COMM_DEFAULT = 0,
    ERR_CODES_COMM_SAFETY_MSG_TIMEOUTED, ///< safety message timeouted [message id, last timestamp]

    ERR_CODES_COMM_NUM_OF_CODES
} err_codes_comm_t;

typedef enum
{
    ERR_CODES_SAFETY_DEFAULT = 0,
    ERR_CODES_SAFETY_STATE_MISMATCH, ///< safety state mismatch [active safety fault, inverted safety fault]
    ERR_CODES_SAFETY_CP_FAULT,       ///< CP safety fault [CP pos voltage, CP neg voltage]

    ERR_CODES_SAFETY_NUM_OF_CODES
} err_codes_safety_t;

typedef enum
{
    ERR_CODES_CP_PP_DEFAULT = 0,
    ERR_CODES_CP_PP_CP_ERROR, ///< [CP pos voltage, CP neg voltage]
    ERR_CODES_CP_PP_PP_ERROR, ///< [PP voltage, -]

    ERR_CODES_CP_PP_NUM_OF_CODES
} err_codes_cp_pp_t;

typedef enum
{
    ERR_CODES_TEMP_DEFAULT = 0,
    ERR_CODES_TEMP_SHORT_TO_BAT,             ///< short to battery [raw current, index]
    ERR_CODES_TEMP_SHORT_TO_GND,             ///< short to ground [raw current, index:4 | raw voltage:12]
    ERR_CODES_TEMP_OPEN_LOAD,                ///< open load [raw current, index:4 | raw voltage:12]
    ERR_CODES_TEMP_OVER_LIMIT,               ///< temperature over limit [raw temp, index]
    ERR_CODES_TEMP_UNDER_LIMIT,              ///< temperature under limit [raw temp, index]
    ERR_CODES_TEMP_RESISTANCE_TOO_HIGH,      ///< resistance too high [resistance/10000, index]
    ERR_CODES_TEMP_RESISTANCE_NEGATIVE,      ///< resistance negative [abs(resistance), index]
    ERR_CODES_TEMP_INVALID_EVALUATION_STATE, ///< invalid evaluation state [state, -]


    ERR_CODES_TEMP_NUM_OF_CODES
} err_codes_temp_t;


typedef enum
{
    ERR_CODES_SYSTEM_DEFAULT = 0,
    ERR_CODES_SYSTEM_WATCHDOG_SELFTEST,  ///< watchdog error [watchdog state, -]
    ERR_CODES_SYSTEM_APP_INIT_FAILED,    ///< application initial selftests failed [-, -]
    ERR_CODES_SYSTEM_APP_CRC_MISMATCH,   ///< application CRC mismatch [calculated CRC, stored CRC]
    ERR_CODES_SYSTEM_APP_INIT_ADC_ERROR, ///< application initial ADC test error [-, -]
    ERR_CODES_SYSTEM_CPU_TEST_ERROR,     ///< CPU test error [-, -]
    ERR_CODES_SYSTEM_RAM_TEST_ERROR,     ///< RAM test error [-, -]
    ERR_CODES_SYSTEM_CLOCK_TEST_ERROR,   ///< clock test error [-, -]
    ERR_CODES_SYSTEM_CLOCK_STOP_ERROR,   ///< clock stop error [-, -]
    ERR_CODES_SYSTEM_ROM_TEST_ERROR,     ///< ROM test error [-, -]
    ERR_CODES_SYSTEM_ADC_TEST_ERROR,     ///< ADC test error [-, -]
    ERR_CODES_SYSTEM_VOLTAGE_TEST_ERROR, ///< voltage test error [-, -]
    ERR_CODES_SYSTEM_TEMPERATURE_ERROR,  ///< temperature error [-, -]
    ERR_CODES_SYSTEM_OTHER_TEST_FAILED,  ///< other test failed [-, -]


    ERR_CODES_SYSTEM_NUM_OF_CODES
} err_codes_system_t;

//--------------------------------------middleware modules--------------------------------------

typedef enum
{
    ERR_CODES_ADC_DEFAULT = 0,
    ERR_CODES_ADC_ELC_INIT_FAILED,           ///< ELC initialization failed [FSP error code, -]
    ERR_CODES_ADC_INIT_FAILED,               ///< ADC initialization failed [FSP error code, -]
    ERR_CODES_ADC_INIT_SCAN_CFG_FAILED,      ///< ADC scan configuration failed [FSP error code, -]
    ERR_CODES_ADC_ELC_ENABLE_FAILED,         ///< ELC enable failed [FSP error code, -]
    ERR_CODES_ADC_SCAN_START_FAILED,         ///< ADC scan start failed [FSP error code, -]
    ERR_CODES_ADC_INIT_GPT_FAILED,           ///< GPT initialization failed [FSP error code, -]
    ERR_CODES_ADC_START_GPT_FAILED,          ///< GPT start failed [FSP error code, -]
    ERR_CODES_ADC_READ_FAILED,               ///< ADC read failed [group, FSP error code]
    ERR_CODES_ADCIF_GET_VALUE_INVALID_PARAM, ///< invalid parameter for adcif_get_value [value, average_size]

    ERR_CODES_ADC_NUM_OF_CODES
} err_codes_adc_t;


typedef enum
{
    ERR_CODES_PWM_DEFAULT = 0,
    ERR_CODES_PWM_INIT_GPT_FAILED,      ///< GPT initialization failed [FSP error code, -]
    ERR_CODES_PWM_START_GPT_FAILED,     ///< GPT start failed [FSP error code, -]
    ERR_CODES_PWM_SET_DUTYCYCLE_FAILED, ///< setting duty cycle failed [dutycycle, FSP error code]

    ERR_CODES_PWM_NUM_OF_CODES
} err_codes_pwm_t;

typedef enum
{
    ERR_CODES_UART_DEFAULT = 0,
    ERR_CODES_UART_INIT_FAILED,         ///< UART initialization failed [FSP error code, -]
    ERR_CODES_UART_RX_BUFFER_OVERFLOW,  ///< UART RX buffer overflow [packet type, buffer index]
    ERR_CODES_UART_TX_BUFFER_OVERFLOW,  ///< UART TX buffer overflow [packet type, buffer index]
    ERR_CODES_UART_TX_FAILED,           ///< UART TX failed [packet type, FSP error code]
    ERR_CODES_UART_NO_TX_PACKET_SET,    ///< no TX packet set [ -, -]


    ERR_CODES_UART_NUM_OF_CODES
} err_codes_uart_t;

typedef enum
{
    ERR_CODES_PARAM_DEFAULT = 0,
    ERR_CODES_PARAM_NOT_FOUND,            ///< parameter not found in memory, defaults will be used [-, -]
    ERR_CODES_PARAM_CRC_MISMATCH,         ///< CRC mismatch, defaults will be used [calculated CRC, stored CRC]
    ERR_CODES_PARAM_INDEX_OUT_OF_BOUNDS,  ///< index out of bounds [index, [1= temp, 2=hv connector, 3=emergency in]]

    ERR_CODES_PARAM_NUM_OF_CODES
} err_codes_param_t;


/*====================================================================*
* global functions;
*--------------------------------------------------------------------*/

/**
 * @brief report an error, or set active again, when already reported, but not sent yet
 * @param module           module, in which this error occurred
 * @param error            error code, depending on module
 * @param additional_data  possibly set additional data
 */
void error_reporter_set_active(err_rep_modules_t module, uint16_t error, uint16_t additional_data1, uint16_t additional_data2);


/**
 * @brief set an possibly reported error to passive, if everything is ok again and the error was not sent yet
 * @param module  module, in which the error was solved
 * @param error   error code, which was solved
 */
void error_reporter_set_passive(err_rep_modules_t module, uint16_t error);


/**
 * @brief send the latest error over UART
 *
 * @param active           pointer to the active error flag
 * @param error_module     pointer to the error module
 * @param error_code       pointer to the error code
 * @param additional_data1 pointer to the additional data 1
 * @param additional_data2 pointer to the additional data 2
 *
 * @return true if an error was available, false if no error was available to be sent
 */
bool error_reporter_send_latest_error(uint8_t* active, uint16_t* error_module, uint16_t* error_code, uint16_t *additional_data1, uint16_t *additional_data2);


#endif /* ERROR_REPORTER_H_ */
