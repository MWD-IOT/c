#include <stdio.h>

#define MAX_TOWERS 50

typedef struct
{
    int length;    //��վ����
    int x;         //x����
    int y;         //y����
    int q;         //�ź�ǿ��
}tower_s;

tower_s towers[MAX_TOWERS];
#if 0
void find_best_tower(int towers, int radius)
{
    
}
#endif

int main(int argc, char *argv[])
{
    int i, towers_num, radius;
    scanf("%d,%d", &towers_num, &radius);
    for(i=0; i<towers_num; i++)
    {
        scanf("%d,%d,%d", &towers[i].x, &towers[i].y, &towers[i].q);
        printf("%d,%d,%d\n", towers[i].x, towers[i].y, towers[i].q);
    }
    
    return 0;
}

