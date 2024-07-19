#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>


void my_sort(int* arr, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

void show_arr(int* arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    putchar(10);
}

int main(int argc, const char* argv[])
{
    int n;
    printf("Ҫ�Ŷ��ٸ�����\n");
    scanf("%d", &n);
    int* arr;
    arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("malloc memory error,try again\n");
        return -1;
    }
    int i = 0;
    while(i<n)
    {
        scanf("%d", arr + i);//һ��������5����ʱ����һ���������arr+1�У�ʣ�µĴ��뻺��������i+1��scanf��ӻ�������ȡ����
        i++;
    }
    
    // printf("len = %d\n",len);
    // my_sort(arr,len);
    // show_arr(arr,len);

    if (arr != NULL)
    {
        free(arr);
        arr = NULL;
    }

    return 0;
}