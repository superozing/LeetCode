#include "헤더.h"

class Solution
{
public:
    int majorityElement(vector<int>& nums)
    {
        // 미친 풀이;;
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];

    }
};

// 아니었고 ^^
//class Solution 
//{
//public:
//    int majorityElement(vector<int>& nums) 
//    {
//        // 잠깐 생각해봤는데 절반 이상의 인자가 한 개의 숫자이면 다 더해서 n만큼 나눈 값 바로 돌려주면 되는거 아닌가?
//        int acc = accumulate(nums.begin(), nums.end(), 0);
//        if (acc % nums.size() != 0)
//            return acc / nums.size() + 1;
//        return acc / nums.size();
//    }
//};