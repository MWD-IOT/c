#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// ������нṹ
typedef struct 
{
    int* data;         // �洢����Ԫ�ص�����
    int capacity;      // ��������
    int front;         // ����ͷָ��
    int rear;          // ����βָ��
    int size;          // ��ǰԪ������
} Queue;

// �������ڴ���һ������
Queue* createQueue(int capacity) 
{
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->data = (int*)malloc(sizeof(int) * capacity);
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = -1; // ��ʼ������βָ��Ϊ-1����ʾ����Ϊ��
    queue->size = 0;
    return queue;
}

// �������ڼ������Ƿ�Ϊ��
bool isEmpty(Queue* queue) 
{
    return queue->size == 0;
}

// �������ڼ������Ƿ�����
bool isFull(Queue* queue) 
{
    return queue->size == queue->capacity;
}

// �������ڽ�Ԫ�����
void enqueue(Queue* queue, int item) 
{
    if (isFull(queue)) 
    {
        printf("�����������޷����\n");
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->data[queue->rear] = item;
    queue->size++;
}

// �������ڴӶ����г���Ԫ��
int dequeue(Queue* queue) 
{
    if (isEmpty(queue)) 
    {
        printf("����Ϊ�գ��޷�����\n");
        return -1; // ����һ��Ĭ��ֵ����ʾ����
    }
    int item = queue->data[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

// �������ڻ�ȡ����ͷԪ�ص�������
int peek(Queue* queue) 
{
    if (isEmpty(queue)) 
    {
        printf("����Ϊ�գ��޷���ȡͷԪ��\n");
        return -1; // ����һ��Ĭ��ֵ����ʾ����
    }
    return queue->data[queue->front];
}

// �����������ٶ���
void destroyQueue(Queue* queue) 
{
    free(queue->data);
    free(queue);
}

int main() 
{
    Queue* queue = createQueue(5);

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);

    printf("����ͷԪ��: %d\n", peek(queue));

    dequeue(queue);
    dequeue(queue);

    enqueue(queue, 4);
    enqueue(queue, 5);
    enqueue(queue, 6); // �������������޷����

    while (!isEmpty(queue)) 
    {
        printf("����Ԫ��: %d\n", dequeue(queue));
    }

    destroyQueue(queue);

    return 0;
}
