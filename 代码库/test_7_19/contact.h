#ifndef __CONTACT_H__
#define __CONTACT_H__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//联系人信息
typedef struct PeoInfo
{
    char name[20];
    int age;
    char tele[12];
    char adress[30];
}PeoInfo;

//存放联系人的通讯录
typedef struct Contact
{
    PeoInfo *data;
    int size;//当前存放人数
    int capacity;//总容量
}Contact;

int InitContact(Contact *pc);

void AddContact(Contact *pc);

void DelContact(Contact *pc);

void ModContact(Contact *pc);

void SeaContact(Contact *pc);

void ShowContact(Contact *pc);

void SortContact(Contact *pc);

void LoadContact(Contact *pc);//加载文件内容

void SaveContact(Contact *pc);//保存通讯录到文件

void DestroyContact(Contact* pc);

#endif
