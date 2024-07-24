#include <stdio.h>

// �ݹ�汾�Ķ��ֲ���
int binary_search_recursive(int arr[], int low, int high, int target) 
{
    if (low <= high) 
    {
        int mid = low + (high - low) / 2;

        // ����м�Ԫ�ص���Ŀ��ֵ�������м�Ԫ�ص�����
        if (arr[mid] == target)
            return mid;

        // ����м�Ԫ�ش���Ŀ��ֵ������벿�ּ�������
        if (arr[mid] > target)
            return binary_search_recursive(arr, low, mid - 1, target);

        // ����м�Ԫ��С��Ŀ��ֵ�����Ұ벿�ּ�������
        return binary_search_recursive(arr, mid + 1, high, target);
    }

    // Ŀ��ֵ�����ڣ�����-1��ʾ����ʧ��
    return -1;
}

// �����汾�Ķ��ֲ���
int binary_search_iterative(int arr[], int n, int target) 
{
    int low = 0;
    int high = n - 1;

    while (low <= high) 
    {
        int mid = low + (high - low) / 2;

        // ����м�Ԫ�ص���Ŀ��ֵ�������м�Ԫ�ص�����
        if (arr[mid] == target)
            return mid;

        // ����м�Ԫ�ش���Ŀ��ֵ������벿�ּ�������
        if (arr[mid] > target)
            high = mid - 1;

        // ����м�Ԫ��С��Ŀ��ֵ�����Ұ벿�ּ�������
        else
            low = mid + 1;
    }

    // Ŀ��ֵ�����ڣ�����-1��ʾ����ʧ��
    return -1;
}

int main() 
{
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;

    int result_recursive = binary_search_recursive(arr, 0, n - 1, target);
    if (result_recursive != -1)
        printf("�ݹ�汾��Ŀ��ֵ %d ������ %d ���ҵ���\n", target, result_recursive);
    else
        printf("�ݹ�汾��Ŀ��ֵ %d δ�ҵ���\n", target);

    int result_iterative = binary_search_iterative(arr, n, target);
    if (result_iterative != -1)
        printf("�����汾��Ŀ��ֵ %d ������ %d ���ҵ���\n", target, result_iterative);
    else
        printf("�����汾��Ŀ��ֵ %d δ�ҵ���\n", target);

    return 0;
}