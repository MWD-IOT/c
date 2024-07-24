typedef struct{
   QElemType *base;  //表示循环队列存储空间的动态数组，即空间的首地址
   int front, rear;  //队头指针front指示队头元素的下标位置；队尾指针rear指示下一次入队位置
   int queueSize;  //循环队列存储空间大小
}CirQueue;  //循环队列类型

Status InitCirQueue(CirQueue &Q, int QSize){
   //构造一个空间大小为QSize的初始空队列Q
   Q.base=(QElemType *)malloc(QSize*sizeof(QElemType));
   if(!Q.base) return OVERFLOW;  //栈存储空间分配失败
   Q.queueSize=QSize;
   Q.front=Q.rear=0;   //置为空队
   return OK;  //初始化成功
}
Status queueIsEmpty(CirQueue Q) {
   //判断循环队列Q是否为空
   if(Q.front==Q.rear) return TRUE;  //队列为空
   else return FALSE;  //队列非空
}
void clearQueue(CirQueue &Q){
   //将循环队列Q清空
   Q.front=Q.rear=0;
}
Status insertQueue(CirQueue &Q, QElemType e){
   //在循环队列Q的队尾端插入元素e
   if((Q.rear+1)%Q.queueSize==Q.front) return OVERFLOW;  //队满，队列空间溢出，入队失败
   Q.base[Q.rear]=e;  //插入元素e
   Q.rear=(Q.rear+1)%Q.queueSize;  //队尾指针后移一个位置
   return OK;  //入队成功
}
Status deleteQueue(CirQueue &Q, QElemType &e){
   //将队列Q的队头元素出队并由e返回其值
   if(Q.front==Q.rear) return ERROR;  //队空则操作出错
   e=Q.base[Q.front];  //由参数e返回出队头元素的值
   Q.front=(Q.front+1)%Q.queueSize;  //队头指针后移一个位置
   return OK;  //出队成功
}
Status getFront(CirQueue Q, QElemType &e){
   //取队列Q的队头元素值
   if(Q.front==Q.rear) return ERROR;  //队空则操作出错
   e=Q.base[Q.front];
   return OK;  //取队头操作成功
}
int queueLength(CirQueue Q){
   //求循环队列Q的长度
   return (Q.rear-Q.front+Q.queueSize)%Q.queueSize;  //返回队长
}
void queueTraverse(CirQueue Q, void (*visit)(QElemType &e)){
     int i;
     for(i=Q.front; i!=Q.rear; i=(i+1)%Q.queueSize)
        visit(Q.base[i]);
}
