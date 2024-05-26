#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#define MAX 1000
using namespace std;

struct People
{
	string name;
	int sex;
	int age;
	string telephone;
	string adress;
};

struct Addressbooks
{
	struct People personArray[MAX];

	int size;

};

void ShowMenu()
{
	cout << "1、添加联系人" << endl;
	cout << "2、显示联系人" << endl;
	cout << "3、删除联系人" << endl;
	cout << "4、查找联系人" << endl;
	cout << "5、修改联系人" << endl;
	cout << "6、清空联系人" << endl;
	cout << "0、退出联系人" << endl;
}


void addPerson(Addressbooks* abs)
{
	if (abs->size == MAX)
	{
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else
	{
		string name;
		cout << "请输入姓名: " << endl;
		cin >> name;
		abs->personArray[abs->size].name = name;

		cout << "请输入性别： "<<endl;
		cout << "1---男" << endl;
		cout << "2---女" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->size].sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}

		cout << "请输入年龄： " << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->size].age = age;

		cout << "请输入联系电话： " << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->size].telephone = phone;

		cout << "请输入家庭住址： " << endl;
		string address;
		cin >> address;
		abs->personArray[abs->size].adress = address;

		abs->size++;

		cout << "添加成功" << endl;

		system("pause");//请按任意键继续
		system("cls");//清屏
	}
}


void showPerson(Addressbooks* abs)
{
	if (abs->size == 0)
	{
		cout << "当前记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->size; i++)
		{
			cout << "姓名: " << abs->personArray[i].name <<"\t";
			cout << "性别: " << (abs->personArray[i].sex==1?"男":"女") << "\t";
			cout << "年龄: " << abs->personArray[i].age <<"\t";
			cout << "电话: " << abs->personArray[i].telephone <<"\t";
			cout << "住址: " << abs->personArray[i].adress <<endl;
		}

		system("pause");
		system("cls");
	}
}

int isExit(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->size; i++)
	{
		if (abs->personArray[i].name == name)
		{
			return i;
		}
	}
	return -1;
}

void deleperson(Addressbooks* abs)
{
	cout << "请输入你要删除的联系人" << endl;

	string name;
	cin >> name;
	
	int ret = isExit(abs, name);
	if (ret!=-1)
	{
		for (int i = ret; i < abs->size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->size--;
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

void findperson(Addressbooks* abs)
{
	cout << "请输入查找的联系人" << endl;
	string name;
	cin >> name;

	int ret = isExit(abs, name);

	if (ret != -1)
	{
		cout << "姓名: " << abs->personArray[ret].name << "\t";
		cout << "性别: " << (abs->personArray[ret].sex == 1 ? "男" : "女") << "\t";
		cout << "年龄: " << abs->personArray[ret].age << "\t";
		cout << "电话: " << abs->personArray[ret].telephone << "\t";
		cout << "住址: " << abs->personArray[ret].adress << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}

	system("pause");
	system("cls");
}

void modifyperson(Addressbooks* abs)
{
	cout << "请输入你要修改的联系人" << endl;
	string name;
	cin >> name;

	int ret = isExit(abs, name);

	if (ret != -1)
	{
		string name;
		cout << "请输入姓名:" << endl;
		cin >> name;
		abs->personArray[ret].name = name;


		cout << "请输入性别: " << endl;
		cout << "1---男" << endl;
		cout << "2---女" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].sex = sex;
				break;
			}
			cout << "输入错误，请重新输入" << endl;
		}


		int age=0;
		cout << "请输入年龄:" << endl;
		cin >> age;
		abs->personArray[ret].age = age;

		string phone;
		cout << "请输入联系电话:" << endl;
		cin >> phone;
		abs->personArray[ret].telephone =phone;

		string address;
		cout << "请输入家庭住址:" << endl;
		cin >> address;
		abs->personArray[ret].adress = address;

		cout << "修改成功！" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls"); 
}

void cleanperson(Addressbooks* abs)
{
	abs->size = 0;
	cout << "通讯录已清空" << endl;
	system("pause");
	system("cls");
}
int main()
{

	Addressbooks abs;
	abs.size = 0;

	int select = 0;
	while (1)
	{
		ShowMenu();

		cin >> select;

		switch (select)
		{
		case 1:
			addPerson(&abs);
			break;
		case 2:
			showPerson(&abs);
			break;
		case 3:
			deleperson(&abs);
			//cout << "请输入删除人的姓名：" << endl;
			//string name;
			//cin >> name;
			//if (isExit(&abs, name) == -1)
			//{
			//	cout << "查无此人" << endl;
			//}
			//else
			//{
			//	cout << "找到此人" << endl;
			//}
			break;
		case 4:
			findperson(&abs);
			break;
		case 5:
			modifyperson(&abs);
			break;
		case 6:
			cleanperson(&abs);
			break;
		case 0:
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入错误，请重新输入！！" << endl;
			break;
		}
	}
	system("pause");
	return 0;
}

