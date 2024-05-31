#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string>

//普通写法和多态技术

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
//		//如果想扩展新的功能
//		//在真实开发中  提倡 开闭原则
//		//开闭原则：对扩展进行开放，对修改进行关闭
//	}
//
//	int m_Num1;
//	int m_Num2;
//
//};
//
//
////利用多态实现 
////多态技术好处：
//// 1.组织结构清晰
//// 2.可读性强
//// 3.对于前期和后期扩展以及维护性高
////计算机抽象类
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
////加法计算器类
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
//	//父类指针或引用指向子类对象
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


//纯虚函数和抽象类
//
//class Base
//{
//public:
//	//只要有一个纯虚函数，就称为抽象类
//	//抽象类特点：
//	//1.无法实例化对象
//	//2.抽象类的子类重写父类中的纯虚函数，否则也属于抽象类
//	virtual void func() = 0;
//};
//
//class Son :public Base
//{
//public:
//	virtual void func() 
//	{
//		cout << "func 函数调用" << endl;
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


//多态案例：制作饮品

//class AbstractDrinking
//{
//public:
//	//煮水
//	virtual void Boil() = 0;
//	//冲泡
//	virtual void Brew() = 0;
//	//倒入杯中
//	virtual void PourInCup() = 0;
//	//加入作料
//	virtual void PutSomething() = 0;
//	//制作饮品
//	void makeDrink()
//	{
//		Boil();
//		Brew();
//		PourInCup();
//		PutSomething();
//	}
//};
//
////制作咖啡
//class Coffee :public AbstractDrinking
//{
//public:
//	//煮水
//	virtual void Boil()
//	{
//		cout << "煮农夫山泉" << endl;
//	}
//	//冲泡
//	virtual void Brew()
//	{
//		cout << "冲泡咖啡" << endl;
//	}
//	//倒入杯中
//	virtual void PourInCup()
//	{
//		cout << "倒入杯中" << endl;
//	}
//	//加入作料
//	virtual void PutSomething()
//	{
//		cout << "加入糖和牛奶" << endl;
//	}
//};
//
////制作茶叶
//class Tea  :public AbstractDrinking
//{
//public:
//	//煮水
//	virtual void Boil()
//	{
//		cout << "煮矿山泉" << endl;
//	}
//	//冲泡
//	virtual void Brew()
//	{
//		cout << "冲泡茶叶" << endl;
//	}
//	//倒入杯中
//	virtual void PourInCup()
//	{
//		cout << "倒入杯中" << endl;
//	}
//	//加入作料
//	virtual void PutSomething()
//	{
//		cout << "加入枸杞" << endl;
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

//虚析构和纯虚析构

//class Animal
//{
//public:
//	Animal()
//	{
//		cout << "Animal构造函数调用" << endl;
//	}
//	//利用虚析构可以解决父类指针释放子类对象不干净问题
//	//virtual ~Animal()
//	//{
//	//	cout << "Animal析构函数调用" << endl;
//	//}
//
//	//纯虚析构   需要声明也需要实现
//	//有了纯虚析构之后，这个类也属于抽象类，无法实例化对象
//	virtual ~Animal() = 0;//纯虚析构
//
//	//纯虚函数
//	virtual void speak() = 0;
//};
//
//Animal::~Animal()
//{
//	cout << "Animal析构函数调用" << endl;
//}
//
//class Cat :public Animal
//{
//public:
//	Cat(string name)
//	{
//		m_Name = new string(name);
//		cout << "Cat构造函数调用" << endl;
//	}
//
//	virtual void speak()
//	{
//		cout << *m_Name<<"小猫在说话" << endl;
//	}
//
//	~Cat()
//	{
//		if (m_Name != NULL)
//		{
//			cout << "Cat析构函数调用" << endl;
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
//	//父类指针在析构时候，不会调用子类中析构函数，导致子类如果有堆区属性，出现内存泄漏
//	delete animal;
//}

//电脑零件的工作模式

//class CPU
//{
//public:
//	//抽象的计算函数
//	virtual void calculate() = 0;
//};
//
////抽象显卡类
//class VideoCard
//{
//public:
//	//抽象的计算函数
//	virtual void display() = 0;
//};
//
////抽象内存条类
//class Memory
//{
//public:
//	virtual void storage() = 0;
//};
//
////电脑类
//class Computer
//{
//public:
//	Computer(CPU* cpu, VideoCard* vc, Memory* mem)
//	{
//		m_cpu = cpu;
//		m_mem = mem;
//		m_vc = vc;
//	}
//	//提供工作函数
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
////具体厂商
////Intel的电脑零件
//class IntelCPU :public CPU
//{
//public:
//	virtual void calculate()
//	{
//		cout << "Intel的CPU开始计算了！" << endl;
//	}
//
//};
//
//class IntelVideoCard :public VideoCard
//{
//public:
//	virtual void display()
//	{
//		cout << "Intel的显卡开始计算了！" << endl;
//	}
//
//};
//
//class IntelMemory :public Memory
//{
//public:
//	virtual void storage()
//	{
//		cout << "Intel的内存条开始存储了！" << endl;
//	}
//
//};
//
////Lenovo的电脑零件
//
//class LenovoCPU :public CPU
//{
//public:
//	virtual void calculate()
//	{
//		cout << "Lenovo的CPU开始计算了！" << endl;
//	}
//
//};
//
//class LenovoVideoCard :public VideoCard
//{
//public:
//	virtual void display()
//	{
//		cout << "Lenovo的显卡开始计算了！" << endl;
//	}
//
//};
//
//class LenovoMemory:public Memory
//{
//public:
//	virtual void storage()
//	{
//		cout << "Lenovo的内存条开始存储了！" << endl;
//	}
//
//};
//
//
//void test01()
//{
//	//第一台电脑零件
//	CPU * intelCpu = new IntelCPU;
//	VideoCard* intelCard = new IntelVideoCard;
//	Memory* intelMem = new IntelMemory;
//
//	Computer* computer1 = new Computer(intelCpu, intelCard, intelMem);
//	computer1->work();
//	delete computer1;
//
//	cout << "第二台电脑开始工作" << endl;
//	Computer* computer2 = new Computer(new LenovoCPU, new LenovoVideoCard, new LenovoMemory);
//	computer2->work();
//	delete computer2	;
//
//	cout << "第三台电脑开始工作" << endl;
//	Computer* computer3 = new Computer(new LenovoCPU, new IntelVideoCard, new LenovoMemory);
//	computer3->work();
//	delete computer3;
//}

//文本文件 写文件
#include<fstream>

//void test01()
//{
//	ofstream ofs;
//
//	ofs.open("test.txt", ios::out);
//
//	ofs << "姓名：张三" << endl;
//
//	ofs << "性别：男" << endl;
//
//	ofs << "年龄：18" << endl;
//
//	ofs.close();
//	
//}

//读文件
//void test01()
//{
//	ifstream ifs;
//
//	ifs.open("test.txt", ios::in);
//	if (!ifs.is_open())
//	{
//		cout << "文件打开失败" << endl;
//		return;
//	}
//
//	//第一种
//	/*char buf[1024] = { 0 };
//	while (ifs >> buf)
//	{
//		cout << buf << endl;
//	}*/
//	//第二种
//	//char buf[1024] = { 0 };
//	//while (ifs.getline(buf, sizeof(buf)))
//	//{
//	//	cout << buf << endl;
//	//}
//	//第三种
//	/*string buf;
//	while (getline(ifs, buf))
//	{
//		cout << buf << endl;
//	}*/
//	//第四种
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
//	ofs.open("person.txt", ios::out | ios::binary);//等价于ofstream ofs("person.txt", ios::out | ios::binary)；
//	Person p = { "张三",18 };
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
//		cout << "文件打开失败" << endl;
//		return;
//	}
//	Person p;
//	ifs.read((char*)&p, sizeof(Person));
//
//	cout << "姓名：" << p.m_Name << "年龄：" << p.m_Age << endl;
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