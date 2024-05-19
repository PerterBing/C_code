#define _CRT_SECURE_NO_WARNINGS
#include"SeqList.h"

//打印数据
void SeqListprint(SL* ps)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

//初始化
void SeqListInit(SL* ps)
{
	//初始化顺序表， 
	ps->a = NULL;
	ps->size = ps->capacity=0;
}

//销毁开辟空间
void SeqListDestory(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}


//检查增容
void SeqListCheckCapacity(SL* ps)
{
	if (ps->size == ps->capacity)
	{
		//如果没有空间或空间不足，则扩容
		int newcapcity = (ps->capacity == 0 ? 4 : ps->capacity * 2);
		SLDataType* tmp = (SLDataType*)realloc(ps->a, newcapcity * sizeof(SLDataType));//要改变内存大小的指针名和开辟内存大小
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);//异常退出程序
		}

		ps->a = tmp;
		ps->capacity = newcapcity;

	}
}


//尾插
void SeqListPushBack(SL* ps, SLDataType x)//传过来一个结构体地址，用ps指针接收，ps里放着的就是s1的地址
{
	SeqListCheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
	//SeqListInsert(ps, ps->size, x);
}

//头插
void SeqListPushFront(SL* ps, SLDataType x)
{
	//SeqListCheckCapacity(ps);
	//SL* SListNode = ps;
	//int i = ps->size-1;
	//for (i = ps->size-1; i >= 0; i--)
	//{
	//	ps->a[i+1] = ps->a[i];
	//	if (i == 0)
	//	{
	//		ps->a[i] = x;
	//	}
	//}
	//ps->size++;
	SeqListInsert(ps, 0, x);
}

//头删
void SeqListPopFront(SL* ps)
{
	assert(ps->size > 0);
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}

//尾删
void SeqListPopBack(SL* ps)
{
	assert(ps->size > 0);
	ps->size--;
}

//查找下标
int SeqListFind(SL* ps, SLDataType x)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}
	return -1;
}

//pos位置插入
void SeqListInsert(SL* ps, int pos, SLDataType x)
{
	SeqListCheckCapacity(ps);
	assert(pos <= ps->size || pos >= 0);
	int i = 0;
	for (i = ps->size - 1; i >= pos; i--)
	{
		ps->a[i + 1] = ps->a[i];
	}
	ps->a[pos] = x;
	ps->size++;
}

//pos位置删除
void SeqListErase(SL* ps, int pos)
{
	int i =pos;
	for (i = pos; i<ps->size; i++)
	{
		ps->a[i] = ps->a[i+1];	
	}
	ps->size--;
}