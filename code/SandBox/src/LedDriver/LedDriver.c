/***
 * Excerpted from "Test-Driven Development for Embedded C",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/jgade for more book information.
 ***/
/*- ------------------------------------------------------------------ -*/
/*-    Copyright (c) James W. Grenning -- All Rights Reserved          -*/
/*-    For use by owners of Test-Driven Development for Embedded C,    -*/
/*-    and attendees of Renaissance Software Consulting, Co. training  -*/
/*-    classes.                                                        -*/
/*-                                                                    -*/
/*-    Available at http://pragprog.com/titles/jgade/                  -*/
/*-        ISBN 1-934356-62-X, ISBN13 978-1-934356-62-3                -*/
/*-                                                                    -*/
/*-    Authorized users may use this source code in your own           -*/
/*-    projects, however the source code may not be used to            -*/
/*-    create training material, courses, books, articles, and         -*/
/*-    the like. We make no guarantees that this source code is        -*/
/*-    fit for any purpose.                                            -*/
/*-                                                                    -*/
/*-    www.renaissancesoftware.net james@renaissancesoftware.net       -*/
/*- ------------------------------------------------------------------ -*/

#include "LedDriver.h"
#include <stdlib.h>
#include <memory.h>

static uint16_t * ledsAddress;
static uint16_t ledsImage;

enum {
	ALL_LEDS_OFF = 0, ALL_LEDS_ON = ~0
};

enum {
	FIRST_LED = 0, LAST_LED = 15
};

static uint16_t convertLedNumberToBit(int led) {
	return 1 << led;
}

static void updateHardware(void) {
	*ledsAddress = ledsImage;
}

static BOOL IsLedOutOfBounds(int ledNumber) {
	if ((ledNumber < FIRST_LED) || (ledNumber > LAST_LED)) {
//            RUNTIME_ERROR("LED Driver: out-of-bounds LED", ledNumber);
		return TRUE;
	}
	return FALSE;
}

void LedDriver_Create(uint16_t *address) {
	ledsAddress = address;
	ledsImage = ALL_LEDS_OFF;
	updateHardware();
}

void LedDriver_Destroy(void) {
}

/**
 * This function will turn a single led on
 * @param led	Number of the led to be turned on (0-15)
 */
void LedDriver_TurnOn(char led) {
	if(IsLedOutOfBounds(led))
		return;
	ledsImage |= convertLedNumberToBit(led);
	updateHardware();
}

/**
 * This function will turn a single led off
 * @param led	Number of the led to be turned on (0-15)
 */
void LedDriver_TurnOff(char led) {
	ledsImage &= ~convertLedNumberToBit(led);
	updateHardware();
}

/**
 * This function will check if a led is on
 * @param led	Number of the led to be checked (0-15)
 * @return		TRUE if the led is ON, FALSE otherwise
 */
BOOL LedDriver_IsOn(char led) {
	return (*ledsAddress & convertLedNumberToBit(led)) > 0;
}

/**
 * This function will check if a led is off
 * @param led	Number of the led to be checked (0-15)
 * @return		TRUE if the led is OFF, FALSE otherwise
 */
BOOL LedDriver_IsOff(char led) {
	return (*ledsAddress & convertLedNumberToBit(led)) == 0;
}

