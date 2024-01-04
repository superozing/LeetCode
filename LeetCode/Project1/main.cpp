#include "헤더.h"




class Solution
{
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        // 일단 이 문제를 보니 전에 풀었던 문제 중에 인덱스 하나를 기준으로 반 갈라서 뒤에 붙여놓은 문제가 생각나네요.
        // 가스 -> +, cost -> -.

        if (accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0))
            return -1;

        // 여까지 왔다면 이제 단 한 가지의 경우의 수가 있다는 뜻이겠죠?
        int CurGas = 0;
        int returnVal = 0;

        for (int i = 0; i < gas.size(); ++i)
        {
            if (CurGas + gas[i] < cost[i])
            {
                CurGas = 0;
                returnVal = i + 1; // (다음 인덱스는 되길 바라며)
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