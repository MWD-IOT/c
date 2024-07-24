#include <stdio.h>
#include <math.h>
double p;
double s;
void TriArea(double &a,double &b,double &c)
{
    if((a+b>c)&&(a+c>b)&&(b+c>a))
    {
		p=(a+b+c)/2;
		s=sqrt(p*(p-a)*(p-b)*(p-c));
		printf("面积为：""%lf",s);
	}
	else
		printf("无法构成三角形");
}
int main()
{
	double a,b,c;
	
    printf("请输入三条边：");
	scanf("%lf%lf%lf",&a,&b,&c);
    TriArea(a,b,c);
	
	return 0;
}