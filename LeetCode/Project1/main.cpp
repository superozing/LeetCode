#include "���.h"



class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        // ���� ������ ���� ���� ������ �������� ��� üũ�ϱ⸸ �ϸ� �� ��?
        int returnValue = 0;
        for (int i = 1; i < prices.size(); ++i)
            if (prices[i - 1] < prices[i])
                returnValue += prices[i] - prices[i - 1];
        return returnValue;

    }
};


int main()
{
    Solution s;
    vector<int> a({ 1,9,6,9,1,7,1,1,5,9,9,9 });
    printf("%d\n", s.maxProfit(a));
    return 0;
}