#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string>
//class Person
//{
//public:
//	static int m_A;
//	static void func()
//	{
//		m_A = 100;
//		/*m_B = 200;*///��̬��Ա�������Է��ʾ�̬��Ա�����������Է��ʷǾ�̬��Ա����
//		cout << "static void func ����" << endl;
//	}
//	int m_B;
//private:
//	static void func2()
//	{
//		cout << "static void func2����" << endl;
//	}
//};
//
//int Person::m_A = 100;
//
//void test01()
//{
	//Person p;
	//cout << p.m_A << endl;

	//Person p2;
	//p2.m_A = 200;
	//cout << p.m_A << endl;
	/*cout << Person::m_A << endl;*/

	//cout << Person::m_B << endl;
//}
//
//void test02()
//{
//	Person p;
//	p.func();
//
//	Person::func();
//
//	Person::func2();
//}

//class Person
//{
//public:
//	Person(int age)
//	{
//		this->m_age = age;
//	}
//
//	Person& PersonAddAge(Person& p)
//	{
//		this->m_age += p.m_age;
//		return *this;
//	}
//
//	int m_age;
//};
//void test02()
//{
//	Person p1(10);
//	Person p2(10);
//
//	p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);
//
//	cout <<  p2.m_age << endl;
//}
//
//class Person
//{
//public:
//	void showPerson() const
//	{
//		this->m_A = 100;
//		this->m_B = 200;
//	}
//	int m_A;
//	mutable int m_B;
//
//};
//
//void test02()
//{
//	Person p;
//}


//class Building
//{
//	friend void goodGay(Building* building);
//public:
//	Building()
//	{
//		m_SittingRoom = "����";
//		m_BedRoom = "����";
//	}
//
//	string m_SittingRoom;
//private:
//	string m_BedRoom;
//};
//
//void goodGay(Building* building)
//{
//	cout << "�û���ȫ�ֺ��� ���ڷ��ʣ�" << building->m_SittingRoom << endl;
//	cout << "�û���ȫ�ֺ��� ���ڷ���" << building->m_BedRoom << endl;
//
//}
//
//void test()
//{
//	Building building;
//	goodGay(&building);
//}



//class Building;
//class GoodGay
//{
//public:
//	GoodGay();
//	void visit();
//
//	Building *building;
//};
// 
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
//	cout << "�û��������ڷ��ʣ�" << building->m_SittingRoom << endl;
//	cout << "�û��������ڷ��ʣ�" << building->m_BedRoom << endl;
//}
//
//void test()
//{
//	GoodGay gg;
//	gg.visit();
//}


//
//class Building;
//
//class GoodGay
//{
//public:
//	GoodGay();
//	void visit1();
//	void vist2();
//private:
//	Building* building;
//};
//
//
//class Building
//{
//	friend void GoodGay::visit1;
//
//public:
//	Building();
//
//public:
//	string m_SittingRoom;
//private:
//	string m_BedRoom;
//};
//
//Building::Building()
//{
//	this->m_SittingRoom = "����";
//	this->m_BedRoom = "����";
//}
//
//GoodGay::GoodGay()
//{
//	building = new Building;
//}
//
//void GoodGay::visit1()
//{
//	cout << "�û��������ڷ��ʣ�" << building->m_SittingRoom << endl;
//	cout << "�û��������ڷ��ʣ�" << building->m_BedRoom << endl;
//}
//
//void GoodGay::visit2()
//{
//	cout << "�û��������ڷ��ʣ�" << building->m_SittingRoom << endl;
//	/*cout << "�û��������ڷ��ʣ�" << building->m_BedRoom << endl;*/
//}
//
//void test()
//{
//	GoodGay gg;
//	gg.visit1();
//}
//int main()
//{
//	test();
//	system("pause");
//	return 0;
//}

//class Person
//{
//public:
//	Person(int age)
//	{
//		this->m_age=age;
//	}
//	Person& PersonAddage(Person& p)
//	{
//		this->m_age += p.m_age;//this ָ��p2
//		return *this;
//	}
//	int m_age;	
//};
//
//void test()
//{
//	//Person p1(10,160);
//	//Person p2(p1);
//	//cout << p2.m_A <<"  " << p2.m_B << endl;
//	//Person p;
//	//p.func();
//
//	//Person::func();
//
//	Person p1(10);
//	Person p2(5);
//	
//
//	p1.PersonAddage(p2).PersonAddage(p2).PersonAddage(p2);
//
//	cout << p2.m_age << endl;
//}


//class Person
//{
//public:
//	static int m_A;
//	static void func()
//	{
//		
//		cout << "func�����ĵ���" << endl;
//	}
//	Person()
//	{
//		cout << "�޲κ����ĵ���" << endl;
//	}
//	Person(int age,int height)
//	{
//		m_age = age;
//		m_height=new int(height);
//		cout << "�вκ����ĵ���" << endl;
//	}
//	Person(const Person &p)
//	{
//		m_age = p.m_age;
//		m_height=new int(*p.m_height);
//		cout << "���������ĵ���" << endl;
//	}
//	~Person()
//	{
//		if (m_height != NULL)
//		{
//			delete m_height;
//			m_height = NULL;
//		}
//		cout << "���������ĵ���" << endl;
//	}
//	int m_age;
//	int* m_height;
//};
//
//int Person::m_A = 100;
//void test()
//{
//	//Person p1(18,160);
//	//Person p2(p1);
//	//cout << p2.m_age<<"   " << *p2.m_height << endl;
//	Person p1;
//	p1.func();
//	cout << p1.m_A << endl;
//	//Person::func();
//
//	Person p2;
//	p2.m_A = 200;
//	cout << p1.m_A << endl;
//
//}

//class Person
//{
//public:
//	void showClassName()const//const Person *const this
//	{
//		this->m_age = 100;
//		cout << "this is Person class" << endl;
//	}
//	void showPersonAge()
//	{
//		if (this == NULL)
//		{
//			return;
//		}
//		cout << "age= " << this->m_age << endl;
//	}
//	mutable int m_age;
//};
//
//void test()
//{
//	Person* p = NULL;
//	p->showClassName();
//	p->showPersonAge();
//	/*Person  const p1;*/
//}


//ȫ�ֺ�������Ԫ
//class Building
//{
//public:
//	friend void goodGay(Building* building);
//	Building()
//	{
//		m_SittingRoom = "����";
//		m_BedRoom = "����";
//	}
//	string m_SittingRoom;
//private:
//	string m_BedRoom;
//};
//void goodGay(Building* building)
//{
//	cout << "�û���ȫ�ֺ��� ���ڷ��ʣ� " << building->m_SittingRoom << endl;
//	cout << "�û���ȫ�ֺ��� ���ڷ��ʣ� " << building->m_BedRoom << endl;
//}
//
//void test()
//{
//	Building building;
//	goodGay(&building);
//}

////������Ԫ
//class Building;
////GoodGay��
//class GoodGay
//{
//public:
//	GoodGay();
//	void visit();
//private:
//	Building *building;
//};
//
////Building��
//class Building
//{
//	friend class GoodGay;
//public:
//	Building();
//	string m_SittingRoom;
//private:
//	string m_BedRoom;
//};
//
////Building�ຯ���������ʼ��
//Building::Building()
//{
//	this->m_SittingRoom = "����";
//	m_BedRoom = "����";
//}
//
////GoodGay�ຯ���ĵ���
//GoodGay::GoodGay()
//{
//	building = new Building;
//}
//
////GoodGay�� visit()�����ĵ���
//void GoodGay::visit()
//{
//	cout << "�û��������ڷ��ʣ�" << building->m_SittingRoom << endl;
//	cout << "�û��������ڷ��ʣ�" << building->m_BedRoom << endl;
//}
//
//void test()
//{
//	GoodGay gg;
//	gg.visit();
//}


//��Ա��������Ԫ
class Building;

class GoodGay
{
public:
	GoodGay();
	void visit();//��visit�������Է���Building�е�˽�г�Ա
	void visit2();//��visit2���������Է���Building�е�˽�г�Ա
private:
	Building* building;
};

class Building
{
	friend void GoodGay::visit();
public:
	Building();
public:
	string m_SittingRoom;
private:
	string m_BedRoom;
};

Building::Building()
{
	m_SittingRoom="����";
	m_BedRoom="����";
}

GoodGay::GoodGay()
{
	building = new Building;
}

void GoodGay::visit()
{
	cout << "visit�������ڷ��ʣ�" << building->m_SittingRoom << endl;
	cout << "visit�������ڷ��ʣ�" << building->m_BedRoom<< endl;
}
void GoodGay::visit2()
{
	cout << "visit2�������ڷ��ʣ�" << building->m_SittingRoom << endl;
	//cout << "visit2�������ڷ��ʣ�" << building->m_BedRoom << endl;
}

void test()
{
	GoodGay gg;
	gg.visit();
	gg.visit2();
}

int main()
{
	test();
	system("pause");
	return 0;
}