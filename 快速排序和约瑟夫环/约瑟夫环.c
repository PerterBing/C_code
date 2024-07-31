#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

typedef struct _Node {
	int data;
	struct _Node* next;
}node_t;

node_t* create_list(int m) {
	node_t* phead = (node_t*)malloc(sizeof(node_t));
	if (NULL == phead) {
		return NULL;
	}
	phead->data = 1;
	node_t* ptail = phead;//先创头节点和尾节点，尾节点移动来增加元素
	node_t* pnew = NULL;
	for (int i = 2; i <= m; i++) {
		pnew = (node_t*)malloc(sizeof(node_t));
		if (NULL == pnew) {
			return NULL;
		}
		pnew->data = i;
		ptail->next = pnew;
		ptail = pnew;
	}
	ptail->next = phead;//尾节点指针域指向头  形成循环
	return phead;
}

int main(int  argc, const char* argv[]) {
	if (3 != argc) {
		printf("Usage :%s 总人数 数到几\n", argv[0]);
		return 0;
	}
	int m = atoi(argv[1]);
	int n = atoi(argv[2]);
	node_t* phead = create_list(m);//创建环型链表
	
	node_t* ptemp = phead;
	while (phead != ptemp->next) {
		printf("%d ", ptemp->data);
		ptemp = ptemp->next;
	}
	printf("%d \n", ptemp->data);
	int count = 0;
	int taobao_count = 0;
	node_t* pbefor = NULL;
	while (phead->next != phead) {
		count++;
		if (n == count) {
			pbefor->next = phead->next;
			printf("第 %d 次淘汰的是 %d 号\n", ++taobao_count, phead->data);
			free(phead);
			phead = pbefor->next;
			count = 0;
		}
		else {
			pbefor = phead;
			phead = phead->next;
		}
	}
	printf("最后剩下的是 %d 号\n", phead->data);
	free(phead);
	phead = NULL;
	pbefor = NULL;
	return 0;
}