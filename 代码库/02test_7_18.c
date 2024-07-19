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
    printf("要排多少个数？\n");
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
        scanf("%d", arr + i);//一次性输入5个数时，第一个数会存入arr+1中，剩下的存入缓冲区，当i+1后，scanf会从缓冲区中取数据
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