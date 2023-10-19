#include "Çì´õ.h"

class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        map<int, int> mNums;
        for (int i = 0; i < nums.size(); ++i)
            mNums.insert(make_pair(nums[i], i));

        map<int, int>::iterator R = mNums.end();
        map<int, int>::iterator L = mNums.begin();
        --R; 
        while (true)
        {
            if (R->first + L->first > target)
            {
                --R;
            }
            else if (R->first + L->first < target)
            {
                ++L;
            }
            
            if ((R->first + L->first == target))
            {
                break;
            }
        }
        
        nums.clear();
        nums.push_back(R->second);
        nums.push_back(L->second);


        return nums;
    }
};

int main()
{
    Solution s;
    vector<int> v;
    v.push_back(3);
    v.push_back(2);
    v.push_back(4);

    
    s.twoSum(v, 6);


}