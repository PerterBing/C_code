#define _CRT_SECURE_NO_WARNINGS
#include"SeqList.h"

//����˳���
int create_list(list_t** p){
	if (p == NULL) {
		printf("����Ϊ��\n");
		return -1;
	}
	*p = (list_t*)malloc(sizeof(list_t));
	(*p)->count = 0;
	memset((*p)->s, 0, sizeof(node_t));
	return 0;
}

//ͷ��
int insert_by_head(list_t *p,int data) {
	if (p == NULL) {
		printf("����Ϊ��\n");
		return -1;
	}
	if (p->count == N) {
		printf("˳������ˣ��޷�ͷ��\n");
		return -1;
	}
	for (int i = p->count; i >0; i--) {
		p->s[i] = p->s[i - 1];
	}
	p->s[0].data = data;
	p->count++;
	return 0;
}

//β��
int insert_by_tail(list_t* p,int data) {
	if (p == NULL) {
		printf("����Ϊ��\n");
		return -1;
	}
	if (p->count == N) {
		printf("˳������ˣ��޷�ͷ��\n");
		return -1;
	}
	p->s[p->count].data = data;
	p->count++;
	return 0;
}

//ͷɾ
int delete_by_head(list_t* p) {
	if (p == NULL) {
		printf("����Ϊ��\n");
		return -1;
	}
	if (p->count == 0) {
		printf("˳���յģ�ɾ����\n");
		return -1;
	}
	for (int i = 0; i < p->count; i++) {
		p->s[i] = p->s[i + 1];
	}
	p->count--;
	return 0;
}

//βɾ
int delete_by_tail(list_t* p) {
	if (p == NULL) {
		printf("����Ϊ��\n");
		return -1;
	}
	if (p->count == 0) {
		printf("˳���յģ�ɾ����\n");
		return -1;
	}
	p->count--;
	return 0;
}


//posλ����,posΪ�����±�
int insert_by_pos(list_t* p,int pos,int data) {
	if (p == NULL) {
		printf("����Ϊ��\n");
		return -1;
	}
	if (p->count == N) {
		printf("˳������ˣ��޷�ͷ��\n");
		return -1;
	}
	if (pos < 0 || pos >= p->count) {
		printf("pos��������\n");
		return -1;
	}
	for (int i = p->count-1; i >= pos; i--) {
		p->s[i+1] = p->s[i];//�ڵ�0��λ���룬����Խ�����
	}
	p->s[pos].data = data;
	p->count++;
	return 0;
}

//posλɾ��
int delete_by_pos(list_t* p, int pos) {
	if (p == NULL) {
		printf("����Ϊ��\n");
		return -1;
	}
	if (pos < 0 || pos >= p->count) {
		printf("pos��������\n");
		return -1;
	}
	if (p->count == 0) {
		printf("˳���յģ�ɾ����\n");
		return -1;
	}
	for (int i = pos; i < p->count; i++) {//p->count-1�ȽϺã��ٱ����ƶ�һ��
		p->s[i] = p->s[i + 1];
	}
	p->count--;
	return 0;
}

int find_by_pos(list_t* p,int data) {
	if (p == NULL) {
		printf("����Ϊ��\n");
		return -1;
	}
	if (p->count == 0) {
		printf("˳���յģ�ɾ����\n");
		return -1;
	}

	for (int i = 0; i < p->count; i++) {
		if (p->s[i].data == data)
		{
			printf("�ҵ��ˣ��±�Ϊ%d\n", i);
			return -1;
		}
	}
	printf("�Ҳ���\n");
	return 0;
}


int cmp_by_list(const void *e1,const void *e2) {
	return ((node_t*)e1)->data > ((node_t*)e2)->data ? 1 : 0;
}
//����
int sort_list(list_t* p) {
	if (p == NULL) {
		printf("����Ϊ��\n");
		return -1;
	}
	qsort(p->s, p->count, sizeof(int), cmp_by_list);
	printf("����ɹ���");
}

//��ת
int overturn_list(list_t* p) {
	if (p == NULL) {
		printf("����Ϊ��\n");
		return -1;
	}
	int left = 0;
	int right = p->count - 1;
	int temp = 0;
	while (left < right) {
		temp = p->s[left].data;
		//����temp������������ʣ����ٳ�ʼ������,���Զ���node_t temp
		//��Ϊ����Ԫ��ֻ��һ��������
		p->s[left].data = p->s[right].data;
		p->s[right].data = temp;
		left++;
		right--;
	}
	printf("��ת�ɹ���");
	return 0;
}

//����
int tichong_list(list_t* p) {
	if (p == NULL) {
		printf("����Ϊ��\n");
		return -1;
	}
	for (int i = 0; i < p->count-1; i++) {
		for (int j = i + 1; j < p->count;) {
			if (p->s[i].data == p->s[j].data) {
				delete_by_pos(p, j);
			}
			else {
				j++;
			}
		}
	}
	printf("���سɹ���");
}

//���
int clean_list(list_t* p) {
	if (p == NULL) {
		printf("����Ϊ��\n");
		return -1;
	}
	p->count = 0;
	return 0;
}

//����
int destroy_list(list_t** p) {
	if (p == NULL||*p==NULL) {
		printf("����Ϊ��\n");
		return -1;
	}
	free(*p);
	*p = NULL;
	return 0;
}

int print_list(list_t* p){
	if (p == NULL) {
		printf("����Ϊ��\n");
		return -1;
	}
	for (int i = 0; i < p->count; i++) {
		printf("%d ", p->s[i].data);
	}
	putchar(10);
}