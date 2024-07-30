#define _CRT_SECURE_NO_WARNINGS

#if 0
#include"LinkStack.h"


int main() {
	stack_t* my_stack = 0;
	create_stack(&my_stack);
	//printf("my_stack£º%#p\n", my_stack);
	push_stack(my_stack, 10);
	push_stack(my_stack, 20);
	push_stack(my_stack, 30);
	print_stack(my_stack);

	int val = 0;
	pop_stack(my_stack, &val);
	printf("val = %d \n", val);
	pop_stack(my_stack, &val);
	printf("val = %d \n", val);
	pop_stack(my_stack, &val);
	printf("val = %d \n", val);
	pop_stack(my_stack, &val);
	//printf("val = %d \n", val);
	clean_stack(my_stack);
	destroy_stack(&my_stack);
	return 0;
}

#endif