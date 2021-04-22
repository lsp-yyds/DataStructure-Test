/*链表实现*/
#ifndef STACK_H
#define STACK_H
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode Stack;
typedef int ElementType;

bool IsEmpty(Stack S);
Stack CreateStack(void);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
void Pop(Stack S);

#endif