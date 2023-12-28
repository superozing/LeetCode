#include "���.h"


class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        int XOR = (x ^ y); // ^ <- xor������, �ٸ� ��� 1�� ����. �װ� �������� ���� ��� 1�� �ǰ���?
        int returnVal = 0;
        // int �� 32��Ʈ�ϱ� �� 32�� ��Ʈ�� �о� ����ϸ� �ǰ���?


        for (int i = 0; i < 32; ++i)
        {
            if (XOR & (1 << i))
            {
                ++returnVal;
            }
        }
        return returnVal;
    }
};


int main()
{
    Solution s;
    vector<int> v{ 5,1,2,3,4 };
    int a = s.search(v, 1);
    printf("%d\n", a);
    return 0;
}