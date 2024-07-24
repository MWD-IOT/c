#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef int datatype; 
 
//定义结构体
typedef struct
{
	datatype data[MAXSIZE];
	int top;
} SqStack;

//建立顺序栈
SqStack *SET(SqStack *s)
{
	int i;
	s=(SqStack*)malloc(sizeof(SqStack));
	s->top=-1;
	printf("请输入顺序栈元素(以空格隔开，以0结束)：");
	scanf("%d",&i);
	do
	{
		s->top++;
		s->data[s->top]=i;
		scanf("%d",&i);
	}
	while(i!=0);
	printf("顺序栈建立成功！\n");
	return s;
}
//清空栈
void SETNULL(SqStack *s)
{
	s->top=-1;
}
//判断栈空
int Empty(SqStack *s)
{
	if(s->top>=0)
		return 0;
	else return 1;
}
 
//进栈
SqStack *Push(SqStack *s)
{
	int x;
	printf("输入要插入的元素：");
	scanf("%d",&x);
	if(s->top==MAXSIZE-1)
	{
		printf("OVERFLOW");
		return NULL;
	}
	else
	{
		s->top++;
		s->data[s->top]=x;
	}
	return s;
}
 
//退栈
SqStack *POP(SqStack *s)
{
	if(s->top<0)
	{
		printf("UNDERLOW");
		return s;
	}
	else
	{
		s->top--;
		printf("删除的栈顶元素是：");
		printf("%d\n",(s->data[s->top+1]));
	}
	return s;
}
 
//取栈顶
void TOP(SqStack *s)
{
	if(s->top<0)
	{
		printf("Stack is Empty");
	}
	else
	{
		printf("当前的栈顶元素是：");
		printf("%d\n",(s->data[s->top]));
	}
}
 
//输出栈
void print(SqStack *s)
{
	int i;
	if(s->top<0)
	{
		printf("清空栈成功！");
	}
	for(i=s->top; i>=0; i--)
		printf("%d ",s->data[i]);
}
 
//主函数
int main()
{
	SqStack *s;
	int i,j;
	printf("1.建立一个顺序栈\n");
	printf("2.输出栈\n");
	printf("3.进栈\n");
	printf("4.退栈\n");
	printf("5.取栈顶元素\n");
	printf("6.清空\n");
	printf("7.判空\n");
	printf("8.结束程序\n");
	do
	{
		printf("\n请选择功能：");
		scanf("%d",&i);
		switch(i)
		{
			case 1:
				s=SET(s);
				break;
			case 2:
				print(s);
				printf("\n");
				break;
			case 3:
				s=Push(s);
				print(s);
				printf("\n");
				break;
			case 4:
				s=POP(s);
				print(s);
				printf("\n");
				break;
			case 5:
				TOP(s);
				break;
			case 6:
				SETNULL(s);
				print(s);
				printf("\n");
				break;
			case 7:
				j=Empty(s);
				if(j==1)
					printf("空栈\n");
				else
					printf("非空栈\n");
				break;
			case 8:
				exit (0);
		}
	}
	while(1);
	return 0;
}