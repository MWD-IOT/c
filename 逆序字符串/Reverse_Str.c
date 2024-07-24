#include <stdio.h>
#include <string.h>

// �����ַ����ĺ���
void reverse_string(char str[]) 
{
    int length = strlen(str);
    int start = 0;
    int end = length - 1;

    while (start < end) 
    {
        // �����ַ�������β�ַ�
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        // �ƶ�ָ�룬����������һ���ַ�
        start++;
        end--;
    }
}

int main() 
{
    char str[] = "Hello, World!";
    
    printf("ԭʼ�ַ���: %s\n", str);
    
    // ���������ַ����ĺ���
    reverse_string(str);

    printf("�������ַ���: %s\n", str);

    return 0;
}