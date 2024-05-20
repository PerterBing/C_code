#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int SLDateType;

typedef struct SListNode
{
	SLDateType data;
	struct SListNode* next;
}SLTNode;


void SListPrint(SLTNode* phead);//��ӡ
void SListPushBack(SLTNode* phead, SLDateType x);//β��
void SListPushFront(SLTNode** phead, SLDateType x);//ͷ��
void SListPopBack(SLTNode** phead);//βɾ
void SListPopFront(SLTNode** phead);//ͷɾ


SLTNode* SListFind(SLTNode* pphead, SLDateType x);
void SListInsert(SLTNode** pphead, SLTNode* pos, SLDateType x);
//void SListInsertAfter(SLTNode* pos, SLDateType x);//pos���
void SListEase(SLTNode** pphead, SLTNode* pos);
//void SListEaseAfter(SLTNode* pos);
void SListDestory(SLTNode** pphead);