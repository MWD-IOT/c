#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int a[4] = {1,2,3,4};
//     int b[4] = {1, 2};
//     int c[4] = {1, 0};
//     int *p = a + 3;
//     printf("sizeof(a):%ld\n", sizeof(a));
//     printf("sizeof(b):%ld\n", sizeof(b));
//     printf("sizeof(c):%ld\n", sizeof(c));
    
//     printf("p[2]:%d\n", p[0]); 
int *ptr1 = &a+1;
// unsigned int *ptr1 = (unsigned int *)(&a+1);
    printf("&a:%p\n", &a);
    printf("ptr1:%p\n", ptr1);
    return 0;
}
// void count(int *a, int b)
// {
//     static int c = 0;
//     *a = ++c + *a + b;
//     printf("*a:%d\n", *a);
//     return;
// }

// int main(void)
// {
    // printf("sizeof(count):%ld\n", sizeof(count));
    // printf("sizeof(count):%zu\n", sizeof(count));
    // printf("sizeof(int):%ld\n", sizeof(int));
    // printf("sizeof(long):%ld\n", sizeof(long));
    // printf("sizeof(long):%ld\n", sizeof(long long));
    // char *str = NULL;
    // char arr[0];
    // printf("sizeof(arr):%ld\n", sizeof(arr));
    // int i, sum = 0;
    // str =(char *)malloc(16);
    // char a[] = "12345";
    // char b[] = {'1', '2', '3', '4', '5'};
    // printf("strlen(a)%d\n", strlen(a));
    // printf("strlen(b)%d\n", strlen(b));

    // memset(str, '0', 16);
    // strcpy(str, "12345678");
    // printf("str:%s\n", str);
    // printf("sizeof(str):%ld\n", sizeof(str));
    // for (i=0; i<sizeof(str); i++)
    // {
    //     count(&sum, str[i]-'0');
    // } 
    // printf("%d\n" ,sum);
//     return 0;
// }

