#include "���.h"

class Solution
{
public:
    int majorityElement(vector<int>& nums)
    {
        // ��ģ Ǯ��;;
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];

    }
};

// �ƴϾ��� ^^
//class Solution 
//{
//public:
//    int majorityElement(vector<int>& nums) 
//    {
//        // ��� �����غôµ� ���� �̻��� ���ڰ� �� ���� �����̸� �� ���ؼ� n��ŭ ���� �� �ٷ� �����ָ� �Ǵ°� �ƴѰ�?
//        int acc = accumulate(nums.begin(), nums.end(), 0);
//        if (acc % nums.size() != 0)
//            return acc / nums.size() + 1;
//        return acc / nums.size();
//    }
//};