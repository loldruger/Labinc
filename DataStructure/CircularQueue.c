#include "CircularQueue.h"

/*public*/
static bool IsEmpty(const CircularQueue* this);
static bool IsFull(const CircularQueue* this);
static bool Enqueue(CircularQueue* this, const void* data, size_t size);
static void* Dequeue(CircularQueue* this);

CircularQueue* new_CircularQueue(size_t size)
{
	CircularQueue* this = (CircularQueue*)malloc(sizeof(CircularQueue));

	this->size = size;
	this->queue = (void**)malloc(sizeof(void**)*size);

	this->front = 0;
	this->rear = 0;

	this->IsEmpty = &IsEmpty;
	this->IsFull = &IsFull;
	this->Enqueue = &Enqueue;
	this->Dequeue = &Dequeue;

#ifdef _DEBUG_
	printf("Instance circular queue has been created.\n");
	printf("Queue Size is %ld.\n", sizeof(*(void*)this->queue));
#endif
	return this;
}

void delete_CircularQueue(CircularQueue* this)
{
#ifdef _DEBUG_
	printf("Instance circular queue has been destroyed.\n");
#endif
	free(this->queue);
	free(this);
}

static bool IsEmpty(const CircularQueue* this)
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

static bool IsFull(const CircularQueue* this)
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

static bool Enqueue(CircularQueue* this, void* data, size_t size)
{
	if(this->IsFull(this))
	    return false;
	
	this->rear = (this->rear + 1) % this->size;

	if(size > 0)
	{
		this->queue[this->rear] = malloc(size);
		memcpy(this->queue[this->rear], data, size);		
	}
	else if (size == 0)
		this->queue[this->rear] = data;
	else
	{
#ifdef _DEBUG_
    printf("Unaceptable size %p at %p\n", this->queue[this->rear], &this->queue[this->rear]);
#endif

		return false;
	}

#ifdef _DEBUG_
    printf("Enqueued %p (copied from %p) at %p\n", this->queue[this->rear], data, &this->queue[this->rear]);
#endif

	return true;
}

static void* Dequeue(CircularQueue* this)
{
	if(this->IsEmpty(this))
	    return NULL;

	this->front = (this->front + 1) % this->size;

#ifdef _DEBUG_
	printf("Dequeued %p from %p\n", this->queue[this->front], &this->queue[this->front]);
#endif

	return this->queue[this->front];
}
