 /******************************************************************************
 *
 * Module: APP
 *
 * File Name: app.h
 *
 * Description: Header file for the App
 *
 * Author: Nada Hamed
 *
 *******************************************************************************/

#ifndef APP_H_
#define APP_H_

#include "std_types.h"
#include "keypad.h"
#include "lcd.h"
#include "uart.h"
#include <util/delay.h>
#include <avr/io.h>
#include <string.h>


#define enter 13         /* # sign */
#define NUM_USERS 5      /* Number of stored user IDs */
#define ID_LENGTH 4      /* Length of each user ID */

/*Stored IDs*/
uint8 users_ID[NUM_USERS][ID_LENGTH + 1] ={"1234","5678","9101","2351","1352"};

/* user's index 0 whose ID is 1234
 * user's index 1 whose ID is 5678
 * user's index 2 whose ID is 9101
 * user's index 3 whose ID is 2351
 * user's index 4 whose ID is 1352
 * 0 means not parked at garage yet
 * 1 means this user parked at slot num1
 * 2 means this user parked at slot num2
 */
uint8 slot_num_assigned[NUM_USERS]={0,0,0,0};

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * initialize lcd , keypad , display default message.
 */
void init_all(void);

/*
 * Description :
 * Displays welcome message and options.
 */
void default_message(void);

/*
 * Description :
 * Takes ID from user and call verify_ID() function to check this ID is verified
 * or not then call my_slot() function to see which slot this ID assigned to then
 * display slot num.
 */
void find_slot(void);

/*
 * Description :
 * Check if this ID is verified or not return 1 if it's verified
 * and returns 0 if not.
 */
uint8 verify_ID(uint8 ID);

/*
 * Description :
 * See what slot does this ID assigned returns 1 in case of slot1 and
 * returns 2 in case of slot2 and returns 0 in case of none "not parked yet" .
 */
uint8 my_slot(uint8 ID);

#endif /* APP_H_ */
