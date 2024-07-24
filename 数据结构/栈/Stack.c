#include <stdio.h>
#include <stdlib.h>

// 定义栈结构
struct Stack 
{
    int* data;
    int top;
    int capacity;
};

// 创建栈
struct Stack* createStack(int capacity) 
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->data = (int*)malloc(sizeof(int) * capacity);
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

// 判断栈是否为空
int isEmpty(struct Stack* stack) 
{
    return stack->top == -1;
}

// 判断栈是否满
int isFull(struct Stack* stack) 
{
    return stack->top == stack->capacity - 1;
}

// 压栈操作
void push(struct Stack* stack, int item) 
{
    if (isFull(stack)) 
    {
        printf("栈已满，无法压栈。\n");
        return;
    }
    stack->data[++stack->top] = item;
}

// 弹栈操作
int pop(struct Stack* stack) 
{
    if (isEmpty(stack)) 
    {
        printf("栈为空，无法弹栈。\n");
        return -1; // 表示栈为空的特殊值
    }
    return stack->data[stack->top--];
}

// 使用两个栈实现队列
struct QueueUsingStacks 
{
    struct Stack* stack1; // 用于入队
    struct Stack* stack2; // 用于出队
};

// 创建队列
struct QueueUsingStacks* createQueue() 
{
    struct QueueUsingStacks* queue = (struct QueueUsingStacks*)malloc(sizeof(struct QueueUsingStacks));
    queue->stack1 = createStack(100); // 假设栈的最大容量为100
    queue->stack2 = createStack(100);
    return queue;
}

// 入队操作
void enqueue(struct QueueUsingStacks* queue, int item) 
{
    while (!isEmpty(queue->stack2)) 
    {
        push(queue->stack1, pop(queue->stack2));
    }
    push(queue->stack1, item);
}

// 出队操作
int dequeue(struct QueueUsingStacks* queue) 
{
    while (!isEmpty(queue->stack1)) 
    {
        push(queue->stack2, pop(queue->stack1));
    }
    if (isEmpty(queue->stack2)) 
    {
        printf("队列为空，无法出队。\n");
        return -1; // 表示队列为空的特殊值
    }
    return pop(queue->stack2);
}

int main() 
{
    struct QueueUsingStacks* queue = createQueue();

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);

    printf("出队操作：%d\n", dequeue(queue));
    printf("出队操作：%d\n", dequeue(queue));

    enqueue(queue, 4);

    printf("出队操作：%d\n", dequeue(queue));
    printf("出队操作：%d\n", dequeue(queue));

    return 0;
}