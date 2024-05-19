#pragma once
#include<stdio.h>
#include<stdlib.h>//���ٿռ亯������
#include<assert.h>
typedef int SLDataType;


//��̬˳���
typedef struct SeqList
{
	SLDataType* a;//ָ��̬�����ڴ�ĵ�ַ
	int size;//��ʾ�����������������Ч����
	int capacity;//����ʵ���ܴ����ݵĿռ��������
}SL;


void SeqListprint(SL* ps);//��ӡ
void SeqListInit(SL* ps);//��ʼ��
void SeqListPushBack(SL* ps, SLDataType x);//β��
void SeqListPopBack(SL* ps);//βɾ
void SeqListPushFront(SL* ps, SLDataType x);//ͷ��
void SeqListPopFront(SL* ps);//ͷɾ
void SeqListDestory(SL* sp);//����
void SeqListCheckCapacity(SL* ps);

int SeqListFind(SL* ps, SLDataType x);//���ҷ���x�±꣬û�з���-1
void SeqListInsert(SL* ps, int pos, SLDataType x);//ָ��pos�±�λ�ò���
void SeqListErase(SL* ps, int pos);//ɾ��posλ�õ�����

