#include "���.h"

class Solution {
public:
    int arrayPairSum(vector<int>& nums) 
    {
        int iReturn = 0;
        // ���� �� ���� ���ʴ�� ���� ���ϸ� ���� ������?
        
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i += 2)
        {
            iReturn += nums[i];
        }
        return iReturn;
    }
};