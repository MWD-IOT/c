#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

// 函数用于将字符串转换为整数
int strToInteger(const char* str) 
{
    int result = 0;
    int sign = 1;
    int i = 0;

    // 处理空格字符
    while (str[i] == ' ') 
    {
        i++;
    }

    // 处理正负号
    if (str[i] == '-') 
    {
        sign = -1;
        i++;
    } 
    else if (str[i] == '+') 
    {
        i++;
    }

    // 逐字符处理数字部分
    while (str[i] >= '0' && str[i] <= '9') 
    {
        // 检查是否会溢出
        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && (str[i] - '0') > INT_MAX % 10)) 
        {
            return sign == 1 ? INT_MAX : INT_MIN;
        }

        // 构建整数值
        result = result * 10 + (str[i] - '0');
        i++;
    }

    return result * sign;
}

int main() 
{
    const char* str1 = "42";
    const char* str2 = "   -123";
    const char* str3 = "12345678901234567890";  // 这个将会溢出

    int result1 = strToInteger(str1);
    int result2 = strToInteger(str2);
    int result3 = strToInteger(str3);

    printf("结果1: %d\n", result1);
    printf("结果2: %d\n", result2);
    printf("结果3: %d\n", result3);

    return 0;
}