#include "헤더.h"

class Solution
{
public:
    // int maxProfit(vector<int>& prices)
    // {
    //     int returnval = 0;
    //     int min = prices[0];
    //     int cur = 0;
    //     // 일단 작은 수를 찾아야 해.
    //     // 작은 수를 찾으면 다음 수를 봐야 해.
    //     // 이렇게 찾으니까 타임아웃이 나네용. 무조건 n으로 끝내야 하나 봐요

    //     // for문을 돌면서 현재 인덱스 값을 비교하면 된다.
    //     // 일단 min과 max를 초기화 해보자
    //     // 작은 수와 큰 수를 저장 후 비교.
    //     // 여기서 예외는 더 작은 수가 나왔을 경우

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