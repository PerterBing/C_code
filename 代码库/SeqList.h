#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define N 10

typedef struct _Node {
	int data;//数据项
}node_t;//数据元素

typedef struct _List {
	node_t s[N];
	int count;
}list_t;//数据对象

//创建顺序表
int create_list(list_t **p);

//头插
int insert_by_head(list_t* p);

//尾插
int insert_by_tail(list_t* p, int data);

//头删
int delete_by_head(list_t* p);

//尾删
int delete_by_tail(list_t* p);

//pos位插入
int insert_by_pos(list_t* p, int pos, int data);

//pos位删除
int delete_by_pos(list_t* p, int pos);

//pos位置查找
int find_by_pos(list_t* p, int data);

//排序
int sort_list(list_t** p);

//翻转
int overturn_list(list_t* p);

//剔重
int tichong_list(list_t* p);

//清空
int clean_list(list_t* p);

//销毁
int destroy_list(list_t** p);

//打印
int print_list(list_t* p);



