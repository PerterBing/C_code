#define _CRT_SECURE_NO_WARNINGS

#include"Contact.h"


void menu()
{
	printf("******************************\n");
	printf("********* 1.add    2.del    **\n");
	printf("********* 3.search 4.modify **\n");
	printf("********* 5.show   6.sort   **\n");
	printf("********* 0.exit            **\n");
	printf("******************************\n");
}
int main()
{
	int input = 0;
	Contact con;
	InitContact(&con);

	do
	{
		menu();
		printf("请输入要进行的操作：\n");
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
			break;
		case 4:
			break;
		case 5:
			ShowContact(&con);
			break;
		case 6:
			break;
		case 0:
			break;
		default:
			break;
		}
	} while (input);
	return 0;
}