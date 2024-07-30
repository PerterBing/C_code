#define _CRT_SECURE_NO_WARNINGS
#include"SeqStack.h"


int create_stack(stack_t** p) {
	if (p == NULL) {
		printf("入参为空\n");
		return -1;
	}
	*p = (stack_t*)malloc(sizeof(stack_t));
	if (*p == NULL) {
		printf("*p malloc fail\n");
		return -1;
	}
	memset(*p, 0, sizeof(stack_t));
	return 0;
}

int is_full(stack_t* my_stack) {
	if (my_stack == NULL) {
		printf("入参为空\n");
		return -1;
	}
	return my_stack->top == N ? 1 : 0;
}
int push_stack(stack_t* my_stack, int data) {
	if (my_stack == NULL) {
		printf("入参为空\n");
		return -1;
	}
	if (is_full(my_stack)) {
		//printf("栈满\n");
		return -1;
	}
	my_stack->s[my_stack->top]=data;
	my_stack->top++;
	return 0;
}
int is_empty(stack_t* my_stack) {
	if (my_stack == NULL) {
		printf("入参为空\n");
		return -1;
	}
	return my_stack->top == 0 ? 1 : 0;
}
int pop_stack(stack_t* my_stack, int* num) {
	if (my_stack == NULL||num==NULL) {
		printf("入参为空\n");
		return -1;
	}
	if (is_empty(my_stack)) {
		//printf("栈空\n");
		return -1;
	}
	*num = my_stack->s[--my_stack->top];
	return 0;
}
int clean_stack(stack_t* my_stack) {
	if (my_stack == NULL) {
		printf("入参为空\n");
		return -1;
	}
	my_stack->top = 0;
	return 0;
}
int destroy_stack(stack_t** my_stack) {
	if (my_stack == NULL||*my_stack==NULL) {
		printf("入参为空\n");
		return -1;
	}
	clean_stack(my_stack);
	free(*my_stack);
	*my_stack = NULL;
	return 0;
}
int print_stack(stack_t* my_stack) {
	if (my_stack == NULL) {
		printf("入参为空\n");
		return -1;
	}
	for (int i = my_stack->top - 1; i >= 0; i--) {
		printf("%d  ", my_stack->s[i]);
	}
	putchar(10);
	return 0;
}