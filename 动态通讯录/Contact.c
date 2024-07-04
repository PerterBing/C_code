#define _CRT_SECURE_NO_WARNINGS

#include"Contact.h"

//增容
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
			printf("增容成功！\n");
		}
	}
}

//加载文件信息到通讯录
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

//销毁通信录
void DestroyContact(Contact* pc)
{
	assert(pc);
	free(pc->data);
	pc->data = NULL;
}

//静态版本
//void InitContact(Contact* pc)
//{
//	pc->count = 0;
//	memset(pc->data, 0, sizeof(pc->data));
//}
//动态版本初始化
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

	//加载文件的信息到通讯录中
	LoadContact(pc);
	return 0;
}


//动态版本增加联系人
void AddContact(Contact* pc)
{
	assert(pc);
	CheckCapacity(pc);
	
	printf("请输入联系人姓名：> ");
	scanf("%s", pc->data[pc->count].name);
	printf("请输入联系人年龄：> ");
	scanf("%d", &pc->data[pc->count].age);
	printf("请输入联系人性别：> ");
	scanf("%s", pc->data[pc->count].sex);
	printf("请输入联系人电话：> ");
	scanf("%s", pc->data[pc->count].tele);
	printf("请输入联系人地址：> ");
	scanf("%s", pc->data[pc->count].addr);

	printf("增加成功！\n");
	pc->count++;

}
//增加联系人   静态版本
//void AddContact(Contact* pc)
//{
//	assert(pc);
//	printf("请输入联系人姓名：> ");
//	scanf("%s", pc->data[pc->count].name);
//	printf("请输入联系人年龄：> ");
//	scanf("%d", &pc->data[pc->count].age);
//	printf("请输入联系人性别：> ");
//	scanf("%s", pc->data[pc->count].sex);
//	printf("请输入联系人电话：> ");
//	scanf("%s", pc->data[pc->count].tele);
//	printf("请输入联系人地址：> ");
//	scanf("%s", pc->data[pc->count].addr);
//
//	printf("增加成功！\n");
//	pc->count++;
//
//}


//显示联系人
void ShowContact(Contact* pc)
{
	assert(pc);
	if (pc->count == 0)
	{
		printf("通讯录为空\n");
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
//删除联系人
void DelContact(Contact* pc)
{
	char name[20] = { 0 };
	assert(pc);
	if (pc->count == 0)
	{
		printf("通讯录为空\n");
		return;
	}
	printf("请输入要删除的名字:> ");
	scanf("%s", name);
	int pos=FindByName(pc,name);
	if (pos < 0)
	{
		printf("查无此人，无法删除\n");
	}
	else
	{
		for (int i = pos; i < pc->count - 1; i++)
		{
			pc->data[i] = pc->data[i + 1];
		}
		printf("删除成功！\n");
		pc->count--;
	}
	
}

//查找联系人
void SeaContact(Contact* pc)
{
	char name[20] = { 0 };
	assert(pc);
	if (pc->count == 0)
	{
		printf("通讯录为空\n");
	}
	printf("请输入要查找的名字:> ");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	printf("%-20s\t%-10d\t%-10s\t%-12s\t%-30s\n", pc->data[pos].name,
		pc->data[pos].age,
		pc->data[pos].sex,
		pc->data[pos].tele,
		pc->data[pos].addr);
}

//修改联系人
void ModifyContact(Contact* pc)
{
	char name[20] = { 0 };
	assert(pc);
	if (pc->count == 0)
	{
		printf("通讯录为空\n");
	}
	printf("请输入要修改的名字:> ");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	printf("请输入修改联系人姓名：> ");
	scanf("%s", pc->data[pos].name);
	printf("请输入修改联系人年龄：> ");
	scanf("%d", &pc->data[pos].age);
	printf("请输入修改联系人性别：> ");
	scanf("%s", pc->data[pos].sex);
	printf("请输入修改联系人电话：> ");
	scanf("%s", pc->data[pos].tele);
	printf("请输入修改联系人地址：> ");
	scanf("%s", pc->data[pos].addr);

	printf("修改成功!\n");
}

int cmp_peo_by_name(const void* e1, const void* e2)
{
	return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);
}
//按名字排序
void SortContact(Contact* pc)
{
	assert(pc);
	qsort(pc->data, pc->count, sizeof(PeoInfo), cmp_peo_by_name);
	printf("排序成功！\n");
}

//保存通讯录
void SaveContact(Contact* pc)
{
	assert(pc);
	FILE* pfWrite = fopen("contact.txt", "wb");//二进制打开
	if (pfWrite == NULL)
	{
		perror("SaveContact");
		return;
	}

	//写文件-二进制
	int i = 0;
	for (i = 0; i < pc->count; i++)
	{
		fwrite(pc->data + i, sizeof(PeoInfo), 1, pfWrite);
	}
	fclose(pfWrite);
	pfWrite = NULL;
}