#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define N 10

typedef struct _Node {
	int data;//������
}node_t;//����Ԫ��

typedef struct _List {
	node_t s[N];
	int count;
}list_t;//���ݶ���

//����˳���
int create_list(list_t **p);

//ͷ��
int insert_by_head(list_t* p);

//β��
int insert_by_tail(list_t* p, int data);

//ͷɾ
int delete_by_head(list_t* p);

//βɾ
int delete_by_tail(list_t* p);

//posλ����
int insert_by_pos(list_t* p, int pos, int data);

//posλɾ��
int delete_by_pos(list_t* p, int pos);

//posλ�ò���
int find_by_pos(list_t* p, int data);

//����
int sort_list(list_t** p);

//��ת
int overturn_list(list_t* p);

//����
int tichong_list(list_t* p);

//���
int clean_list(list_t* p);

//����
int destroy_list(list_t** p);

//��ӡ
int print_list(list_t* p);



