#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char *str = "abcdefgh";
    strcpy(str, "ABCD");
    printf("str:%s\n", str);

    return 0;
}


