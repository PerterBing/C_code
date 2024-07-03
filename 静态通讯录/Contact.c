#define _CRT_SECURE_NO_WARNINGS

#include"Contact.h"

//初始化通讯录
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
		printf("通讯录已满，无法添加");
		return;
	}
	//往通讯录放人
	printf("请输入名字：>");
	scanf("%s",pc->data[pc->count].name);
	printf("请输入年龄：>");
	scanf("%d", &(pc->data[pc->count].age));
	printf("请输入性别：>");
	scanf("%s", pc->data[pc->count].sex);
	printf("请输入电话：>");
	scanf("%s", pc->data[pc->count].tele);
	printf("请输入地址：>");
	scanf("%s", pc->data[pc->count].addr);

	pc->count++;
	printf("增加成功！");
}

//显示联系人信息
void ShowContact(const Contact* pc)
{
	assert(pc);
	int i = 0;
	printf("%-20s\t%-3s\t%-5s\t%-12s\t%-30s\n", "姓名", "年龄", "性别", "电话", "地址");
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

//删除联系人信息
void DelContact(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	assert(pc);
	if (pc->count == 0)
	{
		printf("通讯录为空，没有元素可以删除\n");
		return;
	}
	//删除要知道删除谁
	printf("请输入名字：>\n");
	scanf("%s", name);
	//查找
	int pos=FindByName(pc,name);
	if (pos == -1)
	{
		printf("要删除的人不存在\n");
		return;
	}
	for (int i = pos; i < pc->count-1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->count--;
	printf("删除成功\n");
}

