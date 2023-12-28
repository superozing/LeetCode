#include "헤더.h"

class Solution 
{
public:
    int singleNumber(vector<int>& nums) 
    {
        map<int, bool> 겹치는지확인;
        auto iter = 겹치는지확인.end();

        for (int i = 0; i < nums.size(); ++i)
        {
            iter = 겹치는지확인.find(nums[i]);
            if (iter != 겹치는지확인.end())
                iter->second = false;
            else
                겹치는지확인.insert({ nums[i], true });
        }

        for (auto& it : 겹치는지확인)
        {
            if (it.second)
                return it.first;
        }
        return 0;
    }
};