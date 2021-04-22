#ifndef STACK_H
#define STACK_H
#include <stdbool.h>
#include <stdlib.h>

struct StackRecord;
typedef struct StackRecord* Stack;
typedef int ElementType;

bool IsEmpty(Stack S);
bool IsFull(Stack S);
Stack CreateStack(int MaxElements);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
void Pop(Stack S);
ElementType TopAndPop(Stack S);

#endif