#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<ctime>
#include<cmath>
#include<string>
using namespace	std;


//int main()
//{
//	srand((unsigned)time(NULL));
//	int num=(rand()%101);
//	int cur = 0;
//	cout << "�����������:";
//	while (cur!=num)
//	{
//		cin >> cur;
//		if (cur > num)
//		{
//			cout << "�´���" << endl;
//		}
//		else if(cur<num)
//		{
//			cout << "��С��" << endl;
//		}
//	}
//	cout<<"�¶��ˣ�"<<num<<endl;
//	
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int num = 0;
//	int sum = 0;
//	cin >> num;
//	do
//	{
//		sum=(num % 10)* (num % 10) * (num % 10) +(num/10%10)* (num / 10 % 10) * (num / 10 % 10) +(num/10/10%10)* (num / 10 / 10 % 10)* (num / 10 / 10 % 10);
//
//	} while(0);
//	if (sum == num)
//	{
//		cout << num << "����λˮ�ɻ���" << endl;
//	}
//	else
//	{
//		cout << num << "������λˮ�ɻ���" << endl;
//	}
//	system("pause");
//	return 0;
//}
//
//int main()
//{
//	int num = 0;
//	for (num = 0; num < 101; num++)
//	{
//		if (num % 7 == 0 || num % 10 ==7 || num % 7 == 0)
//		{
//			cout << num;
//			cout << "�����ӣ���" << endl;
//		}
//	}
//	system("pause");
//	return 0;
//}

//i/*nt main()
//{	
//	int i = 1;
//	int j = 1;
//	for (i = 1; i <=9; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			cout << j << "*" << i << "=" << i * j;
//			cout <<"     ";
//		}
//		cout << endl;
//	}
//
//	system("pause");
//	return 0;
//}*/
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5 };
//	int left = 0;
//	int right = sizeof(arr)/sizeof(arr[0])-1;
//	while (left < right)
//	{
//		int tmp =arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		left++;
//		right--;
//	}
//	for (int i = 0; i < 5; i++)
//	{
//		cout << arr[i] << endl;
//	}
//	system("pause");
//	return 0;
//}


//ð������
//int main()
//{
//
//	int arr[9] = { 4,2,8,0,5,7,1,3,9 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int max = arr[0];
//	for (int i = 0; i < sz-1; i++)
//	{
//		for (int j = 0; j < sz - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//	for (int i = 0; i < sz; i++)
//	{
//		cout << arr[i] << " ";
//	}
//	system("pause");
//	return 0;
//}
//
//struct Hero
//{
//	string name;
//	int age;
//	string sex;
//};
//
//void CompareAge(struct Hero s[], int len)
//{
//	int i = 0;
//	for (i = 0; i < len-1; i++)
//	{
//		for (int j = 0; j < len - i - 1; j++)
//		{
//			if (s[j].age > s[j + 1].age)
//			{
//				struct Hero tmp = s[j];
//				s[j]= s[j + 1];
//				s[j + 1] = tmp;
//			}
//		}
//	}
//}
//
//int main()
//{
//	struct Hero s[5] = {
//		{"�ŷ�",20,"��"},
//		{"����",60,"��"},
//		{"����",55,"��"},
//		{"����",30,"��"},
//		{"����",80,"Ů"} };
//	int len = sizeof(s) / sizeof(s[0]);
//	CompareAge(s,len);
//	for (int i = 0; i < len; i++)
//	{
//		cout <<s[i].name<<s[i].age<<s[i].sex<<endl;
//	}
//	system("pause");
//	return 0;
//}

//
//const double PI = 3.14;
//
//class circle
//{
//public:
//	int r;
//	double calculate()
//	{
//		return 2 * PI * r;
//	}
//};
//
//int main()
//{
//	circle c1;
//	c1.r = 10;
//	cout << c1.calculate() << endl;
//	system("pause");
//	return 0;
//}

//class stu
//{
//public:
//	string name;
//	int ID;
//	void showstu()
//	{
//		cout << S.name<< " " << S.ID << endl;
//	}
//};
//int main()
//{
//	stu S;
//	S.name = "����";
//	S.ID =2109132129;
//	S.showstu();
//	system("pause");
//	return 0;
//}

//class Cube
//{
//public:
//	void obtain()
//	{
//		cin >> L;
//		cin >> W;
//		cin >> H;
//	}
//	int obtainS()
//	{
//		return 2 * (L * W + L * H + H * W);
//	}
//	int obtainV()
//	{
//		return L * W * H;
//	}
//private:
//	int L;
//	int W;
//	int H;
//};
//
//int main()
//{
//		Cube c1;
//	c1.obtain();
//	cout << c1.obtainS() << endl;
//	cout << c1.obtainV() << endl;
//	system("pause");
//	return 0;
//}

//class point//����
//{
//public:
//	void setx(int x)
//	{
//		x = x;
//	}
//	void sety(int y)
//	{
//		y = y;
//	}
//	int obtainx()
//	{
//		return x;
//	}
//	int obtainy()
//	{
//		return y;
//	}
//private:
//	int x;
//	int y;
//};
//
//class circle
//{
//public:
//	void setr(int r)
//	{
//		r = r;
//	}
//	int getr()
//	{
//		return r;
//	}
//
//	void setCenter(point center)
//	{
//		Center = center;
//	}
//	point getCenter()
//	{
//		return Center;
//	}
//private:
//	int r;
//	point Center;
//};
//
//void isIncircle(point &o1,circle &c1)
//{
//	int distancecp = (c1.getCenter().obtainx() - o1.obtainx()) * (c1.getCenter().obtainx() - o1.obtainx()) - (c1.getCenter().obtainy() - o1.obtainy()) * (c1.getCenter().obtainy() - o1.obtainy());
//	int distancer = c1.getr() * c1.getr();
//	if (distancecp == distancer)
//	{
//		cout << "����Բ��" << endl;
//	}
//	else if (distancecp < distancer)
//	{
//		cout << "����Բ��" << endl;
//	}
//	else if (distancecp > distancer)
//	{
//		cout << "����Բ��" << endl;
//	}
//}
//
//
//int main()
//{
//	circle c1;
//	c1.setr(10);
//	point center;
//	center.setx(10);
//	center.sety(0);
//	c1.setCenter(center);
//	point o1;
//	o1.setx(10);
//	o1.sety(10);
//	isIncircle(o1,c1);
//	system("pause");
//	return 0;
//}

//class Point
//{
//public:
//	void setx(int x)
//	{
//		m_x = x;
//	}
//	int getx()
//	{
//		return m_x;
//	}
//	void sety(int y)
//	{
//		m_y = y;
//	}
//	int gety()
//	{
//		return m_y;
//	}
//private:
//	int m_x;
//	int m_y;
//};

//class circle
//{
//public:
//	void setr(int r)
//	{
//		m_r = r;
//	}
//	int getr()
//	{
//		return m_r;
//	}
//	void setcenter(Point center)
//	{
//		m_center=center;
//	}
//	Point getcenter()
//	{
//		return m_center;
//	}
//private:
//	int m_r;
//	Point m_center;
//};
//
//#include"circle.h"
//#include"point.h"
//void isIncircle(circle c, Point p)
//{
//	int distancecp = (c.getcenter().getx() - p.getx()) * (c.getcenter().getx() - p.getx()) + (c.getcenter().gety() - p.gety()) * (c.getcenter().gety() - p.gety());
//	int distancer = (c.getr() * c.getr());
//	if (distancecp ==distancer)
//	{
//		cout << "����Բ��" << endl;
//	}
//	else if (distancecp < distancer)
//	{
//		cout << "����Բ��" << endl;
//	}
//	else if (distancecp > distancer)
//	{
//		cout << "����Բ��" << endl;
//	}
//}
//
//int main()
//{
//	circle c;
//	c.setr(10);
//	Point center;
//	center.setx(10);
//	center.sety(0);
//	c.setcenter(center);
//	Point p;
//	p.setx(10);
//	p.sety(9);
//	isIncircle(c, p);
//	system("pause");
//	return 0;
//}

//class Person
//{
//public:
//	Person()
//	{
//		cout << "���캯���ĵ���" << endl;
//	}
//	Person(int a)
//	{
//		age = a;
//		cout << "Person���вι��캯���ĵ���" << endl;
//	}
//	//�������캯��
//	Person(const Person &p)
//	{
//		age = p.age;
//	}
//	~Person()
//	{
//		cout << "Person��������������" << endl;
//	}
//	int age;
//};
//
//
//void test()
//{
//	Person p;//Ĭ�Ϲ��캯������
//	Person p2(10);//�вι��캯��
//	Person p3(p2);//�������캯��
//}
//int main()
//{
//	/*test();*/
//	Person p;
//	system("pause");
//	return 0;
//}

//void test()
//{
//	Person p1(20);
//	Person p2(p1);
//	cout << "p2����������age��" << p2.age << endl; 
//}

//void dowork(Person p)
//{
//
//}
//
//void test()
//{
//	Person p;
//	dowork(p);
//}

//Person dowork2()
//{
//	Person p1;
//	cout << (int*)&p1 << endl;
//	return p1;
//}
//
//void test03()
//{
//	Person p = dowork2();
//	cout << (int*)&p << endl;
//}

//void test()
//{
//	Person p;
//	p.age = 18;
//
//	Person p2(p);
//
//	cout << "p2������Ϊ: " << p2.age << endl;
//}
//void test()
//{
//	Person p1(10);
//	p1.age = 18;
//	Person p2(p1);
//	cout << p1.age << endl;
//}

//void test()
//{
//	Person p1(10);
//	Person p2(p1);
//}
//class Person
//{
//public:
//	Person()
//	{
//		cout << "Ĭ���޲ι��캯���ĵ���" << endl;
//	}
//	Person(int a,int h)
//	{
//		age = a;
//		hight=new int(h);
//		cout << "Ĭ���вι��캯���ĵ���" << endl;
//	}
//	Person(const Person& p)
//	{
//		age = p.age;
//		/*hight = p.hight;*/
//		//���
//		hight=new int(*p.hight);
//		cout << "Ĭ�Ͽ��������ĵ���" << endl;
//	}
//	~Person()
//	{
//		//�������룬�Ѷ������������ͷ�
//		if (hight != NULL)
//		{
//			delete hight;
//			hight = NULL;
//		}
//		cout << "���������ĵ���" << endl;
//	}
//	int age;
//	int *hight;
//};
//void test()
//{
//	Person p1(10,160);
//	Person p2(p1);
//	cout << "p1������Ϊ�� " << p1.age << endl;
//	cout << "p1�����Ϊ�� " << *p1.hight << endl;
//	cout << "p2����������Ϊ�� " << p2.age << endl;
//	cout << "p2���������Ϊ�� " << *p2.hight << endl;
//
//}


class Phone
{
public:

	Phone(string pName)
	{
		m_PName = pName;
	}
	string m_PName;
};


class Person
{
public:

	Person(string name, string pName) :m_Name(name), m_Phone(pName)
	{

	}
	string m_Name;

	Phone m_Phone;
};

void test()
{
	Person p("����", "ƻ��MAx");
	cout << p.m_Name << p.m_Phone.m_PName << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
 }