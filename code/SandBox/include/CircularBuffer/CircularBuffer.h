/*
 * CircularBuffer.h
 *
 *  Created on: Aug 31, 2017
 *      Author: martinezm
 */

#ifndef SANDBOX_INCLUDE_CIRCULARBUFFER_CIRCULARBUFFER_H_
#define SANDBOX_INCLUDE_CIRCULARBUFFER_CIRCULARBUFFER_H_

/**
 * This function will create a circular buffer and will insert the 'number' in
 * the buffer's first item
 * @param elementSize	Size of the elements to be stored in the buffer
 * @return				NULL if error, pointer to the buffer otherwise
 */
void *CircularBuffer_Create(int elementSize);

/**
 * This function will erase a whole circular buffer 'buffer' from memory
 * @param buffer	Buffer which will be erased
 * @return			OK if the buffer is erased, -1 otherwise
 */
int CircularBuffer_Destroy(void *buffer);

/**
 * This function will add a new item next to the current buffer item
 * @param buffer	Pointer to the circular buffer
 * @param number	Number to be inserted
 * @return			OK if the number is inserted in the buffer, -1 otherwise
 */
int CircularBuffer_AddNext(void *buffer, int number);

/**
 * This function will get the current item of the buffer
 * @param buffer	Pointer to the circular buffer
 * @param number	Address where the number retrieved will be stored
 * @return			OK if the number is retrieved from the buffer, -1 otherwise
 */
int CircularBuffer_GetCurrent(void *buffer, int *number);



#endif /* SANDBOX_INCLUDE_CIRCULARBUFFER_CIRCULARBUFFER_H_ */
