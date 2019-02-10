#ifndef _CIRCULARQUEUE_H_
#define _CIRCULARQUEUE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef enum type{_bool_, _uint8_t_, _int8_t_, _uint16_t_, _int16_t_, _uint32_t_, _int32_t_, _uint64_t_, _int64_t_, _uintmax_t_, _intmax_t_, _void_, _uintptr_t_, _intptr_t_} type_t;

struct CircularQueue
{
	size_t size;
	uint8_t rear;
	uint8_t front;

	void** queue;

	bool (*IsEmpty)(const struct CircularQueue* this);
	bool (*IsFull)(const struct CircularQueue* this);
	bool (*Enqueue)(struct CircularQueue* this, void* data, size_t size);
	void* (*Dequeue)(struct CircularQueue* this);
};

typedef struct CircularQueue CircularQueue;

CircularQueue* new_CircularQueue(size_t size);
void delete_CircularQueue(CircularQueue* this);

#endif
