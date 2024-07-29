#define _CRT_SECURE_NO_WARNINGS
#include"SeqList.h"

int main() {
	list_t* plist = NULL;
	create_list(&plist);
	//printf("plist£º%#p\n", plist);

	insert_by_tail(plist, 1);
	insert_by_tail(plist, 1);
	insert_by_tail(plist, 2);
	insert_by_tail(plist, 2);
	insert_by_tail(plist, 3);
	insert_by_tail(plist, 4);
	insert_by_tail(plist, 5);
	insert_by_tail(plist, 6);
	insert_by_tail(plist, 6);//ÂúÁË
	insert_by_pos(plist, 0, 100);
	//delete_by_pos(plist, 0);
	//find_by_pos(plist, 99);
	print_list(plist);
	putchar(10);


	//sort_list(plist);
	//print_list(plist);
	//putchar(10);
	//overturn_list(plist);
	tichong_list(plist);
	print_list(plist);

	return 0;
}