#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAXSIZE 20
#define ARRAYNUM(array) (sizeof(array)/sizeof(array[0]))

/* ��ʼ������ */
void Init_array(int array[], int length)
{
    int i;

    srand(time(NULL));                                  /*!< ��ʱ�����Ϊ����������ӣ�ȷ��ÿ�����ɵ����������һ�� */
    for ( i = 0; i < length; i++ )                      /*!< �����鸳ֵ */
    {
        array[i] = rand() % MAXSIZE;                    /*!< ������������ҿ��������ֵ */
    }
}

/* ð������ */
void bubble_sort(int array[], int length)
{
    int i, tmp;

    while ( length-- )                         /*!< ÿ��length-1�������´α����������еĴ��� */
    {
        for ( i = 0; i < length; i++ )         /*!< ������������ */
        {
            if ( array[i] > array[i+1] )       /*!< ���ǰ�߱Ⱥ��ߴ��򽻻����ߵ�λ�� */
            {
                tmp = array[i+1];
                array[i+1] = array[i];
                array[i] = tmp;
            }
        }
    }
}

/* ѡ������ */
void selection_sort(int array[], int length)
{
    int i, j, minIndex, tmp;

    for ( i = 0; i < length - 1; i++ )          /*!< ������������ */
    {
        minIndex = i;                           /*!< ��Сֵ���� */
        for ( j = i + 1; j < length; j++ )      /*!< ����ʣ�µ��������� */
        {
            if ( array[j] < array[minIndex] )   /*!< �����ǰ��С����Сֵ */
            {
                minIndex = j;                   /*!< �򽫵�ǰֵ���±���Ϊ��Сֵ���� */
            }
        }
        tmp = array[i];                         /*!< ���������е����һ��ֵ����Сֵ����λ�� */
        array[i] = array[minIndex];
        array[minIndex] = tmp;
    }
}

/* �������� */
void insert_sort(int array[], int length)
{
    int i, j, tmp;

    for ( i = 1; i < length; i++ )                         /*!< ��Ϊ�����һ����Ϊ�������Դӵڶ�������ʼ */
    {
        tmp = array[i];                                    /*!< ȡ���±�Ϊi��������tmp�� */
        for ( j = i; j > 0 && array[j-1] > tmp; j-- )      /*!< ��tmpС����ǰһ���� */
        {
            array[j] = array[j-1];                         /*!< ��ǰһ��������һ��λ�� */
        }
        array[j] = tmp;                                    /*!< ��tmp���뵽�±�Ϊj��λ�� */
    }
}

/* ϣ������ */
void shell_sort(int array[], int length)
{
    int i, j, increment, tmp;

    for ( increment = length / 2; increment > 0; increment /= 2 )               /*!< ����������ÿ�γ�2��ֱ������1 */
    {
        for ( i = increment; i < length; i++ )                                  /*!< ����ÿ�������� */
        {
            tmp = array[i];                                                     /*!< ȡ����ǰ�����е���Ԫ����Ϊ��׼ */
            for ( j = i - increment; j >= 0 && tmp < array[j]; j -= increment ) /*!< �Ե�ǰ�����н��в������� */
            {
                array[j + increment] = array[j];                                 /*!< �����ڻ�׼ֵ��Ԫ�غ���һ������ */
            }
            array[j + increment] = tmp;                                          /*!< ��tmp���뵽��ȷ��λ�� */
        }
    }
}

/* �鲢���� */
/* (1) */
void merge(int array[], int L, int M, int R)
{
    int LEFT_SIZE = M - L + 1;
    int RIGHT_SIZE = R - M;
    int left[LEFT_SIZE];
    int right[RIGHT_SIZE];
    int i, j, k;                

    /* ������ */
    for ( i = L; i <= M; i++ )
    {
        left[i - L] = array[i];
    }
    /* ������ */
    for ( i = M + 1; i <= R; i++ )
    {
        right[i - M - 1] = array[i];
    }
    i = 0; j = 0; k = L;
    /* �ҳ�������������С��һ�������ŵ����������� */
    while ( i < LEFT_SIZE && j < RIGHT_SIZE )
    {
        array[k++] = left[i] < right[j] ? left[i++] : right[j++];
    }
    /* ����������л���ʣ��Ԫ�أ���ֱ�Ӹ��Ƶ����������ĩβ */
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

/* �������� */
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
        while ( array[j] >= pivot && i < j )    /*!< ��������������������������ֵ������ָ��С����ָ�� */
        {
            j--;                                /*!< ��ָ��ǰ��һ��λ�ã�ֱ������ֵ������ֵС��������ָ����ȣ��˳�ѭ�� */
        }
        while ( array[i] <= pivot && i < j )    /*!< ����������ұ���������������ֵС������ָ��С����ָ�� */
        {
            i++;                                /*!< ��ָ�����һ��λ�ã�ֱ������ֵ������ֵ�� ��������ָ����ȣ��˳�ѭ�� */
        }

        if ( i < j )                            /*!< ���˲���˵����������Ҫ����λ�õ�������ұ��б�����С��ֵ������б�������ֵ��*/
        {                                       /*!< ��������͸�ֵ��λ�� */
            tmp = array[i];                     
            array[i] = array[j];
            array[j] = tmp;
        }
    }
    array[begin] = array[i];                    /*!<  */
    array[i] = pivot;                           /*!< ������ֵ���ں��ʵ�λ�� */
    quick_soct(array, begin, i - 1);            /*!< �ݹ���ÿ������������������ */
    quick_soct(array, i + 1, end);              /*!< �ݹ���ÿ����������ұ������� */
}

/* ������ */
void swap(int *arr, int i, int j)  
{  
    int tmp;  
    tmp = arr[i];  
    arr[i] = arr[j];  
    arr[j] = tmp;  
}   
void heapify(int tree[], int n, int i) 
{
    // n ��ʾ���г��ȣ�i ��ʾ���ڵ��±�
    if (i >= n) return;
    // ����ӽڵ��±�
    int left = 2 * i + 1;
    // �Ҳ��ӽڵ��±�
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
    // �����һ���ڵ���±�
    int last_node = n - 1;
    // ���һ���ڵ��Ӧ�ĸ��ڵ��±�
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
        // ���Ѷ�Ԫ�������һ��Ԫ�ؽ���
        swap(tree, i, 0);
        // �����ɴ󶥶�
        heapify(tree, i, 0);
    }
}


/* �������� */
void counting_sort(int arr[], int n) 
{
    if (arr == NULL) return;
    // ���帨���ռ䲢��ʼ��
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
    // ����Ŀ������
    int R[n];
    // ͳ��ÿ��Ԫ�س��ֵĴ���
    for (i = 0; i < n; i++) C[arr[i] - min]++;
    // �Ը����ռ������ݽ��м���
    for (i = 1; i < r; i++) C[i] += C[i - 1];
    // �������Ŀ������
    for (i = n - 1; i >= 0; i--) R[--C[arr[i] - min]] = arr[i];
    // Ŀ��������Ľ�����¸�ֵ�� arr
    for (i = 0; i < n; i++) arr[i] = R[i];
}

/* �������� */
// ��������Χ0~9
#define RADIX 10

void radix_sort(int arr[], int n) 
{
    // ��ȡ���ֵ����Сֵ
    int max = arr[0], min = arr[0];
    int i, j, l;
    for (i = 1; i < n; i++) 
    {
        if (max < arr[i]) max = arr[i];
        if (min > arr[i]) min = arr[i];
    }
    // �����������и���������������һ��������ʹ����������ֵ�������
    if (min < 0) 
    {
        for (i = 0; i < n; i++) arr[i] -= min;
        max -= min;
    }
    // ��ȡ���ֵλ��
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
        // ��������
        for (j = 0; j < n; j++) {
            int key = arr[j] % (int)pow(RADIX, i + 1) / (int)pow(RADIX, i);
            queue[key][count[key]++] = arr[j];
        }
        // �ռ�����
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
    // �����������и������ռ�������ʱ�ټ�ȥǰ����ϵĳ���
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
    printf("����ǰ�����У�\n");
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

    printf("���������У�\n");
    for ( i = 0; i < arrnum; i++ )
    {
        printf("%d\n", array[i]);
    }
    // system("pause");
    return 0;
}