#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void delay()
{	for(int i=0;i<2000;i++)
		for(int j=0;j<1000;j++);
}
double fab(int n)  //��쳲��������еĵ�n��ֵ�ķǵݹ��㷨
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
{	FILE *fp=fopen("fab.txt","w");		//ע��1���ļ����ڴ洢��ͬ�����ģ������ʱ�� 
	for(int n=30;n<=72;n+=2)			//ע��2
	{	clock_t start=clock();
		double f=fab(n);				//ע��3�����÷ǵݹ麯��
		clock_t finish=clock();
		printf("fac(%d)=%g\n",n,f);	
		long duration=finish-start;
		printf("runing time:%ldms\n",duration);
		fprintf(fp,"%ld  ",duration);		//������ʱ��д���ļ���
	}
	fclose(fp);
	return 0;	
}

