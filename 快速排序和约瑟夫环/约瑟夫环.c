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
	node_t* ptail = phead;//�ȴ�ͷ�ڵ��β�ڵ㣬β�ڵ��ƶ�������Ԫ��
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
	ptail->next = phead;//β�ڵ�ָ����ָ��ͷ  �γ�ѭ��
	return phead;
}

int main(int  argc, const char* argv[]) {
	if (3 != argc) {
		printf("Usage :%s ������ ������\n", argv[0]);
		return 0;
	}
	int m = atoi(argv[1]);
	int n = atoi(argv[2]);
	node_t* phead = create_list(m);//������������
	
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
			printf("�� %d ����̭���� %d ��\n", ++taobao_count, phead->data);
			free(phead);
			phead = pbefor->next;
			count = 0;
		}
		else {
			pbefor = phead;
			phead = phead->next;
		}
	}
	printf("���ʣ�µ��� %d ��\n", phead->data);
	free(phead);
	phead = NULL;
	pbefor = NULL;
	return 0;
}