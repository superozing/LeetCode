#include "���.h"

class Solution 
{
public:
    int hammingWeight(uint32_t n)
    {
        int returnVal = 0;
        // int �� 32��Ʈ�ϱ� �� 32�� ��Ʈ�� �о� ����ϸ� �ǰ���?

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