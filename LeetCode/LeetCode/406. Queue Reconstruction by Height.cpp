#include "헤더.h"

int cmp(vector<int>& a, vector<int>& b)
{
    // 키가 같을 경우
    if (a[0] == b[0])
    {
        // 앞에 사람 많은 애가 뒤 쪽으로 가야 함.
        // 그 앞에 사람 적은 애가 서있을 수 있도록
        if (a[1] < b[1])
            return true;
        else
            return false;
    }
    // 키가 다를 경우
    else
    {
        if (a[0] < b[0])
            return true;
        else
            return false;
    }
}

class Solution 
{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) 
    {
        sort(people.begin(), people.end(), cmp);

        vector<vector<int>> returnVec(people.size());

        for (auto& iter : people)
        {
            returnVec.insert(returnVec.begin() + iter[1], iter);
        }


        return returnVec;
    }
};