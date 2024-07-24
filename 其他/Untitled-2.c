#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
void GetMemeory(char **p) 
{
    *p = (char *)malloc(100);
    printf("p:%p\n", p);
    printf("*p:%p\n", *p);
    printf("**p:%p\n", **p);
}
 
void Test() 
{   
    char *str = NULL;
    GetMemeory(&str);
    printf("*str:%p\n", *str);
    printf("str:%p\n", str);
    printf("&str:%p\n", &str);
    // strcpy(str, "Thunder");
    // strcat(str + 2, "Downloader");
    // printf(str);
}
int main()
{
	Test();
	return 0;
}
