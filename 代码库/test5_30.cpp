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
//		cout << "Base ��func��������" << endl;
//	}
//	void func(int a)
//	{
//		cout << "Base ��func�вκ�������" << endl;
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
//		cout << "Son��func��������" << endl;
//	}
//	void func(int a)
//	{
//		cout << "Son��func�вκ�������" << endl;
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



//�̳�

//class Animal
//{
//public:
//	//�麯��
//	virtual void speak()
//	{
//		cout << "������˵��" << endl;
//	}
//};
//
//class Cat :public Animal
//{
//public:
//	void speak()
//	{
//		cout << "è��˵��" << endl;
//	}
//};
//
//class Dog :public Animal
//{
//public:
//	void speak()
//	{
//		cout << "С����˵��" << endl;
//	}
//};
//
////ִ��˵���ĺ���
////��ַ���  �ڱ���׶�ȷ��������ַ
////�����ִ����è˵������ô���������ַ�Ͳ�����ǰ�󶨣���Ҫ�����н׶ν��а󶨣���ַ���
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


//��Ԫ��
//ȫ�ֺ�������Ԫ
//
//class Building
//{
//	friend void goodGay(Building* building);
//public:
//	Building()
//	{
//		m_SittingRoom = "����";
//		m_BedRoom = "����";
//	}
//	string m_SittingRoom;
//private:
//	string m_BedRoom;
//};
//
//
////ȫ�ֺ���
//void goodGay(Building* building)
//{
//	cout << "�û���ȫ�ֺ��� ���ڷ���" << building->m_SittingRoom << endl;
//	cout << "�û���ȫ�ֺ��� ���ڷ���" << building->m_BedRoom << endl;
//
//}
//
//void test()
//{
//	Building building;
//	goodGay(&building);
//}

//������Ԫ

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
//	m_SittingRoom = "����";
//	m_BedRoom = "����";
//}
//
//GoodGay::GoodGay()
//{
//	building = new Building;
//}
//
//void GoodGay::visit()
//{
//	cout << "�û��������ڷ��ʣ� " << building->m_SittingRoom << endl;
//	cout << "�û��������ڷ��ʣ� " << building->m_BedRoom << endl;
//}
//
//void test()
//{
//	GoodGay gg;
//	gg.visit();
//}


//��Ա��������Ԫ

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
//	friend void GoodGay::visit();//�ص㣺��סдGoodGay����
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
//	m_SittingRoom = "����";
//	m_BedRoom = "����";
//}
//
//void GoodGay::visit()
//{
//	cout << "visit�������ڷ���: " << building->m_SittingRoom << endl;
//	cout << "visit�������ڷ��ʣ� " << building->m_BedRoom << endl;
//}
//
//void GoodGay::visit2()
//{
//	cout << "visit2�������ڷ��ʣ� " << building->m_SittingRoom << endl;
//
//	//cout << "visit2�������ڷ��ʣ� " << building->m_BedRoom << endl;
//}

//void test()
//{
//	GoodGay gg;
//	gg.visit();
//	gg.visit2();
//}

//���������
//����+��
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

//�������������

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


//�������������
//class MyInteger
//{
//	friend ostream& operator<<(ostream& cout, MyInteger myint);
//public:
//	//�޲ι��캯������
//	MyInteger()
//	{
//		m_Num = 0;
//	}
//
//	//����ǰ��++�����
//	//thisָ����ú����Ķ���*this������Ϊ�ö��󣬷��ظö����ֵ��
//	//�øö������������ý��գ��ö���������������һ���������൱�ڸ�*this�������֣�
//	// ���ֻ�Ǹö����������Ļ�������ֵ�൱�ڸ�����һ��������������������
//	MyInteger& operator++()
//	{
//		m_Num++;
//		return *this;
//	}
//
//	//���õ��������
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


//��ֵ���������
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
//		//�������ṩǳ����
//		//m_Age=p.m_Age;
//		//���ж��Ƿ��������ڶ���������о��ͷŸɾ�
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


//��ϵ���������

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
//		cout << "p1��p2���" << endl;
//	}
//	else
//	{
//		cout << "p1��p2�����" << endl;
//	}
//	if (p1 != p2)
//	{
//		cout << "p1��p2�����" << endl;
//	}
//	else
//	{
//		cout << "p1��p2���" << endl;
//	}
//}


//�������������������

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