Error codes (customer reference)
================================

This document maps numeric **ErrorMessage** fields to human-readable meanings.


Module numbers
--------------

.. list-table::
   :widths: 14 86
   :header-rows: 1

   * - Module number
     - Module name
   * - 1
     - ERR_REP_MOD_APP_TASK
   * - 2
     - ERR_REP_MOD_APP_COMM
   * - 3
     - ERR_REP_MOD_APP_SAFETY
   * - 4
     - ERR_REP_MOD_APP_CP_PP
   * - 5
     - ERR_REP_MOD_APP_TEMP
   * - 6
     - ERR_REP_MOD_APP_SYSTEM
   * - 7
     - ERR_REP_MOD_MW_ADC
   * - 8
     - ERR_REP_MOD_MW_I2C
   * - 9
     - ERR_REP_MOD_MW_PIN
   * - 10
     - ERR_REP_MOD_MW_PWM
   * - 11
     - ERR_REP_MOD_MW_UART
   * - 12
     - ERR_REP_MOD_MW_PARAM

ERR_REP_MOD_APP_TASK (module = 1)
---------------------------------

.. list-table:: Error codes
   :widths: 10 28 38 12 12
   :header-rows: 1

   * - Code
     - Name
     - Description
     - Add. Data 1
     - Add. Data 2
   * - 1
     - ERR_CODES_TASK_NOT_EXECUTED
     - task was not executed in time
     - task id
     - -

ERR_REP_MOD_APP_COMM (module = 2)
---------------------------------

.. list-table:: Error codes
   :widths: 10 28 38 12 12
   :header-rows: 1

   * - Code
     - Name
     - Description
     - Add. Data 1
     - Add. Data 2
   * - 1
     - ERR_CODES_COMM_SAFETY_MSG_TIMEOUTED
     - safety message timeouted
     - message id
     - last timestamp

ERR_REP_MOD_APP_SAFETY (module = 3)
-----------------------------------

.. list-table:: Error codes
   :widths: 10 28 38 12 12
   :header-rows: 1

   * - Code
     - Name
     - Description
     - Add. Data 1
     - Add. Data 2
   * - 1
     - ERR_CODES_SAFETY_STATE_MISMATCH
     - safety state mismatch
     - active safety fault
     - inverted safety fault
   * - 2
     - ERR_CODES_SAFETY_CP_FAULT
     - CP safety fault
     - CP pos voltage
     - CP neg voltage

ERR_REP_MOD_APP_CP_PP (module = 4)
----------------------------------

.. list-table:: Error codes
   :widths: 10 28 38 12 12
   :header-rows: 1

   * - Code
     - Name
     - Description
     - Add. Data 1
     - Add. Data 2
   * - 1
     - ERR_CODES_CP_PP_CP_ERROR
     - 
     - CP pos voltage
     - CP neg voltage
   * - 2
     - ERR_CODES_CP_PP_PP_ERROR
     - 
     - PP voltage
     - -

ERR_REP_MOD_APP_TEMP (module = 5)
---------------------------------

.. list-table:: Error codes
   :widths: 10 28 38 12 12
   :header-rows: 1

   * - Code
     - Name
     - Description
     - Add. Data 1
     - Add. Data 2
   * - 1
     - ERR_CODES_TEMP_SHORT_TO_BAT
     - short to battery
     - raw current
     - index
   * - 2
     - ERR_CODES_TEMP_SHORT_TO_GND
     - short to ground
     - raw current
     - index:4 | raw voltage:12
   * - 3
     - ERR_CODES_TEMP_OPEN_LOAD
     - open load
     - raw current
     - index:4 | raw voltage:12
   * - 4
     - ERR_CODES_TEMP_OVER_LIMIT
     - temperature over limit
     - raw temp
     - index
   * - 5
     - ERR_CODES_TEMP_UNDER_LIMIT
     - temperature under limit
     - raw temp
     - index
   * - 6
     - ERR_CODES_TEMP_RESISTANCE_TOO_HIGH
     - resistance too high
     - resistance/10000
     - index
   * - 7
     - ERR_CODES_TEMP_RESISTANCE_NEGATIVE
     - resistance negative
     - abs(resistance)
     - index
   * - 8
     - ERR_CODES_TEMP_INVALID_EVALUATION_STATE
     - invalid evaluation state
     - state
     - -

ERR_REP_MOD_APP_SYSTEM (module = 6)
-----------------------------------

.. list-table:: Error codes
   :widths: 10 28 38 12 12
   :header-rows: 1

   * - Code
     - Name
     - Description
     - Add. Data 1
     - Add. Data 2
   * - 1
     - ERR_CODES_SYSTEM_WATCHDOG_SELFTEST
     - watchdog error
     - watchdog state
     - -
   * - 2
     - ERR_CODES_SYSTEM_APP_INIT_FAILED
     - application initial selftests failed
     - -
     - -
   * - 3
     - ERR_CODES_SYSTEM_APP_CRC_MISMATCH
     - application CRC mismatch
     - calculated CRC
     - stored CRC
   * - 4
     - ERR_CODES_SYSTEM_APP_INIT_ADC_ERROR
     - application initial ADC test error
     - -
     - -
   * - 5
     - ERR_CODES_SYSTEM_CPU_TEST_ERROR
     - CPU test error
     - -
     - -
   * - 6
     - ERR_CODES_SYSTEM_RAM_TEST_ERROR
     - RAM test error
     - -
     - -
   * - 7
     - ERR_CODES_SYSTEM_CLOCK_TEST_ERROR
     - clock test error
     - -
     - -
   * - 8
     - ERR_CODES_SYSTEM_CLOCK_STOP_ERROR
     - clock stop error
     - -
     - -
   * - 9
     - ERR_CODES_SYSTEM_ROM_TEST_ERROR
     - ROM test error
     - -
     - -
   * - 10
     - ERR_CODES_SYSTEM_ADC_TEST_ERROR
     - ADC test error
     - -
     - -
   * - 11
     - ERR_CODES_SYSTEM_VOLTAGE_TEST_ERROR
     - voltage test error
     - -
     - -
   * - 12
     - ERR_CODES_SYSTEM_TEMPERATURE_ERROR
     - temperature error
     - -
     - -
   * - 13
     - ERR_CODES_SYSTEM_OTHER_TEST_FAILED
     - other test failed
     - -
     - -

ERR_REP_MOD_MW_ADC (module = 7)
-------------------------------

.. list-table:: Error codes
   :widths: 10 28 38 12 12
   :header-rows: 1

   * - Code
     - Name
     - Description
     - Add. Data 1
     - Add. Data 2
   * - 1
     - ERR_CODES_ADC_ELC_INIT_FAILED
     - ELC initialization failed
     - FSP error code
     - -
   * - 2
     - ERR_CODES_ADC_INIT_FAILED
     - ADC initialization failed
     - FSP error code
     - -
   * - 3
     - ERR_CODES_ADC_INIT_SCAN_CFG_FAILED
     - ADC scan configuration failed
     - FSP error code
     - -
   * - 4
     - ERR_CODES_ADC_ELC_ENABLE_FAILED
     - ELC enable failed
     - FSP error code
     - -
   * - 5
     - ERR_CODES_ADC_SCAN_START_FAILED
     - ADC scan start failed
     - FSP error code
     - -
   * - 6
     - ERR_CODES_ADC_INIT_GPT_FAILED
     - GPT initialization failed
     - FSP error code
     - -
   * - 7
     - ERR_CODES_ADC_START_GPT_FAILED
     - GPT start failed
     - FSP error code
     - -
   * - 8
     - ERR_CODES_ADC_READ_FAILED
     - ADC read failed
     - group
     - FSP error code
   * - 9
     - ERR_CODES_ADCIF_GET_VALUE_INVALID_PARAM
     - invalid parameter for adcif_get_value
     - value
     - average_size

ERR_REP_MOD_MW_I2C (module = 8)
-------------------------------

No specific error codes documented for this module.

ERR_REP_MOD_MW_PIN (module = 9)
-------------------------------

No specific error codes documented for this module.

ERR_REP_MOD_MW_PWM (module = 10)
--------------------------------

.. list-table:: Error codes
   :widths: 10 28 38 12 12
   :header-rows: 1

   * - Code
     - Name
     - Description
     - Add. Data 1
     - Add. Data 2
   * - 1
     - ERR_CODES_PWM_INIT_GPT_FAILED
     - GPT initialization failed
     - FSP error code
     - -
   * - 2
     - ERR_CODES_PWM_START_GPT_FAILED
     - GPT start failed
     - FSP error code
     - -
   * - 3
     - ERR_CODES_PWM_SET_DUTYCYCLE_FAILED
     - setting duty cycle failed
     - dutycycle
     - FSP error code

ERR_REP_MOD_MW_UART (module = 11)
---------------------------------

.. list-table:: Error codes
   :widths: 10 28 38 12 12
   :header-rows: 1

   * - Code
     - Name
     - Description
     - Add. Data 1
     - Add. Data 2
   * - 1
     - ERR_CODES_UART_INIT_FAILED
     - UART initialization failed
     - FSP error code
     - -
   * - 2
     - ERR_CODES_UART_RX_BUFFER_OVERFLOW
     - UART RX buffer overflow
     - packet type
     - buffer index
   * - 3
     - ERR_CODES_UART_TX_BUFFER_OVERFLOW
     - UART TX buffer overflow
     - packet type
     - buffer index
   * - 4
     - ERR_CODES_UART_TX_FAILED
     - UART TX failed
     - packet type
     - FSP error code
   * - 5
     - ERR_CODES_UART_NO_TX_PACKET_SET
     - no TX packet set
     - -
     - -

ERR_REP_MOD_MW_PARAM (module = 12)
----------------------------------

.. list-table:: Error codes
   :widths: 10 28 38 12 12
   :header-rows: 1

   * - Code
     - Name
     - Description
     - Add. Data 1
     - Add. Data 2
   * - 1
     - ERR_CODES_PARAM_NOT_FOUND
     - parameter not found in memory, defaults will be used
     - -
     - -
   * - 2
     - ERR_CODES_PARAM_CRC_MISMATCH
     - CRC mismatch, defaults will be used
     - calculated CRC
     - stored CRC
   * - 3
     - ERR_CODES_PARAM_INDEX_OUT_OF_BOUNDS
     - index out of bounds
     - index
     - [1= temp
