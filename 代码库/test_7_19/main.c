#include<stdio.h>
#include"contact.h"

void MNUM()
{
    printf("*****   欢迎登录通讯录系统   *****\n");
    printf("*** 1.添加联系人 2.删除联系人   **\n");
    printf("*** 3.修改联系人 4.查找联系人   **\n");
    printf("*** 5.显示联系人 6.按联系人排序 **\n");
    printf("****0.退出       7.清屏        **\n");
}

int main(int argc,const char *argv[])
{
    int input=1;
    Contact con;
    int ret=InitContact(&con);
    LoadContact(&con);
    if(ret==-1)
    {
        printf("开辟空间失败,程序退出\n");
        return 0;
    }
    do
    {
        MNUM();
        printf("请输入你的选择：> ");
        scanf("%d",&input);
        switch(input)
        {
            case 1:
                AddContact(&con);
                break;
            case 2:
                DelContact(&con);
                break;
            case 3:
                ModContact(&con);
                break;
            case 4:
                SeaContact(&con);
                break;
            case 5:
                ShowContact(&con);
                break;
            case 6:
                SortContact(&con);
                break;  
            case 7:
                system("clear");
                break; 
            case 0:
                SaveContact(&con);//保存通讯录到文件
                DestroyContact(&con);//销毁通讯录
                printf("程序退出,内容保存至文件\n");
                input=0;
                break;
            default:
                break;                 
        }
    } while(input);
    return 0;
}