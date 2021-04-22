// 带有表头的链表
#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_
#include <stdbool.h>
#include <stdlib.h>

struct Node;
typedef int ElementType;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
struct Node
{
	ElementType Element;
	Position Next;
};

List MakeEmpty(List L);
bool IsEmpty(List L);
bool IsLast(Position P, List L);
Position Find(ElementType X, List L);
void Delete(ElementType X, List L);
Position FindPrevious(ElementType X, List L);
void Insert(ElementType X, List L, Position P);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
ElementType Retrieve(Position P);

#endif