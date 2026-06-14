/*
 * BME280.h
 *
 *  Created on: May 29, 2026
 *      Author: ahmedramy
 */

#ifndef INC_BME280_H_
#define INC_BME280_H_
#include "stm32f1xx_hal.h"

int BME280_Config(uint8_t osrs_t , uint8_t osrs_p , uint8_t osrs_h, uint8_t mode , uint8_t t_sb , uint8_t filter );
void TrimRead(void);
void BME280_WakeUP(void);
void BME280_Measure (void);


// oversampling values lives in registers and will be used by other registers
#define OSRS_OFF    	0x00
#define OSRS_1      	0x01
#define OSRS_2      	0x02
#define OSRS_4      	0x03
#define OSRS_8      	0x04
#define OSRS_16     	0x05


// mode definitions
#define sleep 0x00
#define forced 0x01
#define normal 0x03

// stand by time
#define T_SB_0p5    	0x00
#define T_SB_62p5   	0x01
#define T_SB_125    	0x02
#define T_SB_250    	0x03
#define T_SB_500    	0x04
#define T_SB_1000   	0x05
#define T_SB_10     	0x06
#define T_SB_20     	0x07

// IIR filter settings
#define IIR_OFF     	0x00
#define IIR_2       	0x01
#define IIR_4       	0x02
#define IIR_8       	0x03
#define IIR_16      	0x04


// important registers
#define ID 0xD0
#define reset 0xE0
#define ctrl_hum 0xF2
#define status 0xF3
#define ctrl_meas 0xF4
#define config 0xF5
#define PRESS_MSB_REG   0xF7









#endif /* INC_BME280_H_ */
