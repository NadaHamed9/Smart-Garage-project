/******************************************************************************
 *
 * Module: APP
 *
 * File Name: app.c
 *
 * Description: Source file for the App
 *
 * Author: Nada Hamed
 *
 *******************************************************************************/

#include "app.h"

void init_all(void)
{
	UART_ConfigType info_uart={six_bit,disapled,one_bit,rate7};
	SREG|=(1<<7);    /*         enable I-bit      */
	LCD_init();/*     Initialize LCD       */
	UART_init(&info_uart);/*     Initialize   UART    */
	PIR_init();/*     Initialize 2 PIR sensors      */
	default_message();
}

void default_message(void)
{
	uint8 pressed;

	/*display default message on lcd in garage*/
	LCD_clearScreen();
	LCD_displayString("How can i help you :) ? ");
	LCD_moveCursor(1,0);
	LCD_displayString("Press 1: Find My Slot  ");


	/* take pressed key from user */
	pressed=KEYPAD_getPressedKey();
	_delay_ms(500);
	/*Press time */
	while(pressed!='1')
	{
		/*     wait till user choose option     */
		pressed=KEYPAD_getPressedKey();
		_delay_ms(500);
		/*        Press time      */
	}

	find_slot();
}

void find_slot(void)
{
	uint8 ID[ID_LENGTH + 1] = {0}; /*Initialize it by NULL*/
	uint8 pressed;
	uint8 flag=0;
	uint8 slot_num=0;

	LCD_clearScreen();
	LCD_displayString("please enter your ID");

	/* take from user 4-numbers ID */
	for(uint8 i=0;i<4;i++)
	{
		pressed=KEYPAD_getPressedKey();

		if(pressed>=0 && pressed<=9)
		{
			LCD_displayCharacter('*');
			/*store entered digit*/
			ID[i]=pressed;
			_delay_ms(500);

		}
		/*if user entered symbol don't count it*/
		else i--;
	}

	while(KEYPAD_getPressedKey() != enter)
	{
		/*     wait for user to press enter    */
	}
	/*terminate it by NULL*/
	ID[ID_LENGTH] = '\0';
	flag=verify_ID(ID);

	/*if ID is not verified */
	if(flag == 0)
	{
		LCD_clearScreen();
		LCD_displayString("WRONG ID try again");
		/* display message for 5 sec*/
		_delay_ms(5000);
		/*return to default message to try again*/
		default_message();
	}
	/*ID is verified*/
	else{
		/*reset flag to 0*/
		flag=0;
		slot_num=my_slot(ID);
		LCD_clearScreen();
		/*if car at slot1*/
		if(slot_num == 1)
		{
			LCD_displayString("Your Car at Slot num 1 ");
			/* display message for 10 sec*/
			_delay_ms(10000);
			/*reset slot_num to None 0*/
			slot_num=0;
			/*return to default message to try again*/
			default_message();
		}
		/*if car at slot2*/
		else if(slot_num == 2)
		{
			LCD_displayString("Your Car at Slot num 2 ");
			/* display message for 10 sec*/
			_delay_ms(10000);
			/*reset slot_num to None 0*/
			slot_num=0;
			/*return to default message to try again*/
			default_message();
		}
		/*if user is verified but doesn't have parked his car yet*/
		else if(slot_num ==0 )
		{
			LCD_displayString("Your car is not parked at the garage ");
			/* display message for 10 sec*/
			_delay_ms(10000);
			/*return to default message to try again*/
			default_message();
		}
	}
}

uint8 verify_ID(uint8* ID)
{
	uint8 found=0;
	for (uint8 i = 0; i < NUM_USERS; i++) {
		/*Compare entered ID with each stored IDs*/
		if (strcmp((const char*) ID, (const char*)users_ID[i]) == 0) {
			/*ID is verified */
			found = 1;
			return found;
		}
	}
	/* ID is not verified */
	return found;
}

uint8 my_slot(uint8* ID)
{
	uint8 index;
	uint8 slot_num;
	for (index = 0; index < NUM_USERS; index++) {
		/*Compare given ID with each stored IDs to get index*/
		if (strcmp((const char*)ID, (const char*)users_ID[index]) == 0) {
			/*ID is verified */
			break;
		}
	}
	/*get slot num assigned to given ID */
	slot_num=slot_num_assigned[index];
	return slot_num;
}
