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


void SListPrint(SLTNode* phead);//¥Ú”°
void SListPushBack(SLTNode* phead, SLDateType x);//Œ≤≤Â
void SListPushFront(SLTNode** phead, SLDateType x);//Õ∑≤Â
void SListPopBack(SLTNode** phead);//Œ≤…æ
void SListPopFront(SLTNode** phead);//Õ∑…æ


SLTNode* SListFind(SLTNode* pphead, SLDateType x);
void SListInsert(SLTNode** pphead, SLTNode* pos, SLDateType x);
//void SListInsertAfter(SLTNode* pos, SLDateType x);//pos∫Û≤Â
void SListEase(SLTNode** pphead, SLTNode* pos);
//void SListEaseAfter(SLTNode* pos);
void SListDestory(SLTNode** pphead);