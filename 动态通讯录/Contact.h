#pragma once
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>

#define DEFAULT_SZ 3
#define INC_SZ 2
#define MAX 100
#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TELE 12
#define MAX_ADDR 30

typedef struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;

//静态版本
//typedef struct Contact
//{
//	PeoInfo data[100];
//	int count;
//}Contact;

//动态版本
typedef struct Contact
{
	PeoInfo* data;
	int count;
	int capacity;
}Contact;

//初始化通讯录
int InitContact(Contact* pc);

//销毁通信录
void DestroyContact(Contact* pc);

//增加联系人
void AddContact(Contact* pc);

//显示联系人
void ShowContact(Contact* pc);

//删除联系人
void DelContact(Contact* pc);

//查找联系人
void SeaContact(Contact* pc);

//修改联系人
void ModifyContact(Contact* pc);

//按名字排序
void SortContact(Contact* pc);

//保存通讯录v
void SaveContact(const Contact* pc);

//加载文件信息到通讯录
void LoadContact(Contact* pc);

