#include <stdio.h>

// 交换两个元素的函数
void swap(int* a, int* b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 堆化操作，将数组构建成最大堆
void heapify(int arr[], int n, int i) 
{
    int largest = i; // 初始化最大值为根节点
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // 如果左子节点比根节点大
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // 如果右子节点比根节点大
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // 如果最大值不是根节点，则交换它们，并递归地对交换后的子树进行堆化操作
    if (largest != i) 
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// 堆排序函数
void heap_sort(int arr[], int n) 
{
    // 建堆
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // 从堆顶开始反复取出最大值并恢复堆
    for (int i = n - 1; i > 0; i--) 
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
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

    heap_sort(arr, n);

    printf("排序后的数组: ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}