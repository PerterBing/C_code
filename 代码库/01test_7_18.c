//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//
//
////scanf�÷���⣺
//
//int main(int argc, const char* argv[])
//{
//    double pi;
//
//    scanf("%lf", &pi);//С����ʽ����С��long��
//    printf("pi = %le\n", pi);//С����ʽ���룬ָ����ӡ3.14����>3.140000e+00
//
//    scanf("%le", &pi);//ָ������С����ӡ 3.1415e2����>314.150000
//    printf("pi = %lf\n", pi);
//
//    unsigned int x;
//    scanf("%x", &x);
//    printf("%#x\n", x);//AF����>0xaf
//
//    scanf("%o", &x);
//    printf("%#o\n", x);//067����>067    678����>067 ��Ϊ8����8����
//
//   char buf[10];
//    scanf("%9s", buf);//�����ַ��������ո�,tab,�س��ͻ��������,ֻ����9���ַ�
//
//    int a;
//    int b;
//    scanf("%d%*d%d", &a,&b);
//    printf("%d,%d\n", a, b);
//
//    int a, b, c;
//    scanf("%d%d%d", &a, &b, &c);//���������Կո�tab���س���Ϊ�ָ���
//
//    //1.��
//    char buf[20];
//    scanf("%s", buf);//ֻ���ܿո�ǰ���
//
//    gets(buf);//���Խ��մ��ո��ַ���
//    printf("%s\n", buf);
//
//    while (getchar() != '\n');//�Ե�����
//
//    gets(buf);//��ȡ������ʣ���ַ�
//    printf("%s\n", buf);
//
//    //2.��
//    char buf[20];
//    scanf("%[^\n]s", buf);//���˻س����ܽ���
//    printf("%s\n", buf);
//
//    //3.��
//    int a;
//    scanf("%d\n", &a);
//    printf("%d\n", a);//��\n,\r,\t���ո�ʱ�����밴�س�û���ã����������ַ�scanf�Ż��˳�
//
//
//    //4.��
//    int d;
//    scanf("a = %d", &d);
//    printf("%d \n", d);//ԭ��������
//
//    //5.ֻ�������ַ�����%c(�ո�tab���س�����Ϊ���ַ�)�Ž��������ַ���������������������ַ��������
//
//    return 0;
//}