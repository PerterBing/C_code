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
//	//	printf("单链表中无此数据，请重新输入: ");
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
	printf("————————————————————————————————\n");
	printf("******1.头插        2.尾插******\n");
	printf("******3.头删        4.尾删******\n");
	printf("******5.查找某位置插入  6.某位置删除******\n");
	printf("******7.打印******\n");
	printf("————————————————————————————————\n");
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
			printf("请输入要头插的数，以-1结束:\n");
			scanf("%d", &x);
			while (x != -1)
			{
				SListPushFront(&plist, x);
				scanf("%d", &x);
			}
			break;
		case 2:
			printf("请输入要尾插的数，以-1结束:\n");
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
			printf("请输入查找的数字:\n");
			scanf("%d", &x);
			SLTNode* pos = SListFind(plist, x);
			if (pos != NULL)
			{
				int y = 0;
				printf("请输入要插入的数：\n");
				scanf("%d", &y);
				SListInsert(&plist, pos, y);
			}
			break;
		case 6:
			printf("请输入查找的数字:\n");
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
			printf("操作有误，请重新输入！！\n");
		}
}
}

int main()
{
	//SListTest1();
	SListText2();
	return 0;
}