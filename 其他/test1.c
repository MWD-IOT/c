#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define sum(num1, num2) num1 + num2

int main(void)
{
    //printf("sum:%d\n", sum(sum(2, 5), sum(4, 10)) * sum(2, 3));
    int a = 320;
    char *ptr;

    ptr = (char *)&a;
    printf("%d\n", *ptr);

    return 0;

}