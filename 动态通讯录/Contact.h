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

//��̬�汾
//typedef struct Contact
//{
//	PeoInfo data[100];
//	int count;
//}Contact;

//��̬�汾
typedef struct Contact
{
	PeoInfo* data;
	int count;
	int capacity;
}Contact;

//��ʼ��ͨѶ¼
int InitContact(Contact* pc);

//����ͨ��¼
void DestroyContact(Contact* pc);

//������ϵ��
void AddContact(Contact* pc);

//��ʾ��ϵ��
void ShowContact(Contact* pc);

//ɾ����ϵ��
void DelContact(Contact* pc);

//������ϵ��
void SeaContact(Contact* pc);

//�޸���ϵ��
void ModifyContact(Contact* pc);

//����������
void SortContact(Contact* pc);

//����ͨѶ¼v
void SaveContact(const Contact* pc);

//�����ļ���Ϣ��ͨѶ¼
void LoadContact(Contact* pc);

