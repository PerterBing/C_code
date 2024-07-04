#define _CRT_SECURE_NO_WARNINGS

#include"Contact.h"

//����
void CheckCapacity(Contact* pc)
{
	if (pc->count == pc->capacity)
	{
		PeoInfo* ptr = (PeoInfo*)realloc(pc->data, (pc->capacity + INC_SZ) * sizeof(PeoInfo));
		if (ptr == NULL)
		{
			printf("AddContact::%s\n", strerror(errno));
			return;
		}
		else
		{
			pc->data = ptr;
			pc->capacity += INC_SZ;
			printf("���ݳɹ���\n");
		}
	}
}

//�����ļ���Ϣ��ͨѶ¼
void LoadContact(Contact* pc)
{
	FILE* pfRead = fopen("contact.txt", "rb");
	if (pfRead == NULL)
	{
		perror("LoadContact");
		return;
	}
	PeoInfo tmp = { 0 };

	while(fread(&tmp,sizeof(PeoInfo),1,pfRead)==1);
	{
		CheckCapacity(pc);

		pc->data[pc->count] = tmp;
		pc->count++;
	}

	fclose(pfRead);
	pfRead = NULL;
}

//����ͨ��¼
void DestroyContact(Contact* pc)
{
	assert(pc);
	free(pc->data);
	pc->data = NULL;
}

//��̬�汾
//void InitContact(Contact* pc)
//{
//	pc->count = 0;
//	memset(pc->data, 0, sizeof(pc->data));
//}
//��̬�汾��ʼ��
int InitContact(Contact* pc)
{
	assert(pc);
	pc->count = 0;
	pc->data = (PeoInfo*)calloc(DEFAULT_SZ, sizeof(PeoInfo));
	if (pc->data == NULL)
	{
		printf("InitContact::%s\n", strerror(errno));
		return 1;
	}
	pc->capacity = DEFAULT_SZ;

	//�����ļ�����Ϣ��ͨѶ¼��
	LoadContact(pc);
	return 0;
}


//��̬�汾������ϵ��
void AddContact(Contact* pc)
{
	assert(pc);
	CheckCapacity(pc);
	
	printf("��������ϵ��������> ");
	scanf("%s", pc->data[pc->count].name);
	printf("��������ϵ�����䣺> ");
	scanf("%d", &pc->data[pc->count].age);
	printf("��������ϵ���Ա�> ");
	scanf("%s", pc->data[pc->count].sex);
	printf("��������ϵ�˵绰��> ");
	scanf("%s", pc->data[pc->count].tele);
	printf("��������ϵ�˵�ַ��> ");
	scanf("%s", pc->data[pc->count].addr);

	printf("���ӳɹ���\n");
	pc->count++;

}
//������ϵ��   ��̬�汾
//void AddContact(Contact* pc)
//{
//	assert(pc);
//	printf("��������ϵ��������> ");
//	scanf("%s", pc->data[pc->count].name);
//	printf("��������ϵ�����䣺> ");
//	scanf("%d", &pc->data[pc->count].age);
//	printf("��������ϵ���Ա�> ");
//	scanf("%s", pc->data[pc->count].sex);
//	printf("��������ϵ�˵绰��> ");
//	scanf("%s", pc->data[pc->count].tele);
//	printf("��������ϵ�˵�ַ��> ");
//	scanf("%s", pc->data[pc->count].addr);
//
//	printf("���ӳɹ���\n");
//	pc->count++;
//
//}


//��ʾ��ϵ��
void ShowContact(Contact* pc)
{
	assert(pc);
	if (pc->count == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	printf("%-20s\t%-10s\t%-10s\t%-12s\t%-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	for (int i = 0; i < pc->count; i++)
	{
		printf("%-20s\t%-10d\t%-10s\t%-12s\t%-30s\n", pc->data[i].name,
			pc->data[i].age,
			pc->data[i].sex,
			pc->data[i].tele,
			pc->data[i].addr);
	}
}


int FindByName(Contact* pc,char name[])
{
	int pos = 0;
	for (int i = 0; i < pc->count; i++)
	{
		if(0==strcmp(pc->data[i].name,name))
			return i;
	}
	return -1;
}
//ɾ����ϵ��
void DelContact(Contact* pc)
{
	char name[20] = { 0 };
	assert(pc);
	if (pc->count == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
		return;
	}
	printf("������Ҫɾ��������:> ");
	scanf("%s", name);
	int pos=FindByName(pc,name);
	if (pos < 0)
	{
		printf("���޴��ˣ��޷�ɾ��\n");
	}
	else
	{
		for (int i = pos; i < pc->count - 1; i++)
		{
			pc->data[i] = pc->data[i + 1];
		}
		printf("ɾ���ɹ���\n");
		pc->count--;
	}
	
}

//������ϵ��
void SeaContact(Contact* pc)
{
	char name[20] = { 0 };
	assert(pc);
	if (pc->count == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	printf("������Ҫ���ҵ�����:> ");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	printf("%-20s\t%-10d\t%-10s\t%-12s\t%-30s\n", pc->data[pos].name,
		pc->data[pos].age,
		pc->data[pos].sex,
		pc->data[pos].tele,
		pc->data[pos].addr);
}

//�޸���ϵ��
void ModifyContact(Contact* pc)
{
	char name[20] = { 0 };
	assert(pc);
	if (pc->count == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	printf("������Ҫ�޸ĵ�����:> ");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	printf("�������޸���ϵ��������> ");
	scanf("%s", pc->data[pos].name);
	printf("�������޸���ϵ�����䣺> ");
	scanf("%d", &pc->data[pos].age);
	printf("�������޸���ϵ���Ա�> ");
	scanf("%s", pc->data[pos].sex);
	printf("�������޸���ϵ�˵绰��> ");
	scanf("%s", pc->data[pos].tele);
	printf("�������޸���ϵ�˵�ַ��> ");
	scanf("%s", pc->data[pos].addr);

	printf("�޸ĳɹ�!\n");
}

int cmp_peo_by_name(const void* e1, const void* e2)
{
	return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);
}
//����������
void SortContact(Contact* pc)
{
	assert(pc);
	qsort(pc->data, pc->count, sizeof(PeoInfo), cmp_peo_by_name);
	printf("����ɹ���\n");
}

//����ͨѶ¼
void SaveContact(Contact* pc)
{
	assert(pc);
	FILE* pfWrite = fopen("contact.txt", "wb");//�����ƴ�
	if (pfWrite == NULL)
	{
		perror("SaveContact");
		return;
	}

	//д�ļ�-������
	int i = 0;
	for (i = 0; i < pc->count; i++)
	{
		fwrite(pc->data + i, sizeof(PeoInfo), 1, pfWrite);
	}
	fclose(pfWrite);
	pfWrite = NULL;
}