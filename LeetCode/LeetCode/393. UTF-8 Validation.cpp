#include "���.h"
class Solution
{
public:
    bool validUtf8(vector<int>& data)
    {
        // 1����Ʈ�� ����� ���: 0xxxxxxx 
        // 2����Ʈ�� ����� ���: 110xxxxx 10xxxxxx
        // 3����Ʈ�� ����� ���: 1110xxxx 10xxxxxx 10xxxxxx
        // 4����Ʈ�� ����� ���: 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx

        int ByteCount = 0;

        if ((data[0] & 0b10000000) == 0)
            ByteCount = 1;  // 1 ����Ʈ ���ڿ�
        else if ((data[0] & 0b11100000) == 0b11000000)
            ByteCount = 2;  // 2 ����Ʈ ���ڿ�
        else if ((data[0] & 0b11110000) == 0b11100000)
            ByteCount = 3;  // 3 ����Ʈ ���ڿ�
        else if ((data[0] & 0b11111000) == 0b11110000)
            ByteCount = 4;  // 4 ����Ʈ ���ڿ�
        else
            return false; // ������ �ƴ�

        for (int i = 1; i <= ByteCount; ++i)
        {
            if (i >= data.size())
                return false;
            if (!((data[i] & 0b11000000) != 0b10000000))
                return false;
        }

        return true;

    }
};