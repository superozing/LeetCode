#include "헤더.h"

class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        // 이전 값보다 작은 값이 나오기 이전까지 계속 체크하기만 하면 될 듯?
        int returnValue = 0;
        int CurCheckIdx = 0;
        for (int i = 1; i < prices.size(); ++i)
        {
            // 이전 값 보다 현재 값이 작은 경우
            if (prices[i] < prices[i - 1] || i == prices.size() - 1)
            {
                returnValue += prices[i - 1] - prices[CurCheckIdx];
                CurCheckIdx = i;
            }
        }

        return returnValue;
        
    }
};