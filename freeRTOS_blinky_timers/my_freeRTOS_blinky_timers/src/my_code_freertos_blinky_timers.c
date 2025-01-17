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
#include "timers.h"

xTimerHandle timer_handle;
int red = 1;
int green = 0;
int blue = 0;
bool update = true; //when update is required
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

static void vTimerCallbackfunc(xTimerHandle pxTimer)
{
	if (red == 0)
	{
		red = 1;
		green = 0;

	}
	else if (green == 0)
	{
		green = 1;
		blue = 0;
	}
	else if (blue == 0)
	{
		blue = 1;
		red = 0;
	}
	update = true;
}

/* LED1 toggle thread */
static void vLEDTask1(void *pvParameters)
{

	while (1)
	{
		if (update == true)
		{
			Board_LED_Set(0, red);

			Board_LED_Set(1, green);

			Board_LED_Set(2, blue);

			update = false;
		}
		vTaskDelay(10);
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

	xTaskCreate(vLEDTask1, (signed char* ) "vTaskLed1",
			configMINIMAL_STACK_SIZE, NULL, (tskIDLE_PRIORITY + 1UL),
			(xTaskHandle *) NULL);
	timer_handle = xTimerCreate("timerexercise", (1000),
	pdTRUE, (void*) 0, vTimerCallbackfunc);

	if (xTimerStart(timer_handle, 0) != pdPASS)
	{
		for (;;)
			; /* failure!?! */
	}
	/* Start the scheduler */
	vTaskStartScheduler();
	/* Should never arrive here */
	return 1;
}

/**
 * @}
 */

