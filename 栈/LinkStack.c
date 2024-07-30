#define _CRT_SECURE_NO_WARNINGS
#if 0

#include"LinkStack.h"

int create_stack(stack_t** p) {
	if (p == NULL) {
		printf("���Ϊ��\n");
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
		printf("���Ϊ��\n");
		return -1;
	}
	node_t* pnew = (node_t*)malloc(sizeof(node_t));
	if (pnew == NULL) {
		printf("pnew malloc fail\n");
		return -1;
	}
	pnew->data = data;
	//topָ��ջ��Ԫ�أ��������Ϊtop����ջ��Ԫ�أ�pnew�൱����ջ��Ԫ��ͷ��
	pnew->next = my_stack->top;
	my_stack->top = pnew;
	my_stack->count++;
	return 0;
}

int is_empty(stack_t* my_stack) {
	if (my_stack == NULL) {
		printf("���Ϊ��\n");
		return -1;
	}
	return my_stack->count == 0 ? 1 : 0;
}

int pop_stack(stack_t* my_stack, int* num) {
	if (my_stack == NULL||num==NULL) {
		printf("���Ϊ��\n");
		return -1;
	}
	if (is_empty(my_stack)) {
		printf("ջ��\n");
		return -1;
	}
	//����Ҫ���ٿռ䣬pdel���м���ֻ��Ҫ�ͷſռ䣬��Ϊ�վͿ���
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
		printf("���Ϊ��\n");
		return -1;
	}
	node_t* pdel = NULL;//���ٽڵ㲻��Ҫ���ٿռ�
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
		printf("���Ϊ��\n");
		return -1;
	}
	clean_stack(*my_stack);
	free(*my_stack);
	*my_stack = NULL;
	return 0;
}

int print_stack(stack_t* my_stack) {
	if (my_stack == NULL) {
		printf("���Ϊ��\n");
		return -1;
	}
	if (is_empty(my_stack)) {
		printf("ջ��\n");
		return -1;
	}
	//������뽫topָ�븳ֵ��ptemp����Ϊ������ӡ��ı�my_stack->top�洢�ĵ�ַ����Ȼ���ݵ���ͬ��ָ�룬�����ݵ��ǽṹ��ĵ�ַ
	//������ô��⣺����stack_t *my_stackָ�룬ָ�����һ��ṹ��ĵ�ַ���ṹ����topָ���count����ֻҪ��my_stack��ŵĽṹ����Ǹ���ַ
	//�Ϳ����޸�top�ڵ�ֵ��data��next����
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