//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//
//
////scanf用法详解：
//
//int main(int argc, const char* argv[])
//{
//    double pi;
//
//    scanf("%lf", &pi);//小数形式浮点小数long型
//    printf("pi = %le\n", pi);//小数形式输入，指数打印3.14——>3.140000e+00
//
//    scanf("%le", &pi);//指数输入小数打印 3.1415e2——>314.150000
//    printf("pi = %lf\n", pi);
//
//    unsigned int x;
//    scanf("%x", &x);
//    printf("%#x\n", x);//AF——>0xaf
//
//    scanf("%o", &x);
//    printf("%#o\n", x);//067——>067    678——>067 因为8超过8进制
//
//   char buf[10];
//    scanf("%9s", buf);//输入字符串遇到空格,tab,回车就会结束接收,只接收9个字符
//
//    int a;
//    int b;
//    scanf("%d%*d%d", &a,&b);
//    printf("%d,%d\n", a, b);
//
//    int a, b, c;
//    scanf("%d%d%d", &a, &b, &c);//连续输入以空格，tab，回车符为分隔符
//
//    //1.：
//    char buf[20];
//    scanf("%s", buf);//只接受空格前面的
//
//    gets(buf);//可以接收带空格字符串
//    printf("%s\n", buf);
//
//    while (getchar() != '\n');//吃掉换行
//
//    gets(buf);//读取缓冲区剩余字符
//    printf("%s\n", buf);
//
//    //2.：
//    char buf[20];
//    scanf("%[^\n]s", buf);//除了回车都能接收
//    printf("%s\n", buf);
//
//    //3.：
//    int a;
//    scanf("%d\n", &a);
//    printf("%d\n", a);//有\n,\r,\t，空格时，输入按回车没有用，输入任意字符scanf才会退出
//
//
//    //4.：
//    int d;
//    scanf("a = %d", &d);
//    printf("%d \n", d);//原样手输入
//
//    //5.只有输入字符串或%c(空格，tab，回车会认为是字符)才接收垃圾字符，输入数字如果有其他字符不会接收
//
//    return 0;
//}