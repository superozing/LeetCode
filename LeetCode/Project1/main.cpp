#include "헤더.h"


class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        int XOR = (x ^ y); // ^ <- xor연산자, 다를 경우 1을 뱉음. 그걸 뒤집으면 같은 경우 1이 되겠죠?
        int returnVal = 0;
        // int 는 32비트니까 총 32번 비트를 밀어 계산하면 되겠죠?


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