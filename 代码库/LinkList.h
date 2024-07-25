#ifndef __SEQLIST_H__
#define __SEQLIST_H__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _Node{
    int data;
    struct _Node *next;
}node_t;

int create_node(node_t** p,int data);//创建新节点

int insert_head_node(node_t* phead,int data);//头插
int delete_head_node(node_t** phead);//头删

int insert_tail_node(node_t* phead,int data);//尾插
int delete_tail_node(node_t* phead);//尾删

int insert_pos_after_node(node_t* phead,int pos,int data);//pos位置后插
int insert_pos_after_node(node_t* phead,int pos,int data);//pos位置前插
int insert_pos_list(node_t* phead,int pos,int data);//pos位置的任意插入，按数组
// int insert_pos_before_node(node_t* phead,int pos,int data);//pos位置前插

int delete_pos_list(node_t** phead,int pos);//任意位置删除

int modify_pos_list(node_t* phead,int pos,int data);//修改链表指定位置的元素

int search_list(node_t* phead,int val);//查找链表指定位置的元素

node_t* combine_list1_list2(node_t* list1,node_t* list2);//两个链表合并


node_t* overturn_list(node_t* phead);//链表的翻转

node_t* soul_list(node_t* phead); //链表的剔重

int Print_node(node_t* phead);//打印

#endif