#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 5

typedef struct _Stack {
	int s[N];
	int top;
}stack_t;

int create_stack(stack_t** p);
int is_full(stack_t* my_stack);
int push_stack(stack_t* my_stack,int data);
int is_empty(stack_t* my_stack);
int pop_stack(stack_t* my_stack,int *num);
int clean_stack(stack_t* my_stack);
int destroy_stack(stack_t** my_stack);
int print_stack(stack_t* my_stack);