#include "���.h"

class Solution 
{
public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
        // ������� ������
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int gIdx = 0;
        int sIdx = 0;
        while (sIdx < s.size() || gIdx < g.size())
        {
            if (g[gIdx] >= s[sIdx])
                ++gIdx;
            ++sIdx;
        }

        // �����Ͻ� ���ڸ� �ٷ� return.
        return gIdx;
    }
};