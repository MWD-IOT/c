#include <stdio.h>
#include <stdlib.h>

// ������нṹ
struct Queue 
{
    int* data;
    int front;
    int rear;
    int capacity;
};

// ��������
struct Queue* createQueue(int capacity) 
{
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->data = (int*)malloc(sizeof(int) * capacity);
    queue->front = -1;
    queue->rear = -1;
    queue->capacity = capacity;
    return queue;
}

// �ж϶����Ƿ�Ϊ��
int isEmpty(struct Queue* queue) 
{
    return queue->front == -1;
}

// �ж϶����Ƿ���
int isFull(struct Queue* queue) 
{
    return (queue->rear + 1) % queue->capacity == queue->front;
}

// ��Ӳ���
void enqueue(struct Queue* queue, int item) 
{
    if (isFull(queue)) 
    {
        printf("�����������޷���ӡ�\n");
        return;
    }
    if (isEmpty(queue)) 
    {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->data[queue->rear] = item;
}

// ���Ӳ���
int dequeue(struct Queue* queue) 
{
    if (isEmpty(queue)) 
    {
        printf("����Ϊ�գ��޷����ӡ�\n");
        return -1; // ��ʾ����Ϊ�յ�����ֵ
    }
    int item = queue->data[queue->front];
    if (queue->front == queue->rear) 
    {
        queue->front = -1;
        queue->rear = -1;
    } 
    else 
    {
        queue->front = (queue->front + 1) % queue->capacity;
    }
    return item;
}

// ʹ����������ʵ��ջ
struct StackUsingQueues 
{
    struct Queue* queue1; // ���ڴ洢ջ��Ԫ��
    struct Queue* queue2; // ���ڸ�������
};

// ����ջ
struct StackUsingQueues* createStack() 
{
    struct StackUsingQueues* stack = (struct StackUsingQueues*)malloc(sizeof(struct StackUsingQueues));
    stack->queue1 = createQueue(100); // ������е��������Ϊ100
    stack->queue2 = createQueue(100);
    return stack;
}

// ѹջ����
void push(struct StackUsingQueues* stack, int item) 
{
    enqueue(stack->queue2, item);
    while (!isEmpty(stack->queue1)) 
    {
        enqueue(stack->queue2, dequeue(stack->queue1));
    }
    struct Queue* temp = stack->queue1;
    stack->queue1 = stack->queue2;
    stack->queue2 = temp;
}

// ��ջ����
int pop(struct StackUsingQueues* stack) 
{
    if (isEmpty(stack->queue1)) 
    {
        printf("ջΪ�գ��޷���ջ��\n");
        return -1; // ��ʾջΪ�յ�����ֵ
    }
    return dequeue(stack->queue1);
}

int main() 
{
    struct StackUsingQueues* stack = createStack();

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);

    printf("��ջ������%d\n", pop(stack));
    printf("��ջ������%d\n", pop(stack));

    push(stack, 4);

    printf("��ջ������%d\n", pop(stack));
    printf("��ջ������%d\n", pop(stack));

    return 0;
}