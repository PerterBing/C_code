#pragma once
#include<stdio.h>
#include<stdlib.h>//开辟空间函数调用
#include<assert.h>
typedef int SLDataType;


//动态顺序表
typedef struct SeqList
{
	SLDataType* a;//指向动态开辟内存的地址
	int size;//表示数组中连续存多少有效数据
	int capacity;//数组实际能存数据的空间容量多大
}SL;


void SeqListprint(SL* ps);//打印
void SeqListInit(SL* ps);//初始化
void SeqListPushBack(SL* ps, SLDataType x);//尾插
void SeqListPopBack(SL* ps);//尾删
void SeqListPushFront(SL* ps, SLDataType x);//头插
void SeqListPopFront(SL* ps);//头删
void SeqListDestory(SL* sp);//销毁
void SeqListCheckCapacity(SL* ps);

int SeqListFind(SL* ps, SLDataType x);//查找返回x下标，没有返回-1
void SeqListInsert(SL* ps, int pos, SLDataType x);//指定pos下标位置插入
void SeqListErase(SL* ps, int pos);//删除pos位置的数据

