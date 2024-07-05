#define _CRT_SECURE_NO_WARNINGS
#include"contect.h"


//����
void CheckContact(Contact* pc)
{
	assert(pc);
	if (pc->count == pc->capacity)
	{
		PeoInfo *ptr= (PeoInfo*)realloc(pc->data, sizeof(PeoInfo) *(INC_SZ+pc->capacity));
		if (ptr == NULL)
		{
			printf("AddContact::%s\n", strerror(errno));
			return;
		}
		else
		{
			pc->data=ptr;
			pc->capacity += INC_SZ;
			printf("���ݳɹ���\n");
		}
	}
}

//�����ļ���Ϣ��ͨѶ¼
void LoadContact(Contact* pc)
{
	FILE* pfRead = fopen("Contacts.txt", "rb");
	if (pfRead == NULL)
	{
		perror("LoadContact");
		return;
	}
	PeoInfo tmp = { 0 };

	while (fread(&tmp, sizeof(PeoInfo), 1, pfRead) == 1)
	{
		CheckContact(pc);

		pc->data[pc->count] = tmp;
		pc->count++;
	}

	fclose(pfRead);
	pfRead = NULL;
}


//����ͨѶ¼
void DestoryContact(Contact* pc)
{
	assert(pc);
	free(pc->data);
	pc->data = NULL;
}

//��ʼ��ͨѶ¼
int InitContact(Contact* pc)
{
	assert(pc);

	pc->count = 0;
	pc->data = (PeoInfo*)calloc(3, sizeof(PeoInfo));
	if (pc->data == NULL)
	{
		perror("InitContact");
		return 1;
	}
	pc->capacity = 3;
	LoadContact(pc);
	return 0;
}


//������ϵ�˵�ͨѶ¼
void AddContact(Contact* pc)
{
	assert(pc);

	CheckContact(pc);//�������

	printf("��������ϵ��������> ");
	scanf("%s", pc->data[pc->count].name);
	printf("��������ϵ�����䣺> ");
	scanf("%d", &(pc->data[pc->count].age));
	printf("��������ϵ���Ա�> ");
	scanf("%s", pc->data[pc->count].sex);
	printf("��������ϵ�˵绰��> ");
	scanf("%s", pc->data[pc->count].tele);
	printf("��������ϵ�˵�ַ��> ");
	scanf("%s", pc->data[pc->count].addr);

	printf("���ӳɹ�!!\n");
	pc->count++;
}


//��ʾ��ϵ��
void ShowContact(Contact* pc)
{
	assert(pc);

	if (pc->count == 0)
	{
		printf("ͨѶ¼Ϊ�գ��޷���ӡ��Ϣ!\n");
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


int FindByName(Contact *pc,char name[])
{
	int pos = 0;
	for (int i = 0; i < pc->count; i++)
	{
		if (0 == strcmp(pc->data[i].name, name))
			return i;
	}
	return -1;
}
//ɾ����ϵ��
void DelContact(Contact* pc)
{
	assert(pc);
	char name[128] = { 0 };
	if (pc->count == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
		return;
	}
	printf("��������Ҫɾ��������:> \n");
	scanf("%s", name);
	int pos=FindByName(pc,name);
	if (pos< 0)
	{
		printf("���޴���\n");
	}
	else
	{
		for (int i = pos; i < pc->count-1; i++)
		{
			pc->data[i] = pc->data[i + 1];
		}
	
		printf("ɾ���ɹ���\n");
		pc->count--;
	}
	
}

//����ָ����ϵ��
void SeaContact(Contact* pc)
{
	assert(pc);
	char name[20] = { 0 };
	printf("��������Ҫ���ҵ�����:> ");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("���޴���\n");
		return;
	}
	else
	{
		printf("%-20s\t%-10d\t%-10s\t%-12s\t%-30s\n", pc->data[pos].name,
			pc->data[pos].age,
			pc->data[pos].sex,
			pc->data[pos].tele,
			pc->data[pos].addr);
	}
}


//�޸�ָ����ϵ��
void ModContact(Contact* pc)
{
	assert(pc);
	char name[20] = { 0 };
	printf("��������Ҫ�޸ĵ�����:> ");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos<0)
	{
		printf("���޴��ˣ��޷��޸�\n");
		return;
	}
	else
	{
		printf("�������޸���ϵ��������> ");
		scanf("%s", pc->data[pos].name);
		printf("�������޸���ϵ�����䣺> ");
		scanf("%d", &(pc->data[pos].age));
		printf("�������޸���ϵ���Ա�> ");
		scanf("%s", pc->data[pos].sex);
		printf("�������޸���ϵ�˵绰��> ");
		scanf("%s", pc->data[pos].tele);
		printf("�������޸���ϵ�˵�ַ��> ");
		scanf("%s", pc->data[pos].addr);

		printf("�޸ĳɹ�!!n");
	}
}


int cmp_peo_by_name(const void* e1,const void* e2)
{
	return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);
}
//����ͨѶ¼����
void SortContact(Contact* pc)
{
	assert(pc);
	qsort(pc->data, pc->count, sizeof(PeoInfo), cmp_peo_by_name);
	printf("����ɹ���\n");
}

//����ͨѶ¼����Ϣ���ļ�
void SaveContact(Contact* pc)
{
	assert(pc);
	FILE* pfWrite = fopen("Contacts.txt", "wb");
	if (pfWrite == NULL)
	{
		perror("SaveContact");
		return;
	}
	for (int i = 0; i < pc->count; i++)
	{
		fwrite(pc->data + i, sizeof(PeoInfo), 1, pfWrite);
	}

	fclose(pfWrite);
	pfWrite = NULL;
}