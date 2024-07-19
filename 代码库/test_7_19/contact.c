#include "contact.h"

void pp(void)
{
    printf("-------------------------------------------------------------\n");
    putchar(10);
}

void check_Capacity(Contact *pc)
{
    if (pc->size == pc->capacity)
    {
        PeoInfo *ptr = (PeoInfo *)realloc(pc->data, (pc->capacity + 3) * sizeof(PeoInfo));
        if (ptr != NULL)
        {
            pc->data = ptr;
            pc->capacity += 3;
            printf("增容成功\n");
        }
        else
        {
            printf("增容失败\n");
            return;
        }
    }
}

void LoadContact(Contact *pc)
{
    FILE* pfread=fopen("contact.txt","rb");
    if(pfread==NULL)
    {
        perror("LoadContact");
        return ;
    }
    PeoInfo tmp={0};
    while(fread(&tmp,sizeof(PeoInfo),1,pfread)==1)
    {
        check_Capacity(pc);

        pc->data[pc->size]=tmp;
        pc->size++;
    }

    fclose(pfread);
    pfread=NULL;
}

int InitContact(Contact *pc)
{
    
    pc->size = 0;
    pc->capacity = 3;
    pc->data = (PeoInfo *)malloc(pc->capacity * sizeof(PeoInfo));
    if (pc->data == NULL)
    {
        printf("data malloc error,try again\n");
        return -1;
    }
    return 0;
}

void AddContact(Contact *pc)
{
    check_Capacity(pc);
retry:
    printf("请依次输入联系人姓名，年龄，电话，地址：\n");
    int ret = scanf("%s %d %s %s",
                    pc->data[pc->size].name,
                    &pc->data[pc->size].age,
                    pc->data[pc->size].tele,
                    pc->data[pc->size].adress);
    if (ret != 4)
    {
        printf("输入错误，重新输入\n");
        while (getchar() != '\n')
            ;
        goto retry;
    }

    pc->size++;
    printf("添加成功\n");
}

void ShowContact(Contact *pc)
{
    if (pc->size == 0)
    {
        printf("通讯录为空\n");
    }
    printf("%-20s\t%-10s\t%-12s\t%-30s\n", "姓名", "年龄", "电话", "地址");
    for (int i = 0; i < pc->size; i++)
    {
        printf("%-20s\t%-10d\t%-12s\t%-30s\n",
               pc->data[i].name,
               pc->data[i].age,
               pc->data[i].tele,
               pc->data[i].adress);
    }
    pp();
}

int FindByName(Contact *pc, char *name)
{
    for (int i = 0; i < pc->size; i++)
    {
        if (strcmp(pc->data[i].name, name) == 0)
        {
            return i;
        }
    }
    return -1;
}

void DelContact(Contact *pc)
{
    char name[20] = {0};
    if (pc->size == 0)
    {
        printf("通讯录为空，删除失败\n");
    }
    else
    {
        printf("请输入要删除的姓名：> ");
        scanf("%s", name);
        int pos = FindByName(pc, name);
        printf("pos = %d \n", pos);
        if (pos == -1)
        {
            printf("找不到,重新输入\n");
            pp();
        }
        else
        {
            for (int i = pos; i < pc->size; i++)
            {
                pc->data[i] = pc->data[i + 1];
            }
            pc->size--;
            printf("删除成功\n");
            pp();
        }
    }
}

void ModContact(Contact *pc)
{
    char name[20] = {0};
    printf("请输入要修改的姓名：> ");
    scanf("%s", name);
    int pos = FindByName(pc, name);
    if (pos == -1)
    {
        printf("找不到,重新输入\n");
        pp();
    }
    else
    {
        printf("请重新输入联系人信息：> ");
    retry:
        printf("请依次输入联系人姓名，年龄，电话，地址：\n");
        int ret = scanf("%s %d %s %s",
                        pc->data[pos].name,
                        &pc->data[pos].age,
                        pc->data[pos].tele,
                        pc->data[pos].adress);
        if (ret != 4)
        {
            printf("输入错误，重新输入\n");
            while (getchar() != '\n');
            goto retry;
        }
        printf("修改成功\n");
        pp();
    }
}

void SeaContact(Contact *pc)
{
    char name[20] = {0};
    printf("请输入要查找的姓名：> ");
    scanf("%s", name);
    int pos = FindByName(pc, name);
    printf("pos = %d \n", pos);
    if (pos == -1)
    {
        printf("找不到,重新输入\n");
        pp();
    }
    else
    {
        printf("找到了\n");
        printf("%-20s\t%-10d\t%-12s\t%-30s\n",
                pc->data[pos].name,
                pc->data[pos].age,
                pc->data[pos].tele,
                pc->data[pos].adress);
        pp();
    }
}

int cmp_by_age(const void *e1,const void *e2)
{
    return ((PeoInfo*)e1)->age>((PeoInfo*)e2)->age?1:0;
}

void SortContact(Contact *pc)
{
    qsort(pc->data,pc->size,sizeof(PeoInfo),cmp_by_age);
    printf("排序成功\n");
}

void DestroyContact(Contact* pc)
{
	free(pc->data);
	pc->data = NULL;
}

void SaveContact(Contact *pc)//保存通讯录到文件
{
    FILE* pfwrite = fopen("contact.txt","wb");
    if(pfwrite==NULL)
    {
        perror("SaveContact");
        return ;
    }

    for(int i=0;i<pc->size;i++)
    {
        fwrite(pc->data+i,sizeof(PeoInfo),1,pfwrite);
    }
    fclose(pfwrite);
    pfwrite=NULL;
}