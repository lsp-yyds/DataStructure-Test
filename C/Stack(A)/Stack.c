#include "Stack.h"
#include <stdio.h>
#define EmptyTOS 0

/*定义结构体*/
struct StackRecord
{
	int Capacity;
	int TopOfStack;
	ElementType* Array;
};

bool IsEmpty(Stack S)
{
	return S->TopOfStack == EmptyTOS;
}

bool IsFull(Stack S)
{
	return S->TopOfStack == S->Capacity;
}

Stack CreateStack(int MaxElements)
{
	Stack S;

	if(MaxElements < 0)
		printf("Stack size is too small\n");
		//Error("Stack size is too small");

	S = malloc(sizeof(struct StackRecord));
	if(S == NULL)
		printf("Out of space!!!\n");
		//FatalError("Out of space!!!");

	S->Array = malloc(sizeof(ElementType) * MaxElements);
	if(S->Array == NULL)
		printf("Out of space!!!\n");
		//FatalError("Out of space!!!");
	S->Capacity = MaxElements;
	MakeEmpty(S);

	return S;
}

void DisposeStack(Stack S)
{
	if(S != NULL)
	{
		free(S->Array);
		free(S);
	}
}

void MakeEmpty(Stack S)
{
	S->TopOfStack = EmptyTOS;
}

void Push(ElementType X, Stack S)
{
	if(IsFull(S))
		printf("Full stack\n");
		//Error("Full stack");
	else
		S->Array[++S->TopOfStack] = X;
}

ElementType Top(Stack S)
{
	if(!IsEmpty(S))
		return S->Array[S->TopOfStack];
	printf("Empty stack\n");
	//Error("Empty stack");
	return 0;	/* 用此返回值避免警告 */
}

void Pop(Stack S)
{
	if(IsEmpty(S))
		printf("Empty stack\n");
		//Error("Empty stack");
	else
		S->TopOfStack--;
}

ElementType TopAndPop(Stack S)
{
	if(!IsEmpty(S))
		return S->Array[S->TopOfStack--];
	printf("Empty stack\n");
	//Error("Empty stack");
	return 0;
}

int main(int argc, char const *argv[])
{
	Stack s = CreateStack(10);
	printf("%d\n", s->TopOfStack);
	Push(1,s);
	printf("%d\n", s->TopOfStack);
	return 0;
}