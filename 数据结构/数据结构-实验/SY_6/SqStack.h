//顺序栈的类型定义 
#define StackIncrStep 20   //存储空间的增量
typedef struct{
   SElemType *base;  //SElemType为栈中元素类型，base为表示顺序栈存储空间的动态数组
   int top;  //指示下一次入栈的下标位置
   int stackSize;  //当前顺序栈存储空间大小
}SqStack;  //SqStack为顺序栈类型
Status InitSqStack (SqStack &S, int InitSize){
   //构造一个初始空间大小为InitSize的空栈S
   S.base=(SElemType *)malloc(InitSize*sizeof(SElemType));
   if(!S.base) return OVERFLOW;  //栈存储空间分配失败
   S.stackSize=InitSize;
   S.top=0;   //置为空栈
   return OK;  //初始化成功
}
Status stackIsEmpty(SqStack S) {
   //判断顺序栈S是否为空
   if(!S.top) return TRUE;  //栈空
   else return FALSE;  //栈非空
}
void clearStack(SqStack &S){
   //将顺序栈S清空
   S.top=0;
}
int stackLength(SqStack S){
   //求顺序栈S的长度
   return S.top;
}
Status Push(SqStack &S, SElemType e){
   //对于顺序栈S，将元素e入栈
   if(S.top==S.stackSize){
      //若当前栈的空间已满
      S.base=(SElemType*)malloc((S.stackSize+StackIncrStep)*sizeof(SElemType));
      if(!S.base) return OVERFLOW;  //存储空间分配失败
      S.stackSize+=StackIncrStep;
   }
   S.base[S.top]=e;  //插入元素e
   S.top++;  //栈顶指针top上移一个位置
   return OK;  //入栈成功
}
Status Pop(SqStack &S, SElemType &e){
   //将顺序栈S的栈顶元素出栈
   if(!S.top) return ERROR;  //若栈空（top值为0）
   S.top--;  //栈顶指针top下移一个位置
   e=S.base[S.top];  //由参数e返回出栈元素的值
   return OK;  //出栈成功
}
Status getTop(SqStack S, SElemType &e){
   //取顺序栈S的栈顶元素
   if(!S.top) return ERROR;  //若栈空
   e=S.base[S.top-1];
   return OK;  //取栈顶操作成功
}
void stackTraverse(SqStack S, void (*visit)(SElemType e)){
     int i;
     for (i=0; i<S.top; i++)
       visit(S.base[i]);
}
