#include <stdio.h>

// ��������Ԫ�صĺ���
void swap(int* a, int* b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// ������������С�ڻ�׼ֵ��Ԫ�ط�����ߣ����ڻ�׼ֵ��Ԫ�ط����ұ�
int partition(int arr[], int low, int high)
{
    int pivot = arr[low]; // ѡ���һ��Ԫ����Ϊ��׼
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

    swap(&arr[low], &arr[j]); // ����׼Ԫ�ط�����ȷ��λ��
    return j; // ���ػ�׼Ԫ�ص�����
}

// ����������
void quick_sort(int arr[], int low, int high) 
{
    if (low < high) 
    {
        int pivot_index = partition(arr, low, high); // ��ȡ��׼Ԫ�ص�����
        quick_sort(arr, low, pivot_index - 1); // ������������п�������
        quick_sort(arr, pivot_index + 1, high); // ������������п�������
    }
}

int main() 
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("ԭʼ����: ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    quick_sort(arr, 0, n - 1);

    printf("����������: ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}