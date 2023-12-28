#include "헤더.h"
class Solution
{
public:
    int search(vector<int>& nums, int target)
    {
        // 일단 피벗 인덱스를 찾아야 할 것 같아.
        // 피벗 인덱스로부터 오른 쪽은 값이 작은 값들이 모여있겠고, 왼 쪽은 값이 큰 값들이 모여있겠지?
        // 그러면 피벗 인덱스로부터 왼 쪽을 판단할 지, 오른 쪽을 판단할 지를 결정할 수 있을 거야.
        // 여기까지 와서 이진 탐색을 사용해서 원하는 인덱스를 찾아내면 될 듯 하네요.


        // 피벗 인덱스 찾기.
        // 값이 커지다가 작은 값이 나온다면 해당 지점이 피벗 인덱스.
        // 피벗 인덱스가 없을 수도 있나?
        // -> 없으면 그냥 이진탐색 돌려.

        int Search = false; // -1 왼, 0 정렬 안됨, 1 오
        int FivotIdx = 0;
        for (; FivotIdx < nums.size() - 1; ++FivotIdx)
        {
            if (nums[FivotIdx] > nums[FivotIdx + 1])
            {
                if (target >= nums[nums.size() - 1])
                    Search = 1;
                else if (target <= nums[0])
                    Search = -1;
                else if (target == nums[nums.size() - 1])
                    return nums.size() - 1;
                else
                    return FivotIdx;

                break;
            }
        }
        printf("FivotIdx : %d\n", FivotIdx);
        printf("Search : %d\n", Search);

        int left = 0;
        int right = 0;

        if (Search == -1)
        {
            if (FivotIdx == 0 && nums[FivotIdx + 1] == target)
                return FivotIdx + 1;
            left = FivotIdx;
            right = nums.size() - 1;
        }
        else if (Search == 1)
        {
            if (nums[FivotIdx + 1] == target)
                return FivotIdx + 1;
            else if (nums.back() == target)
                return nums.size() - 1;
            left = 0;
            right = FivotIdx;
        }
        else // -> 피벗 뭐시기가 없는 경우
        {
            left = 0;
            right = nums.size() - 1;
        }

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
            printf("CurIdx : %d\n", CurIdx);
            printf("left : %d\n", left);
            printf("right : %d\n", right);

        }

        return -1;
    }
};