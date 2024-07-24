#include <stdio.h>
#include <stdlib.h>

/* ∑÷≈‰ƒ⁄¥Ê */
void AllocMem(int **ptr, int size)
{
    printf("*ptr:%p\n", *ptr);
    printf("ptr:%p\n", ptr);
    printf("&ptr:%p\n\n", &ptr);
    *ptr = (int *)malloc(size);
    printf("*ptr:%p\n", *ptr);
    printf("ptr:%p\n", ptr);
    printf("&ptr:%p\n\n", &ptr);
}

int main(int argc, char **argv)
{
    int size = 8;
    int *p = &size;

    printf("p:%p\n", p);
    printf("&p:%p\n\n", &p);
    AllocMem(&p, size);

    printf("p:%p\n", p);
    printf("&p:%p\n\n", &p);

    return 0;
}



