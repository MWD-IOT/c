#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void delay()  //延时函数
{	for(int i=0;i<2000;i++)
		for(int j=0;j<1000;j++);
}
int sum1(int n)  //求1~n的和
{	int s=0;
	for(int i=1;i<=n;i++)
	{	delay();	s+=i;	}
	return s;
}
int sum2(int n)  //求1~n的奇数和
{	int s=0;
	for(int i=1;i<=n;i+=2)
	{	delay();	s+=i;	}
	return s;
}
int sum3(int n)  //求1~n的和
{	delay();
	return n*(n+1)/2;
}
int main()
{	for(int n=100;n<=700;n+=100)
	{	clock_t start=clock();
		int s=sum3(n);
		clock_t finish=clock();
		printf("\nsum(%d)=%d\n",n,s);	
		long dur=finish-start;  //计算运行时间
		printf("runing time:%ldms\n",dur);
	}
	return 0;
}

