#include "헤더.h"

class Solution 
{
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        // 나눗셈 금지
        // 그러면 1/n으로 곱하면 되는거 아닌가?
        // /이 들어가서 안되는건가?
        // 규칙을 찾지 못하겠어요.
        vector<int> vReturn(nums.size(), 1);

        for (int i = 0; i < nums.size(); ++i)
        {
            int iBuf = nums[i];

            for (int j = 0; j < nums.size(); ++j)
            {
                if (i == j) continue;
                vReturn[j] *= iBuf;
            }

        }

        return vReturn;
    }
};