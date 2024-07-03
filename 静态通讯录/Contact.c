#define _CRT_SECURE_NO_WARNINGS

#include"Contact.h"

//��ʼ��ͨѶ¼
void InitContact(Contact* pc)
{
	pc->count = 0;
	memset(pc->data, 0, sizeof(pc->data));
}

void AddContact(Contact* pc)
{
	assert(pc);
	if (pc->count == 100)
	{
		printf("ͨѶ¼�������޷����");
		return;
	}
	//��ͨѶ¼����
	printf("���������֣�>");
	scanf("%s",pc->data[pc->count].name);
	printf("���������䣺>");
	scanf("%d", &(pc->data[pc->count].age));
	printf("�������Ա�>");
	scanf("%s", pc->data[pc->count].sex);
	printf("������绰��>");
	scanf("%s", pc->data[pc->count].tele);
	printf("�������ַ��>");
	scanf("%s", pc->data[pc->count].addr);

	pc->count++;
	printf("���ӳɹ���");
}

//��ʾ��ϵ����Ϣ
void ShowContact(const Contact* pc)
{
	assert(pc);
	int i = 0;
	printf("%-20s\t%-3s\t%-5s\t%-12s\t%-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	for (i = 0; i < pc->count; i++)
	{
		printf("%-20s\t%-3d\t%-5s\t%-12s\t%-30s\n",  pc->data[i].name,
												pc->data[i].age,
												pc->data[i].sex,
												pc->data[i].tele,
												pc->data[i].addr);
	}
}


int FindName(Contact* pc,char name)
{
	assert(pc);
	int i = 0;
	for (i = 0; i < pc->count; i++)
	{
		if (0 == strcmp(pc->data[i].name, name))
		{
			return i;
		}
	}
	return -1;
}

//ɾ����ϵ����Ϣ
void DelContact(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	assert(pc);
	if (pc->count == 0)
	{
		printf("ͨѶ¼Ϊ�գ�û��Ԫ�ؿ���ɾ��\n");
		return;
	}
	//ɾ��Ҫ֪��ɾ��˭
	printf("���������֣�>\n");
	scanf("%s", name);
	//����
	int pos=FindByName(pc,name);
	if (pos == -1)
	{
		printf("Ҫɾ�����˲�����\n");
		return;
	}
	for (int i = pos; i < pc->count-1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->count--;
	printf("ɾ���ɹ�\n");
}

