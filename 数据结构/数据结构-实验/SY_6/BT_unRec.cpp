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
    PreOrder_N(T,visit);	printf("\n");  
    printf("二叉树T的中序序列为："); 
    InOrder_N(T, visit);	printf("\n");
    printf("二叉树T的层次序列为："); 
    levelOrder(T, visit);	printf("\n");
}

/*输入举例

ABD##EG###C#FH###

*/    
