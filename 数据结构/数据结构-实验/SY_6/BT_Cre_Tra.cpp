#include <stdio.h>
#include <stdlib.h>
#include "Status.h"
typedef char TElemType;
#include "BiTree.h"
void inputTElem(TElemType &e)
{	scanf("%c",&e);
}
Status isEmptyElem(TElemType e)
{	if(e=='#') return TRUE;
	else return FALSE;
}
Status equal(TElemType e1,TElemType e2) //元素比较
{	if(e1==e2) return TRUE;
	else return FALSE; 
}
void visit(TElemType &e)
{	printf("%c",e);
}
int main()
{   BiTree T;
    printf("创建二叉树\n");
	printf("输入含有空树信息的先序序列:\n");
    createBiTree(T);
    printf("二叉树T的先序序列为："); 
    PreOrder(T,visit);	printf("\n");  
    printf("二叉树T的中序序列为："); 
    InOrder(T, visit);	printf("\n");
    printf("二叉树T的后序序列为："); 
    PostOrder(T, visit);	printf("\n");
    int n=nodesNum(T) ;
    printf("总结点数=%d\n",n);
    int n0=countLeaf(T);
    printf("叶子结点数=%d\n",n0);
    int k=depthBiTree(T);
    printf("深度=%d\n",k);
    char ch;
    fflush(stdin);
    printf("input ch:"); scanf("%c",&ch);
    BiTNode *p=searchBiTree(T,ch);
    if(p)
    {	if(p->LChild)	
			printf("%c的左孩子%c!\n",ch,p->LChild->data);
		else printf("%c无左孩子!\n",ch);
		if(p->RChild)	
			printf("%c的右孩子%c!\n",ch,p->RChild->data);
		else printf("%c无右孩子!\n",ch);
	}
	else printf("%c不存在!\n",ch); 
	    
    return 0;
}

/* 输入举例 

ABD##EG###C#FH###

*/    
