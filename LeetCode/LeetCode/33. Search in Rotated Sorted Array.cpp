#include "���.h"
class Solution
{
public:
    int search(vector<int>& nums, int target)
    {
        // �ϴ� �ǹ� �ε����� ã�ƾ� �� �� ����.
        // �ǹ� �ε����κ��� ���� ���� ���� ���� ������ ���ְڰ�, �� ���� ���� ū ������ ���ְ���?
        // �׷��� �ǹ� �ε����κ��� �� ���� �Ǵ��� ��, ���� ���� �Ǵ��� ���� ������ �� ���� �ž�.
        // ������� �ͼ� ���� Ž���� ����ؼ� ���ϴ� �ε����� ã�Ƴ��� �� �� �ϳ׿�.


        // �ǹ� �ε��� ã��.
        // ���� Ŀ���ٰ� ���� ���� ���´ٸ� �ش� ������ �ǹ� �ε���.
        // �ǹ� �ε����� ���� ���� �ֳ�?
        // -> ������ �׳� ����Ž�� ����.

        int Search = false; // -1 ��, 0 ���� �ȵ�, 1 ��
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
        else // -> �ǹ� ���ñⰡ ���� ���
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