#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAXSIZE 20
#define ARRAYNUM(array) (sizeof(array)/sizeof(array[0]))

/* 初始化数组 */
void Init_array(int array[], int length)
{
    int i;

    srand(time(NULL));                                  /*!< 用时间戳作为随机数的种子，确保每次生成的随机数都不一样 */
    for ( i = 0; i < length; i++ )                      /*!< 给数组赋值 */
    {
        array[i] = rand() % MAXSIZE;                    /*!< 产生随机数并且控制其最大值 */
    }
}

/* 冒泡排序 */
void bubble_sort(int array[], int length)
{
    int i, tmp;

    while ( length-- )                         /*!< 每次length-1，减少下次遍历无序序列的次数 */
    {
        for ( i = 0; i < length; i++ )         /*!< 遍历无序序列 */
        {
            if ( array[i] > array[i+1] )       /*!< 如果前者比后者大，则交互两者的位置 */
            {
                tmp = array[i+1];
                array[i+1] = array[i];
                array[i] = tmp;
            }
        }
    }
}

/* 选择排序 */
void selection_sort(int array[], int length)
{
    int i, j, minIndex, tmp;

    for ( i = 0; i < length - 1; i++ )          /*!< 遍历无序序列 */
    {
        minIndex = i;                           /*!< 最小值索引 */
        for ( j = i + 1; j < length; j++ )      /*!< 遍历剩下的无序序列 */
        {
            if ( array[j] < array[minIndex] )   /*!< 如果当前数小于最小值 */
            {
                minIndex = j;                   /*!< 则将当前值的下标设为最小值索引 */
            }
        }
        tmp = array[i];                         /*!< 将有序序列的最后一个值与最小值交换位置 */
        array[i] = array[minIndex];
        array[minIndex] = tmp;
    }
}

/* 插入排序 */
void insert_sort(int array[], int length)
{
    int i, j, tmp;

    for ( i = 1; i < length; i++ )                         /*!< 因为假设第一个数为有序，所以从第二个数开始 */
    {
        tmp = array[i];                                    /*!< 取出下标为i的数放在tmp中 */
        for ( j = i; j > 0 && array[j-1] > tmp; j-- )      /*!< 若tmp小于它前一个数 */
        {
            array[j] = array[j-1];                         /*!< 将前一个数后移一个位置 */
        }
        array[j] = tmp;                                    /*!< 将tmp插入到下标为j的位置 */
    }
}

/* 希尔排序 */
void shell_sort(int array[], int length)
{
    int i, j, increment, tmp;

    for ( increment = length / 2; increment > 0; increment /= 2 )               /*!< 控制增量，每次除2，直到等于1 */
    {
        for ( i = increment; i < length; i++ )                                  /*!< 遍历每个子序列 */
        {
            tmp = array[i];                                                     /*!< 取出当前子序列的首元素作为基准 */
            for ( j = i - increment; j >= 0 && tmp < array[j]; j -= increment ) /*!< 对当前子序列进行插入排序 */
            {
                array[j + increment] = array[j];                                 /*!< 将大于基准值的元素后移一个增量 */
            }
            array[j + increment] = tmp;                                          /*!< 将tmp插入到正确的位置 */
        }
    }
}

/* 归并排序 */
/* (1) */
void merge(int array[], int L, int M, int R)
{
    int LEFT_SIZE = M - L + 1;
    int RIGHT_SIZE = R - M;
    int left[LEFT_SIZE];
    int right[RIGHT_SIZE];
    int i, j, k;                

    /* 左序列 */
    for ( i = L; i <= M; i++ )
    {
        left[i - L] = array[i];
    }
    /* 右序列 */
    for ( i = M + 1; i <= R; i++ )
    {
        right[i - M - 1] = array[i];
    }
    i = 0; j = 0; k = L;
    /* 找出两个序列中最小的一个数，放到辅助数组中 */
    while ( i < LEFT_SIZE && j < RIGHT_SIZE )
    {
        array[k++] = left[i] < right[j] ? left[i++] : right[j++];
    }
    /* 如果子序列中还有剩余元素，则直接复制到辅助数组的末尾 */
    while ( i < LEFT_SIZE )
    {
        array[k++] = left[i++];
    }
    while ( j < RIGHT_SIZE )
    {
        array[k++] = right[j++];
    }
}
/* (2) */
void merge_sort(int array[], int L, int R)
{
    int M = (L + R) / 2;

    if ( L == R )
    {
        return;
    }
    
    merge_sort(array, L, M);
    merge_sort(array, M + 1, R);
    merge(array, L, M, R);
}

/* 快速排序 */
void quick_soct(int array[], int begin, int end)
{
    int i, j, tmp, pivot;
    if ( begin > end )
    {
        return;
    }
    pivot = array[begin];
    i = begin;
    j = end;

    while ( i != j )
    {
        while ( array[j] >= pivot && i < j )    /*!< 如果从右往左遍历的数都比枢轴值大并且左指针小于右指针 */
        {
            j--;                                /*!< 右指针前移一个位置，直到有数值比枢轴值小或者左右指针相等，退出循环 */
        }
        while ( array[i] <= pivot && i < j )    /*!< 如果从左往右遍历的数都比枢轴值小并且左指针小于右指针 */
        {
            i++;                                /*!< 左指针后移一个位置，直到有数值比枢轴值大 或者左右指针相等，退出循环 */
        }

        if ( i < j )                            /*!< 到此步，说明遇到了需要交换位置的情况：右边有比枢轴小的值（左边有比枢轴大的值）*/
        {                                       /*!< 交换枢轴和该值的位置 */
            tmp = array[i];                     
            array[i] = array[j];
            array[j] = tmp;
        }
    }
    array[begin] = array[i];                    /*!<  */
    array[i] = pivot;                           /*!< 将枢轴值放在合适的位置 */
    quick_soct(array, begin, i - 1);            /*!< 递归调用快速排序处理左边子序列 */
    quick_soct(array, i + 1, end);              /*!< 递归调用快速排序处理右边子序列 */
}

/* 堆排序 */
void swap(int *arr, int i, int j)  
{  
    int tmp;  
    tmp = arr[i];  
    arr[i] = arr[j];  
    arr[j] = tmp;  
}   
void heapify(int tree[], int n, int i) 
{
    // n 表示序列长度，i 表示父节点下标
    if (i >= n) return;
    // 左侧子节点下标
    int left = 2 * i + 1;
    // 右侧子节点下标
    int right = 2 * i + 2;
    int max = i;
    if (left < n && tree[left] > tree[max]) max = left;
    if (right < n && tree[right] > tree[max]) max = right;
    if (max != i) 
    {
        swap(tree, max, i);
        heapify(tree, n, max);
    }
}
void build_heap(int tree[], int n) 
{
    // 树最后一个节点的下标
    int last_node = n - 1;
    // 最后一个节点对应的父节点下标
    int parent = (last_node - 1) / 2;
    int i;
    for (i = parent; i >= 0; i--) 
    {
        heapify(tree, n, i);
    }
}
void heap_sort(int tree[], int n) 
{
    build_heap(tree, n);
    int i;
    for (i = n - 1; i >= 0; i--) 
    {
        // 将堆顶元素与最后一个元素交换
        swap(tree, i, 0);
        // 调整成大顶堆
        heapify(tree, i, 0);
    }
}


/* 计数排序 */
void counting_sort(int arr[], int n) 
{
    if (arr == NULL) return;
    // 定义辅助空间并初始化
    int max = arr[0], min = arr[0];
    int i;
    for (i = 1; i < n; i++) 
    {
        if (max < arr[i]) max = arr[i];
        if (min > arr[i]) min = arr[i];
    }
    int r = max - min + 1;
    int C[r];
    memset(C, 0, sizeof(C));
    // 定义目标数组
    int R[n];
    // 统计每个元素出现的次数
    for (i = 0; i < n; i++) C[arr[i] - min]++;
    // 对辅助空间内数据进行计算
    for (i = 1; i < r; i++) C[i] += C[i - 1];
    // 反向填充目标数组
    for (i = n - 1; i >= 0; i--) R[--C[arr[i] - min]] = arr[i];
    // 目标数组里的结果重新赋值给 arr
    for (i = 0; i < n; i++) arr[i] = R[i];
}

/* 基数排序 */
// 基数，范围0~9
#define RADIX 10

void radix_sort(int arr[], int n) 
{
    // 获取最大值和最小值
    int max = arr[0], min = arr[0];
    int i, j, l;
    for (i = 1; i < n; i++) 
    {
        if (max < arr[i]) max = arr[i];
        if (min > arr[i]) min = arr[i];
    }
    // 假如序列中有负数，所有数加上一个常数，使序列中所有值变成正数
    if (min < 0) 
    {
        for (i = 0; i < n; i++) arr[i] -= min;
        max -= min;
    }
    // 获取最大值位数
    int d = 0;
    while (max > 0) {
        max /= RADIX;
        d ++;
    }
    int queue[RADIX][n];
    memset(queue, 0, sizeof(queue));
    int count[RADIX] = {0};
    for (i = 0; i < d; i++) 
    {
        // 分配数据
        for (j = 0; j < n; j++) {
            int key = arr[j] % (int)pow(RADIX, i + 1) / (int)pow(RADIX, i);
            queue[key][count[key]++] = arr[j];
        }
        // 收集数据
        int c = 0;
        for (j = 0; j < RADIX; j++) {
            for (l = 0; l < count[j]; l++) 
            {
                arr[c++] = queue[j][l];
                queue[j][l] = 0;
            }
            count[j] = 0;
        }
    }
    // 假如序列中有负数，收集排序结果时再减去前面加上的常数
    if (min < 0) 
    {
        for (i = 0; i < n; i++) arr[i] += min;
    }
}


int main(void)
{
    int i;
    int arrnum;
    int array[MAXSIZE];
    
    arrnum = ARRAYNUM(array);
    Init_array(array, arrnum);
    printf("排序前的序列：\n");
    for ( i = 0; i < arrnum; i++ )
    {
        printf("%d\n", array[i]);
    }
    printf("\n-------------------------------\n");
    // bubble_sort(array, arrnum);
    // selection_sort(array, arrnum);
    // insert_sort(array, arrnum);
    // shell_sort(array, arrnum);
    // merge_sort(array, 0, arrnum - 1);
    // quick_soct(array, 0, arrnum - 1);

    printf("排序后的序列：\n");
    for ( i = 0; i < arrnum; i++ )
    {
        printf("%d\n", array[i]);
    }
    // system("pause");
    return 0;
}