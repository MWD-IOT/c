#include <stdio.h>
#include <stdlib.h>

// 二叉树节点的定义
struct TreeNode 
{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// 创建新的二叉树节点
struct TreeNode* createNode(int data) 
{
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 前序遍历
void preorderTraversal(struct TreeNode* root) 
{
    if (root == NULL)
        return;

    printf("%d ", root->data); // 访问根节点
    preorderTraversal(root->left); // 递归遍历左子树
    preorderTraversal(root->right); // 递归遍历右子树
}

// 中序遍历
void inorderTraversal(struct TreeNode* root) 
{
    if (root == NULL)
        return;

    inorderTraversal(root->left); // 递归遍历左子树
    printf("%d ", root->data); // 访问根节点
    inorderTraversal(root->right); // 递归遍历右子树
}

// 后序遍历
void postorderTraversal(struct TreeNode* root) 
{
    if (root == NULL)
        return;

    postorderTraversal(root->left); // 递归遍历左子树
    postorderTraversal(root->right); // 递归遍历右子树
    printf("%d ", root->data); // 访问根节点
}

int main() 
{
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("前序遍历结果: ");
    preorderTraversal(root);
    printf("\n");

    printf("中序遍历结果: ");
    inorderTraversal(root);
    printf("\n");

    printf("后序遍历结果: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}