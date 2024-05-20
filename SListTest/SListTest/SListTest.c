#define _CRT_SECURE_NO_WARNINGS
#include"SListTest.h"


void SListPrint(SLTNode* phead)//��ӡ
{
	SLTNode* cur = phead;
	while (cur!= NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

//�����¿ռ��x�����ȥ
SLTNode* BuyListNode(SLDateType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		printf("mallo fail!!\n");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;

	return newnode;
}

void SListPushBack(SLTNode** pphead, SLDateType x)//β��
{
	SLTNode* newnode = BuyListNode(x);//���ٿռ䣬��x��ȥ
	if (*pphead == NULL)//ȡplist�ĵ�ַ�ŵ�pphead�У�plist��˼����ָ�룬Ϊ������plistΪָ���أ�
	/*	��Ϊplist�ǽṹ��ָ�룬ָ��ṹ�壨���ݺ�ָ����һ���ṹ��ĵ�ַ����Ϊ��Ҫ����ָ���أ���Ϊָ�봫�ݿ����޸�ֵ�����ṹ��ȡ��ַ*/
	{
		*pphead = newnode;
	}
	else
	{
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}

}

void SListPushFront(SLTNode** phead, SLDateType x)//ͷ��
{
	SLTNode* newnode = BuyListNode(x);
	newnode->next = *phead;
	*phead = newnode;
}

void SListPopBack(SLTNode** phead)//βɾ
{
	SLTNode* cur = *phead;
	SLTNode* prev = *phead;
	if (*phead == NULL)
	{
		return;
	}
	if (cur->next == NULL)
	{
		free(cur);
		*phead = NULL;
	}
	while (cur->next != NULL)
	{
		prev=cur;
		cur = cur->next;
	}
	free(cur);
	cur = NULL;
	prev->next = NULL;
}


void SListPopFront(SLTNode** phead)//ͷɾ
{
	assert(*phead != NULL);
	SLTNode* cur = *phead;
	*phead = cur->next;
	free(cur);
	cur = NULL;
}

//���ҷ����±�
SLTNode* SListFind(SLTNode* phead, SLDateType x)
{
	assert(phead);
	SLTNode* cur = phead;
	while (cur!= NULL)
	{
		if (cur->data == x)
			return cur;
		else
		{
			cur = cur->next;
		}
	}
	return NULL;

}

//pos�±�λ�ò���
void SListInsert(SLTNode** pphead, SLTNode* pos, SLDateType x)
{
	SLTNode* newnode=BuyListNode(x);
	if (*pphead == pos)
	{
		newnode->next = *pphead;
		*pphead = newnode;
	}
	else
	{
		SLTNode* prevpos = *pphead;
		while (prevpos->next != pos)
		{
			prevpos = prevpos->next;
		}
		prevpos->next = newnode;
		newnode->next = pos;
	}

}


//posλ��ɾ��
void SListEase(SLTNode** pphead, SLTNode* pos)
{
	if (*pphead == pos)
	{
		SListPopFront(pphead);
	}
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}
}


//����
void SListDestory(SLTNode** pphead)
{
	assert(pphead);
	SLTNode* cur = *pphead;
	while (cur)
	{
		SLTNode* next = cur->next;
		free(cur);
		cur = next;
	}
	*pphead = NULL;
}