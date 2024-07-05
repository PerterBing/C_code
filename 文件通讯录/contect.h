#pragma once
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
#include<errno.h>

#define MAX 100
#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TELE 12
#define MAX_ADDR 30
#define INC_SZ 3


//人的信息
typedef struct PeopInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;


//通讯录的信息  静态版本
typedef struct Contact
{
	PeoInfo *data;//存放100人信息
	int count;//记录当前通讯录人数
	int capacity;//记录总容量
}Contact;


//初始化通讯录
int InitContact(Contact* pc);

//销毁通讯录
void DestoryContact(Contact* pc);

//增加联系人到通讯录
void AddContact(Contact* pc);

//显示通讯录信息
void ShowContact(const Contact* pc);

//删除联系人
void DelContact(Contact* pc);

//查找指定联系人
void SeaContact(Contact* pc);

//修改指定联系人
void ModContact(Contact* pc);

//排序通讯录内容
void SortContact(Contact* pc);

//保存通讯录的信息到文件
void SaveContact(Contact* pc);

//加载文件信息到通讯录
void LoadContact(Contact* pc);
