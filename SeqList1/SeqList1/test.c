#define _CRT_SECURE_NO_WARNINGS
#include"SeqList.h"

void Menu()
{
	printf("����������������������������������������������������\n");
	printf("***** 1.ͷ��   2.ͷɾ*****\n");
	printf("***** 3.β��   4.βɾ*****\n");
	printf("***** 5.pos��  6.posɾ*****\n");
	printf("***** 7.����   0.��ӡ *****\n");
	printf("����������������������������������������������������\n");
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
			printf("������Ҫͷ������֣���-1������");
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
			printf("��������Ҫβ������ݣ���-1������\n");
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
			printf("������Ҫ������±�����ݣ�");
			int pos = 0;
			scanf("%d", &pos);
			scanf("%d", &x);
			SeqListInsert(&s1, pos, x);
			break;
		case 6:
			printf("������Ҫɾ�����ݵ��±꣺");
			pos = 0;
			scanf("%d", &pos);
			SeqListErase(&s1, pos);
			
			break;
		case 7:
			printf("������Ҫ���ҵ����ݣ�");
			scanf("%d", &x);
			int ret = SeqListFind(&s1, x);
			if (ret == -1)
			{
				printf("��˳������޴�����");
			}
			else
			{
				printf("�������±�Ϊ��%d\n", ret);
			}
			break;
		default:
			printf("�޴�ѡ�����������\n");
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