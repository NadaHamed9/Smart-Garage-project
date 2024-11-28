 /******************************************************************************
 *
 * Module: PIR SENSOR
 *
 * File Name: pir_sensor.h
 *
 * Description: Header file for the PIR sensor driver
 *
 * Author: Nada Hamed
 *
 *******************************************************************************/

#ifndef PIR_SENSOR_H_
#define PIR_SENSOR_H_

#include "std_types.h"
#include "gpio.h"
#include <util/delay.h>

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/* PIR sensors port configurations */
#define SENSOR_1_INPUT_PORT_ID               PORTB_ID
#define SENSOR_1_INPUT_PIN_ID                PIN1_ID

#define SENSOR_2_INPUT_PORT_ID               PORTB_ID
#define SENSOR_2_INPUT_PIN_ID                PIN2_ID


/* Keypad button logic configurations */
#define MOTION_DETECTED                 LOGIC_HIGH
#define MOTION_NOT_DETECTED             LOGIC_LOW

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * initialize two PIR sensors.
 */
void PIR_init(void);

/*
 * Description :get readings of sensor returns 1 if detected motion
 * returns 0 if there's no motion .
 */
uint8 detect_motion(uint8 port_num, uint8 pin_num);

#endif /* PIR_SENSOR_H_ */
