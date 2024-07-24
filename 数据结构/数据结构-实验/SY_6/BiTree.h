//�������Ķ�����������
typedef struct BiTNode 
{  TElemType data;                 //������
   struct BiTNode *LChild, *RChild;   //ָ�����Һ��ӵ�ָ��
}BiTNode, *BiTree; 
void inputTElem(TElemType &e);
Status isEmptyElem(TElemType e);
void createBiTree(BiTree &T) 
{  //���������������������н���ֵ����������T
   TElemType e;
   inputTElem(e);      //����Ԫ��e������inputTElemΪ����Ԫ�ص����뺯��
   if(isEmptyElem(e))  //����isEmptyElem(e)�����ж�e�Ƿ�Ϊ"�������"������ֵ
      T=NULL;       //��������
   else 
   {
      T=(BiTree)malloc(sizeof(BiTNode));  //����һ���ռ�
      T->data= e;               // ���ɸ����
      createBiTree(T->LChild);  // ���򴴽�������
      createBiTree(T->RChild);  // ���򴴽�������
   }
} 
void PreOrder(BiTree T, void (*visit)(TElemType &e)) 
{  //�������������T�ĵݹ��㷨
   if(T)
   {  visit(T->data);           // �ٷ��ʽ��
      PreOrder(T->LChild, visit);  // �ڱ���������
      PreOrder(T->RChild, visit);  // �۱���������
   }
}

void InOrder(BiTree T, void(*visit)(TElemType & e))
{  //�������������T�ĵݹ��㷨
   if(T)
   {  InOrder(T->LChild, visit);
      visit(T->data);   
      InOrder(T->RChild, visit);  
   }
} 
void PostOrder(BiTree T, void (*visit)(TElemType & e))
{  //�������������T�ĵݹ��㷨
   if(T)
   {  PostOrder(T->LChild, visit);
      PostOrder(T->RChild, visit);
      visit(T->data);   
   }
} 
int countLeaf(BiTree T)
{  //ͳ�ƶ�����T��Ҷ�ӽ����Ŀ
   int countLeft, countRight;
   if(!T) return 0;          //������
   if(T->LChild==NULL&&T->RChild==NULL) return 1;  //����ΪҶ�ӽ��
   countLeft=countLeaf(T->LChild);    //����������Ҷ�ӽ����
   countRight=countLeaf(T->RChild);   //����������Ҷ�ӽ����
   return countLeft+countRight;       //�������е�Ҷ�ӽ������
} 
int nodesNum(BiTree T)
{  //ͳ�ƶ�����T�ܽ����
   int numLeft, numRight;
   if(!T) return 0;          //������
   numLeft=nodesNum(T->LChild);    //���������Ľ����
   numRight=nodesNum(T->RChild);   //���������Ľ����
   return numLeft+numRight+1;     //�����ܽ��
} 
int depthBiTree(BiTree T )
{  //�������T�����
   int depthLeft, depthRight; 
   if ( !T )  return 0;     //������
   else 
   {
      depthLeft=depthBiTree(T->LChild );     //�������������
      depthRight=depthBiTree(T->RChild );    //�������������
      if(depthLeft>=depthRight) return depthLeft+1;   //������������Ƚϴ�
      else return depthRight+1;   //������������Ƚϴ�
   } 
}
Status equal(TElemType e1,TElemType e2); //����������Ԫ�رȽ� 
BiTNode* searchBiTree(BiTree T, TElemType e )
{  //����Ԫ��ֵΪe��Ԫ�أ���������ָ�� 
   if( !T )  return NULL;     //���������ؿ�ָ��
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
		Pop(S, p);  //����NULL
		if(! stackIsEmpty(S) )
		{	Pop(S, p);  
			Push(S, p->RChild);  
		}           
	} 
}
void InOrder_N(BiTree T,void (*visit)(TElemType &e))
{	//����˳��ջʵ�ֶ�����������ǵݹ�����㷨
	SqStack S;
	BiTree p;
	InitSqStack(S,100); p=T; 			 //��ʼ��ָ��ջS��p���ζ�������������ָ��
	while ( p || !stackIsEmpty(S) )		 //TΪ�ղ���ջ��ʱѭ������
	{	if ( p ) { Push(S, p); p = p->LChild;}    //��ָ���ջ,����������
		else 
		{	Pop(S, p); //��ָ����ջ
			visit(p->data); //���ʽ��,�����ý��������
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



