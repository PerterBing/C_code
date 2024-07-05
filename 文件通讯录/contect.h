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


//�˵���Ϣ
typedef struct PeopInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;


//ͨѶ¼����Ϣ  ��̬�汾
typedef struct Contact
{
	PeoInfo *data;//���100����Ϣ
	int count;//��¼��ǰͨѶ¼����
	int capacity;//��¼������
}Contact;


//��ʼ��ͨѶ¼
int InitContact(Contact* pc);

//����ͨѶ¼
void DestoryContact(Contact* pc);

//������ϵ�˵�ͨѶ¼
void AddContact(Contact* pc);

//��ʾͨѶ¼��Ϣ
void ShowContact(const Contact* pc);

//ɾ����ϵ��
void DelContact(Contact* pc);

//����ָ����ϵ��
void SeaContact(Contact* pc);

//�޸�ָ����ϵ��
void ModContact(Contact* pc);

//����ͨѶ¼����
void SortContact(Contact* pc);

//����ͨѶ¼����Ϣ���ļ�
void SaveContact(Contact* pc);

//�����ļ���Ϣ��ͨѶ¼
void LoadContact(Contact* pc);
