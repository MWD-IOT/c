//˳��ջ�����Ͷ��� 
#define StackIncrStep 20   //�洢�ռ������
typedef struct{
   SElemType *base;  //SElemTypeΪջ��Ԫ�����ͣ�baseΪ��ʾ˳��ջ�洢�ռ�Ķ�̬����
   int top;  //ָʾ��һ����ջ���±�λ��
   int stackSize;  //��ǰ˳��ջ�洢�ռ��С
}SqStack;  //SqStackΪ˳��ջ����
Status InitSqStack (SqStack &S, int InitSize){
   //����һ����ʼ�ռ��СΪInitSize�Ŀ�ջS
   S.base=(SElemType *)malloc(InitSize*sizeof(SElemType));
   if(!S.base) return OVERFLOW;  //ջ�洢�ռ����ʧ��
   S.stackSize=InitSize;
   S.top=0;   //��Ϊ��ջ
   return OK;  //��ʼ���ɹ�
}
Status stackIsEmpty(SqStack S) {
   //�ж�˳��ջS�Ƿ�Ϊ��
   if(!S.top) return TRUE;  //ջ��
   else return FALSE;  //ջ�ǿ�
}
void clearStack(SqStack &S){
   //��˳��ջS���
   S.top=0;
}
int stackLength(SqStack S){
   //��˳��ջS�ĳ���
   return S.top;
}
Status Push(SqStack &S, SElemType e){
   //����˳��ջS����Ԫ��e��ջ
   if(S.top==S.stackSize){
      //����ǰջ�Ŀռ�����
      S.base=(SElemType*)malloc((S.stackSize+StackIncrStep)*sizeof(SElemType));
      if(!S.base) return OVERFLOW;  //�洢�ռ����ʧ��
      S.stackSize+=StackIncrStep;
   }
   S.base[S.top]=e;  //����Ԫ��e
   S.top++;  //ջ��ָ��top����һ��λ��
   return OK;  //��ջ�ɹ�
}
Status Pop(SqStack &S, SElemType &e){
   //��˳��ջS��ջ��Ԫ�س�ջ
   if(!S.top) return ERROR;  //��ջ�գ�topֵΪ0��
   S.top--;  //ջ��ָ��top����һ��λ��
   e=S.base[S.top];  //�ɲ���e���س�ջԪ�ص�ֵ
   return OK;  //��ջ�ɹ�
}
Status getTop(SqStack S, SElemType &e){
   //ȡ˳��ջS��ջ��Ԫ��
   if(!S.top) return ERROR;  //��ջ��
   e=S.base[S.top-1];
   return OK;  //ȡջ�������ɹ�
}
void stackTraverse(SqStack S, void (*visit)(SElemType e)){
     int i;
     for (i=0; i<S.top; i++)
       visit(S.base[i]);
}
