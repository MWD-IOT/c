#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// ����ѭ���������ṹ
typedef struct 
{
    int* buffer;        // ����������
    int capacity;       // ����������
    int front;          // ͷָ��
    int rear;           // βָ��
    int size;           // ��ǰԪ������
} CircularBuffer;

// �������ڴ���һ��ѭ��������
CircularBuffer* createCircularBuffer(int capacity) 
{
    CircularBuffer* cb = (CircularBuffer*)malloc(sizeof(CircularBuffer));
    cb->buffer = (int*)malloc(sizeof(int) * capacity);
    cb->capacity = capacity;
    cb->front = 0;
    cb->rear = 0;
    cb->size = 0;
    return cb;
}

// �������ڼ��ѭ���������Ƿ�Ϊ��
bool isEmpty(CircularBuffer* cb) 
{
    return cb->size == 0;
}

// �������ڼ��ѭ���������Ƿ�����
bool isFull(CircularBuffer* cb) 
{
    return cb->size == cb->capacity;
}

// ����������ѭ�������������Ԫ��
void enqueue(CircularBuffer* cb, int item) 
{
    if (isFull(cb)) 
    {
        printf("ѭ���������������޷����Ԫ��\n");
        return;
    }

    // ��Ԫ����ӵ�β����������βָ��ʹ�С
    cb->buffer[cb->rear] = item;
    cb->rear = (cb->rear + 1) % cb->capacity;
    cb->size++;
}

// �������ڴ�ѭ����������ȡ��Ԫ��
int dequeue(CircularBuffer* cb) 
{
    if (isEmpty(cb)) 
    {
        printf("ѭ��������Ϊ�գ��޷�ȡ��Ԫ��\n");
        return -1; // ����һ��Ĭ��ֵ����ʾ����
    }

    // ȡ��Ԫ�ز�����ͷָ��ʹ�С
    int item = cb->buffer[cb->front];
    cb->front = (cb->front + 1) % cb->capacity;
    cb->size--;
    return item;
}

// ������������ѭ��������
void destroyCircularBuffer(CircularBuffer* cb) 
{
    free(cb->buffer);
    free(cb);
}

int main() 
{
    CircularBuffer* cb = createCircularBuffer(5);

    enqueue(cb, 1);
    enqueue(cb, 2);
    enqueue(cb, 3);

    printf("ȡ��Ԫ��: %d\n", dequeue(cb));
    printf("ȡ��Ԫ��: %d\n", dequeue(cb));

    enqueue(cb, 4);
    enqueue(cb, 5);
    enqueue(cb, 6); // ���������������޷����

    while (!isEmpty(cb)) 
    {
        printf("ȡ��Ԫ��: %d\n", dequeue(cb));
    }

    destroyCircularBuffer(cb);

    return 0;
}

