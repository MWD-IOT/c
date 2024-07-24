#include <stdio.h>
#include <stdlib.h>
typedef struct PNode
{   float coef;
    int exp;
    struct PNode *next;
}PNode, *Poly;  //POLY为一元多项式的类型
void CreatPoly(Poly &L,int n) //一元多项式的创建操作，其中n为一元多项式的项数
{	float coef;
	int i,expn;
    Poly p,s;
    L=(Poly)malloc(sizeof(struct PNode));
    L->next=NULL;
    p=L;
    for(i=1;i<=n;i++)
    {	printf("input %dth coef:",i);
	    scanf("%f",&coef);
	    printf("input %dth expn:",i);
	    scanf("%d",&expn);	    
	    s=(Poly)malloc(sizeof(struct PNode));
	    s->coef=coef;s->exp=expn;
	    s->next=NULL;p->next=s;p=s;
    }
}
void OutputPoly(Poly  L) //一元多项式的输出操作
{  int flag=1;  //flag用来是否为第一项的标识
    Poly p;
    p=L->next;
    while(p)
    { 	if(flag) { printf("%.2fX^%d",p->coef,p->exp); flag=0; }
        else  printf("%+.2fX^%d",p->coef,p->exp);
        p=p->next;
    }
    printf("\n");
}
//一元多项式的相加运算；利用多项式A与B的结点空间，实现A=A+B
void PolyAdd(Poly &A, Poly &B)
{
	Poly pa=A->next, pb=B->next, rear=A, q;
	while(pa&&pb){
	    if(pa->exp<pb->exp){
	    	rear->next=pa; rear=pa; pa=pa->next;
	    }
	    else if(pa->exp>pb->exp) {
	    	rear->next=pb; rear=pb; pb=pb->next;
	    }
	    else {
	    	pa->coef+=pb->coef;
	    	if(pa->coef!=0.0) {
	    		rear->next=pa; rear=pa; pa=pa->next;
	    		q=pb; pb=pb->next; free(q);
	    	}
	    	else { 
	    		q=pa; pa=pa->next; free(q);
	    		q=pb; pb=pb->next; free(q);
	    	}
		}
	}
	if(pa) rear->next=pa;
	else rear->next=pb;
	free(B);
}
//一元多项式的相加运算；函数返回A-B结果 
Poly PolyDec(Poly A, Poly B)
{	PNode  *pa=A->next, *pb=B->next, *rear, *q;
	Poly C;
	C=(Poly)malloc(sizeof(PNode));
	rear=C; 
	while(pa&&pb)
	{   if(pa->exp<pb->exp)
		{  	q=(PNode*)malloc(sizeof(PNode));
			q->coef=pa->coef;
			q->exp=pa->exp;
			rear->next=q; rear=q; 
			pa=pa->next;
	    }
	    else if(pa->exp>pb->exp) 
		{  	q=(PNode*)malloc(sizeof(PNode));
			q->coef=-pb->coef;
			q->exp=pb->exp;
			rear->next=q; rear=q; 
			pb=pb->next;
	    }
	    else 
		{  	float x=pa->coef-pb->coef;
	    	if(x!=0.0) 
			{	q=(PNode*)malloc(sizeof(PNode));
				q->coef=x;
				q->exp=pa->exp;
				rear->next=q; rear=q; 								
	    	}
	    	pa=pa->next; pb=pb->next;	    	
		}
	}
	while(pa) 
	{	q=(PNode*)malloc(sizeof(PNode));
		q->coef=pa->coef;
		q->exp=pa->exp;
		rear->next=q; rear=q; 
		pa=pa->next;		
	}
	while(pb) 
	{	q=(PNode*)malloc(sizeof(PNode));
		q->coef=-pb->coef;
		q->exp=pb->exp;
		rear->next=q; rear=q; 
		pb=pb->next;		
	}
	rear->next=NULL;
	return C;
}

int main()
{  	Poly A,B,C;
    int n;
    printf("创建一元多项式 A:\n");
    printf("\t输入项数:");
    scanf("%d",&n);
    CreatPoly(A,n); printf("\nA(x)="); OutputPoly(A);
    printf("创建一元多项式 B:\n");
    printf("\t输入项数:");
    scanf("%d",&n);
    CreatPoly(B,n); printf("\nB(x)="); OutputPoly(B);
    C=PolyDec(A,B);
    printf("C(x)=A(x)-B(x)="); OutputPoly(C);
    PolyAdd(A,B);
    printf("A(x)=A(x)+B(x)="); OutputPoly(A);    
    return 0;
}
/*
5
7  0
-3 1
9  8
5 11
-2  17
6
8 1
22 7
-9 8
5 11
-4 20
5 24

*/














