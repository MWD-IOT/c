#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

// �������ڽ��ַ���ת��Ϊ����
int strToInteger(const char* str) 
{
    int result = 0;
    int sign = 1;
    int i = 0;

    // ����ո��ַ�
    while (str[i] == ' ') 
    {
        i++;
    }

    // ����������
    if (str[i] == '-') 
    {
        sign = -1;
        i++;
    } 
    else if (str[i] == '+') 
    {
        i++;
    }

    // ���ַ��������ֲ���
    while (str[i] >= '0' && str[i] <= '9') 
    {
        // ����Ƿ�����
        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && (str[i] - '0') > INT_MAX % 10)) 
        {
            return sign == 1 ? INT_MAX : INT_MIN;
        }

        // ��������ֵ
        result = result * 10 + (str[i] - '0');
        i++;
    }

    return result * sign;
}

int main() 
{
    const char* str1 = "42";
    const char* str2 = "   -123";
    const char* str3 = "12345678901234567890";  // ����������

    int result1 = strToInteger(str1);
    int result2 = strToInteger(str2);
    int result3 = strToInteger(str3);

    printf("���1: %d\n", result1);
    printf("���2: %d\n", result2);
    printf("���3: %d\n", result3);

    return 0;
}