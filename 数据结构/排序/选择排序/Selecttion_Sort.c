#include <stdio.h>

// 交换数组中两个元素的值
void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 选择排序函数
void selectionSort(int array[], int size) 
{
    for (int i = 0; i < size - 1; i++) 
    {
        // 假设当前位置的元素为最小值
        int minIndex = i;

        // 在剩余的未排序部分中找到最小值的索引
        for (int j = i + 1; j < size; j++) 
        {
            if (array[j] > array[minIndex]) 
            {
                minIndex = j;
            }
        }

        // 将找到的最小值与当前位置交换
        swap(&array[i], &array[minIndex]);
    }
}

int main(void) 
{
    int array[] = {45, 56, 76, 234, 1, 34, 23, 2, 3};
    int arraySize = sizeof(array) / sizeof(array[0]);

    // 使用选择排序算法对数组进行降序排列
    selectionSort(array, arraySize);

    // 输出排序后的数组
    printf("降序排列后的数组：\n");
    for (int i = 0; i < arraySize; i++) 
    {
        printf("%d ", array[i]);
    }

    return 0;
}
