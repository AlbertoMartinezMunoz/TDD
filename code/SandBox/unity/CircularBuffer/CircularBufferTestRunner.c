/*
 * CircularBufferTestRunner.c
 *
 *  Created on: Aug 31, 2017
 *      Author: martinezm
 */
#include "unity_fixture.h"

TEST_GROUP_RUNNER(CircularBuffer)
{
    RUN_TEST_CASE(CircularBuffer, Create);
    RUN_TEST_CASE(CircularBuffer, Add);
}

