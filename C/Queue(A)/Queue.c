#include "Queue.h"
#include <stdio.h>

struct QueueRecord
{
	int Capacity;
	/*队头*/
	int Front;
	/*队尾*/
	int Rear;
	int Size;
	ElementType* Array;
};

bool IsEmpty(Queue Q)
{
	return Q->Size == 0;
}

bool IsFull(Queue Q)
{
	return Q->Size == Q->Capacity;
}

Queue CreateQueue(int MaxElements)
{
	Queue Q;

	if(MaxElements < 0)
		printf("Error:Queue size is to small\n");
		//Error("Queue size is to small");

	Q = malloc(sizeof(struct QueueRecord));
	if(Q == NULL)
		printf("Error:Out of space!!!\n");
		//Error("Out of space!!!");

	Q->Array = malloc(sizeof(ElementType) * MaxElements);
	if(Q->Array == NULL)
		printf("Error:Out of space!!!\n");
		//Error("Out of space!!!");
	Q->Capacity = MaxElements;
	MakeEmpty(Q);

	return Q;
}

void disposeQueue(Queue Q)
{
	if(Q != NULL)
	{
		free(Q->Array);
		free(Q);
	}
}

void MakeEmpty(Queue Q)
{
	Q->Size = 0;
	Q->Front = 1;
	Q->Rear = 0;
}

static int Succ(int Value, Queue Q)
{
	if(++Value == Q->Capacity)
		Value = 0;
	return Value;
}

void Enqueue(ElementType X, Queue Q)
{
	if(IsFull(Q))
		printf("Error:Full queue\n");
	//Error("Full queue");
	else
	{
		Q->Size++;
		Q->Rear = Succ(Q->Rear, Q);
		Q->Array[Q->Rear] = X;
	}
}

ElementType Front(Queue Q)
{
	if(!IsEmpty(Q))
		return Q->Array[Q->Front];
	printf("Error:Empty queue\n");
	//Error("Empty queue");
	return 0;	/* 用此返回值避免警告 */
}

void Dequeue(Queue Q)
{
	if(IsEmpty(Q))
		printf("Error:Empty queue\n");
	else
	{
		Q->Size--;
		Q->Front = Succ(Q->Front, Q);
	}
}

ElementType FrontAndDequeue(Queue Q)
{
	if(!IsEmpty(Q))
	{
		Q->Size--;
		return Q->Array[Q->Front];
	}
	printf("Error:Empty stack\n");
	//Error("Empty stack");
	return 0;
}

int main(int argc, char const *argv[])
{
	Queue q = CreateQueue(10);
	if(IsEmpty(q))
		printf("Empty\n");
	else
		printf("Not Empty\n");
	Enqueue(0, q);
	Enqueue(1, q);
	Enqueue(2, q);
	Enqueue(3, q);
	Enqueue(4, q);
	Enqueue(5, q);
	Enqueue(6, q);
	Enqueue(7, q);
	Enqueue(8, q);
	Enqueue(9, q);
	Enqueue(10, q);
	if(IsFull(q))
		printf("Full\n");
	else
		printf("Not Full\n");
	Dequeue(q);
	if(IsFull(q))
		printf("Full\n");
	else
		printf("Not Full\n");
	int x = FrontAndDequeue(q);
	printf("%d\n", x);
	return 0;
}
