#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string>


//�ӷ����������
//class Person
//{
//public:
//	//��Ա��������
//	Person operator+(Person &p)
//	{
//		Person temp;
//		temp.m_A = this->m_A + p.m_A;
//		temp.m_B = this->m_B + p.m_B;
//		return temp;
//	}
//
//	int m_A;
//	int m_B;
//};
//
////ȫ�ֺ�������
//Person operator+(Person &p1, Person &p2)
//{
//	Person temp;
//	temp.m_A = p1.m_A + p2.m_A;
//	temp.m_B = p1.m_B + p2.m_B;
//	return temp;
//}
//
//void test()
//{
//	Person p1;
//	p1.m_A = 10;
//	p1.m_B = 10;
//	Person p2;
//	p2.m_A = 20;
//	p2.m_B = 20;
//	//Person p3;
//	//p3 = p1 + p2;
//
//	Person p3 = p1.operator+(p2);
//	 p3 = operator+(p1, p2);
//
//	cout << p3.m_A << "  " << p3.m_B << endl;
//}



//�������������

//class Person
//{
//	friend ostream& operator<<(ostream& cout, Person& p);
//public:
//	Person(int a, int b)
//	{
//		m_A = a;
//		m_B = b;
//	}
//
//	//��Ա��������
//private:
//	int m_A;
//	int m_B;
//};
//
////ȫ�ֺ������������
//ostream& operator<<(ostream &cout,Person &p)//����  operator<<(cout,p) ��Ϊ  cout<<p;
//{
//	cout << "m_A = " << p.m_A << "  m_B = " << p.m_B;
//	return cout;
//}
//void test()
//{
//	Person p(10, 10);
//
//	cout << p << "hello world " << endl;;
//}


//���ص��������

//class MyInteger
//{
//	friend ostream& operator<<(ostream& cout, MyInteger myint);
//public:
//	MyInteger()
//	{
//		m_Num = 0;
//	}
//
//	//����ǰ��++�����
//	MyInteger& operator++()//����ֵ����������ΪҪ����������ֻ��һ�����ݽ���++����ֹԴ���ݱ����ġ�
//	{
//		m_Num++;
//		return *this;
//	}
//
//	//���غ���++�����
//
//	MyInteger operator++(int)//int ����ռλ��������������ǰ�úͺ��õ���
//	{
//		//�ȼ�¼�ṹ
//		MyInteger temp = *this;
//		//�����
//		m_Num++;
//		//���������
//		return temp;//��ʱ���������ܷ������ã���Ϊ������
//	}
//private:
//	int m_Num;
//};
//
////�������������
//ostream& operator<<(ostream& cout, MyInteger myint)
//{
//	
//	cout << myint.m_Num;
//	return cout;
//}
//
//void test01()
//{
//	MyInteger myint;
//
//	cout << ++(++myint) << endl;
//	cout << myint << endl;
//}
//
//void test02()
//{
//	MyInteger myint;
//	cout << myint++ << endl;
//	cout << myint << endl;
//}


//��ֵ���������

//class Person
//{
//public:
//	Person(int age)
//	{
//		m_Age = new int(age);
//	}
//
//	int* m_Age;
//
//	~Person()
//	{
//		if (m_Age != NULL)
//		{
//			delete m_Age;
//			m_Age = NULL;
//		}
//	}
//
//	Person& operator=(Person& p)
//	{
//		//�������ṩǳ����
//		// m_Age=p.m_Age;
//		//���ж��Ƿ��������ڶ�������������ͷŸɾ���Ȼ���ٽ������
//
//		if (m_Age != NULL)
//		{
//			delete m_Age;
//			m_Age = NULL;
//		}
//		//���
//		m_Age = new int(*p.m_Age);
//
//		return *this;
//	}
//};
//
//void test()
//{
//	Person p1(18);
//
//	Person p2(20);
//
//	Person p3(22);
//
//	p3=p2 = p1;
//
//	cout << "p1������Ϊ�� " << *p1.m_Age << endl;
//	cout << "p2������Ϊ�� " << *p2.m_Age << endl;
//	cout << "p3������Ϊ�� " << *p3.m_Age << endl;
//}


//��ϵ���������
//class Person
//{
//public:
//	Person(string name, int age)
//	{
//		m_Name = name;
//		m_Age = age;
//	}
//	bool operator==(Person& p)
//	{
//		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
//		{
//			return true;
//		}
//		else
//			return false;
//	}
//
//	bool operator!=(Person& p)
//	{
//		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
//		{
//			return false;
//		}
//		else
//			return true;
//	}
//
//	string m_Name;
//	int m_Age;
//};
//
//void test()
//{
//	Person p1("Tom",18);
//
//	Person p2("jack", 18);
//
//	if (p1 == p2)
//	{
//		cout << "p1��p2���" << endl;
//	}
//	else
//	{
//		cout << "p1��p2�����" << endl;
//	}
//
//	if (p1 != p2)
//	{
//		cout << "p1��p2�����" << endl;
//	}
//	else
//	{
//		cout << "p1��p2���" << endl;
//	}
//}


//�����������������
//
//class MyPrint
//{
//public:
//	void operator()(string test)
//	{
//		cout << test << endl;
//	}
//};
//
//void MyPrint02(string test)
//{
//	cout << test << endl;
//}
//
//void test01()
//{
//	MyPrint myPrint;
//
//	myPrint("hello world");//�º���
//
//	MyPrint02("hello world");
//}
//
//class MyAdd
//{
//public:
//	int operator()(int num1, int num2)
//	{
//		return num1 + num2;
//	}
//};
//
//void test02()
//{
//	MyAdd myadd;
//	int ret=myadd(100, 100);
//	cout << "ret = " << ret << endl;
//
//	//������������
//	cout << MyAdd()(100, 100) << endl;
//}

//class Base1
//{
//public:
//	int m_A;
//protected:
//	int m_B;
//private:
//	int m_C;
//};
//
//class Son1 :public Base1
//{
//public:
//	void func()
//	{
//		m_A = 10;
//		m_B = 10;//����Ȩ�ޣ����ڷ��ʣ����ⲻ�ɷ���
//	/*	m_C = 10;*/
//	}
//};
//
//class Base2
//{
//public:
//	int m_A;
//protected:
//	int m_B;
//private:
//	int m_C;
//};
//class Son2 :protected Base2
//{
//	void func()
//	{
//		m_A = 10;
//		m_B = 10;
//	}
//};
//
//void test()
//{
//	Base1 p;
//	p.m_A;
//		Base2 p1;
//		p1.m_A
//
//}

class Base
{
public:
	Base()
	{
		cout << "Base���캯����" << endl;
	}
	~Base()
	{
		cout << "Base����������" << endl;
	}
};

class Son:public Base
{
public:
	Son()
	{
		cout << "Son���캯����" << endl;
	}
	~Son()
	{
		cout << "Son����������" << endl;
	}
};


void test()
{
	Base b;

	Son s;

}
int main()
{
	/*test01();*/
	test();
	system("pause");
	return 0;
}
