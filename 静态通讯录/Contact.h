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


//��ʼ��ͨѶ¼
void InitContact(Contact* pc);

//������ϵ�˵���Ϣ
void AddContact(Contact* pc);

//��ʾ��ϵ����Ϣ
void ShowContact(const Contact* pc);

//ɾ����ϵ����Ϣ
void DelContact(Contact* pc);