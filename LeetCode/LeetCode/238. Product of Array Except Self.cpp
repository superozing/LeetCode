#include "���.h"

class Solution 
{
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        // ������ ����
        // �׷��� 1/n���� ���ϸ� �Ǵ°� �ƴѰ�?
        // /�� ���� �ȵǴ°ǰ�?
        // ��Ģ�� ã�� ���ϰھ��.
        vector<int> vReturn(nums.size(), 1);

        for (int i = 0; i < nums.size(); ++i)
        {
            int iBuf = nums[i];

            for (int j = 0; j < nums.size(); ++j)
            {
                if (i == j) continue;
                vReturn[j] *= iBuf;
            }

        }

        return vReturn;
    }
};