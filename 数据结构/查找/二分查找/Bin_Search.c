#include <stdio.h>

// 递归版本的二分查找
int binary_search_recursive(int arr[], int low, int high, int target) 
{
    if (low <= high) 
    {
        int mid = low + (high - low) / 2;

        // 如果中间元素等于目标值，返回中间元素的索引
        if (arr[mid] == target)
            return mid;

        // 如果中间元素大于目标值，在左半部分继续查找
        if (arr[mid] > target)
            return binary_search_recursive(arr, low, mid - 1, target);

        // 如果中间元素小于目标值，在右半部分继续查找
        return binary_search_recursive(arr, mid + 1, high, target);
    }

    // 目标值不存在，返回-1表示查找失败
    return -1;
}

// 迭代版本的二分查找
int binary_search_iterative(int arr[], int n, int target) 
{
    int low = 0;
    int high = n - 1;

    while (low <= high) 
    {
        int mid = low + (high - low) / 2;

        // 如果中间元素等于目标值，返回中间元素的索引
        if (arr[mid] == target)
            return mid;

        // 如果中间元素大于目标值，在左半部分继续查找
        if (arr[mid] > target)
            high = mid - 1;

        // 如果中间元素小于目标值，在右半部分继续查找
        else
            low = mid + 1;
    }

    // 目标值不存在，返回-1表示查找失败
    return -1;
}

int main() 
{
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;

    int result_recursive = binary_search_recursive(arr, 0, n - 1, target);
    if (result_recursive != -1)
        printf("递归版本：目标值 %d 在索引 %d 处找到。\n", target, result_recursive);
    else
        printf("递归版本：目标值 %d 未找到。\n", target);

    int result_iterative = binary_search_iterative(arr, n, target);
    if (result_iterative != -1)
        printf("迭代版本：目标值 %d 在索引 %d 处找到。\n", target, result_iterative);
    else
        printf("迭代版本：目标值 %d 未找到。\n", target);

    return 0;
}