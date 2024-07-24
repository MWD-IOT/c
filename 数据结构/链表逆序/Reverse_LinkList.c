#include <stdio.h>
#include <stdlib.h>

// ��������ڵ�ṹ
struct ListNode 
{
    int val;
    struct ListNode* next;
};

// �������ڽ���������
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
    
    return prev;  // �µ�ͷ�ڵ�
}

// �������ڴ���һ���½ڵ�
struct ListNode* createNode(int val) 
{
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// �������ڴ�ӡ����
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
    // ����һ���򵥵����� 1 -> 2 -> 3 -> 4 -> 5
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    
    printf("ԭʼ����\n");
    printLinkedList(head);
    
    // ���ú�����������
    head = reverseLinkedList(head);
    
    printf("����������\n");
    printLinkedList(head);
    
    // �ͷ�����ڵ���ڴ�
    while (head != NULL) 
    {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }
    
    return 0;
}