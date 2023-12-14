#include "���.h"

class Solution
{
public:
    // int maxProfit(vector<int>& prices)
    // {
    //     int returnval = 0;
    //     int min = prices[0];
    //     int cur = 0;
    //     // �ϴ� ���� ���� ã�ƾ� ��.
    //     // ���� ���� ã���� ���� ���� ���� ��.
    //     // �̷��� ã���ϱ� Ÿ�Ӿƿ��� ���׿�. ������ n���� ������ �ϳ� ����

    //     // for���� ���鼭 ���� �ε��� ���� ���ϸ� �ȴ�.
    //     // �ϴ� min�� max�� �ʱ�ȭ �غ���
    //     // ���� ���� ū ���� ���� �� ��.
    //     // ���⼭ ���ܴ� �� ���� ���� ������ ���

    //     for (int i = 1; i < prices.size(); ++i)
    //     {
    //         cur = prices[i];
    //         if (min < cur)
    //         {   
    //             if (returnval < cur - min)
    //                 returnval = cur - min;
    //             continue;
    //         }
    //         if (min > cur)
    //             min = cur;
    //     }
    //     return returnval;
    // }

    int maxProfit(vector<int>& prices)
    {
        int returnval = 0;
        int min = prices[0];
        for (int i = 1; i < prices.size(); ++i)
        {
            if (min < prices[i])
            {
                if (returnval < prices[i] - min)
                    returnval = prices[i] - min;
                continue;
            }
            if (min > prices[i])
                min = prices[i];
        }
        return returnval;
    }
};