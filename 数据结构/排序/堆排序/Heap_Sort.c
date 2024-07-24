#include <stdio.h>

// ��������Ԫ�صĺ���
void swap(int* a, int* b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// �ѻ������������鹹��������
void heapify(int arr[], int n, int i) 
{
    int largest = i; // ��ʼ�����ֵΪ���ڵ�
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // ������ӽڵ�ȸ��ڵ��
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // ������ӽڵ�ȸ��ڵ��
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // ������ֵ���Ǹ��ڵ㣬�򽻻����ǣ����ݹ�ضԽ�������������жѻ�����
    if (largest != i) 
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// ��������
void heap_sort(int arr[], int n) 
{
    // ����
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // �ӶѶ���ʼ����ȡ�����ֵ���ָ���
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

    printf("ԭʼ����: ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    heap_sort(arr, n);

    printf("����������: ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}