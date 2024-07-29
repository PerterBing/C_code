#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int datatype;

typedef struct _Node {
	datatype data;
	struct _Node *next;
}node_t;

node_t * create_node(node_t** pnew,int data);
int insert_list_by_head(node_t* phead, int data);
int print_list(node_t* phead);
int insert_list_by_tail(node_t* phead, int data);
int insert_list_by_pos(node_t* phead, int pos, int data);

int delete_list_by_tail(node_t* phead);
int delet_list_by_head(node_t* phead);
int delete_list_by_pos(node_t* phead, int pos);

int modify_list_by_pos(node_t* phead, int pos, int data);
int search_list_by_pos(node_t* phead, int data);

int clean_list(node_t* phead);
int destroy_list(node_t** phead);

int hebing_list();
int sort_list();
int overturn_list();
int tichong();

