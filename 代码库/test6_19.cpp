#include<stdio.h>
#include<string.h>

//实现通用 对数组进行排序的函数
//规则从大到小
//算法  选择
//测试 char 数组，int 数组
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
//	//测试数组
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
//			printf("%d是斐波那契数\n", num);
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

#include<Windows.h>
#include<stdlib.h>
#include<time.h>
//char* gets(char* str);

	/*double pi = 3.141500;
	scanf_s("%lf", &pi);
	printf("pi=%le\n", pi);

	scanf_s("%le", &pi);
	printf("pi=%lf\n", pi);*/
	/*unsigned int x;
	scanf_s("%o", &x);
	printf("%#o\n", x);*/

	//char buf[10];
	//// scanf("%ms", buf);  // 最多接收9个字符，遇到空格 tab键 回车也会停止接收
	//scanf_s("%9s", buf);  // 数组名表示数字的首地址，不需要加&
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
	//int a = 6500;
	//printf("%c\n", (char)a);
	//

	//putchar(48);

	//int a = 0;
	//int* p = &a;
	//printf("%d\n", sizeof(int*));

	//printf("printf(\"hello world!\\n\");\n");
	/*printf("\\ta");*/

	//for (int i = 0, k = 0; k = 0; k++)
	//{
	//	printf("1111111\n");
	////}
	//printf("111111\n");
	//Sleep(1000);
	//printf("222222\n");
	//Sleep(1000);
	//system("cls");

//int fib(int n)
//{
//	if (n < 0)
//		return -1;
//	else if (n == 0)
//		return 0;
//	else if (n == 1)
//		return 1;
//	else
//		return fib(n - 1) + fib(n - 2);
//}
//
//int main()
//{
//	int n = 0;
//	printf("请输入fib数：\n");
//	scanf_s("%d", &n);
//	printf("%d\n", fib(n));
//	return 0;
//}
//
//int main()
//{
//	int n, n1 = 1, n2 = 1, n3;
//	printf("求斐波那契数前n个数：\n");
//	scanf_s("%d", &n);
//	if (n <= 2)
//		printf("数列：%d %d", n1, n2);
//	else
//	{
//		printf("数列：%d %d", n1, n2);
//		for (int i = 3; i <= n; i++) {
//			n3 = n1 + n2;
//			printf(" %d", n3);
//			n1 = n2;
//			n2 = n3;
//		}
//	}
//
//}

//int main()
//{
//	char arr[] = "anagram";
//	char* s = arr;
//	int sz=sizeof(s) / sizeof(*s);
//	printf("sizeof(arr)=%d\n", sizeof(arr));
//	printf("sizeof(arr[0])=%d\n", sizeof(arr[0]));
//	printf("sizeof(arr)/sizeof(arr[0])=%d\n", sizeof(arr) / sizeof(arr[0]));
//
//	printf("sizeof(s)=%d\n", sizeof(&(*s)));
//	printf("sizeof(*s)=%d\n", sizeof(*s));
//	printf("%d\n", sz);
//	/*strlen(s);
//	printf("%d\n", strlen(s));*/
//	if ('a' < 'b')
//	{
//		printf("11111111\n");
//	}
//	return 0;
//}


//我的字母异位，我的狗屎代码
//int main()
//{
//	char arr[] = "anagram";
//	char arr1[] = "aganmar";
//	char* s = arr;
//	char* t = arr1;
//	for (int i = 0; i < strlen(s) - 1; i++)
//	{
//		for (int j = 0; j < strlen(s) - i - 1; j++)
//		{
//			if (*(s + j + 1) == '\0')
//			{
//				break;
//			}
//			if (*(s + j) > *(s + j + 1))
//			{
//				char temp = *(s + j);
//				*(s + j) = *(s + j + 1);
//				*(s + j+1) = temp;
//			}
//		}
//	}
//
//	for (int i = 0; i < strlen(t) - 1; i++)
//	{
//		for (int j = 0; j < strlen(t) - i - 1; j++)
//		{
//			if (*(t + j + 1) == '\0')
//			{
//				break;
//			}
//			if (*(t + j) > *(t + j + 1))
//			{
//				char temp = *(t + j);
//				*(t + j) = *(t + j + 1);
//				*(t + j + 1) = temp;
//			}
//		}
//	}
//	printf("%s\n", s);
//	printf("%s\n", t);
//	if (!strcmp(s, t))
//	{
//		printf("11111111\n");
//	}
//	else
//	{
//		printf("222222222\n");
//	}
//	return 0;
//}
//
////人家的牛逼代码
//int cmp(const void *a, const void *b)
//{
//	return strcmp((char*)a, (char*)b);
//}
//
//int main()
//{
//	char arr1[] = "anagram";
//	char arr2[] = "aganmar";
//	char* s = arr1;
//	char* t = arr2;
//	if (strlen(s) != strlen(t))
//	{
//		return false;
//	}
//	qsort(s, strlen(s), sizeof(char), cmp);
//	qsort(t, strlen(t), sizeof(char), cmp);
//	if (!strcmp(s, t))
//		printf("s和t是异构\n");
//	else
//		printf("s和t不是异构\n");
//	return 0;
//}

int my_strlen(char* str)
{
	char* start = str;
	while (*str != '\0')
	{
		str++;
	}
	return (str - start);
}


int main()
{
	//static int a;
	//printf("%d\n", a);
	//printf("%d\n", b);
//	char arr[] = "hello bit";
//	char arr1[] = "hello";
//	char* p = &arr1[7];
//	printf("%d\n", p - arr1);
	//printf("%d\n",my_strlen(arr));
	int a = 0;
	int b = 0;
	scanf_s("%d %d", &a, &b);
	printf("%d,%d\n", a, b);
	return 0;
}