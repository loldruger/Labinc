#ifndef _CIRCULARQUEUE_H_
#define _CIRCULARQUEUE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

struct CircularQueue
{
	uint16_t size;
	uint8_t rear;
	uint8_t front;

	void** queue;

	bool (*IsEmpty)(struct CircularQueue* this);
	bool (*IsFull)(struct CircularQueue* this);
	bool (*Enqueue)(struct CircularQueue* this, void* data);
	void* (*Dequeue)(struct CircularQueue* this);
};

typedef struct CircularQueue CircularQueue;

CircularQueue* new_CircularQueue(uint16_t size);

#endif
