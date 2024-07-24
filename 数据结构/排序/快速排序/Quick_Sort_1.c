#include <stdio.h>

// ��������Ԫ��
void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// ����Ԫ��
int partition(int array[], int low, int high) 
{
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) 
    {
        if (array[j] >= pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }

    swap(&array[i + 1], &array[high]);
    return i + 1;
}

// ��������
void quickSort(int array[], int low, int high) 
{
    if (low < high) 
    {
        // ����
        int pi = partition(array, low, high);

        // �ݹ�
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

int main(void) 
{
    int array[] = {45, 56, 76, 234, 1, 34, 23, 2, 3};
    int arraySize = sizeof(array) / sizeof(array[0]);

    quickSort(array, 0, arraySize - 1);

    printf("�������к�����飺\n");
    for (int i = 0; i < arraySize; i++) 
    {
        printf("%d ", array[i]);
    }

    return 0;
}


