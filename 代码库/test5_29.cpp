#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string>


//加法运算符重载
//class Person
//{
//public:
//	//成员函数重载
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
////全局函数重载
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



//左移运算符重载

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
//	//成员函数重载
//private:
//	int m_A;
//	int m_B;
//};
//
////全局函数左移运算符
//ostream& operator<<(ostream &cout,Person &p)//本质  operator<<(cout,p) 简化为  cout<<p;
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


//重载递增运算符

//class MyInteger
//{
//	friend ostream& operator<<(ostream& cout, MyInteger myint);
//public:
//	MyInteger()
//	{
//		m_Num = 0;
//	}
//
//	//重载前置++运算符
//	MyInteger& operator++()//返回值是引用是因为要创建别名，只对一个数据进行++，防止源数据被更改。
//	{
//		m_Num++;
//		return *this;
//	}
//
//	//重载后置++运算符
//
//	MyInteger operator++(int)//int 代表占位参数，可以区分前置和后置递增
//	{
//		//先记录结构
//		MyInteger temp = *this;
//		//后递增
//		m_Num++;
//		//最后结果返回
//		return temp;//临时变量，不能返回引用，因为会销毁
//	}
//private:
//	int m_Num;
//};
//
////重载左移运算符
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


//赋值运算符重载

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
//		//编译器提供浅拷贝
//		// m_Age=p.m_Age;
//		//先判断是否有属性在堆区，如果有先释放干净，然后再进行深拷贝
//
//		if (m_Age != NULL)
//		{
//			delete m_Age;
//			m_Age = NULL;
//		}
//		//深拷贝
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
//	cout << "p1的年龄为： " << *p1.m_Age << endl;
//	cout << "p2的年龄为： " << *p2.m_Age << endl;
//	cout << "p3的年龄为： " << *p3.m_Age << endl;
//}


//关系运算符重载
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
//		cout << "p1和p2相等" << endl;
//	}
//	else
//	{
//		cout << "p1和p2不相等" << endl;
//	}
//
//	if (p1 != p2)
//	{
//		cout << "p1和p2不相等" << endl;
//	}
//	else
//	{
//		cout << "p1和p2相等" << endl;
//	}
//}


//函数调用运算符重载
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
//	myPrint("hello world");//仿函数
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
//	//匿名函数对象
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
//		m_B = 10;//保护权限，类内访问，类外不可访问
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
		cout << "Base构造函数！" << endl;
	}
	~Base()
	{
		cout << "Base析构函数！" << endl;
	}
};

class Son:public Base
{
public:
	Son()
	{
		cout << "Son构造函数！" << endl;
	}
	~Son()
	{
		cout << "Son析构函数！" << endl;
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
