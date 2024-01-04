#include "���.h"

class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        // ���� ������ ���� ���� ������ �������� ��� üũ�ϱ⸸ �ϸ� �� ��?
        int returnValue = 0;
        int CurCheckIdx = 0;
        for (int i = 1; i < prices.size(); ++i)
        {
            // ���� �� ���� ���� ���� ���� ���
            if (prices[i] < prices[i - 1] || i == prices.size() - 1)
            {
                returnValue += prices[i - 1] - prices[CurCheckIdx];
                CurCheckIdx = i;
            }
        }

        return returnValue;
        
    }
};