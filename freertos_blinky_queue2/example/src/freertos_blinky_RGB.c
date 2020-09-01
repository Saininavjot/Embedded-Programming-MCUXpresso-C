/*
 * @brief FreeRTOS Blinky example
 *
 * @note
 * Copyright(C) NXP Semiconductors, 2014
 * All rights reserved.
 *
 * @par
 * Software that is described herein is for illustrative purposes only
 * which provides customers with programming information regarding the
 * LPC products.  This software is supplied "AS IS" without any warranties of
 * any kind, and NXP Semiconductors and its licensor disclaim any and
 * all warranties, express or implied, including all implied warranties of
 * merchantability, fitness for a particular purpose and non-infringement of
 * intellectual property rights.  NXP Semiconductors assumes no responsibility
 * or liability for the use of the software, conveys no license or rights under any
 * patent, copyright, mask work right, or any other intellectual property rights in
 * or to any products. NXP Semiconductors reserves the right to make changes
 * in the software without notification. NXP Semiconductors also makes no
 * representation or warranty that such application will be suitable for the
 * specified use without further testing or modification.
 *
 * @par
 * Permission to use, copy, modify, and distribute this software and its
 * documentation is hereby granted, under NXP Semiconductors' and its
 * licensor's relevant copyrights in the software, without fee, provided that it
 * is used in conjunction with NXP Semiconductors microcontrollers.  This
 * copyright, permission, and disclaimer notice must appear in all copies of
 * this code.
 */

#include "board.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
xQueueHandle Queue_Handle;
/*****************************************************************************
 * Private types/enumerations/variables
 ****************************************************************************/

/*****************************************************************************
 * Public types/enumerations/variables
 ****************************************************************************/

/*****************************************************************************
 * Private functions
 ****************************************************************************/

/* Sets up system hardware */

static void prvSetupHardware(void)
{
	SystemCoreClockUpdate();
	Board_Init();

	/* Initial LED0 state is off */
	Board_LED_Set(0, FALSE);
	Board_LED_Set(1, FALSE);
	Board_LED_Set(2, FALSE);
}

/* LED1 toggle thread */
void sender_task(void *pvParameter)
{
	while (1)
	{
		for (int i = 0; i <= 2; ++i)// i define the LED color
		{
			xQueueSend(Queue_Handle, &i, 1000);// queue sends data i to receiver
		}
	}
}
void receiver_task(void *pvParameters)
{
	int currentColor;
	while (1)
	{
		if (xQueueReceive(Queue_Handle,&currentColor,1000) == pdTRUE)//it receive data from sender
		{
			if (currentColor == 0)// check if received data is 0
			{
				Board_LED_Set(currentColor, FALSE);//red led is turned off
				vTaskDelay(configTICK_RATE_HZ / 2);// delay of 0.5 sec
				Board_LED_Set(currentColor, TRUE);//red led turned on
				vTaskDelay(configTICK_RATE_HZ / 2);//delay of 0.5 sec
			}
			else if (currentColor == 1)// check if received data is 1
			{
				Board_LED_Set(currentColor, FALSE);// turn off Green LED
				/* About a 3Hz on/off toggle rate */
				vTaskDelay(configTICK_RATE_HZ / 2);
				Board_LED_Set(currentColor, TRUE);// turn on Green LED
				vTaskDelay(configTICK_RATE_HZ / 2);
			}
			else if (currentColor == 2)// if color is blue
			{
				Board_LED_Set(currentColor, FALSE);// turn off blue LED
				vTaskDelay(configTICK_RATE_HZ / 2);
				Board_LED_Set(currentColor, TRUE);// Turn on blue LED
				vTaskDelay(configTICK_RATE_HZ / 2);
			}
		}
	}
}
/*****************************************************************************
 * Public functions
 ****************************************************************************/

/**
 * @brief	main routine for FreeRTOS blinky example
 * @return	Nothing, function should not exit
 */
int main(void)
{

	prvSetupHardware();
	Queue_Handle = xQueueCreate(3, sizeof(int));
	if (Queue_Handle != 0)
	{
		xTaskCreate(sender_task, (signed char* ) "sender",
				configMINIMAL_STACK_SIZE, NULL, (tskIDLE_PRIORITY + 1UL),
				(xTaskHandle *) NULL);

		xTaskCreate(receiver_task, (signed char* ) "receiver",
				configMINIMAL_STACK_SIZE, NULL, (tskIDLE_PRIORITY + 1UL),
				(xTaskHandle *) NULL);

		/* Start the scheduler */
		vTaskStartScheduler();

		/* Should never arrive here */
		return 1;
	}
}

/**
 * @}
 */

