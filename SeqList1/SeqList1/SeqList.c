#define _CRT_SECURE_NO_WARNINGS
#include"SeqList.h"

//��ӡ����
void SeqListprint(SL* ps)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

//��ʼ��
void SeqListInit(SL* ps)
{
	//��ʼ��˳��� 
	ps->a = NULL;
	ps->size = ps->capacity=0;
}

//���ٿ��ٿռ�
void SeqListDestory(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}


//�������
void SeqListCheckCapacity(SL* ps)
{
	if (ps->size == ps->capacity)
	{
		//���û�пռ��ռ䲻�㣬������
		int newcapcity = (ps->capacity == 0 ? 4 : ps->capacity * 2);
		SLDataType* tmp = (SLDataType*)realloc(ps->a, newcapcity * sizeof(SLDataType));//Ҫ�ı��ڴ��С��ָ�����Ϳ����ڴ��С
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);//�쳣�˳�����
		}

		ps->a = tmp;
		ps->capacity = newcapcity;

	}
}


//β��
void SeqListPushBack(SL* ps, SLDataType x)//������һ���ṹ���ַ����psָ����գ�ps����ŵľ���s1�ĵ�ַ
{
	SeqListCheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
	//SeqListInsert(ps, ps->size, x);
}

//ͷ��
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

//ͷɾ
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

//βɾ
void SeqListPopBack(SL* ps)
{
	assert(ps->size > 0);
	ps->size--;
}

//�����±�
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

//posλ�ò���
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

//posλ��ɾ��
void SeqListErase(SL* ps, int pos)
{
	int i =pos;
	for (i = pos; i<ps->size; i++)
	{
		ps->a[i] = ps->a[i+1];	
	}
	ps->size--;
}