/*
 * CircularBufferTest.c
 *
 *  Created on: Aug 31, 2017
 *      Author: martinezm
 */
#include "unity_fixture.h"
#include "CircularBuffer.h"

TEST_GROUP(CircularBuffer);

static void *buffer;

TEST_SETUP(CircularBuffer)
{
	buffer = CircularBuffer_Create(0);
}

TEST_TEAR_DOWN(CircularBuffer)
{
	CircularBuffer_Destroy(buffer);
}

TEST(CircularBuffer, Create)
{
	TEST_ASSERT_NOT_EQUAL(NULL, buffer);
}

TEST(CircularBuffer, Add)
{
	TEST_ASSERT_EQUAL(0, CircularBuffer_AddNext(buffer,0));
}

