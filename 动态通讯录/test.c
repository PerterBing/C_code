#define _CRT_SECURE_NO_WARNINGS

#include"Contact.h"
//��̬�����汾
//����ھ�̬�汾����ͨѶ¼�Ĵ洢�������˸���
//��ͨѶ¼�洢��ϵ����Ϣ��װ����ָ�룬������ʼ����Ϊ3��
//���������㣬�������˼������ģ��
//�ֱ�����˶�̬��ʼ����������̬������ϵ�˺��������ݺ��������ٺ���

//�ļ�Ŀ¼�汾
//�������ļ�

void menu()
{ 
	printf("**************************\n");
	printf("****** 1.Add  2.Del  *****\n");
	printf("****** 3.Sea  4.Mod  *****\n");
	printf("****** 5.Show 6.Sort *****\n");
	printf("****** 0.Exit        *****\n");
	printf("**************************\n");
}

int main()
{
	int input = 0;
	Contact con;
	InitContact(&con);
	do
	{
		menu();
		printf("���������ѡ��:> ");
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
			ModifyContact(&con);
			break;
		case 5:
			ShowContact(&con);
			break;
		case 6:
			SortContact(&con);
			break;
		case 0:
			SaveContact(&con);
			DestroyContact(&con);
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);
}


