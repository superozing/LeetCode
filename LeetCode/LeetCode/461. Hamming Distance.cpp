#include "���.h"
class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        int XOR = (x ^ y); // ^ <- xor������, �ٸ� ��� 1�� ����
        int returnVal = 0;
        // int �� 32��Ʈ�ϱ� �� 32�� ��Ʈ�� �о� ����ϸ� �ǰ���?

        for (int i = 0; i < 32; ++i)
            if (XOR & (1 << i))
                ++returnVal;

        return returnVal;
    }

    //int hammingDistance(int x, int y)
    //{
    //    x = (x ^ y); // ^ <- xor������, �ٸ� ��� 1�� ����
    //    y = 0;
    //    // int �� 32��Ʈ�ϱ� �� 32�� ��Ʈ�� �о� ����ϸ� �ǰ���?
    //    for (int i = 0; i < 32; ++i)
    //        if (x & (1 << i))
    //            ++y;
    //    return y;
    //}
};