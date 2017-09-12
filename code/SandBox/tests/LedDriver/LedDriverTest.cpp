//- ------------------------------------------------------------------
//-    Copyright (c) James W. Grenning -- All Rights Reserved         
//-    For use by owners of Test-Driven Development for Embedded C,   
//-    and attendees of Renaissance Software Consulting, Co. training 
//-    classes.                                                       
//-                                                                   
//-    Available at http://pragprog.com/titles/jgade/                 
//-        ISBN 1-934356-62-X, ISBN13 978-1-934356-62-3               
//-                                                                   
//-    Authorized users may use this source code in your own          
//-    projects, however the source code may not be used to           
//-    create training material, courses, books, articles, and        
//-    the like. We make no guarantees that this source code is       
//-    fit for any purpose.                                           
//-                                                                   
//-    www.renaissancesoftware.net james@renaissancesoftware.net      
//- ------------------------------------------------------------------

extern "C" {
#include "LedDriver.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(LedDriver)
{
	uint16_t virtualLeds;

	void setup() {
		virtualLeds = 0xFFFF;
		LedDriver_Create (&virtualLeds);
	}

	void teardown() {
		LedDriver_Destroy();
	}
};

TEST(LedDriver, Create)
{
	UNSIGNED_LONGS_EQUAL(0, virtualLeds);
}

TEST(LedDriver, TurnOnLedOne)
{
	LedDriver_TurnOn(1);
	UNSIGNED_LONGS_EQUAL(0x0002, virtualLeds);
}

TEST(LedDriver, TurnOnMultipleLeds)
{
	LedDriver_TurnOn(1);
	LedDriver_TurnOn(11);
	UNSIGNED_LONGS_EQUAL(0x0802, virtualLeds);
}

TEST(LedDriver, TurnOffLedOne)
{
	LedDriver_TurnOn(1);
	LedDriver_TurnOn(11);
	LedDriver_TurnOff(1);
	UNSIGNED_LONGS_EQUAL(0x0800, virtualLeds);
}

TEST(LedDriver, IsLedOn) {
	CHECK_EQUAL(FALSE, LedDriver_IsOn(1));
	LedDriver_TurnOn(1);
	CHECK_EQUAL(TRUE, LedDriver_IsOn(1));
}

TEST(LedDriver, IsLedOff) {
	LedDriver_TurnOn(1);
	CHECK_EQUAL(FALSE, LedDriver_IsOff(1));
	LedDriver_TurnOff(1);
	CHECK_EQUAL(TRUE, LedDriver_IsOff(1));
}

TEST(LedDriver, UpperAndLowerBounds)
{
    LedDriver_TurnOn(0);
    LedDriver_TurnOn(15);
    LONGS_EQUAL(0x8001, virtualLeds);
}

TEST(LedDriver, OutOfBoundsTurnOnDoesNoHarm)
{
    LedDriver_TurnOn(-1);
    LedDriver_TurnOn(16);
    LedDriver_TurnOn(33);

    LONGS_EQUAL(0, virtualLeds);
}
