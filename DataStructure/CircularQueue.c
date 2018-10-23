#include "CircularQueue.h"

bool IsEmpty(CircularQueue* this);
bool IsFull(CircularQueue* this);
bool Enqueue(CircularQueue* this, intptr_t* data);
intptr_t* Dequeue(CircularQueue* this);

CircularQueue* new_CircularQueue(size_t size)
{
	CircularQueue* this = (CircularQueue*)malloc(sizeof(CircularQueue));

	this->size = size;
	this->queue = (intptr_t**)malloc(sizeof(intptr_t**)*size);

	this->front = 0;
	this->rear = 0;

	this->IsEmpty = &IsEmpty;
	this->IsFull = &IsFull;
	this->Enqueue = &Enqueue;
	this->Dequeue = &Dequeue;

#ifdef _DEBUG_
	printf("Instance circular queue has been created.\n");
	printf("Queue Size is %ld.\n", sizeof(this->queue[0]));
#endif
	return this;
}

bool IsEmpty(CircularQueue* this)
{
    if(this->front == this->rear)
    {
#ifdef _DEBUG_
    	printf("Queue is empty.\n");
#endif
    	return true;
    }
    else
    	return false;
}

bool IsFull(CircularQueue* this)
{
    if((this->rear + 1) % this->size == this->front)
    {
#ifdef _DEBUG_
    	printf("Queue is full.\n");
#endif
    	return true;
    }
    else
        return false;
}

bool Enqueue(CircularQueue* this, intptr_t* data)
{
	if(this->IsFull(this))
	    return false;

	this->rear = (this->rear + 1) % this->size;
	this->queue[this->rear] = data;

#ifdef _DEBUG_
    printf("Enqueued %p at %p\n", this->queue[this->rear], &this->queue[this->rear]);
#endif

	return true;
}

intptr_t* Dequeue(CircularQueue* this)
{
	if(this->IsEmpty(this))
	    return NULL;

	this->front = (this->front + 1) % this->size;

#ifdef _DEBUG_
	printf("Dequeued %p from %p\n", this->queue[this->front], &this->queue[this->front]);
#endif

	return this->queue[this->front];
}
