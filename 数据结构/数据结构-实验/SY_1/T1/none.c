#include <stdio.h>
void swap( int a, int b)
{	int temp;
	temp=a; a=b; b=temp;
}
int main()
{	int a=12, b=34;
	swap(a, b);
	printf("a=%d,b=%d\n", a,b);
	return 0;
}

