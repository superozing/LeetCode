#include "헤더.h"
class Solution
{
public:
    bool validUtf8(vector<int>& data)
    {
        // 1바이트만 사용할 경우: 0xxxxxxx 
        // 2바이트를 사용할 경우: 110xxxxx 10xxxxxx
        // 3바이트를 사용할 경우: 1110xxxx 10xxxxxx 10xxxxxx
        // 4바이트를 사용할 경우: 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx

        int ByteCount = 0;

        if ((data[0] & 0b10000000) == 0)
            ByteCount = 1;  // 1 바이트 문자열
        else if ((data[0] & 0b11100000) == 0b11000000)
            ByteCount = 2;  // 2 바이트 문자열
        else if ((data[0] & 0b11110000) == 0b11100000)
            ByteCount = 3;  // 3 바이트 문자열
        else if ((data[0] & 0b11111000) == 0b11110000)
            ByteCount = 4;  // 4 바이트 문자열
        else
            return false; // 무엇도 아님

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