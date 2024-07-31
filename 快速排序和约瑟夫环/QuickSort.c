#define _crt_secure_no_warnings
#include<stdio.h>

#if 0
void print_sort(int* arr, int len) {
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	putchar(10);
	return 0;
}

int my_sort(int* arr, int low, int high) {
	int flag = arr[low];
	while (low < high) {
		while (arr[high] > flag&&low<high) {
			high--;
		}
		if (low < high) {
			arr[low] = arr[high];
			low++;
		}
		while (arr[low]<flag && low < high)
		{
			low++;
		}
		if (low < high) {
			arr[high] = arr[low];
			high--;
		}
	}
	arr[low] = flag;
	return low;
}

int quicksort(int* arr, int low, int high) {
	if (low < high) {
		int ret = my_sort(arr, low, high);
		quicksort(arr, low, ret-1);
		quicksort(arr, ret+1, high);
	}
}

int main(int argc, const char* argv[]) {
	int arr[10] = { 6, 4, 9, 3, 10, 22, 8, 5, 1, 10 };
	quicksort(arr, 0, 9);
	print_sort(arr, 10);
	return 0;
}
#endif