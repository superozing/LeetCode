#include "���.h"

class Solution
{
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        // �ϴ� �� ������ ���� ���� Ǯ���� ���� �߿� �ε��� �ϳ��� �������� �� ���� �ڿ� �ٿ����� ������ �������׿�.
        // ���� -> +, cost -> -.

        if (accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0))
            return -1;

        // ������ �Դٸ� ���� �� �� ������ ����� ���� �ִٴ� ���̰���?
        int CurGas = 0;
        int returnVal = 0;

        for (int i = 0; i < gas.size(); ++i)
        {
            if (CurGas + gas[i] < cost[i])
            {
                CurGas = 0;
                returnVal = i + 1; // (���� �ε����� �Ǳ� �ٶ��)
            }
            else
                CurGas += gas[i] - cost[i];
        }

        return returnVal;
    }
};
