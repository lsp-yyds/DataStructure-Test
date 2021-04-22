#include "Stack.h"

struct Node
{
	ElementType Element;
	PtrToNode Next;
};

bool IsEmpty(Stack S)
{
	return S->Next == NULL;
}


Stack CreateStack(void)
{
	Stack S;

	S = malloc(sizeof(struct Node));
	if(S == NULL)
		printf("Out of space!!!\n");
	S->Next == NULL;
	MakeEmpty(S);
	return S;
}

void DisposeStack(Stack S)
{

}

void MakeEmpty(Stack S)
{
	if(S == NULL)
		printf("Must use CreateStack first\n");
	else
		while(!IsEmpty(S))
			Pop(S);
}

void Push(ElementType X, Stack S)
{
	PtrToNode TmpCell;

	TmpCell = malloc(sizeof(struct Node));
	if(TmpCell == NULL)
		printf("Out of space!!!\n");
	else
	{
		TmpCell->Element = X;
		TmpCell->Next = S->Next;
		S->Next = TmpCell;
	}
}

ElementType Top(Stack S)
{
	if(!IsEmpty(S))
		return S->Next->Element;
	printf("Empty stack\n");
	return 0;
}

void Pop(Stack S)
{
	PtrToNode FirstCell;

	if(IsEmpty(S))
		printf("Empty stack\n");
	else
	{
		FirstCell = S->Next;
		S->Next = S->Next->Next;
		free(FirstCell);
	}
}

int main(int argc, char const *argv[])
{
	/*struct Node Header = {-1, NULL};
	struct Node n4 = {3, NULL}, n3 = {2, &n4}, n2 = {1, &n3}, n1 = {0, &n2};
	Header.Next = &n1;
	Stack s = &Header;*/
	//MakeEmpty(s);
	if(IsEmpty(s))
		printf("Empty\n");
	else
		printf("Not Empty\n");

	return 0;
}