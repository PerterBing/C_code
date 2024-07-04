#define _CRT_SECURE_NO_WARNINGS

#include"Contact.h"
//动态增长版本
//相比于静态版本，将通讯录的存储容量做了改善
//将通讯录存储联系人信息封装成了指针，给定起始容量为3，
//当容量不足，又设置了检查增容模块
//分别添加了动态初始化函数，动态增加联系人函数，增容函数，销毁函数

//文件目录版本
//增加了文件

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
		printf("请输入你的选择:> ");
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
			printf("退出通讯录\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
}


