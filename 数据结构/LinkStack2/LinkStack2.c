#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
//1.定义数据类型
typedef int ElemType;
//2.定义链栈结构体
typedef struct LinkStackNode
{
    ElemType data;//存数据
    struct LinkStackNode *next;//存下个节点的地址
} LinkStack;
//3.初始化链栈
int initLinkStack(LinkStack *L)
{
    L = (LinkStack *) malloc(sizeof(LinkStack));//申请内存
    if(!L->data) return 0;//申请失败
    L->data = 0;//初始化链栈头结点数据域
    L->next = NULL;//初始化链栈头结点指针域
    return 1;
}
//4.入栈
int push(LinkStack *L, ElemType e)
{
    LinkStack *n;//新节点
    n = (LinkStack *) malloc(sizeof(LinkStack));
    if(!n->data) return 0;
    n->data = e;//存入数据
    n->next = L->next;//链栈栈顶元素链入新节点，新节点变成栈顶
    L->next = n;//新节点链入链栈头结点末尾
    return 1;
}
//5.出栈
int pop(LinkStack *L, ElemType *e)
{
    if(!L->next) return 0;//栈空，返回0
    LinkStack *d = L->next;//出栈指针指向栈顶
    *e = d->data;//赋值
    L->next = d->next;//头结点跳过出栈节点，链入出栈节点的下一节点
    free(d);//释放内存
    return 1;
}
//6.取栈顶
int getTop(LinkStack *L, ElemType *e)
{
    if(!L->next) return 0;
    *e = L->next->data;
    return 1;
}
void printStack(LinkStack *L)
{
    LinkStack *p = L;//遍历指针
    while (p)
    {
        p = p->next;
        printf("%d ", p->data);
    }
    printf("\n");
}
//7.演示
int main()
{
    LinkStack L;
    initLinkStack(&L);
    ElemType e;
    printf("入栈元素：");
    scanf("%d", &e);
    push(&L, e);
    getTop(&L, &e);
    printf("栈顶元素：%d\n",e);
    pop(&L, &e);
    printf("出栈元素：%d", e);
    printf("\n入栈元素(Ctrl + C结束)：");
    while (scanf("%d", &e) != EOF)
    {
        push(&L, e);
        printf("入栈元素(Ctrl + C结束)：");
    }
    printf("\n遍历元素：");
    printStack(&L);
    return 0;
}
