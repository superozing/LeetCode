#include "���.h"

class Solution 
{
public:
    int singleNumber(vector<int>& nums) 
    {
        map<int, bool> ��ġ����Ȯ��;
        auto iter = ��ġ����Ȯ��.end();

        for (int i = 0; i < nums.size(); ++i)
        {
            iter = ��ġ����Ȯ��.find(nums[i]);
            if (iter != ��ġ����Ȯ��.end())
                iter->second = false;
            else
                ��ġ����Ȯ��.insert({ nums[i], true });
        }

        for (auto& it : ��ġ����Ȯ��)
        {
            if (it.second)
                return it.first;
        }
        return 0;
    }
};