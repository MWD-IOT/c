#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <windows.h>
#include "Status.h"
typedef struct task
{
	int ord;
	//char taskName[21];
	int comeTime;
	int finishTime;
	int ducTime;
} task;
typedef task QElemType;
#include "CirQueue.h"
int main(){
    CirQueue Q;
    InitCirQueue(Q,100);
    int totalTime, runningTime=0;
    srand((unsigned)time(NULL));
    printf("设置任务接受截止时间(分钟)：");
	scanf("%d",&totalTime);
	int taskOrd=0;
	task curTask;
	int remainTime=0;
	while(1)
	{
		if(runningTime<totalTime)
		{
			int flag=rand()%4;
			if(flag==2)
			{
				task t1;
				taskOrd++;
				t1.ord=taskOrd;
				t1.comeTime=runningTime;
				t1.ducTime=rand()%10+1;
				t1.finishTime=0;
				insertQueue(Q,t1);
			}
			
		}
		if(remainTime==0&&!queueIsEmpty(Q))
		{	
			deleteQueue(Q,curTask);
			remainTime=curTask.ducTime;			
		}
		if(runningTime>totalTime&&remainTime==0&&queueIsEmpty(Q))
			break;
		runningTime+=1;
		Sleep(250);
		if(remainTime>0)
		{	remainTime--;
			if(remainTime==0) 
			{	curTask.finishTime=runningTime;
				//printInfoTask(curTask);
				printf("\n---------------------------\n");
				printf("Task %d is finished!\n",curTask.ord);
				printf("Come time:%d, ducTime:%d,Finish time:%d\n",
					curTask.comeTime,curTask.ducTime,curTask.finishTime);
				printf("---------------------------\n");
			}
		}			 
	}
	printf("All tasks is done! \n");     
    return 0;
}
