#include"LinkList.h"


void test01()
{
    node_t *list=NULL;
    create_node(&list,-1);

    //头插
    insert_head_node(list,10);
    insert_head_node(list,20);
    insert_head_node(list,30);
    Print_node(list);
    
    // //尾插
    // insert_tail_node(list,1);
    // insert_tail_node(list,2);
    // insert_tail_node(list,3);
    //Print_node(list);

    //delete_pos_list(&list,6);
    //delete_pos_list(&list,0);
    //delete_pos_list(&list,5);
    //delete_pos_list(&list,1);
    //delete_head_node(&list);

    //修改pos
    // modify_pos_list(list,0,100);
    // modify_pos_list(list,1,100);
    // modify_pos_list(list,6,100);
    // modify_pos_list(list,7,100);

    //search_list(list,30);
    //Print_node(list);
}



void test02()
{
    //合并两个有序链表
    node_t *list1=NULL;
    create_node(&list1,-1);
    node_t *list2=NULL;
    create_node(&list2,-1);
    insert_head_node(list1,4);
    insert_head_node(list1,2);
    insert_head_node(list1,1);

    insert_head_node(list2,4);
    insert_head_node(list2,3);
    insert_head_node(list2,1);
    Print_node(list1);
    Print_node(list2);

    node_t* comphead=combine_list1_list2(list1,list2);
    Print_node(comphead);
}

void test03()
{
    //链表翻转
    node_t *list=NULL;
    create_node(&list,-1);
    insert_head_node(list,20);
    insert_head_node(list,13);
    insert_head_node(list,15);
    insert_tail_node(list,78);
    insert_tail_node(list,67);
    insert_tail_node(list,99);
    Print_node(list);
    node_t* ret=overturn_list(list);
}

void test04()
{
    node_t *list=NULL;
    create_node(&list,-1);
    insert_tail_node(list,1);
    insert_tail_node(list,3);
    insert_tail_node(list,1);
    insert_tail_node(list,3);
    insert_tail_node(list,1);
    insert_tail_node(list,6);
    insert_tail_node(list,1);
    Print_node(list);
    soul_list(list);
    Print_node(list);
}

int main(int argc,const char *argv[])
{
    //test02();//合并有序链表
    //test03();//链表的翻转
    test04();//链表的剔重
    return 0;
}