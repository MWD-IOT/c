#include <stdio.h>

// 函数用于统计一个字节中有多少个位是1
int countSetBits(unsigned char byte) 
{
    int count = 0;
    
    // 逐位检查字节中的每一位
    for (int i = 0; i < 8; i++) 
    {
        if (byte & (1 << i))
        {
            count++;
        }
    }    
    return count;
}

int main() 
{
    unsigned char byte = 0b11011011; // 二进制表示：11011010，有5个位是1
    
    int result = countSetBits(byte);
    
    printf("字节 %02X 中有 %d 个位是1\n", byte, result);
    
    return 0;
}