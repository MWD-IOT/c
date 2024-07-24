#include <stdio.h>
#include <stdlib.h>

// 定义队列结构
struct Queue 
{
    int* data;
    int front;
    int rear;
    int capacity;
};

// 创建队列
struct Queue* createQueue(int capacity) 
{
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->data = (int*)malloc(sizeof(int) * capacity);
    queue->front = -1;
    queue->rear = -1;
    queue->capacity = capacity;
    return queue;
}

// 判断队列是否为空
int isEmpty(struct Queue* queue) 
{
    return queue->front == -1;
}

// 判断队列是否满
int isFull(struct Queue* queue) 
{
    return (queue->rear + 1) % queue->capacity == queue->front;
}

// 入队操作
void enqueue(struct Queue* queue, int item) 
{
    if (isFull(queue)) 
    {
        printf("队列已满，无法入队。\n");
        return;
    }
    if (isEmpty(queue)) 
    {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->data[queue->rear] = item;
}

// 出队操作
int dequeue(struct Queue* queue) 
{
    if (isEmpty(queue)) 
    {
        printf("队列为空，无法出队。\n");
        return -1; // 表示队列为空的特殊值
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

// 使用两个队列实现栈
struct StackUsingQueues 
{
    struct Queue* queue1; // 用于存储栈的元素
    struct Queue* queue2; // 用于辅助操作
};

// 创建栈
struct StackUsingQueues* createStack() 
{
    struct StackUsingQueues* stack = (struct StackUsingQueues*)malloc(sizeof(struct StackUsingQueues));
    stack->queue1 = createQueue(100); // 假设队列的最大容量为100
    stack->queue2 = createQueue(100);
    return stack;
}

// 压栈操作
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

// 弹栈操作
int pop(struct StackUsingQueues* stack) 
{
    if (isEmpty(stack->queue1)) 
    {
        printf("栈为空，无法弹栈。\n");
        return -1; // 表示栈为空的特殊值
    }
    return dequeue(stack->queue1);
}

int main() 
{
    struct StackUsingQueues* stack = createStack();

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);

    printf("弹栈操作：%d\n", pop(stack));
    printf("弹栈操作：%d\n", pop(stack));

    push(stack, 4);

    printf("弹栈操作：%d\n", pop(stack));
    printf("弹栈操作：%d\n", pop(stack));

    return 0;
}