#include <stdio.h>

// 交换两个元素的函数
void swap(int* a, int* b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 分区函数，将小于基准值的元素放在左边，大于基准值的元素放在右边
int partition(int arr[], int low, int high)
{
    int pivot = arr[low]; // 选择第一个元素作为基准
    int i = low + 1;
    int j = high;

    while (1) 
    {
        while (i <= j && arr[i] <= pivot)
            i++;
        while (arr[j] >= pivot && j >= i)
            j--;
        if (j < i)
            break;
        swap(&arr[i], &arr[j]);
    }

    swap(&arr[low], &arr[j]); // 将基准元素放入正确的位置
    return j; // 返回基准元素的索引
}

// 快速排序函数
void quick_sort(int arr[], int low, int high) 
{
    if (low < high) 
    {
        int pivot_index = partition(arr, low, high); // 获取基准元素的索引
        quick_sort(arr, low, pivot_index - 1); // 对左子数组进行快速排序
        quick_sort(arr, pivot_index + 1, high); // 对右子数组进行快速排序
    }
}

int main() 
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("原始数组: ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    quick_sort(arr, 0, n - 1);

    printf("排序后的数组: ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}