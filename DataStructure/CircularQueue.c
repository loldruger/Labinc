#include "CircularQueue.h"

bool IsEmpty(CircularQueue* this);
bool IsFull(CircularQueue* this);
bool Enqueue(CircularQueue* this, void* data);
void* Dequeue(CircularQueue* this);

CircularQueue* new_CircularQueue(uint16_t size)
{
	CircularQueue* this = (CircularQueue*)malloc(sizeof(CircularQueue));

	this->size = size;
	this->queue = (void**)malloc(sizeof(void*)*size);
	this->front = 0;
	this->rear = 0;

	this->IsEmpty = &IsEmpty;
	this->IsFull = &IsFull;
	this->Enqueue = &Enqueue;
	this->Dequeue = &Dequeue;

	return this;
}

bool IsEmpty(CircularQueue* this)
{
    if(this->front == this->rear)
        return true;
    else
    	return false;
}

bool IsFull(CircularQueue* this)
{
    if((this->rear + 1) % this->size == this->front)
        return true;
    else
        return false;
}

bool Enqueue(CircularQueue* this, void* data)
{
	if(this->IsFull(this))
		return false;

	this->rear = (this->rear + 1) % this->size;
	this->queue[this->rear] = data;

	return true;
}

void* Dequeue(CircularQueue* this)
{
	if(this->IsEmpty(this))
		return NULL;

	this->front = (this->front + 1) % this->size;

	return this->queue[this->front];
}
