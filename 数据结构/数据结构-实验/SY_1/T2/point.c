#include <stdio.h>
void swap( int *pa, int *pb)
{	int temp;
	temp=*pa; *pa=*pb; *pb=temp;
}
int main()
{	int a=12, b=34;
	swap(&a, &b);
	printf("a=%d,b=%d\n", a,b);
	return 0;
}

