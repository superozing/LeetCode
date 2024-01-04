#include "헤더.h"




class Solution
{
public:
    int findContentChildren(vector<int>& g, vector<int>& s)
    {
        // 욕심쟁이 문제들
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int gIdx = 0;
        int sIdx = 0;
        while (sIdx < s.size() && gIdx < g.size())
        {
            if (g[gIdx] >= s[sIdx])
                ++gIdx;
            ++sIdx;
        }

        // 만족하신 숫자를 바로 return.
        return gIdx;
    }
};


int main()
{
    Solution s;
    vector<int> a1({ 1,2,3 });
    vector<int> a2({ 1,1 });
    printf("%d\n", s.findContentChildren(a1, a2));
    return 0;
}