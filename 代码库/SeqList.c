#define _CRT_SECURE_NO_WARNINGS
#include"SeqList.h"

//创建顺序表
int create_list(list_t** p){
	if (p == NULL) {
		printf("传参为空\n");
		return -1;
	}
	*p = (list_t*)malloc(sizeof(list_t));
	(*p)->count = 0;
	memset((*p)->s, 0, sizeof(node_t));
	return 0;
}

//头插
int insert_by_head(list_t *p,int data) {
	if (p == NULL) {
		printf("传参为空\n");
		return -1;
	}
	if (p->count == N) {
		printf("顺序表满了，无法头插\n");
		return -1;
	}
	for (int i = p->count; i >0; i--) {
		p->s[i] = p->s[i - 1];
	}
	p->s[0].data = data;
	p->count++;
	return 0;
}

//尾插
int insert_by_tail(list_t* p,int data) {
	if (p == NULL) {
		printf("传参为空\n");
		return -1;
	}
	if (p->count == N) {
		printf("顺序表满了，无法头插\n");
		return -1;
	}
	p->s[p->count].data = data;
	p->count++;
	return 0;
}

//头删
int delete_by_head(list_t* p) {
	if (p == NULL) {
		printf("传参为空\n");
		return -1;
	}
	if (p->count == 0) {
		printf("顺序表空的，删不了\n");
		return -1;
	}
	for (int i = 0; i < p->count; i++) {
		p->s[i] = p->s[i + 1];
	}
	p->count--;
	return 0;
}

//尾删
int delete_by_tail(list_t* p) {
	if (p == NULL) {
		printf("传参为空\n");
		return -1;
	}
	if (p->count == 0) {
		printf("顺序表空的，删不了\n");
		return -1;
	}
	p->count--;
	return 0;
}


//pos位插入,pos为数组下标
int insert_by_pos(list_t* p,int pos,int data) {
	if (p == NULL) {
		printf("传参为空\n");
		return -1;
	}
	if (p->count == N) {
		printf("顺序表满了，无法头插\n");
		return -1;
	}
	if (pos < 0 || pos >= p->count) {
		printf("pos参数错误\n");
		return -1;
	}
	for (int i = p->count-1; i >= pos; i--) {
		p->s[i+1] = p->s[i];//在第0号位插入，数组越界访问
	}
	p->s[pos].data = data;
	p->count++;
	return 0;
}

//pos位删除
int delete_by_pos(list_t* p, int pos) {
	if (p == NULL) {
		printf("传参为空\n");
		return -1;
	}
	if (pos < 0 || pos >= p->count) {
		printf("pos参数错误\n");
		return -1;
	}
	if (p->count == 0) {
		printf("顺序表空的，删不了\n");
		return -1;
	}
	for (int i = pos; i < p->count; i++) {//p->count-1比较好，少遍历移动一次
		p->s[i] = p->s[i + 1];
	}
	p->count--;
	return 0;
}

int find_by_pos(list_t* p,int data) {
	if (p == NULL) {
		printf("传参为空\n");
		return -1;
	}
	if (p->count == 0) {
		printf("顺序表空的，删不了\n");
		return -1;
	}

	for (int i = 0; i < p->count; i++) {
		if (p->s[i].data == data)
		{
			printf("找到了，下标为%d\n", i);
			return -1;
		}
	}
	printf("找不到\n");
	return 0;
}


int cmp_by_list(const void *e1,const void *e2) {
	return ((node_t*)e1)->data > ((node_t*)e2)->data ? 1 : 0;
}
//排序
int sort_list(list_t* p) {
	if (p == NULL) {
		printf("传参为空\n");
		return -1;
	}
	qsort(p->s, p->count, sizeof(int), cmp_by_list);
	printf("排序成功：");
}

//翻转
int overturn_list(list_t* p) {
	if (p == NULL) {
		printf("传参为空\n");
		return -1;
	}
	int left = 0;
	int right = p->count - 1;
	int temp = 0;
	while (left < right) {
		temp = p->s[left].data;
		//遍历temp定义在外面合适，减少初始化次数,可以定义node_t temp
		//因为数据元素只有一个数据项
		p->s[left].data = p->s[right].data;
		p->s[right].data = temp;
		left++;
		right--;
	}
	printf("翻转成功：");
	return 0;
}

//剔重
int tichong_list(list_t* p) {
	if (p == NULL) {
		printf("传参为空\n");
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
	printf("剔重成功：");
}

//清空
int clean_list(list_t* p) {
	if (p == NULL) {
		printf("传参为空\n");
		return -1;
	}
	p->count = 0;
	return 0;
}

//销毁
int destroy_list(list_t** p) {
	if (p == NULL||*p==NULL) {
		printf("传参为空\n");
		return -1;
	}
	free(*p);
	*p = NULL;
	return 0;
}

int print_list(list_t* p){
	if (p == NULL) {
		printf("传参为空\n");
		return -1;
	}
	for (int i = 0; i < p->count; i++) {
		printf("%d ", p->s[i].data);
	}
	putchar(10);
}