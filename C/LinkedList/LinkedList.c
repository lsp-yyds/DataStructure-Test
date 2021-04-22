#include <stdio.h>
#include "LinkedList.h"

List MakeEmpty(List L)
{
	L->Next = NULL;
	return L;
}

/* return true if L is empty*/
bool IsEmpty(List L)
{
	return L->Next == NULL;
}

/*return true if P is the last position in list*/
bool IsLast(Position P, List L)
{
	return P->Next == NULL;
}


Position Find(ElementType X, List L)
{
	Position P;
	
	P = L->Next;
	while(P != NULL && P->Element != X)
		P = P->Next;
	
	return P;
}

void Delete(ElementType X, List L)
{
	Position P, TmpCell;

	P = FindPrevious(X, L);

	if( !IsLast(P, L) ) {
		TmpCell = P->Next;
		P->Next = TmpCell->Next;
		free(TmpCell);
	}
}

Position FindPrevious(ElementType X, List L)
{
	Position P;
	
	P = L;
	while(P->Next != NULL && P->Next->Element != X)
		P = P->Next;

	return P;
}

void Insert(ElementType X, List L, Position P)
{
	Position TmpCell;
	
	TmpCell = malloc(sizeof(struct Node));
	if(TmpCell == NULL) 
		printf("Out of space!!!\n");

	TmpCell->Element = X;
	TmpCell->Next = P->Next;
	P->Next = TmpCell;
}

void DeleteList(List L)
{
	Position P, Tmp;

	P = L->Next;
	L->Next = NULL;
	while( P != NULL ){
		Tmp = P->Next;
		free(P);
		P = Tmp->Next;
	}
}

Position Header(List L)
{
	return L;
}

Position First(List L)
{
	return L->Next;
}

/*Position Advance(Position P)*/

ElementType Retrieve(Position P)
{
	return P->Element;
}

/*main函数中为测试用的代码*/
int main(int argc, char const *argv[])
{
	
	struct Node m = { 2, NULL }, n = { 1, &m }, header = {0, &n};
	List L = &header;
	if(IsEmpty(L))
		printf("列表为空！\n");
	else
		printf("链表不为空！\n");
	//MakeEmpty(L);
	if(IsLast(&m,L))
		printf("yes！\n");
	else
		printf("no！\n");
	Position P1 = Find(2, L);
	printf("%d\n", P1->Element);
	Position P2 = FindPrevious(2, L);
	printf("%d\n", P2->Element);
	Insert(3, L, P2);
	printf("%d\n", P2->Next->Element);
	printf("%d\n", Header(L)->Next->Element);
	printf("%d\n", First(L)->Element);
	printf("%d\n", Retrieve(&m));
	return 0;
}