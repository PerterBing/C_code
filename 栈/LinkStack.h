#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#if 0

typedef struct node {
	int data;
	struct node* next;
}node_t;//�����ڵ�����Ԫ��

typedef struct stack {
	node_t* top;
	int count;
}stack_t;//����ջ

int create_stack(stack_t** p);
int push_stack(stack_t* my_stack, int data);
int is_empty(stack_t* my_stack);
int pop_stack(stack_t* my_stack, int* num);
int clean_stack(stack_t* my_stack);
int destroy_stack(stack_t** my_stack);
int print_stack(stack_t* my_stack);
#endif