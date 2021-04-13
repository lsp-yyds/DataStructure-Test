#ifndef SQLIST_H
#define SQLIST_H
#define MAXSIZE 10

typedef int ElemType;
typedef struct
{
	ElemType data[MAXSIZE];
	int length;
}SqList;

//	初始化顺序表
void InitList(SqList& L);
//	判空操作（判断顺序表是否为空）
bool isEmpty(SqList L);
//	插入操作（判合法下标，判满）
void ListInsert(SqList& L, int i, int e);
//	删除操作（判合法下标）
void ListDelete(SqList& L,int i,int& e);
//	按位查找操作（返回元素的值）
ElemType GetElem(SqList L,int i);
//  按值查找操作（返回元素的位置）
ElemType LocateElem(SqList L, int e);

#endif