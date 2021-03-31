#include "ADS1115.h"

#define ADS1115_ADDRESS 0x90

extern I2C_HandleTypeDef hi2c1;


void InitADS1115(uint8_t channel)
{
	unsigned char buffer[3];	
	unsigned char ads1115_addr = 0x90;
	
	if(channel > 3)
		channel = 0;
	buffer[0] = 0x01;
	buffer[1] = 0xC2 + (channel * 16);
	buffer[2] = 0x83;	
	HAL_I2C_Master_Transmit(&hi2c1, ads1115_addr, (uint8_t *)buffer, 3, 100);
	HAL_Delay(10);
}

float Read_Ads1115(void)
{
	unsigned char buffer[3];	
	unsigned char ads1115_addr = 0x90;
	unsigned short data = 0;
	
	buffer[0] = 0x00;
	HAL_I2C_Master_Transmit(&hi2c1, ads1115_addr, (uint8_t *)buffer, 1, 100);
	HAL_Delay(10);
	HAL_I2C_Master_Receive(&hi2c1, ads1115_addr + 1, buffer, 2, 100);
	data = (buffer[0] << 8) + buffer[1];
	if(data == 0xFFFF) data = 0;
	
	return (float)(0.125 * (float)data);
}

