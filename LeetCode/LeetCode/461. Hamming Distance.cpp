#include "헤더.h"
class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        int XOR = (x ^ y); // ^ <- xor연산자, 다를 경우 1을 뱉음
        int returnVal = 0;
        // int 는 32비트니까 총 32번 비트를 밀어 계산하면 되겠죠?

        for (int i = 0; i < 32; ++i)
            if (XOR & (1 << i))
                ++returnVal;

        return returnVal;
    }

    //int hammingDistance(int x, int y)
    //{
    //    x = (x ^ y); // ^ <- xor연산자, 다를 경우 1을 뱉음
    //    y = 0;
    //    // int 는 32비트니까 총 32번 비트를 밀어 계산하면 되겠죠?
    //    for (int i = 0; i < 32; ++i)
    //        if (x & (1 << i))
    //            ++y;
    //    return y;
    //}
};