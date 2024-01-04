#include "���.h"

class Solution
{
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        // �ϴ� �� ������ ���� ���� Ǯ���� ���� �߿� �ε��� �ϳ��� �������� �� ���� �ڿ� �ٿ����� ������ �������׿�.
        // ���� -> +, cost -> -.

        if (accumulate(gas.begin(), gas.end(), 0) < 0)
            return -1;

        // ������ �Դٸ� ���� �� �� ������ ����� ���� �ִٴ� ���̰���?
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
