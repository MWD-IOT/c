#include <stdio.h>
#include <stdlib.h>

// �������ڵ�Ķ���
struct TreeNode 
{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// �����µĶ������ڵ�
struct TreeNode* createNode(int data) 
{
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// ǰ�����
void preorderTraversal(struct TreeNode* root) 
{
    if (root == NULL)
        return;

    printf("%d ", root->data); // ���ʸ��ڵ�
    preorderTraversal(root->left); // �ݹ����������
    preorderTraversal(root->right); // �ݹ����������
}

// �������
void inorderTraversal(struct TreeNode* root) 
{
    if (root == NULL)
        return;

    inorderTraversal(root->left); // �ݹ����������
    printf("%d ", root->data); // ���ʸ��ڵ�
    inorderTraversal(root->right); // �ݹ����������
}

// �������
void postorderTraversal(struct TreeNode* root) 
{
    if (root == NULL)
        return;

    postorderTraversal(root->left); // �ݹ����������
    postorderTraversal(root->right); // �ݹ����������
    printf("%d ", root->data); // ���ʸ��ڵ�
}

int main() 
{
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("ǰ��������: ");
    preorderTraversal(root);
    printf("\n");

    printf("����������: ");
    inorderTraversal(root);
    printf("\n");

    printf("����������: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}