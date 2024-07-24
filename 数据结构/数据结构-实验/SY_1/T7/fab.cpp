#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void delay()
{	for(int i=0;i<2000;i++)
		for(int j=0;j<1000;j++);
}
double fab(int n)  //求斐波那契数列的第n项值的非递归算法
{ 	double f1=0,f2=1,f3=1;
	for(int i=3;i<=n;i++)
	{	delay();
		f1=f2; 
		f2=f3;
		f3=f1+f2;
	}	
	return f3;	
}

int main()
{	FILE *fp=fopen("fab.txt","w");		//注释1：文件用于存储不同问题规模的运行时间 
	for(int n=30;n<=72;n+=2)			//注释2
	{	clock_t start=clock();
		double f=fab(n);				//注释3：调用非递归函数
		clock_t finish=clock();
		printf("fac(%d)=%g\n",n,f);	
		long duration=finish-start;
		printf("runing time:%ldms\n",duration);
		fprintf(fp,"%ld  ",duration);		//将运行时间写入文件中
	}
	fclose(fp);
	return 0;	
}

