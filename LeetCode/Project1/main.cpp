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



int main()
{
    Solution s;
    vector<int> a1({ 5,8,2,8 });
    vector<int> a2({ 6,5,6,6 });
    printf("%d\n", s.canCompleteCircuit(a1, a2));
    return 0;
}