#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLTDateType;

typedef struct SListNode
{
	SLTDateType data;
	struct SListNode* next;
}SLTNode;

void SListPrint(SLTNode* phead);
void SListPushBack(SLTNode* phead,SLTDateType x);
void SListPushFront(SLTNode** pphead, SLTDateType x);
void SListPopBack(SLTNode** pphead);
void SListPopFront(SLTNode** pphead);



SLTNode* SListFind(SLTNode* pphead, SLTDateType x);
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDateType x);
void SListInsertAfter(SLTNode* pos, SLTDateType x);//posºó²å
void SListEase(SLTNode** pphead, SLTNode* pos);
void SListEaseAfter( SLTNode* pos);//
void SListDestory(SLTNode** pphead);