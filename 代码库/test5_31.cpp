#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string>

//��ͨд���Ͷ�̬����

//class Calculator
//{
//public:
//
//	int getResult(string oper)
//	{
//		if (oper == "+")
//		{
//			return m_Num1 + m_Num2;
//		}
//		else if (oper == "-")
//		{
//			return m_Num1 - m_Num2;
//		}
//		else if (oper == "*")
//		{
//			return m_Num1 * m_Num2;
//		}
//
//		//�������չ�µĹ���
//		//����ʵ������  �ᳫ ����ԭ��
//		//����ԭ�򣺶���չ���п��ţ����޸Ľ��йر�
//	}
//
//	int m_Num1;
//	int m_Num2;
//
//};
//
//
////���ö�̬ʵ�� 
////��̬�����ô���
//// 1.��֯�ṹ����
//// 2.�ɶ���ǿ
//// 3.����ǰ�ںͺ�����չ�Լ�ά���Ը�
////�����������
//class AbstractCalculator
//{
//public:
//	virtual int getResult()
//	{
//		return 0;
//	}
//
//	int m_Num1;
//	int m_Num2;
//};
//
////�ӷ���������
//class AddCalculator :public AbstractCalculator
//{
//public:
//	int getResult()
//	{
//		return m_Num1 + m_Num2;
//	}
//};
//
//class SubCalculator :public AbstractCalculator
//{
//public:
//	int getResult()
//	{
//		return m_Num1 - m_Num2;
//	}
//};
//
//class MulCalculator :public AbstractCalculator
//{
//public:
//	int getResult()
//	{
//		return m_Num1 * m_Num2;
//	}
//};
//
//void test02()
//{
//	//����ָ�������ָ���������
//
//	AbstractCalculator* abc = new AddCalculator;
//	abc->m_Num1 = 10;
//	abc->m_Num2 = 10;
//	cout << abc->m_Num1 << "+" << abc->m_Num2 << "=" << abc->getResult() << endl;
//	delete abc;
//
//	abc = new SubCalculator;
//	abc->m_Num1 = 100;
//	abc->m_Num2 = 100;
//	cout << abc->m_Num1 << "-" << abc->m_Num2 << "=" << abc->getResult() << endl;
//	delete abc;
//
//	abc = new MulCalculator;
//	abc->m_Num1 = 100;
//	abc->m_Num2 = 100;
//	cout << abc->m_Num1 << "*" << abc->m_Num2 << "=" << abc->getResult() << endl;
//	delete abc;
//}
//void test01()
//{
//	Calculator c;
//	c.m_Num1 = 10;
//	c.m_Num2 = 10;
//
//	cout << c.m_Num1 << "+" << c.m_Num2 << "=" << c.getResult("+") << endl;
//
//	cout << c.m_Num1 << "-" << c.m_Num2 << "=" << c.getResult("-") << endl;
//
//	cout << c.m_Num1 << "*" << c.m_Num2 << "=" << c.getResult("*") << endl;
//}


//���麯���ͳ�����
//
//class Base
//{
//public:
//	//ֻҪ��һ�����麯�����ͳ�Ϊ������
//	//�������ص㣺
//	//1.�޷�ʵ��������
//	//2.�������������д�����еĴ��麯��������Ҳ���ڳ�����
//	virtual void func() = 0;
//};
//
//class Son :public Base
//{
//public:
//	virtual void func() 
//	{
//		cout << "func ��������" << endl;
//	};
//};
//
//void test02()
//{
//	/*Base b;
//	new Base;*/
//	Son S;
//
//	Base* base = new Son;
//	base->func();
//
//}


//��̬������������Ʒ

//class AbstractDrinking
//{
//public:
//	//��ˮ
//	virtual void Boil() = 0;
//	//����
//	virtual void Brew() = 0;
//	//���뱭��
//	virtual void PourInCup() = 0;
//	//��������
//	virtual void PutSomething() = 0;
//	//������Ʒ
//	void makeDrink()
//	{
//		Boil();
//		Brew();
//		PourInCup();
//		PutSomething();
//	}
//};
//
////��������
//class Coffee :public AbstractDrinking
//{
//public:
//	//��ˮ
//	virtual void Boil()
//	{
//		cout << "��ũ��ɽȪ" << endl;
//	}
//	//����
//	virtual void Brew()
//	{
//		cout << "���ݿ���" << endl;
//	}
//	//���뱭��
//	virtual void PourInCup()
//	{
//		cout << "���뱭��" << endl;
//	}
//	//��������
//	virtual void PutSomething()
//	{
//		cout << "�����Ǻ�ţ��" << endl;
//	}
//};
//
////������Ҷ
//class Tea  :public AbstractDrinking
//{
//public:
//	//��ˮ
//	virtual void Boil()
//	{
//		cout << "���ɽȪ" << endl;
//	}
//	//����
//	virtual void Brew()
//	{
//		cout << "���ݲ�Ҷ" << endl;
//	}
//	//���뱭��
//	virtual void PourInCup()
//	{
//		cout << "���뱭��" << endl;
//	}
//	//��������
//	virtual void PutSomething()
//	{
//		cout << "�������" << endl;
//	}
//};
//
//
//void doWork(AbstractDrinking* abs)
//{
//	abs->makeDrink();
//	delete abs;
//}
//
//void test02()
//{
//	doWork(new Coffee);
//	cout << "-------------------" << endl;
//
//	doWork(new Tea);
//}

//�������ʹ�������

//class Animal
//{
//public:
//	Animal()
//	{
//		cout << "Animal���캯������" << endl;
//	}
//	//�������������Խ������ָ���ͷ�������󲻸ɾ�����
//	//virtual ~Animal()
//	//{
//	//	cout << "Animal������������" << endl;
//	//}
//
//	//��������   ��Ҫ����Ҳ��Ҫʵ��
//	//���˴�������֮�������Ҳ���ڳ����࣬�޷�ʵ��������
//	virtual ~Animal() = 0;//��������
//
//	//���麯��
//	virtual void speak() = 0;
//};
//
//Animal::~Animal()
//{
//	cout << "Animal������������" << endl;
//}
//
//class Cat :public Animal
//{
//public:
//	Cat(string name)
//	{
//		m_Name = new string(name);
//		cout << "Cat���캯������" << endl;
//	}
//
//	virtual void speak()
//	{
//		cout << *m_Name<<"Сè��˵��" << endl;
//	}
//
//	~Cat()
//	{
//		if (m_Name != NULL)
//		{
//			cout << "Cat������������" << endl;
//			delete m_Name;
//			m_Name = NULL;
//		}
//	}
//
//	string* m_Name;
//};
//
//void test02()
//{
//	Animal* animal = new Cat("Tom");
//	animal->speak();
//	//����ָ��������ʱ�򣬲����������������������������������ж������ԣ������ڴ�й©
//	delete animal;
//}

//��������Ĺ���ģʽ

//class CPU
//{
//public:
//	//����ļ��㺯��
//	virtual void calculate() = 0;
//};
//
////�����Կ���
//class VideoCard
//{
//public:
//	//����ļ��㺯��
//	virtual void display() = 0;
//};
//
////�����ڴ�����
//class Memory
//{
//public:
//	virtual void storage() = 0;
//};
//
////������
//class Computer
//{
//public:
//	Computer(CPU* cpu, VideoCard* vc, Memory* mem)
//	{
//		m_cpu = cpu;
//		m_mem = mem;
//		m_vc = vc;
//	}
//	//�ṩ��������
//	void work()
//	{
//		m_cpu->calculate();
//		m_vc->display();
//		m_mem->storage();
//	}
//
//	~Computer()
//	{
//		if (m_cpu != NULL)
//		{
//			delete m_cpu;
//		}
//		if (m_vc != NULL)
//		{
//			delete m_vc;
//		}
//		if (m_mem != NULL)
//		{
//			delete m_mem;
//		}
//	}
//private:
//	CPU* m_cpu;
//	VideoCard* m_vc;
//	Memory* m_mem;
//};
//
//
////���峧��
////Intel�ĵ������
//class IntelCPU :public CPU
//{
//public:
//	virtual void calculate()
//	{
//		cout << "Intel��CPU��ʼ�����ˣ�" << endl;
//	}
//
//};
//
//class IntelVideoCard :public VideoCard
//{
//public:
//	virtual void display()
//	{
//		cout << "Intel���Կ���ʼ�����ˣ�" << endl;
//	}
//
//};
//
//class IntelMemory :public Memory
//{
//public:
//	virtual void storage()
//	{
//		cout << "Intel���ڴ�����ʼ�洢�ˣ�" << endl;
//	}
//
//};
//
////Lenovo�ĵ������
//
//class LenovoCPU :public CPU
//{
//public:
//	virtual void calculate()
//	{
//		cout << "Lenovo��CPU��ʼ�����ˣ�" << endl;
//	}
//
//};
//
//class LenovoVideoCard :public VideoCard
//{
//public:
//	virtual void display()
//	{
//		cout << "Lenovo���Կ���ʼ�����ˣ�" << endl;
//	}
//
//};
//
//class LenovoMemory:public Memory
//{
//public:
//	virtual void storage()
//	{
//		cout << "Lenovo���ڴ�����ʼ�洢�ˣ�" << endl;
//	}
//
//};
//
//
//void test01()
//{
//	//��һ̨�������
//	CPU * intelCpu = new IntelCPU;
//	VideoCard* intelCard = new IntelVideoCard;
//	Memory* intelMem = new IntelMemory;
//
//	Computer* computer1 = new Computer(intelCpu, intelCard, intelMem);
//	computer1->work();
//	delete computer1;
//
//	cout << "�ڶ�̨���Կ�ʼ����" << endl;
//	Computer* computer2 = new Computer(new LenovoCPU, new LenovoVideoCard, new LenovoMemory);
//	computer2->work();
//	delete computer2	;
//
//	cout << "����̨���Կ�ʼ����" << endl;
//	Computer* computer3 = new Computer(new LenovoCPU, new IntelVideoCard, new LenovoMemory);
//	computer3->work();
//	delete computer3;
//}

//�ı��ļ� д�ļ�
#include<fstream>

//void test01()
//{
//	ofstream ofs;
//
//	ofs.open("test.txt", ios::out);
//
//	ofs << "����������" << endl;
//
//	ofs << "�Ա���" << endl;
//
//	ofs << "���䣺18" << endl;
//
//	ofs.close();
//	
//}

//���ļ�
//void test01()
//{
//	ifstream ifs;
//
//	ifs.open("test.txt", ios::in);
//	if (!ifs.is_open())
//	{
//		cout << "�ļ���ʧ��" << endl;
//		return;
//	}
//
//	//��һ��
//	/*char buf[1024] = { 0 };
//	while (ifs >> buf)
//	{
//		cout << buf << endl;
//	}*/
//	//�ڶ���
//	//char buf[1024] = { 0 };
//	//while (ifs.getline(buf, sizeof(buf)))
//	//{
//	//	cout << buf << endl;
//	//}
//	//������
//	/*string buf;
//	while (getline(ifs, buf))
//	{
//		cout << buf << endl;
//	}*/
//	//������
//	/*char c;
//	while ((c = ifs.get()) != EOF)
//	{
//		cout << c;
//	}*/
//
//	ifs.close();
//}

//class Person
//{
//public:
//	char m_Name[64];
//	int m_Age;
//};
//
//void test01()
//{
//	ofstream ofs;
//	ofs.open("person.txt", ios::out | ios::binary);//�ȼ���ofstream ofs("person.txt", ios::out | ios::binary)��
//	Person p = { "����",18 };
//	ofs.write((const char*)&p, sizeof(Person));
//
//	ofs.close();
//}

//class Person
//{
//public:
//	char m_Name[64];
//	int m_Age;
//};
//
//void test01()
//{
//	ifstream ifs;
//	ifs.open("person.txt", ios::in | ios::binary);
//	if (!ifs.is_open())
//	{
//		cout << "�ļ���ʧ��" << endl;
//		return;
//	}
//	Person p;
//	ifs.read((char*)&p, sizeof(Person));
//
//	cout << "������" << p.m_Name << "���䣺" << p.m_Age << endl;
//
//	ifs.close();
//}

//int main()
//{
//	test01();
//	//test02();
//	system("pause");
//	return 0;
//}