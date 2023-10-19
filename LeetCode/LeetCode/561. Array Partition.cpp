#include "헤더.h"

class Solution {
public:
    int arrayPairSum(vector<int>& nums) 
    {
        int iReturn = 0;
        // 작은 값 부터 차례대로 절반 더하면 되지 않을까?
        
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i += 2)
        {
            iReturn += nums[i];
        }
        return iReturn;
    }
};