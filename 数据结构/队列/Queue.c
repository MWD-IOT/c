#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 定义队列结构
typedef struct 
{
    int* data;         // 存储队列元素的数组
    int capacity;      // 队列容量
    int front;         // 队列头指针
    int rear;          // 队列尾指针
    int size;          // 当前元素数量
} Queue;

// 函数用于创建一个队列
Queue* createQueue(int capacity) 
{
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->data = (int*)malloc(sizeof(int) * capacity);
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = -1; // 初始化队列尾指针为-1，表示队列为空
    queue->size = 0;
    return queue;
}

// 函数用于检查队列是否为空
bool isEmpty(Queue* queue) 
{
    return queue->size == 0;
}

// 函数用于检查队列是否已满
bool isFull(Queue* queue) 
{
    return queue->size == queue->capacity;
}

// 函数用于将元素入队
void enqueue(Queue* queue, int item) 
{
    if (isFull(queue)) 
    {
        printf("队列已满，无法入队\n");
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->data[queue->rear] = item;
    queue->size++;
}

// 函数用于从队列中出队元素
int dequeue(Queue* queue) 
{
    if (isEmpty(queue)) 
    {
        printf("队列为空，无法出队\n");
        return -1; // 返回一个默认值来表示错误
    }
    int item = queue->data[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

// 函数用于获取队列头元素但不出队
int peek(Queue* queue) 
{
    if (isEmpty(queue)) 
    {
        printf("队列为空，无法获取头元素\n");
        return -1; // 返回一个默认值来表示错误
    }
    return queue->data[queue->front];
}

// 函数用于销毁队列
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

    printf("队列头元素: %d\n", peek(queue));

    dequeue(queue);
    dequeue(queue);

    enqueue(queue, 4);
    enqueue(queue, 5);
    enqueue(queue, 6); // 队列已满，将无法入队

    while (!isEmpty(queue)) 
    {
        printf("出队元素: %d\n", dequeue(queue));
    }

    destroyQueue(queue);

    return 0;
}
