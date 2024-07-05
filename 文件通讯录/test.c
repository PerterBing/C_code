#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"contect.h"

//动态通讯录，通讯录结构体中创建了PeoInfo* 类型的指针，指向开辟的空间，并将开辟空间初始化为3个PeoInfo
//当空间不足时，可以检查增容，当通讯录人数等于总容量时，增加3个人的信息
//当关闭通讯录时，销毁通讯录指针

//文件版本
void menu()
{
	printf("******************************\n");
	printf("**** 1.add       2.del    ****\n");
	printf("**** 3.sea       4.mod    ****\n");
	printf("**** 5.show      6.sort   ****\n");
	printf("**** 0.exit(必须使用0退出此程序！！） ****\n");
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
		printf("请输入你的选择：> ");
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
			printf("退出通讯录\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}

	} while (input);

    return 0;
}
