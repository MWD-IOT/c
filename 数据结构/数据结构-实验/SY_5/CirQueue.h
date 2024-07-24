typedef struct{
   QElemType *base;  //��ʾѭ�����д洢�ռ�Ķ�̬���飬���ռ���׵�ַ
   int front, rear;  //��ͷָ��frontָʾ��ͷԪ�ص��±�λ�ã���βָ��rearָʾ��һ�����λ��
   int queueSize;  //ѭ�����д洢�ռ��С
}CirQueue;  //ѭ����������

Status InitCirQueue(CirQueue &Q, int QSize){
   //����һ���ռ��СΪQSize�ĳ�ʼ�ն���Q
   Q.base=(QElemType *)malloc(QSize*sizeof(QElemType));
   if(!Q.base) return OVERFLOW;  //ջ�洢�ռ����ʧ��
   Q.queueSize=QSize;
   Q.front=Q.rear=0;   //��Ϊ�ն�
   return OK;  //��ʼ���ɹ�
}
Status queueIsEmpty(CirQueue Q) {
   //�ж�ѭ������Q�Ƿ�Ϊ��
   if(Q.front==Q.rear) return TRUE;  //����Ϊ��
   else return FALSE;  //���зǿ�
}
void clearQueue(CirQueue &Q){
   //��ѭ������Q���
   Q.front=Q.rear=0;
}
Status insertQueue(CirQueue &Q, QElemType e){
   //��ѭ������Q�Ķ�β�˲���Ԫ��e
   if((Q.rear+1)%Q.queueSize==Q.front) return OVERFLOW;  //���������пռ���������ʧ��
   Q.base[Q.rear]=e;  //����Ԫ��e
   Q.rear=(Q.rear+1)%Q.queueSize;  //��βָ�����һ��λ��
   return OK;  //��ӳɹ�
}
Status deleteQueue(CirQueue &Q, QElemType &e){
   //������Q�Ķ�ͷԪ�س��Ӳ���e������ֵ
   if(Q.front==Q.rear) return ERROR;  //�ӿ����������
   e=Q.base[Q.front];  //�ɲ���e���س���ͷԪ�ص�ֵ
   Q.front=(Q.front+1)%Q.queueSize;  //��ͷָ�����һ��λ��
   return OK;  //���ӳɹ�
}
Status getFront(CirQueue Q, QElemType &e){
   //ȡ����Q�Ķ�ͷԪ��ֵ
   if(Q.front==Q.rear) return ERROR;  //�ӿ����������
   e=Q.base[Q.front];
   return OK;  //ȡ��ͷ�����ɹ�
}
int queueLength(CirQueue Q){
   //��ѭ������Q�ĳ���
   return (Q.rear-Q.front+Q.queueSize)%Q.queueSize;  //���ضӳ�
}
void queueTraverse(CirQueue Q, void (*visit)(QElemType &e)){
     int i;
     for(i=Q.front; i!=Q.rear; i=(i+1)%Q.queueSize)
        visit(Q.base[i]);
}
