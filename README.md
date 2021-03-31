STM32 library for read result ADC from ADS1115 with i2c protocol
using mcu STM32F429ZI and HAL library

First select your channel with -> void InitADS1115(uint8_t channel)
Then read float value with -> float Read_Ads1115(void)
