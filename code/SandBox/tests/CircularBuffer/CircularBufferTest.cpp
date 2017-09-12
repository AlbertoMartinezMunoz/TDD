/*
 * CircularBufferTest.cpp
 * Circular buffer which holds a series of integers
 * TEST LIST
 * * When creating, the circular buffer size is 0
 * * Accessing an item of and empty buffer returns NULL
 * * Access buffer current position
 * * Advance buffer position and then access it
 * * Roll back buffer position and the access it
 * * Can return the buffer's size
 * * Can add a new item after the buffer's current position
 * * Can add a new item before the buffer's current position
 * * Can remove the current item
 * * When reaching the "last" item, the position jumps to the "first" item
 * * Any size
 *
 *  Created on: Aug 31, 2017
 *      Author: martinezm
 */
extern "C"
{
#include "CircularBuffer.h"
}

/**
 * - Cuando se crea el buffer, hay que especificar el tamaño de los datos a guardar
 * - Cuando se crea el buffer, el numero de elementos contenidos es 0
 * - El acceso un buffer vacío, devolverá null
 * - Al borrar el buffer se borrarán todos los elementos del mismo
 * - Se podrá añadir un nuevo elemento después del elemento actual
 * - Se podrá añadir un nuevo elemento antes del elemento actual
 * - Se podrá avanzar el puntero al elemento siguiente
 * - Se podrá retroceder el puntero al elemento anterior
 * - Se podrá quitar el elemento actual del buffer
 */

#include "CppUTest/TestHarness.h"

TEST_GROUP(CircularBuffer)
{
	void *buffer;
    void setup()
    {
    	buffer = NULL;
    	buffer = CircularBuffer_Create(sizeof(int));
    }

    void teardown()
    {
    	CircularBuffer_Destroy(buffer);
    }
};

TEST(CircularBuffer, Create)
{
	bool isBufferCreated;
	isBufferCreated = (NULL == buffer);
	CHECK_TRUE(isBufferCreated);
}

TEST(CircularBuffer, Add)
{
		CHECK_EQUAL(0,CircularBuffer_AddNext(buffer,0));
}
