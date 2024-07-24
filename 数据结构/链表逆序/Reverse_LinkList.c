#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构
struct ListNode 
{
    int val;
    struct ListNode* next;
};

// 函数用于将链表逆序
struct ListNode* reverseLinkedList(struct ListNode* head) 
{
    struct ListNode* prev = NULL;
    struct ListNode* current = head;
    
    while (current != NULL) 
    {
        struct ListNode* nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    
    return prev;  // 新的头节点
}

// 函数用于创建一个新节点
struct ListNode* createNode(int val) 
{
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// 函数用于打印链表
void printLinkedList(struct ListNode* head) 
{
    struct ListNode* current = head;
    while (current != NULL) 
    {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}

int main() 
{
    // 创建一个简单的链表 1 -> 2 -> 3 -> 4 -> 5
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    
    printf("原始链表：\n");
    printLinkedList(head);
    
    // 调用函数进行逆序
    head = reverseLinkedList(head);
    
    printf("逆序后的链表：\n");
    printLinkedList(head);
    
    // 释放链表节点的内存
    while (head != NULL) 
    {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }
    
    return 0;
}