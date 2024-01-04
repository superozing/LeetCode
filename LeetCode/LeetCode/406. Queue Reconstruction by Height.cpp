#include "���.h"

int cmp(vector<int>& a, vector<int>& b)
{
    // Ű�� ���� ���
    if (a[0] == b[0])
    {
        // �տ� ��� ���� �ְ� �� ������ ���� ��.
        // �� �տ� ��� ���� �ְ� ������ �� �ֵ���
        if (a[1] < b[1])
            return true;
        else
            return false;
    }
    // Ű�� �ٸ� ���
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