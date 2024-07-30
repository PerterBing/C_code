#define _CRT_SECURE_NO_WARNINGS
#if 0

#include"LinkStack.h"

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
	(*p)->top= NULL;
	(*p)->count = 0;
	return 0;
}
int push_stack(stack_t* my_stack, int data) {
	if (my_stack == NULL) {
		printf("入参为空\n");
		return -1;
	}
	node_t* pnew = (node_t*)malloc(sizeof(node_t));
	if (pnew == NULL) {
		printf("pnew malloc fail\n");
		return -1;
	}
	pnew->data = data;
	//top指向栈顶元素，可以理解为top就是栈顶元素，pnew相当于在栈顶元素头插
	pnew->next = my_stack->top;
	my_stack->top = pnew;
	my_stack->count++;
	return 0;
}

int is_empty(stack_t* my_stack) {
	if (my_stack == NULL) {
		printf("入参为空\n");
		return -1;
	}
	return my_stack->count == 0 ? 1 : 0;
}

int pop_stack(stack_t* my_stack, int* num) {
	if (my_stack == NULL||num==NULL) {
		printf("入参为空\n");
		return -1;
	}
	if (is_empty(my_stack)) {
		printf("栈空\n");
		return -1;
	}
	//不需要开辟空间，pdel做中间量只需要释放空间，置为空就可以
	*num = my_stack->top->data;
	node_t* pdel = my_stack->top;
	my_stack->top = pdel->next;
	free(pdel);
	pdel = NULL;
	my_stack->count--;
	return 0;
}
int clean_stack(stack_t* my_stack) {
	if (my_stack == NULL) {
		printf("入参为空\n");
		return -1;
	}
	node_t* pdel = NULL;//销毁节点不需要开辟空间
	while (my_stack->top != NULL) {
		pdel=my_stack->top;
		my_stack->top = pdel->next;
		free(pdel);
	}
	pdel = NULL;
	my_stack->count = 0;
	return 0;	
}

int destroy_stack(stack_t** my_stack) {
	if (*my_stack == NULL||my_stack==NULL) {
		printf("入参为空\n");
		return -1;
	}
	clean_stack(*my_stack);
	free(*my_stack);
	*my_stack = NULL;
	return 0;
}

int print_stack(stack_t* my_stack) {
	if (my_stack == NULL) {
		printf("入参为空\n");
		return -1;
	}
	if (is_empty(my_stack)) {
		printf("栈空\n");
		return -1;
	}
	//这里必须将top指针赋值给ptemp，因为遍历打印会改变my_stack->top存储的地址，虽然传递的是同级指针，但传递的是结构体的地址
	//可以这么理解：定义stack_t *my_stack指针，指向的是一块结构体的地址，结构体存放top指针和count数，只要有my_stack存放的结构体的那个地址
	//就可以修改top内的值（data和next）；
	node_t* ptemp = my_stack->top;
	while (ptemp != NULL) {
		printf("%d ", ptemp->data);
		ptemp = ptemp->next;
		if (ptemp != NULL) {
			printf("->");
		}
	}
	putchar(10);
	return 0;
}

#endif