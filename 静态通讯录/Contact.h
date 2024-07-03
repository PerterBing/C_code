#pragma once
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>

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

typedef struct Contact
{
	PeoInfo data[MAX];
	int count;
}Contact;


//初始化通讯录
void InitContact(Contact* pc);

//增加联系人的信息
void AddContact(Contact* pc);

//显示联系人信息
void ShowContact(const Contact* pc);

//删除联系人信息
void DelContact(Contact* pc);