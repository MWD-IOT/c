#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Status.h"
typedef struct{
   int id;              //���
   int height;          //���
   int refuse;          //���������뱻�ܾ�������������Ů���ܾ��������������
   int totalRefuse;      //�ܾ��򱻾ܾ����ܴ���
   int finished;         //��ɵ��������
}stuType;             //ѧ����Ϣ����
typedef int QElemType;  //������Ԫ������
#include "CirQueue.h"
CirQueue boyQ, girlQ, danceQ;          //�ֱ�Ϊ�����ȴ����С�Ů���ȴ����С���������Ķ���
stuType *stu;                         //��̬���飬�洢����ѧ����Ϣ
void partyStart(int boyNum, int girlNum){
   //��Ὺʼ������boyNum��������girlNum��Ů����Ϣ������˳�������Ӧ����
   int i;
   time_t t; 
   stu=(stuType *)malloc((boyNum+girlNum)*sizeof(stuType));  
   InitCirQueue(boyQ, boyNum+1);                 //�����ȴ����г�ʼ��
   InitCirQueue(girlQ, girlNum+1);                 //Ů���ȴ����г�ʼ��
   InitCirQueue(danceQ, boyNum+girlNum+1);       //������������ѧ�����г�ʼ��
   srand((unsigned int)time(&t));                   //�����������
   for(i=0; i<boyNum; i++){ 
      stu[i].id=i+1;
      stu[i].height=165+rand()%30;                //��������������
      stu[i].refuse=stu[i].totalRefuse=0;
      stu[i].finished=0;
      insertQueue(boyQ, i);                       //�������������boyQ
   }
   for(i=boyNum; i<boyNum+girlNum; i++){  
      stu[i].id=i-boyNum+1;
      stu[i].height=160+rand()%25;                 //�������Ů�����
      stu[i].refuse=stu[i].totalRefuse=0;
      stu[i].finished=0;
      insertQueue(girlQ,i);                        //����Ů�������±�λ�ã������girlQ
   }
}
void musicStart(int n){
   //��n֧������ʼ
   int boy, girl;
   int count=0;                                      //��¼��ǰ���������������
   printf("\nThe %dth music is playing.......\n\n", n);    
   while(!queueIsEmpty(boyQ)&&!queueIsEmpty(girlQ)){
      deleteQueue(boyQ, boy);                         //��ǰ�����������
      getFront(girlQ, girl);                             //��ȡ������ǰ���Ů��
      if(stu[boy].height<stu[girl].height||stu[boy].height>stu[girl].height+25){
         //��boy��girl������ʧ��
         stu[boy].refuse++;  stu[boy].totalRefuse++;
         stu[girl].refuse++;  stu[girl].totalRefuse++;
         if(stu[boy].refuse<2)  insertQueue(boyQ, boy);   //����������1�α��ܾ��������Ŷ�
         else  printf("Boy %d left.\n", stu[boy].id);       //��������2�α��ܾ����뿪���
         if(stu[girl].refuse>=2) {
            //��Ů������2�����Ͼܾ�����
            deleteQueue(girlQ, girl);  //����
            if(stu[girl].refuse==2)  insertQueue(girlQ,girl);     //����2�ξܾ��������Ŷ�
            else  printf("Girl %d left.\n", stu[girl].id);          //����3�ξܾ����뿪���
         }                                  
      }
      else{
         //boy��girl�����Գɹ���Ů�������������������
         deleteQueue(girlQ, girl);  
         insertQueue(danceQ, boy); insertQueue(danceQ, girl);     //boy��girl���danceQ
         printf("Boy %d and girl %d go to dance.\n", stu[boy].id,stu[girl].id);
         stu[boy].finished++; stu[girl].finished++;
         count++;  
         stu[boy].refuse=0; stu[girl].refuse=0;                 //�������ܾ���ܾ�������0
      }
   }
   printf("\n%d pairs are(is) dancing.\n", count);  
   printf("Music is stoped.\n");  
}                                                     
void musicEnd(){
   //���ֽ��������������ѧ����������ص�˳������ȥ�ŶӵȺ�
   int s1;
   while (!queueIsEmpty(danceQ)){
      deleteQueue(danceQ, s1); insertQueue(boyQ, s1);      //һ����������������Ŷ�
      deleteQueue(danceQ, s1); insertQueue(girlQ, s1);      //һ�������Ů�������Ŷ�
   }
}
void partyEnd(int boyNum, int girlNum){
   //��������ͳ����ʤ��
   int king, queen;
   int i, f1, r1;
   king=0;
   for (i=1;i<boyNum; i++){
      //��������ʤ�ߵ�finishedֵ��totalRefuseֵ
      if(stu[i].finished>stu[king].finished) king=i;
      else if(stu[i].finished==stu[king].finished&&stu[i].totalRefuse<stu[king].totalRefuse)
             king=i;
   }
   f1=stu[king].finished; r1=stu[king].totalRefuse;
   printf("The best boy dancer(s)(finished=%d,totalRefuse=%d),they are:\n", f1, r1);
   for (i=0;i<boyNum; i++){
      //�������������ʤ��
       if(stu[i].finished==f1&&stu[i].totalRefuse==r1)  printf("boy %d  ", stu[i].id);
   }  
   printf("\n");  
   queen=boyNum;    
   for (i=boyNum+1;i<boyNum+girlNum; i++){
      //��Ů����ʤ�ߵ�finishedֵ��totalRefuseֵ
      if(stu[i].finished>stu[queen].finished) queen=i;
      else if(stu[i].finished==stu[queen].finished&&stu[i].totalRefuse<stu[queen].totalRefuse)
             queen=i;
   }
   f1=stu[queen].finished; r1=stu[queen].totalRefuse;
   printf("The best girl dancer(s)(finished=%d,totalRefuse=%d),they are:\n", f1, r1);
   for (i=boyNum;i<boyNum+girlNum; i++){
      //�������Ů����ʤ��
      if(stu[i].finished==f1&&stu[i].totalRefuse==r1)  printf("girl %d  ", stu[i].id);
   } 
   printf("\n"); 
}  
int main(){
   int boyNum, girlNum, musicNum, i;
   printf("Input numbers of boys:"); scanf("%d", &boyNum);         //����������
   printf("Input numbers of girls:"); scanf("%d", &girlNum);          //����Ů����
   printf("Input numbers of musics:"); scanf("%d", &musicNum);      //����������
   partyStart(boyNum, girlNum);                                //��Ὺʼ
   printf("Boys information(id,height):\n");
   for(i=0; i<boyNum; i++){                        //�������������š������Ϣ
      printf("(%3d, %3d)  ", stu[i].id, stu[i].height);
      if((i+1)%6==0) printf("\n");
    }
    printf("\nGirls information(id,height):\n");
    for(i=1; i<=girlNum; i++){                      //�������Ů����š������Ϣ
       printf("(%3d, %3d)  ", stu[boyNum+i-1].id, stu[boyNum+i-1].height);
       if(i%6==0) printf("\n");
    }
    for(i=1; i<=musicNum; i++){                    //����ÿֻ����
       musicStart(i);  
       musicEnd();
       system("pause");
    }
    partyEnd(boyNum, girlNum);                    //������
    system("pause");
    return 0;
} 
