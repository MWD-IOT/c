#include <stdio.h>
#include <stdlib.h>
typedef struct StuNode  //学生链表的结点类型
{	int id;
	char name[13];
	float score;
	struct StuNode *next;   //指向后继结点的指针
} StuNode;  //学生链表的结点类型
int main()
{	StuNode *stuList=NULL,*p,*r;  //stuList为学生链表的头指针，非空时指向第一个结点
	int i, n;
	printf("输入学生人数:"); scanf("%d",&n);
	if(n<1) return 0;
	for(i=1;i<=n; i++)  //循环生成每个学生结点，并插入到链表尾端
	{	p= (StuNode*)malloc(sizeof(StuNode)); // 生成一个新的结点
		//输入每个学生结点的数据
		printf("序号：");  scanf("%d", &p->id); 
		printf("姓名：");  scanf("%s", p->name);
		printf("成绩：");  scanf("%f", &p->score);
		if(i==1)  stuList=p;	//p结点作为第一个结点
		else  r->next=p;  //p结点作为最后一个结点
 		r=p;		 //r始终指向当前最后一个结点
	}
	r->next=NULL; 
	printf("%6s %12s %6s\n","序号","姓名","成绩"); 
	p=stuList;	//p指向第一个结点
	while(p)  //当p非空时循环输出每一个结点p的数据值
	{	printf("%6d %12s %6.1f\n",p->id,p->name,p->score);
		p=p->next;  //指针后移
	}
	return 0;
}


