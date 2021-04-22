#ifndef QUEUE_H
#define QUEUE_H value
#include <stdbool.h>

struct QueueRecord;
typedef struct QueueRecord* Queue;

bool IsEempty(Queue Q);
bool IsFull(Queue Q);
Queue CreateQueue(int MaxElements);
void disposeQueue(Queue Q);
void MakeEmpty(Queue Q);
void Enqueue(ElementType X, Queue Q);
ElementType Front(Queue Q);
void Dequeue(Queue Q);
ElementType FrontAndDequeue(Queue Q);

#endif