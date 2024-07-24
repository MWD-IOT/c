#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Status.h"
typedef struct{
   int id;              //编号
   int height;          //身高
   int refuse;          //男生的邀请被拒绝的连续次数或女生拒绝邀请的连续次数
   int totalRefuse;      //拒绝或被拒绝的总次数
   int finished;         //完成的跳舞次数
}stuType;             //学生信息类型
typedef int QElemType;  //队列中元素类型
#include "CirQueue.h"
CirQueue boyQ, girlQ, danceQ;          //分别为男生等待队列、女生等待队列、正在跳舞的队列
stuType *stu;                         //动态数组，存储所有学生信息
void partyStart(int boyNum, int girlNum){
   //舞会开始，生成boyNum个男生和girlNum个女生信息，并按顺序插入相应队列
   int i;
   time_t t; 
   stu=(stuType *)malloc((boyNum+girlNum)*sizeof(stuType));  
   InitCirQueue(boyQ, boyNum+1);                 //男生等待队列初始化
   InitCirQueue(girlQ, girlNum+1);                 //女生等待队列初始化
   InitCirQueue(danceQ, boyNum+girlNum+1);       //正在舞池跳舞的学生队列初始化
   srand((unsigned int)time(&t));                   //设置随机种子
   for(i=0; i<boyNum; i++){ 
      stu[i].id=i+1;
      stu[i].height=165+rand()%30;                //随机生成男生身高
      stu[i].refuse=stu[i].totalRefuse=0;
      stu[i].finished=0;
      insertQueue(boyQ, i);                       //将该男生入队列boyQ
   }
   for(i=boyNum; i<boyNum+girlNum; i++){  
      stu[i].id=i-boyNum+1;
      stu[i].height=160+rand()%25;                 //随机生成女生身高
      stu[i].refuse=stu[i].totalRefuse=0;
      stu[i].finished=0;
      insertQueue(girlQ,i);                        //将该女生（其下标位置）入队列girlQ
   }
}
void musicStart(int n){
   //第n支舞曲开始
   int boy, girl;
   int count=0;                                      //记录当前正在跳舞的舞伴对数
   printf("\nThe %dth music is playing.......\n\n", n);    
   while(!queueIsEmpty(boyQ)&&!queueIsEmpty(girlQ)){
      deleteQueue(boyQ, boy);                         //最前面的男生出队
      getFront(girlQ, girl);                             //获取排在最前面的女生
      if(stu[boy].height<stu[girl].height||stu[boy].height>stu[girl].height+25){
         //当boy与girl舞伴配对失败
         stu[boy].refuse++;  stu[boy].totalRefuse++;
         stu[girl].refuse++;  stu[girl].totalRefuse++;
         if(stu[boy].refuse<2)  insertQueue(boyQ, boy);   //男生仅连续1次被拒绝，重新排队
         else  printf("Boy %d left.\n", stu[boy].id);       //男生连续2次被拒绝，离开舞会
         if(stu[girl].refuse>=2) {
            //该女生连续2次以上拒绝邀请
            deleteQueue(girlQ, girl);  //出队
            if(stu[girl].refuse==2)  insertQueue(girlQ,girl);     //连续2次拒绝，重新排队
            else  printf("Girl %d left.\n", stu[girl].id);          //连续3次拒绝，离开舞会
         }                                  
      }
      else{
         //boy与girl舞伴配对成功，女生出队与男生进入舞池
         deleteQueue(girlQ, girl);  
         insertQueue(danceQ, boy); insertQueue(danceQ, girl);     //boy与girl入队danceQ
         printf("Boy %d and girl %d go to dance.\n", stu[boy].id,stu[girl].id);
         stu[boy].finished++; stu[girl].finished++;
         count++;  
         stu[boy].refuse=0; stu[girl].refuse=0;                 //连续被拒绝或拒绝次数清0
      }
   }
   printf("\n%d pairs are(is) dancing.\n", count);  
   printf("Music is stoped.\n");  
}                                                     
void musicEnd(){
   //音乐结束，正在跳舞的学生按进入舞池的顺序重新去排队等候
   int s1;
   while (!queueIsEmpty(danceQ)){
      deleteQueue(danceQ, s1); insertQueue(boyQ, s1);      //一对舞伴中男生重新排队
      deleteQueue(danceQ, s1); insertQueue(girlQ, s1);      //一对舞伴中女生重新排队
   }
}
void partyEnd(int boyNum, int girlNum){
   //舞会结束，统计优胜者
   int king, queen;
   int i, f1, r1;
   king=0;
   for (i=1;i<boyNum; i++){
      //求男生优胜者的finished值和totalRefuse值
      if(stu[i].finished>stu[king].finished) king=i;
      else if(stu[i].finished==stu[king].finished&&stu[i].totalRefuse<stu[king].totalRefuse)
             king=i;
   }
   f1=stu[king].finished; r1=stu[king].totalRefuse;
   printf("The best boy dancer(s)(finished=%d,totalRefuse=%d),they are:\n", f1, r1);
   for (i=0;i<boyNum; i++){
      //输出所有男生优胜者
       if(stu[i].finished==f1&&stu[i].totalRefuse==r1)  printf("boy %d  ", stu[i].id);
   }  
   printf("\n");  
   queen=boyNum;    
   for (i=boyNum+1;i<boyNum+girlNum; i++){
      //求女生优胜者的finished值和totalRefuse值
      if(stu[i].finished>stu[queen].finished) queen=i;
      else if(stu[i].finished==stu[queen].finished&&stu[i].totalRefuse<stu[queen].totalRefuse)
             queen=i;
   }
   f1=stu[queen].finished; r1=stu[queen].totalRefuse;
   printf("The best girl dancer(s)(finished=%d,totalRefuse=%d),they are:\n", f1, r1);
   for (i=boyNum;i<boyNum+girlNum; i++){
      //输出所有女生优胜者
      if(stu[i].finished==f1&&stu[i].totalRefuse==r1)  printf("girl %d  ", stu[i].id);
   } 
   printf("\n"); 
}  
int main(){
   int boyNum, girlNum, musicNum, i;
   printf("Input numbers of boys:"); scanf("%d", &boyNum);         //输入男生数
   printf("Input numbers of girls:"); scanf("%d", &girlNum);          //输入女生数
   printf("Input numbers of musics:"); scanf("%d", &musicNum);      //输入舞曲数
   partyStart(boyNum, girlNum);                                //舞会开始
   printf("Boys information(id,height):\n");
   for(i=0; i<boyNum; i++){                        //输出所有男生编号、身高信息
      printf("(%3d, %3d)  ", stu[i].id, stu[i].height);
      if((i+1)%6==0) printf("\n");
    }
    printf("\nGirls information(id,height):\n");
    for(i=1; i<=girlNum; i++){                      //输出所有女生编号、身高信息
       printf("(%3d, %3d)  ", stu[boyNum+i-1].id, stu[boyNum+i-1].height);
       if(i%6==0) printf("\n");
    }
    for(i=1; i<=musicNum; i++){                    //播放每只舞曲
       musicStart(i);  
       musicEnd();
       system("pause");
    }
    partyEnd(boyNum, girlNum);                    //舞会结束
    system("pause");
    return 0;
} 
