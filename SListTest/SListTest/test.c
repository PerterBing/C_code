#define _CRT_SECURE_NO_WARNINGS
#include"SListTest.h"


//void SListTest1()
//{
//	struct SListNode* plist=NULL;
//	SListPushBack(&plist, 1);
//	SListPushBack(&plist, 2);
//	SListPushBack(&plist, 3);
//	SListPushBack(&plist, 4);
//	SListPrint(plist);
//	printf("\n");
//	//SListPushFront(&plist, 10);
//	//SListPushFront(&plist, 9);
//	//SListPushFront(&plist, 8);
//	//SListPushFront(&plist, 7);
//	//SListPrint(plist);
//	//printf("\n");
//
//	/*SListPopBack(&plist);
//	SListPopBack(&plist);
//	SListPopBack(&plist);
//	SListPopBack(&plist);
//	SListPopBack(&plist);
//	SListPrint(plist);
//	printf("\n");*/
//	
//	//SListPopFront(&plist);
//	//SListPopFront(&plist);
//	//SListPopFront(&plist);
//	//SListPopFront(&plist);
//	//SListPopFront(&plist);
//
//	//SListPrint(plist);
//	//int ret=SListFind(plist, 5);
//	//if (ret == -1)
//	//{
//	//	printf("���������޴����ݣ�����������: ");
//	//}
//	//else
//	//{
//	//	printf("%d\n", ret);
//	//}
	//SLTNode* pos=SListFind(plist, 4);
	//if (pos != NULL)
	//{
	//	SListInsert(&plist, pos, 11);
	//}
//	SListPrint(plist);
//	pos = SListFind(plist, 4);
//	if (pos != NULL)
//	{
//		SListInsert(&plist, pos, 12);
//	}
//	SListPrint(plist);
//
//	pos = SListFind(plist, 1);
//	if (pos != NULL)
//	{
//		SListEase(&plist, pos);
//	}
//	SListPrint(plist);
//
//
//	SListDestory(&plist);
//}

void My_menu()
{
	printf("����������������������������������������������������������������\n");
	printf("******1.ͷ��        2.β��******\n");
	printf("******3.ͷɾ        4.βɾ******\n");
	printf("******5.����ĳλ�ò���  6.ĳλ��ɾ��******\n");
	printf("******7.��ӡ******\n");
	printf("����������������������������������������������������������������\n");
}

SListText2()
{
	int input = 0;
	int x = 0;
	struct SListNode* plist = NULL;
	while (input!=-1)
	{
		My_menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("������Ҫͷ���������-1����:\n");
			scanf("%d", &x);
			while (x != -1)
			{
				SListPushFront(&plist, x);
				scanf("%d", &x);
			}
			break;
		case 2:
			printf("������Ҫβ���������-1����:\n");
			scanf("%d", &x);
			while (x != -1)
			{
				SListPushBack(&plist, x);
				scanf("%d", &x);
			}
			break;
		case 3:
			SListPopFront(&plist);
			SListPrint(plist);
			break;
		case 4:
			SListPopBack(&plist);
			SListPrint(plist);
			break;
		case 5:
			printf("��������ҵ�����:\n");
			scanf("%d", &x);
			SLTNode* pos = SListFind(plist, x);
			if (pos != NULL)
			{
				int y = 0;
				printf("������Ҫ���������\n");
				scanf("%d", &y);
				SListInsert(&plist, pos, y);
			}
			break;
		case 6:
			printf("��������ҵ�����:\n");
			scanf("%d", &x);
			pos = SListFind(plist, x);
			if (pos != NULL)
			{
				SListEase(&plist, pos);
			}
			break;
		case 7:
			SListPrint(plist);
			break;
		default:
			printf("�����������������룡��\n");
		}
}
}

int main()
{
	//SListTest1();
	SListText2();
	return 0;
}