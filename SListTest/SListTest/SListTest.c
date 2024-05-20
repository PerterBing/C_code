#define _CRT_SECURE_NO_WARNINGS
#include"SListTest.h"


void SListPrint(SLTNode* phead)//打印
{
	SLTNode* cur = phead;
	while (cur!= NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

//开辟新空间把x插入进去
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

void SListPushBack(SLTNode** pphead, SLDateType x)//尾插
{
	SLTNode* newnode = BuyListNode(x);//开辟空间，放x进去
	if (*pphead == NULL)//取plist的地址放到pphead中，plist意思就是指针，为甚定义plist为指针呢，
	/*	因为plist是结构体指针，指向结构体（数据和指向下一个结构体的地址），为甚要定义指针呢，因为指针传递可以修改值，而结构体取地址*/
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

void SListPushFront(SLTNode** phead, SLDateType x)//头插
{
	SLTNode* newnode = BuyListNode(x);
	newnode->next = *phead;
	*phead = newnode;
}

void SListPopBack(SLTNode** phead)//尾删
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


void SListPopFront(SLTNode** phead)//头删
{
	assert(*phead != NULL);
	SLTNode* cur = *phead;
	*phead = cur->next;
	free(cur);
	cur = NULL;
}

//查找返回下标
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

//pos下标位置插入
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


//pos位置删除
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


//销毁
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