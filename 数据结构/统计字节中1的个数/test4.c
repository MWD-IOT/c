#include <stdio.h>

// ��������ͳ��һ���ֽ����ж��ٸ�λ��1
int countSetBits(unsigned char byte) 
{
    int count = 0;
    
    // ��λ����ֽ��е�ÿһλ
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
    unsigned char byte = 0b11011011; // �����Ʊ�ʾ��11011010����5��λ��1
    
    int result = countSetBits(byte);
    
    printf("�ֽ� %02X ���� %d ��λ��1\n", byte, result);
    
    return 0;
}