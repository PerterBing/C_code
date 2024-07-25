#include "LinkList.h"

int create_node(node_t **p, int data)
{
    if (NULL == p)
    {
        printf("无参传入\n");
        return -1;
    }
    *p = (node_t *)malloc(sizeof(node_t));
    if (*p == NULL)
    {
        printf("malloc file\n");
        return -1;
    }

    (*p)->data = data;
    (*p)->next = NULL;
}

int insert_head_node(node_t *phead, int data)// 头插
{
    if (NULL == phead)
    {
        printf("无参传入\n");
        return -1;
    }
    node_t *pnew = NULL;
    create_node(&pnew, data);
    pnew->next = phead->next;
    phead->next = pnew;
    return 0;
}

int delete_head_node(node_t **phead) // 头删
{
    if (NULL == phead)
    {
        printf("无参传入\n");
        return -1;
    }
    node_t *cur = *phead;
    *phead = (*phead)->next;
    free(cur);
    cur = NULL;
}

int insert_tail_node(node_t *phead, int data) // 尾插
{
    if (NULL == phead)
    {
        printf("无参传入\n");
        return -1;
    }
    node_t *pnew = NULL;
    create_node(&pnew, data);
    while (phead->next != NULL)
    {
        phead = phead->next;
    }
    phead->next = pnew;
    return 0;
}

int delete_tail_node(node_t *phead) // 尾删
{
    if (NULL == phead)
    {
        printf("无参传入\n");
        return -1;
    }
    node_t *prev = phead;
    node_t *cur = phead;
    while (cur->next != NULL)
    {
        prev = cur;
        cur = cur->next;
    }
    cur = NULL;
    prev->next = NULL;
    return 0;
}

int insert_pos_after_node(node_t *phead, int pos, int data) // pos位置后插
{
    if (NULL == phead)
    {
        printf("无参传入\n");
        return -1;
    }
    node_t *pnew = NULL;
    create_node(&pnew, data);
    while (phead->data != pos)
    {
        phead = phead->next;
    }
    pnew->next = phead->next;
    phead->next = pnew;
}

int insert_pos_list(node_t *phead, int pos, int data) // pos是每个数据元素位置
{
    if (NULL == phead)
    {
        printf("无参传入\n");
        return -1;
    }
    if (pos < 0)
    {
        printf("插入失败\n");
        return -1;
    }

    int num = 0;
    node_t *cur = phead;
    while (num != pos)
    {
        if (cur->next == NULL)
        {
            printf("超出范围无法插入\n");
            return -1;
        }
        cur = cur->next;
        num++;
    }
    node_t *pnew = NULL;
    create_node(&pnew, data);
    pnew->next = cur->next;
    cur->next = pnew;
    return 0;
}

int delete_pos_list(node_t **phead, int pos) // 任意位置删除
{
    if (NULL == phead)
    {
        printf("无参传入\n");
        return -1;
    }
    int num = 1;
    node_t *cur = (*phead)->next;
    node_t *prev = (*phead)->next;
    if (pos < 1)
    {
        printf("pos传入错误，请重试\n");
        return -1;
    }else if(pos==1)
    {
        delete_head_node(phead);
        return 0;
    }
    while (num != pos)
    {
        if (cur->next == NULL)
        {
            printf("没有pos对应元素项，删除错误\n");
            return -1;
        }
        prev = cur;
        cur = cur->next;
        num++;
    }
    prev->next = cur->next;
    free(cur);
    cur = NULL;
    printf("删除成功\n");
}

int modify_pos_list(node_t* phead,int pos,int data)//修改链表指定位置的元素
{
    if (NULL == phead)
    {
        printf("无参传入\n");
        return -1;
    }
    if(pos<1)
    {
        printf("pos输入错误，请重新输入\n");
        return -1;
    }
    int num=1;
    node_t* cur=phead->next;
    while(num!=pos)
    {
        if (cur->next == NULL)
        {
            printf("没有pos对应元素项，修改失败\n");
            return -1;
        }
        cur=cur->next;
        num++;
    }
    cur->data=data;
    printf("修改成功\n");
}

int search_list(node_t* phead,int val)//查找链表指定位置的元素
{
    if (NULL == phead)
    {
        printf("无参传入\n");
        return -1;
    }
    node_t* cur=phead->next;
    while(cur!=NULL)
    {
        if(cur->data==val)
        {
            printf("找到了:%d\n",cur->data);
            return 0;
        }
    }
    printf("找不到\n");
    return 0;

}

//两个链表合并
node_t* combine_list1_list2(node_t* list1,node_t* list2){
    if(list1==NULL){
        return list2;
    }
    if(list2==NULL){
        return list1;
    }
    node_t* head=NULL;
    node_t* tail=NULL;
    while(list1&&list2){
        if(list1->data<list2->data){
            if(tail==NULL){
                head=tail=list1;
            }else{
                tail->next=list1;
                tail=list1;
            }
            list1=list1->next;
        }else{
            if(tail==NULL)
            {
                head=tail=list2;
            }else{
                tail->next=list2;
                tail=list2;
            }
            list2=list2->next;
        }
    }
    printf("head: ");
    Print_node(head);
    if(list1!=NULL)
    {
        tail->next=list1;
    }
    if(list2!=NULL)
    {
        tail->next=list2;
    }
    return head;
}

node_t* overturn_list(node_t* phead)//链表的翻转
{
    if (NULL == phead)
    {
        printf("无参传入\n");
        return NULL;
    }
    node_t* cur=phead->next->next;
    node_t* next=NULL;
    phead=phead->next;
    phead->next=NULL;
    while(cur!=NULL)
    {
        next=cur->next;
        cur->next=phead;
        phead=cur;
        cur=next;
    }
    node_t *pnew = NULL;
    create_node(&pnew, -1);
    pnew->next=phead;
    phead=pnew;
    return phead;
}

node_t* soul_list(node_t* phead) //链表的剔重
{
    node_t* head=phead->next;
    while(head->next!=NULL)
    {
        node_t* cur=head->next;
        node_t* prev=head;
        while(cur!=NULL)
        {
            if(head->data==cur->data)
            {
                prev->next=cur->next;
                cur=cur->next;
            }else{
                prev=cur;
                cur=cur->next;
            }
            
        }
        head=head->next;
        if(head==NULL)
        {
            break;
        }
    }
    printf("剔重成功: ");
}

int Print_node(node_t *phead)// 打印
{
    if (NULL == phead)
    {
        printf("无参传入\n");
        return -1;
    }
    node_t *ptemp = phead; // 备份头结点
    while (NULL != ptemp->next)
    {
        ptemp = ptemp->next;
        printf("%d", ptemp->data);
        if(NULL != ptemp->next)
            printf("->");
    }
    printf("\n");
    return 0;
}