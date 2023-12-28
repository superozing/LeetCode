#include "헤더.h"

class Solution 
{
public:
    void sortColors(vector<int>& nums) 
    {
        // nums 자체를 수정해야 해.
        // in-place 알고리즘 사용해야 함 -> 새로운 공간을 만들어서 사용하면 안된다는 뜻이겠죠?
        // 0, 1, 2

        // [2,0,2,1,1,0]일 경우?
        if (nums.size() == 1)
            return;

        int color[3] = {};
        for (int i = 0; i < nums.size(); ++i)
        {
            switch (nums[i])
            {
            case 0:
                ++color[0];
                break;
            case 1:
                ++color[1];
                break;
            case 2:
                ++color[2];
                break;
            }
        }
        
        int idx = 0;

        for (int i = 0; i < color[0]; ++i)
        {
            nums[idx] = 0;
            ++idx;
        }
        for (int i = 0; i < color[1]; ++i)
        {
            nums[idx] = 1;
            ++idx;
        }
        for (int i = 0; i < color[2]; ++i)
        {
            nums[idx] = 2;
            ++idx;
        }

    }
};