/******************************************************************************
 *
 * Module: PIR SENSOR
 *
 * File Name: pir_sensor.c
 *
 * Description: Source file for the PIR sensor driver
 *
 * Author: Nada Hamed
 *
 *******************************************************************************/
#include "pir_sensor.h"

void PIR_init(void)
{
	/* Configure the direction for the two PIR sensors as input pin */
	GPIO_setupPinDirection(SENSOR_1_INPUT_PORT_ID ,SENSOR_1_INPUT_PIN_ID,PIN_INPUT);
	GPIO_setupPinDirection(SENSOR_2_INPUT_PORT_ID ,SENSOR_2_INPUT_PIN_ID,PIN_INPUT);

	_delay_ms(3000);		/* waits 3sec till sensor stabilize*/

}

uint8 detect_motion(uint8 port_num, uint8 pin_num)
{
	return GPIO_readPin(port_num,pin_num);
}

