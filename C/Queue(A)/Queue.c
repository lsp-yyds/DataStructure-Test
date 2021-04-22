#include "Queue.h"

struct QueueRecord
{
	int Capacity;
	int Front;
	int Rear;
	int Size;
	ElementType* Array;
};

bool IsEempty(Queue Q)
{
	return Q->Size == 0;
}

bool IsFull(Queue Q)
{
	return Q->Size == Capacity;
}
Queue CreateQueue(int MaxElements);
void disposeQueue(Queue Q);
void MakeEmpty(Queue Q)
{
	Q->Size = 0;
	Q->Front = 1;
	Q->Rear = 0;
}
void Enqueue(ElementType X, Queue Q);
ElementType Front(Queue Q);
void Dequeue(Queue Q);
ElementType FrontAndDequeue(Queue Q);