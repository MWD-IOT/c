#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void delay()
{	for(int i=0;i<2000;i++)
		for(int j=0;j<1000;j++);
}

double fabR(int n)  //��쳲��������еĵ�n��ֵ�ĵݹ��㷨
{	if(n==1||n==2) return  1;
	else return  fabR(n-2)+fabR(n-1);
}

int main()
{	FILE *fp=fopen("fabR.txt","w");		//ע��1���ļ����ڴ洢��ͬ�����ģ������ʱ�� 
	for(int n=30;n<=44;n+=2)			//ע��2
	{	clock_t start=clock();
		double f=fabR(n);				//ע��3�����÷ǵݹ麯��
		clock_t finish=clock();
		printf("fac(%d)=%g\n",n,f);	
		long duration=finish-start;
		printf("runing time:%ldms\n",duration);
		fprintf(fp,"%ld  ",duration);		//������ʱ��д���ļ���
	}
	fclose(fp);
	return 0;	
}

