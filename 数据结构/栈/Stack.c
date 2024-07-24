#include <stdio.h>
#include <stdlib.h>

// ����ջ�ṹ
struct Stack 
{
    int* data;
    int top;
    int capacity;
};

// ����ջ
struct Stack* createStack(int capacity) 
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->data = (int*)malloc(sizeof(int) * capacity);
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

// �ж�ջ�Ƿ�Ϊ��
int isEmpty(struct Stack* stack) 
{
    return stack->top == -1;
}

// �ж�ջ�Ƿ���
int isFull(struct Stack* stack) 
{
    return stack->top == stack->capacity - 1;
}

// ѹջ����
void push(struct Stack* stack, int item) 
{
    if (isFull(stack)) 
    {
        printf("ջ�������޷�ѹջ��\n");
        return;
    }
    stack->data[++stack->top] = item;
}

// ��ջ����
int pop(struct Stack* stack) 
{
    if (isEmpty(stack)) 
    {
        printf("ջΪ�գ��޷���ջ��\n");
        return -1; // ��ʾջΪ�յ�����ֵ
    }
    return stack->data[stack->top--];
}

// ʹ������ջʵ�ֶ���
struct QueueUsingStacks 
{
    struct Stack* stack1; // �������
    struct Stack* stack2; // ���ڳ���
};

// ��������
struct QueueUsingStacks* createQueue() 
{
    struct QueueUsingStacks* queue = (struct QueueUsingStacks*)malloc(sizeof(struct QueueUsingStacks));
    queue->stack1 = createStack(100); // ����ջ���������Ϊ100
    queue->stack2 = createStack(100);
    return queue;
}

// ��Ӳ���
void enqueue(struct QueueUsingStacks* queue, int item) 
{
    while (!isEmpty(queue->stack2)) 
    {
        push(queue->stack1, pop(queue->stack2));
    }
    push(queue->stack1, item);
}

// ���Ӳ���
int dequeue(struct QueueUsingStacks* queue) 
{
    while (!isEmpty(queue->stack1)) 
    {
        push(queue->stack2, pop(queue->stack1));
    }
    if (isEmpty(queue->stack2)) 
    {
        printf("����Ϊ�գ��޷����ӡ�\n");
        return -1; // ��ʾ����Ϊ�յ�����ֵ
    }
    return pop(queue->stack2);
}

int main() 
{
    struct QueueUsingStacks* queue = createQueue();

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);

    printf("���Ӳ�����%d\n", dequeue(queue));
    printf("���Ӳ�����%d\n", dequeue(queue));

    enqueue(queue, 4);

    printf("���Ӳ�����%d\n", dequeue(queue));
    printf("���Ӳ�����%d\n", dequeue(queue));

    return 0;
}