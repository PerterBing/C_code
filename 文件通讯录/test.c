#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"contect.h"

//��̬ͨѶ¼��ͨѶ¼�ṹ���д�����PeoInfo* ���͵�ָ�룬ָ�򿪱ٵĿռ䣬�������ٿռ��ʼ��Ϊ3��PeoInfo
//���ռ䲻��ʱ�����Լ�����ݣ���ͨѶ¼��������������ʱ������3���˵���Ϣ
//���ر�ͨѶ¼ʱ������ͨѶ¼ָ��

//�ļ��汾
void menu()
{
	printf("******************************\n");
	printf("**** 1.add       2.del    ****\n");
	printf("**** 3.sea       4.mod    ****\n");
	printf("**** 5.show      6.sort   ****\n");
	printf("**** 0.exit(����ʹ��0�˳��˳��򣡣��� ****\n");
	printf("******************************\n");
}


int main(int   argc, char* argv[], char* envp[])
{
	int input = 0;
	Contact con;
	InitContact(&con);
	do
	{
		menu();
		printf("���������ѡ��> ");
		scanf("%d", &input);
		
		switch (input)
		{
		case 1:
			AddContact(&con);
			break;
		case 2:
			DelContact(&con);
			break;
		case 3:
			SeaContact(&con);
			break;
		case 4:
			ModContact(&con);
			break;
		case 5:
			ShowContact(&con);
			break;
		case 6:
			SortContact(&con);
			break;
		case 0:
			SaveContact(&con);
			DestoryContact(&con);
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}

	} while (input);

    return 0;
}
