#define _CRT_SECURE_NO_WARNINGS
#include"SeqStack.h"


int main(int argc,const char *argv[]) {
	
	stack_t* my_stack = 0;
	create_stack(&my_stack);
	int num = 0;
	printf("请输入一个十进制数：");
	scanf("%d", &num);
	int yushu = 0;
	while (num) {
		yushu = num % 2;
		push_stack(my_stack, yushu);
		num = num / 2;
	}
	int ret = 0;
	while (!pop_stack(my_stack, &ret)) {
		printf("%d", ret);
	}
	putchar(10);
	destroy_stack(&my_stack);
	return 0;
}