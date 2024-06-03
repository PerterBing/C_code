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
	cout << "1�������ϵ��" << endl;
	cout << "2����ʾ��ϵ��" << endl;
	cout << "3��ɾ����ϵ��" << endl;
	cout << "4��������ϵ��" << endl;
	cout << "5���޸���ϵ��" << endl;
	cout << "6�������ϵ��" << endl;
	cout << "0���˳���ϵ��" << endl;
}


void addPerson(Addressbooks* abs)
{
	if (abs->size == MAX)
	{
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		return;
	}
	else
	{
		string name;
		cout << "����������: " << endl;
		cin >> name;
		abs->personArray[abs->size].name = name;

		cout << "�������Ա� "<<endl;
		cout << "1---��" << endl;
		cout << "2---Ů" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->size].sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}

		cout << "���������䣺 " << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->size].age = age;

		cout << "��������ϵ�绰�� " << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->size].telephone = phone;

		cout << "�������ͥסַ�� " << endl;
		string address;
		cin >> address;
		abs->personArray[abs->size].adress = address;

		abs->size++;

		cout << "��ӳɹ�" << endl;

		system("pause");//�밴���������
		system("cls");//����
	}
}


void showPerson(Addressbooks* abs)
{
	if (abs->size == 0)
	{
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->size; i++)
		{
			cout << "����: " << abs->personArray[i].name <<"\t";
			cout << "�Ա�: " << (abs->personArray[i].sex==1?"��":"Ů") << "\t";
			cout << "����: " << abs->personArray[i].age <<"\t";
			cout << "�绰: " << abs->personArray[i].telephone <<"\t";
			cout << "סַ: " << abs->personArray[i].adress <<endl;
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
	cout << "��������Ҫɾ������ϵ��" << endl;

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
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

void findperson(Addressbooks* abs)
{
	cout << "��������ҵ���ϵ��" << endl;
	string name;
	cin >> name;

	int ret = isExit(abs, name);

	if (ret != -1)
	{
		cout << "����: " << abs->personArray[ret].name << "\t";
		cout << "�Ա�: " << (abs->personArray[ret].sex == 1 ? "��" : "Ů") << "\t";
		cout << "����: " << abs->personArray[ret].age << "\t";
		cout << "�绰: " << abs->personArray[ret].telephone << "\t";
		cout << "סַ: " << abs->personArray[ret].adress << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}

	system("pause");
	system("cls");
}

void modifyperson(Addressbooks* abs)
{
	cout << "��������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;

	int ret = isExit(abs, name);

	if (ret != -1)
	{
		string name;
		cout << "����������:" << endl;
		cin >> name;
		abs->personArray[ret].name = name;


		cout << "�������Ա�: " << endl;
		cout << "1---��" << endl;
		cout << "2---Ů" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].sex = sex;
				break;
			}
			cout << "�����������������" << endl;
		}


		int age=0;
		cout << "����������:" << endl;
		cin >> age;
		abs->personArray[ret].age = age;

		string phone;
		cout << "��������ϵ�绰:" << endl;
		cin >> phone;
		abs->personArray[ret].telephone =phone;

		string address;
		cout << "�������ͥסַ:" << endl;
		cin >> address;
		abs->personArray[ret].adress = address;

		cout << "�޸ĳɹ���" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls"); 
}

void cleanperson(Addressbooks* abs)
{
	abs->size = 0;
	cout << "ͨѶ¼�����" << endl;
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
			//cout << "������ɾ���˵�������" << endl;
			//string name;
			//cin >> name;
			//if (isExit(&abs, name) == -1)
			//{
			//	cout << "���޴���" << endl;
			//}
			//else
			//{
			//	cout << "�ҵ�����" << endl;
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
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "����������������룡��" << endl;
			break;
		}
	}
	system("pause");
	return 0;
}

