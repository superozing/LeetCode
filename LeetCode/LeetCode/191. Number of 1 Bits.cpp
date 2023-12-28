#include "헤더.h"

class Solution 
{
public:
    int hammingWeight(uint32_t n)
    {
        int returnVal = 0;
        // int 는 32비트니까 총 32번 비트를 밀어 계산하면 되겠죠?

        for (int i = 0; i < 32; ++i)
        {
            if (n & (1 << i))
            {
                ++returnVal;
            }
        }
        return returnVal;
    }
};