#define _CRT_SECURE_NO_WARNINGS
#include"SList.h"

void Test1()
{
	SLTNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);


	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);

	//SListPrint(plist);
	//printf("\n");
	//SListPopBack(&plist);
	SListPrint(plist);
	printf("\n");



	//SLTNode* pos = SListFind(plist, 2);
	//int i = 1;
	//while (pos)
	//{
	//	printf("��%d��pos�ڵ�:%p->%d\n", i++, pos, pos->data);
	//	pos = SListFind(pos->next, 2);
	//}
	//���Ҳ��޸�
	//SLTNode* pos = SListFind(plist, 3);
	//if (pos)
	//{
	//	pos->data=30;
	//}
	//SListPrint(plist);
	//���Ҳ�����ֵ
	SLTNode* pos = SListFind(plist, 3);
	if (pos)
	{
		SListInsert(&plist, pos, 30);
	}
	SListPrint(plist);
	printf("\n");
	pos = SListFind(plist, 4);
	if (pos)
	{
		SListInsert(&plist, pos, 30);
	}
	SListPrint(plist);
}
Test2()
{

}

int main()
{
	Test1();
	Test2();
	return 0;
}