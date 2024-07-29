#define _CRT_SECURE_NO_WARNINGS
#include"LinkList.h"

//�����ڵ�
node_t* create_node(node_t** pnew,int data) {
	if (pnew == NULL) {
		printf("����Ϊ��\n");
		return -1;
	}
	*pnew = (node_t*)malloc(sizeof(node_t));
	if (*pnew == NULL) {
		printf("pnew malloc fail\n");
		return -1;
	}
	(*pnew)->data = data;
	(*pnew)->next = NULL;
	return *pnew;//ע�ⷵ��ֵ������	
}

//ͷ��
int insert_list_by_head(node_t* phead,int data) {
	if (phead == NULL) {
		printf("����Ϊ��\n");
		return -1;
	}
	node_t* pnew = NULL;
	pnew=create_node(&pnew,data);
	pnew->next = phead->next;
	phead->next = pnew;
	return 0;
}

int print_list(node_t* phead) {
	if (phead == NULL) {
		printf("����Ϊ��\n");
		return -1;
	}
	node_t* ptemp = phead;
	while (ptemp->next != NULL) {
		ptemp = ptemp->next;
		printf("%d ", ptemp->data);
		if (ptemp->next != NULL) {
			printf("->");
		}
	}
	puts("-> NULL");
}

//β��
int insert_list_by_tail(node_t* phead, int data) {
	if (phead == NULL) {
		printf("����Ϊ��\n");
		return -1;
	}
	node_t* ptail = phead;
	while (ptail->next != NULL) {
		ptail = ptail->next;
	}
	node_t* pnew = create_node(&pnew, data);
	pnew->next = ptail->next;
	ptail->next = pnew;
	return 0;
}

//posλ��  1  2  3  4  5  6
//       0 |1 |2 |3 |4| 5| 7
int insert_list_by_pos(node_t* phead, int pos,int data) {
	if (phead == NULL) {
		printf("����Ϊ��\n");
		return -1;
	}
	node_t* ptemp = phead;
	for (int i = 0; i < pos; i++) {
		if (ptemp == NULL) {
			printf("pos������\n");//��һ��
			return -1;//��һ��
		}
		ptemp = ptemp->next;
	}
	if (pos < 0) {
		printf("pos������\n");
		return -1;
	}
	node_t* pnew = create_node(&pnew, data);
	pnew->next= ptemp->next;
	ptemp->next = pnew;
	return 0;
}

int delete_list_by_tail(node_t* phead) {
	if (phead == NULL) {
		printf("����Ϊ��\n");
		return -1;
	}
	if (phead->next == NULL) {
		printf("������Ԫ��\n");
		return -1;
	}
	while (phead->next->next != NULL) {
		phead = phead->next;
	}
	free(phead->next);;
	phead->next = NULL;
	return 0;
}

int delet_list_by_head(node_t* phead) {
	if (phead == NULL) {
		printf("����Ϊ��\n");
		return -1;
	}
	if (phead->next == NULL) {
		printf("������Ԫ��\n");
		return -1;
	}
	node_t* pdel = phead->next;
	phead->next = pdel->next;
	free(pdel);
	pdel = NULL;
	return 0;
}

//posλ��  1  2  3  4  5  6
//         0  1  2  3  4  5
int delete_list_by_pos(node_t* phead, int pos) {
	if (phead == NULL) {
		printf("����Ϊ��\n");
		return -1;
	}
	if (phead->next == NULL) {
		printf("������Ԫ��\n");
		return -1;
	}
	if (pos < 0) {
		printf("pos������\n");
		return -1;
	}
	node_t* ptemp = phead;
	for (int i = 0; i < pos; i++) {
		ptemp = ptemp->next;
		if (ptemp->next== NULL) {//��һ��
			printf("posλ�ò�����\n");
			return -1;
		}
	}
	node_t* pdel = ptemp->next;
	ptemp->next = pdel->next;
	free(pdel);
	pdel = NULL;
	return 0;
}

//posλ��  1  2  3  4  5  6
//         0  1  2  3  4  5
int modify_list_by_pos(node_t* phead, int pos,int data) {
	if (phead == NULL) {
		printf("����Ϊ��\n");
		return -1;
	}
	if (phead->next == NULL) {
		printf("������Ԫ��\n");
		return -1;
	}
	if (pos < 0) {
		printf("pos������\n");
		return -1;
	}
	node_t* ptemp = phead;
	for (int i = 0; i < pos+1; i++) {//��һ��
		ptemp = ptemp->next;
		if (ptemp == NULL) {//��һ��
			printf("posλ�ò�����\n");
			return -1;
		}
	}
	ptemp->data = data;
	return 0;
}
int search_list_by_pos(node_t* phead, int data ) {
	if (phead == NULL) {
		printf("����Ϊ��\n");
		return -1;
	}
	if (phead->next == NULL) {
		printf("������Ԫ��\n");
		return -1;
	}
	node_t* ptemp = phead;
	int i = 0;
	while (ptemp != NULL) {
		ptemp = ptemp->next;
		if (ptemp->data == data) {
			printf("�ǵ�%d��Ԫ��\n", i);
			return 0;
		}
		i++;
	}
	printf("û�ҵ�\n");
	return -1;
}

int clean_list(node_t* phead) {
	if (phead == NULL) {
		printf("����Ϊ��\n");
		return -1;
	}
	node_t* pdel = phead;
	while (pdel->next != NULL) {
		pdel = pdel->next;
		phead->next = pdel->next;
		free(pdel);
		
	}
	pdel = NULL;
	return 0;
}

int destroy_list(node_t** phead) {
	if (*phead == NULL || phead == NULL) {
		printf("����Ϊ��\n");
		return -1;
	}
	clean_list(*phead);
	free(*phead);
	*phead = NULL;
	return 0;
}