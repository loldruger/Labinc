#ifndef _CIRCULARQUEUE_H_
#define _CIRCULARQUEUE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

struct CircularQueue
{
	size_t size;
	uint8_t rear;
	uint8_t front;

	intptr_t** queue;

	bool (*IsEmpty)(struct CircularQueue* this);
	bool (*IsFull)(struct CircularQueue* this);
	bool (*Enqueue)(struct CircularQueue* this, intptr_t* data);
	intptr_t* (*Dequeue)(struct CircularQueue* this);
};

typedef struct CircularQueue CircularQueue;

CircularQueue* new_CircularQueue(size_t size);

#endif
