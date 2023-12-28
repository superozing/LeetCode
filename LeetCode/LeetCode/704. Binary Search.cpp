#include "Çì´õ.h"
class Solution
{
public:
    int search(vector<int>& nums, int target)
    {
        if (nums.size() == 1)
        {
            if (nums[0] == target)
                return 0;
            else
                return -1;
        }
        if (nums.size() == 0)
            return -1;



        int left = 0;
        int right = nums.size() - 1;

        int CurIdx = left + (right - left) / 2;

        while (left <= right)
        {
            if (nums[CurIdx] < target)
            {
                left = CurIdx + 1;
            }
            else if (nums[CurIdx] > target)
            {
                right = CurIdx - 1;
            }
            else if (nums[CurIdx] == target)
            {
                return CurIdx;
            }
            CurIdx = left + (right - left) / 2;
        }

        return -1;

    }
};