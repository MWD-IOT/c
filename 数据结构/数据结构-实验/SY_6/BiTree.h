//二叉树的二叉链表类型
typedef struct BiTNode 
{  TElemType data;                 //数据域
   struct BiTNode *LChild, *RChild;   //指向左右孩子的指针
}BiTNode, *BiTree; 
void inputTElem(TElemType &e);
Status isEmptyElem(TElemType e);
void createBiTree(BiTree &T) 
{  //按照先序次序输入二叉树中结点的值创建二叉树T
   TElemType e;
   inputTElem(e);      //读入元素e；其中inputTElem为树中元素的输入函数
   if(isEmptyElem(e))  //函数isEmptyElem(e)用来判断e是否为"代表空树"的特殊值
      T=NULL;       //创建空树
   else 
   {
      T=(BiTree)malloc(sizeof(BiTNode));  //申请一结点空间
      T->data= e;               // 生成根结点
      createBiTree(T->LChild);  // 先序创建左子树
      createBiTree(T->RChild);  // 先序创建右子树
   }
} 
void PreOrder(BiTree T, void (*visit)(TElemType &e)) 
{  //先序遍历二叉树T的递归算法
   if(T)
   {  visit(T->data);           // ①访问结点
      PreOrder(T->LChild, visit);  // ②遍历左子树
      PreOrder(T->RChild, visit);  // ③遍历右子树
   }
}

void InOrder(BiTree T, void(*visit)(TElemType & e))
{  //中序遍历二叉树T的递归算法
   if(T)
   {  InOrder(T->LChild, visit);
      visit(T->data);   
      InOrder(T->RChild, visit);  
   }
} 
void PostOrder(BiTree T, void (*visit)(TElemType & e))
{  //后序遍历二叉树T的递归算法
   if(T)
   {  PostOrder(T->LChild, visit);
      PostOrder(T->RChild, visit);
      visit(T->data);   
   }
} 
int countLeaf(BiTree T)
{  //统计二叉树T中叶子结点数目
   int countLeft, countRight;
   if(!T) return 0;          //若树空
   if(T->LChild==NULL&&T->RChild==NULL) return 1;  //若根为叶子结点
   countLeft=countLeaf(T->LChild);    //求左子树的叶子结点数
   countRight=countLeaf(T->RChild);   //求右子树的叶子结点数
   return countLeft+countRight;       //返回树中的叶子结点总数
} 
int nodesNum(BiTree T)
{  //统计二叉树T总结点数
   int numLeft, numRight;
   if(!T) return 0;          //若树空
   numLeft=nodesNum(T->LChild);    //求左子树的结点数
   numRight=nodesNum(T->RChild);   //求右子树的结点数
   return numLeft+numRight+1;     //返回总结点
} 
int depthBiTree(BiTree T )
{  //求二叉树T的深度
   int depthLeft, depthRight; 
   if ( !T )  return 0;     //若树空
   else 
   {
      depthLeft=depthBiTree(T->LChild );     //求左子树的深度
      depthRight=depthBiTree(T->RChild );    //求右子树的深度
      if(depthLeft>=depthRight) return depthLeft+1;   //若左子树的深度较大
      else return depthRight+1;   //若右子树的深度较大
   } 
}
Status equal(TElemType e1,TElemType e2); //函数声明：元素比较 
BiTNode* searchBiTree(BiTree T, TElemType e )
{  //查找元素值为e的元素，并返回其指针 
   if( !T )  return NULL;     //空树，返回空指针
   if(equal(T->data,e)) return T;
   BiTNode *p=searchBiTree(T->LChild,e);
   if(p) return p;
   p=searchBiTree(T->RChild,e);
   return p;   
}

typedef BiTree SElemType;
#include "SqStack.h"
void PreOrder_N(BiTree T,void (*visit)(TElemType &e)) 
{	BiTNode *p;    SqStack S;
	InitSqStack(S,100);
	Push(S, T);
	while(!stackIsEmpty(S) )
	{	while( getTop(S, p) &&p )
		{	visit( p->data);
			Push( S, p->LChild );
		}
		Pop(S, p);  //弹出NULL
		if(! stackIsEmpty(S) )
		{	Pop(S, p);  
			Push(S, p->RChild);  
		}           
	} 
}
void InOrder_N(BiTree T,void (*visit)(TElemType &e))
{	//利用顺序栈实现二叉树的中序非递归遍历算法
	SqStack S;
	BiTree p;
	InitSqStack(S,100); p=T; 			 //初始化指针栈S；p是游动遍历各个结点的指针
	while ( p || !stackIsEmpty(S) )		 //T为空并且栈空时循环结束
	{	if ( p ) { Push(S, p); p = p->LChild;}    //根指针进栈,遍历左子树
		else 
		{	Pop(S, p); //根指针退栈
			visit(p->data); //访问结点,遍历该结点右子树
			p=p->RChild;
		}
	} 
}
typedef BiTree QElemType;
#include "CirQueue.h"
void levelOrder(BiTree T,void (*visit)(TElemType &e)) 
{	CirQueue Q;
	BiTNode *p;
	InitCirQueue(Q, 100);
	if(T) insertQueue(Q,T);
	while(!queueIsEmpty(Q))
	{	deleteQueue(Q, p);
		visit(p->data);
		if( p->LChild ) insertQueue(Q, p->LChild);
		if( p->RChild ) insertQueue(Q, p->RChild);
	}
} 



