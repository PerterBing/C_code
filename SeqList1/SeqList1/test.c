#define _CRT_SECURE_NO_WARNINGS
#include"SeqList.h"

void Menu()
{
	printf("——————————————————————————\n");
	printf("***** 1.头插   2.头删*****\n");
	printf("***** 3.尾插   4.尾删*****\n");
	printf("***** 5.pos插  6.pos删*****\n");
	printf("***** 7.查找   0.打印 *****\n");
	printf("——————————————————————————\n");
}

TestMenu()
{

	SL s1;
	SeqListInit(&s1);
	int input = 0;
	int x = 0;
	Menu();
	while (input != -1)
	{ 
		printf("******************\n");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			SeqListprint(&s1);
			break;
		case 1:
			printf("请输入要头插的数字，以-1结束：");
			scanf("%d", &x);
			while (x != -1)
			{
				SeqListPushFront(&s1, x);
				scanf("%d", &x);
			}
			break;
		case 2:
			SeqListPopFront(&s1);
			break;
		case 3:
			printf("请输入你要尾插的数据，以-1结束：\n");
			scanf("%d", &x);
			while (x != -1)
			{
				SeqListPushBack(&s1, x);
				scanf("%d", &x);
			}
			break;
		case 4:
			SeqListPopBack(&s1);
			break;
		case 5:
			printf("输入你要插入的下标和数据：");
			int pos = 0;
			scanf("%d", &pos);
			scanf("%d", &x);
			SeqListInsert(&s1, pos, x);
			break;
		case 6:
			printf("输入你要删除数据的下标：");
			pos = 0;
			scanf("%d", &pos);
			SeqListErase(&s1, pos);
			
			break;
		case 7:
			printf("输入需要查找的数据：");
			scanf("%d", &x);
			int ret = SeqListFind(&s1, x);
			if (ret == -1)
			{
				printf("该顺序表中无此数据");
			}
			else
			{
				printf("该数据下标为：%d\n", ret);
			}
			break;
		default:
			printf("无此选项，请重新输入\n");
			break;
		}
	}
	SeqListDestory(&s1);
}

int main()
{
	TestMenu();
	return 0;
}