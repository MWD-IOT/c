#include <stdio.h>
#include <string.h>

// 逆序字符串的函数
void reverse_string(char str[]) 
{
    int length = strlen(str);
    int start = 0;
    int end = length - 1;

    while (start < end) 
    {
        // 交换字符串的首尾字符
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        // 移动指针，继续交换下一对字符
        start++;
        end--;
    }
}

int main() 
{
    char str[] = "Hello, World!";
    
    printf("原始字符串: %s\n", str);
    
    // 调用逆序字符串的函数
    reverse_string(str);

    printf("逆序后的字符串: %s\n", str);

    return 0;
}