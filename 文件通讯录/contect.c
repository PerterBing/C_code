#define _CRT_SECURE_NO_WARNINGS
#include"contect.h"


//增容
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
			printf("增容成功！\n");
		}
	}
}

//加载文件信息到通讯录
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


//销毁通讯录
void DestoryContact(Contact* pc)
{
	assert(pc);
	free(pc->data);
	pc->data = NULL;
}

//初始化通讯录
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


//增加联系人到通讯录
void AddContact(Contact* pc)
{
	assert(pc);

	CheckContact(pc);//检查增容

	printf("请输入联系人姓名：> ");
	scanf("%s", pc->data[pc->count].name);
	printf("请输入联系人年龄：> ");
	scanf("%d", &(pc->data[pc->count].age));
	printf("请输入联系人性别：> ");
	scanf("%s", pc->data[pc->count].sex);
	printf("请输入联系人电话：> ");
	scanf("%s", pc->data[pc->count].tele);
	printf("请输入联系人地址：> ");
	scanf("%s", pc->data[pc->count].addr);

	printf("增加成功!!\n");
	pc->count++;
}


//显示联系人
void ShowContact(Contact* pc)
{
	assert(pc);

	if (pc->count == 0)
	{
		printf("通讯录为空，无法打印信息!\n");
	}
	printf("%-20s\t%-10s\t%-10s\t%-12s\t%-30s\n", "姓名", "年龄", "性别", "电话", "地址");
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
//删除联系人
void DelContact(Contact* pc)
{
	assert(pc);
	char name[128] = { 0 };
	if (pc->count == 0)
	{
		printf("通讯录为空\n");
		return;
	}
	printf("请输入你要删除的姓名:> \n");
	scanf("%s", name);
	int pos=FindByName(pc,name);
	if (pos< 0)
	{
		printf("查无此人\n");
	}
	else
	{
		for (int i = pos; i < pc->count-1; i++)
		{
			pc->data[i] = pc->data[i + 1];
		}
	
		printf("删除成功！\n");
		pc->count--;
	}
	
}

//查找指定联系人
void SeaContact(Contact* pc)
{
	assert(pc);
	char name[20] = { 0 };
	printf("请输入你要查找的姓名:> ");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("查无此人\n");
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


//修改指定联系人
void ModContact(Contact* pc)
{
	assert(pc);
	char name[20] = { 0 };
	printf("请输入你要修改的姓名:> ");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos<0)
	{
		printf("查无此人，无法修改\n");
		return;
	}
	else
	{
		printf("请输入修改联系人姓名：> ");
		scanf("%s", pc->data[pos].name);
		printf("请输入修改联系人年龄：> ");
		scanf("%d", &(pc->data[pos].age));
		printf("请输入修改联系人性别：> ");
		scanf("%s", pc->data[pos].sex);
		printf("请输入修改联系人电话：> ");
		scanf("%s", pc->data[pos].tele);
		printf("请输入修改联系人地址：> ");
		scanf("%s", pc->data[pos].addr);

		printf("修改成功!!n");
	}
}


int cmp_peo_by_name(const void* e1,const void* e2)
{
	return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);
}
//排序通讯录内容
void SortContact(Contact* pc)
{
	assert(pc);
	qsort(pc->data, pc->count, sizeof(PeoInfo), cmp_peo_by_name);
	printf("排序成功！\n");
}

//保存通讯录的信息到文件
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