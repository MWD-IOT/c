
#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>

typedef int ElemenType;
typedef struct node{
	ElemenType data;
	struct node *next;
}stacknode, *linkstackptr;

typedef struct stack{
	linkstackptr top;		//栈顶指针 
	int count;				//计数器 
}Linkstack;

//判空
int stackempty(Linkstack S)
{ 
        if (S.count == 0)
                return 1;
        else
                return 0;
}

//入栈操作 
bool push(Linkstack *S, ElemenType e)		
{
	linkstackptr s = (linkstackptr)malloc(sizeof(stacknode));
	s -> data = e;
	s -> next = S -> top;		//把当前的栈顶赋值给新的元素的后继(指针的指向)
	S -> top = s;		//新的节点赋值给栈顶指针（即让新元素成为栈顶元素）
	S -> count++;
	return true; 
}

//出栈操作
int pop(Linkstack *s, ElemenType *e)		
{
	linkstackptr p;		//临时节点
	if(stackempty(*s))
		return 0;
	else
	{
		*e = s -> top -> data;
		p = s -> top;		//将栈顶指针交给p 
		s -> top = s -> top -> next;	//使得栈顶指针下移一位
		free(p);		//因为节点被删除，所以要释放临时节点		
		s -> count--;			//计数器减一个 
		return 1;
	}	
}

void visit(ElemenType p)
{
	printf("%d ", p);
}
bool traversestack(Linkstack s)
{
	linkstackptr p;
	p = s.top;
	while(p)
	{
		visit(p -> data);
		p = p -> next;
	}
	printf("\n");
	return true;
}

//构造一个空链栈
bool InitStack(Linkstack *S)
{ 
        S -> top = (linkstackptr)malloc(sizeof(stacknode));
        if(!S -> top)
                return false;
        S -> top = NULL;
        S -> count = 0;
        return true;
}

//清空栈
bool ClearStack(Linkstack *S)
{ 
        linkstackptr p,q;
        p = S -> top;
        while(p)
        {  
                q = p;
                p = p -> next;
                free(q);		//对每一个节点进行释放 
        } 
        S -> count = 0;
        return true;
}

//求栈长
int StackLength(Linkstack S)
{ 
        return S.count;
}

//返回栈顶元素
int GetTop(Linkstack S,ElemenType *e)
{
        if (S.top == NULL)
                return 0;
        else
                *e = S.top -> data;
        return 1;
}
int main()
{
        int j;
        Linkstack s;
        int e;
        if(InitStack(&s) == true)
                for(j = 1;j <= 10;j++)
                        push(&s,j);
        printf("栈中元素为：");
        traversestack(s);
        pop(&s,&e);
        printf("取出的栈顶元素：e=%d\n",e);
        printf("判空：%d(1：空 0：非空)\n",stackempty(s));
        GetTop(s,&e);
        printf("栈顶元素：e=%d\n栈的长度为：%d\n",e,StackLength(s));
        ClearStack(&s);
        printf("清空栈后，判空：%d(1:空 0:非空)\n",stackempty(s));
        return 0;
}
