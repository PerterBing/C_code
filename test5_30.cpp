#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string>

//class Base
//{
//public:
//	Base()
//	{
//		m_A = 100;
//	}
//
//	void func()
//	{
//		cout << "Base 的func函数调用" << endl;
//	}
//	void func(int a)
//	{
//		cout << "Base 的func有参函数调用" << endl;
//	}
//
//	int m_A;
//};
//
//class Son :public Base
//{
//public:
//	Son()
//	{
//		m_A = 200;
//	}
//
//	void func()
//	{
//		cout << "Son的func函数调用" << endl;
//	}
//	void func(int a)
//	{
//		cout << "Son的func有参函数调用" << endl;
//	}
//
//	int m_A;
//};
//
//void test()
//{
//	Son s;
//	cout << s.Base::m_A << endl;
//}
//
//void test02()
//{
//	Son s;
//
//	s.func();
//
//	s.func(100);
//}



//继承

//class Animal
//{
//public:
//	//虚函数
//	virtual void speak()
//	{
//		cout << "动物在说话" << endl;
//	}
//};
//
//class Cat :public Animal
//{
//public:
//	void speak()
//	{
//		cout << "猫在说话" << endl;
//	}
//};
//
//class Dog :public Animal
//{
//public:
//	void speak()
//	{
//		cout << "小狗在说话" << endl;
//	}
//};
//
////执行说话的函数
////地址早绑定  在编译阶段确定函数地址
////如果想执行让猫说话，那么这个函数地址就不能提前绑定，需要在运行阶段进行绑定，地址晚绑定
//void dospeak(Animal &animal)
//{
//	animal.speak();
//}
//
//void test()
//{
//	Cat cat;
//	dospeak(cat);
//
//	Dog dog;
//	dospeak(dog);
//}


//友元：
//全局函数做友元
//
//class Building
//{
//	friend void goodGay(Building* building);
//public:
//	Building()
//	{
//		m_SittingRoom = "客厅";
//		m_BedRoom = "卧室";
//	}
//	string m_SittingRoom;
//private:
//	string m_BedRoom;
//};
//
//
////全局函数
//void goodGay(Building* building)
//{
//	cout << "好基友全局函数 正在访问" << building->m_SittingRoom << endl;
//	cout << "好基友全局函数 正在访问" << building->m_BedRoom << endl;
//
//}
//
//void test()
//{
//	Building building;
//	goodGay(&building);
//}

//类做友元

//class Building;
//class GoodGay
//{
//
//public:
//	GoodGay();
//	void visit();
//	Building* building;
//	
//};
//
//class Building
//{
//	friend class GoodGay;
//public:
//	Building();
//public:
//	string m_SittingRoom;
//private:
//	string m_BedRoom;
//};
//
//Building::Building()
//{
//	m_SittingRoom = "客厅";
//	m_BedRoom = "卧室";
//}
//
//GoodGay::GoodGay()
//{
//	building = new Building;
//}
//
//void GoodGay::visit()
//{
//	cout << "好基友类正在访问： " << building->m_SittingRoom << endl;
//	cout << "好基友类正在访问： " << building->m_BedRoom << endl;
//}
//
//void test()
//{
//	GoodGay gg;
//	gg.visit();
//}


//成员函数做友元

//class Building;
//class GoodGay
//{
//public:
//	GoodGay();
//	void visit();
//	void visit2();
//private:
//	Building* building;
//};
//
//class Building
//{
//	friend void GoodGay::visit();//重点：记住写GoodGay：：
//public:
//	Building();
//public:
//	string m_SittingRoom;
//private:
//	string m_BedRoom;
//};
//
//GoodGay::GoodGay()
//{
//	building = new Building;
//}
//
//Building::Building()
//{
//	m_SittingRoom = "客厅";
//	m_BedRoom = "卧室";
//}
//
//void GoodGay::visit()
//{
//	cout << "visit函数正在访问: " << building->m_SittingRoom << endl;
//	cout << "visit函数正在访问： " << building->m_BedRoom << endl;
//}
//
//void GoodGay::visit2()
//{
//	cout << "visit2函数正在访问： " << building->m_SittingRoom << endl;
//
//	//cout << "visit2函数正在访问： " << building->m_BedRoom << endl;
//}

//void test()
//{
//	GoodGay gg;
//	gg.visit();
//	gg.visit2();
//}

//运算符重载
//重载+号
//Person PersonAddPerson(Person& p)
//{
//	Person temp;
//	temp.m_A = this->m_A + m_A;
//	temp.m_B = this->m_B + m_B;
//	return temp;
//}


//class Person
//{
//public:
//	Person(){}
//	Person(int a, int b) :m_A(a), m_B(b){}
//	//Person operator+(Person &p)
//	//{
//	//	Person temp;
//	//	temp.m_A = this->m_A + p.m_A;
//	//	temp.m_B = this->m_B + p.m_B;
//	//	return temp;
//	//}
//
//	int m_A;
//	int m_B;
//};
//
//Person operator+(Person& p1, Person& p2)
//{
//	Person temp;
//	temp.m_A = p1.m_A + p2.m_A;
//	temp.m_B = p1.m_B + p2.m_B;
//	return temp;
//}
//void test()
//{
//	Person p1(10,10);
//	Person p2(20,20);
//	Person p3 = p1 + p2;
//	/*Person p3 = p1.operator(p2);*/
//	cout << p3.m_A << "   " << p3.m_B << endl;
//}

//左移重载运算符

//class Person
//{
//	friend ostream& operator<<(ostream& cout, Person& p);
//public:
//	Person(){}
//	Person(int a, int b)
//	{
//		m_A = a;
//		m_B = b;
//	}
//private:
//	int m_A;
//	int m_B;
//};
//
//ostream& operator<<(ostream& out, Person& p)//operator<<(cout,p),cout<<p;
//{
//	out << "m_A = " << p.m_A << "m_B = " << p.m_B << endl;
//	return out;
//}
//
//void test()
//{
//	Person p(10,10);
//	cout << p <<"hello world "<< endl;
//}


//递增运算符重载
//class MyInteger
//{
//	friend ostream& operator<<(ostream& cout, MyInteger myint);
//public:
//	//无参构造函数调用
//	MyInteger()
//	{
//		m_Num = 0;
//	}
//
//	//重置前载++运算符
//	//this指向调用函数的对象，*this解引用为该对象，返回该对象的值，
//	//用该对象类型名引用接收，该对象类型名引用是一个别名，相当于给*this换个名字，
//	// 如果只是该对象类型名的话，返回值相当于给了另一个变量，本身不会再增加
//	MyInteger& operator++()
//	{
//		m_Num++;
//		return *this;
//	}
//
//	//后置递增运算符
//	MyInteger& operator++(int)
//	{
//		MyInteger temp = *this;
//
//		m_Num++;
//		return temp;
//	}
//
//private:
//	int m_Num;
//};
//
//ostream& operator<<(ostream& cout, MyInteger myint)
//{
//	cout << myint.m_Num;
//	return cout;
//}
//
//void test()
//{
//	MyInteger myint;
//
//	/*cout*/ /*<< ++(++myint) << endl;
//	cout << myint << endl;*/
//
//	cout << (myint++)++ << endl;
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
//		//m_Age=p.m_Age;
//		//先判断是否有属性在堆区，如果有就释放干净
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
//
//};
//
//void test()
//{
//	Person p1(10);
//	Person p2(20);
//	Person p3(30);
//
//	p3 = p2 = p1;
//
//	cout <<* p1.m_Age << endl;
//	cout << *p2.m_Age << endl;
//	cout << *p3.m_Age << endl;
//
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
//
//	bool operator==(Person& p)
//	{
//		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
//		{
//			return true;
//		}
//		else
//			return false;
//	}
//	bool operator!=(Person &p)
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
//	Person p1("Tom", 18);
//
//	Person p2("jack", 18);
//
//	if(p1==p2)
//	{
//		cout << "p1和p2相等" << endl;
//	}
//	else
//	{
//		cout << "p1和p2不相等" << endl;
//	}
//	if (p1 != p2)
//	{
//		cout << "p1和p2不相等" << endl;
//	}
//	else
//	{
//		cout << "p1和p2相等" << endl;
//	}
//}


//函数调用运算符的重载

class MyPrint
{
public:
	void operator()(string test)
	{
		cout << test << endl;
	}
};

void MyPrint02(string test)
{
	cout << test << endl;
}

void test01()
{
	MyPrint myPrint;

	myPrint("hello world");

	MyPrint02("hello world");
}

class MyAdd
{
public:
	int operator()(int num1, int num2)
	{
		return num1 + num2;
	}
};

void test02()
{
	MyAdd myadd;
	int ret = myadd(100, 100);
	cout << "ret = " << ret << endl;

	cout << MyAdd()(100, 100) << endl;
}

int main()
{
	test02();
	system("pause");
	return 0;
}