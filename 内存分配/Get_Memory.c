#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
void GetMemeory(char **p) {
    *p = (char *)malloc(100);
}
 
void Test() {   
    char *str = NULL;
    GetMemeory(&str);
    strcpy(str, "Thunder");
    strcat(str + 2, "Downloader");
    printf(str);
}
int main()
{
	Test();
	return 0;
}
