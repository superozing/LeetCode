#include "헤더.h"

class Solution
{
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        // 일단 이 문제를 보니 전에 풀었던 문제 중에 인덱스 하나를 기준으로 반 갈라서 뒤에 붙여놓은 문제가 생각나네요.
        // 가스 -> +, cost -> -.

        if (accumulate(gas.begin(), gas.end(), 0) < 0)
            return -1;

        // 여까지 왔다면 이제 단 한 가지의 경우의 수가 있다는 뜻이겠죠?
        for (int j = 0; j < gas.size(); ++j)
        {
            int CurGas = 0;
            bool FailFlag = false;

            for (int i = 0; i < gas.size(); ++i)
            {
                int idx = i + j;
                if (idx >= gas.size())
                    idx -= gas.size();
                if (CurGas + gas[idx] < cost[idx])
                {
                    FailFlag = true;
                    break;
                }
                CurGas += gas[idx] - cost[idx];
            }
            if (!FailFlag)
                return j;
        }

        return -1;
    }
};
