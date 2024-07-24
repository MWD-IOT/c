#include <stdio.h>
#include <stdlib.h>

typedef struct stuInfo
{	int id;
	char name[13];
	float score;
}StuType;
void inputInfo(StuType &s) //利用参数s,输入学生信息数据s的各项信息
{	printf("序号:"); scanf("%d",&s.id);
	printf("姓名:"); scanf("%s",&s.name);
	printf("成绩:"); scanf("%f",&s.score);	
}
void displayInfo(StuType s)//采用值参数s，显示学生信息数据s的各项信息
{	printf("%d %s %5.1f\n",s.id,s.name,s.score);
}
int main()
{	StuType *stus;//用于存储学生信息数据的动态数组名  
	int i, n;	
	printf("输入学生人数:"); scanf("%d",&n);
	stus= (StuType*)malloc(n*sizeof(StuType));//分配长度为n的动态数组空间
	if(!stus) return -2;
	for(i=0; i<n; i++)  inputInfo(stus[i]);//调用inputInfo函数，输入数据存于数组stus中
  			
	printf("%s %s %s\n","序号","姓名","成绩");
	for(i=0;i<n;i++)  displayInfo(stus[i]);
	//调用displayInfo函数，将数组stus中的学生信息输出		
	return 0;
}

