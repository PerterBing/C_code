#include<stdio.h>
#include<string.h>

//ʵ��ͨ�� �������������ĺ���
//����Ӵ�С
//�㷨  ѡ��
//���� char ���飬int ����
//
//template<class T>
//void mySwap(T &a,T &b)
//{
//	T temp = a;
//	a = b;
//	b = temp;
//}
//
//template<class T>
//void mySort(T arr[], int len)
//{
//	for (int i = 0; i < len; i++)
//	{
//		int max = i;
//		for (int j = i + 1; j < len; j++)
//		{
//			if (arr[max] < arr[j])
//			{
//				max = j;
//			}
//		}
//		if (max != i)
//		{
//			mySwap(arr[max], arr[i]);
//		}
//	}
//}
//
//template<class T>
//void printArray(T arr[], int len)
//{
//	for (int i = 0; i < len; i++)
//	{
//		cout << arr[i] << " ";
//	}
//}
//
//void test01()
//{
//	//��������
//	char charArr[] = "badcfe";
//	int num = sizeof(charArr) / sizeof(charArr[0]);
//	mySort(charArr, num);
//	printArray(charArr, num);
//}
//
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}

//int main(int argc, const char* argv[])
//{
//	int num = 0;
//	int f1 = 1;
//	int f2 = 1;
//	int f3 = 0;
//	while (1)
//	{
//		if (num == f2)
//		{
//			printf("%d��쳲�������\n", num);
//			break;
//		}
//		else if (num < f2)
//		{
//			printf("%d\n", (f2 - num) > (num - f1) ? num - f1 : f2 - num);
//			break;
//		}
//		else
//		{
//			f3 = f1 + f2;
//			f1 = f2;
//			f2 = f3;
//		}
//	}
//		return 0;
//
//}


//int main()
//{
//	int line = 5;
//	int i = 0;
//	while (i < line)
//	{
//		int j = 0;
//		while (j <= i)
//		{
//			printf("*");
//			j++;
//		}
//		i++;
//		printf("\n");
//	}
//
//	int k = 0;
//	while (k < line - 1)
//	{
//		int j = 0;
//		while (j <= k)
//		{
//			printf(" ");
//			j++;
//		}
//		while (j < line )
//		{
//			printf("*");
//			j++;
//		}
//		k++;
//		printf("\n");
//	}
//
//	return 0;
//}

//int main()
//{
//	int i =1 ;
//	for (i = 1; i <= 9; i++)
//	{
//		for (int j = 1; j <= i; j++)
//		{
//			printf("%d * %d = %d  ", i, j, i * j);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//int main()
//{
//	int i = 1;
//	int line = 5;
//	
//	for (i = 1; i <=line; i++)
//	{
//		for (int k = 1; k <= line-i; k++)
//		{
//			printf(" ");
//		}
//		for (int j = 1; j <= 2 * i - 1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	return 0;
//}


//char* gets(char* str);
int main()
{
	/*double pi = 3.141500;
	scanf_s("%lf", &pi);
	printf("pi=%le\n", pi);

	scanf_s("%le", &pi);
	printf("pi=%lf\n", pi);*/
	/*unsigned int x;
	scanf_s("%o", &x);
	printf("%#o\n", x);*/

	//char buf[10];
	//// scanf("%ms", buf);  // ������9���ַ��������ո� tab�� �س�Ҳ��ֹͣ����
	//scanf_s("%9s", buf);  // ��������ʾ���ֵ��׵�ַ������Ҫ��&
	//printf("buf = %s\n", buf);

	/*int a, b;
	scanf_s("%d%*d%d", &a, &b);
	printf("a=%d,b=%d\n", a, b);*/

	//char buf[20];
	//gets_s(buf, 9);
	//printf("buf=%s\n", buf);

	//while (getchar() != '\n');

	/*gets(buf);
	printf("buf=%s\n", buf);*/
	int a = 6500;
	printf("%c\n", (char)a);
	
	return 0;
}