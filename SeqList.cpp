#include <stdio.h>
#include "SqList.h"

//	初始化顺序表
void InitList(SqList& L)
{
	L.length = 0;
	printf("初始化成功!\n");
}

//	判空操作（判断顺序表是否为空）
bool isEmpty(SqList L)
{
	if(L.length == 0){
		printf("当前顺序表为空!\n");
		return true;
	}
	else{
		printf("当前顺序表不为空!\n");
		return false;
	}
}

//	插入操作（判合法下标，判满）
void ListInsert(SqList& L, int i, int e)
{
	if(i < 1 || i > L.length + 1){
		printf("插入失败，请输入正确的插入位置!\n");
	}
	else if(L.length >= MAXSIZE){
		printf("插入失败，顺序表已满，无法插入更多的元素!\n");
	}
	else{
		for(int j = L.length;j >= i;j--)
			L.data[j] = L.data[j-1];
		L.data[i-1] = e;
		L.length++;
		printf("元素插入成功!\n");
	}
}

//	删除操作（判合法下标）
void ListDelete(SqList& L,int i,int& e)
{
	if(i < 1 || i > L.length){
		printf("删除失败，请输入正确的删除位置!\n");
	}else{
		e = L.data[i-1];
		for(int j = i;j < L.length;j++)
			L.data[j-1] = L.data[j];
		L.length--;
		printf("元素删除成功，删除的元素值为:%d\n",e);
	}
}

//	按位查找操作（返回元素的值）
ElemType GetElem(SqList L,int i)
{
	return L.data[i-1];
}

//  按值查找操作（返回元素的位置）
ElemType LocateElem(SqList L, int e)
{
	int i = 0;
	for(i = 0;i < L.length;i++){
		if(L.data[i] == e)
			break;
	}
	return i + 1;
}

//  main()函数测试
/*int main(int argc, char const *argv[])
{
	int e = -1;
	SqList L;
	InitList(L);
	for(int i = 0;i < MAXSIZE;i++){
		L.data[i] = i;
		printf("%d\n", L.data[i]);
		L.length++;
		printf("当前顺序表的长度为:%d\n",L.length);
	}
	printf("第四个元素的值为:%d\n", GetElem(L,4));
	printf("元素3为第%d个元素\n", LocateElem(L,3));
	ListInsert(L, 4, 22);
	ListInsert(L, 44, 2);
	ListDelete(L, 4, e);
	ListInsert(L, 4, 22);
	for(int i = 0;i < MAXSIZE;i++){
		printf("%d\n", L.data[i]);
	}
	return 0;
}*/
