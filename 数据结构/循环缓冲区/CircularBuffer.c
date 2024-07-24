#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 定义循环缓冲区结构
typedef struct 
{
    int* buffer;        // 缓冲区数组
    int capacity;       // 缓冲区容量
    int front;          // 头指针
    int rear;           // 尾指针
    int size;           // 当前元素数量
} CircularBuffer;

// 函数用于创建一个循环缓冲区
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

// 函数用于检查循环缓冲区是否为空
bool isEmpty(CircularBuffer* cb) 
{
    return cb->size == 0;
}

// 函数用于检查循环缓冲区是否已满
bool isFull(CircularBuffer* cb) 
{
    return cb->size == cb->capacity;
}

// 函数用于向循环缓冲区中添加元素
void enqueue(CircularBuffer* cb, int item) 
{
    if (isFull(cb)) 
    {
        printf("循环缓冲区已满，无法添加元素\n");
        return;
    }

    // 将元素添加到尾部，并更新尾指针和大小
    cb->buffer[cb->rear] = item;
    cb->rear = (cb->rear + 1) % cb->capacity;
    cb->size++;
}

// 函数用于从循环缓冲区中取出元素
int dequeue(CircularBuffer* cb) 
{
    if (isEmpty(cb)) 
    {
        printf("循环缓冲区为空，无法取出元素\n");
        return -1; // 返回一个默认值来表示错误
    }

    // 取出元素并更新头指针和大小
    int item = cb->buffer[cb->front];
    cb->front = (cb->front + 1) % cb->capacity;
    cb->size--;
    return item;
}

// 函数用于销毁循环缓冲区
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

    printf("取出元素: %d\n", dequeue(cb));
    printf("取出元素: %d\n", dequeue(cb));

    enqueue(cb, 4);
    enqueue(cb, 5);
    enqueue(cb, 6); // 缓冲区已满，将无法添加

    while (!isEmpty(cb)) 
    {
        printf("取出元素: %d\n", dequeue(cb));
    }

    destroyCircularBuffer(cb);

    return 0;
}

