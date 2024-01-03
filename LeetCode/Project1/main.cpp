#include "헤더.h"


#define 체크하기 ㅇ(MinIdx, MaxIdx, s, tCheck)
#define 체크하기1 ㅇ(MinIdx + 1, MaxIdx, s, tCheck)
class Solution
{
public:
    string minWindow(string s, string t)
    {
        // 일단 배열을 적게 만들기 위해서 - 'A'를 상시 해주어야 해.
        vector<bool> tCheck(26);
        for (auto& it : t)
            tCheck[it - 'A'] = true;

        int MinIdx_r = 0;
        int MaxIdx_r = t.length() - 1;

        int MinIdx = 0;
        int MaxIdx = t.length() - 1;

        // MaxIdx를 늘려가면서 s가 포함되는지 체크
        while (true)
        {
            if (체크하기)
                break;
            else
                ++MaxIdx;
        }


        // MinIdx를 늘려가면서 s가 포함되는지 체크
        while (true)
        {
            if (체크하기1)
                ++MinIdx;
            else
                break;
        }

        MinIdx_r = MinIdx;
        MaxIdx_r = MaxIdx;

        string r;
        for (int i = MinIdx_r; i < MaxIdx_r; ++i)
        {
            r += s[i];
        }
        return r;

    }

    bool ㅇ(int min, int max, const string& s, const vector<bool>& boolArr)
    {
        for (int i = min; i < max; ++i)
        {
            if (boolArr[i - min] s[i] - 'A' == false)
                return false;
        }

        return true;
    }



};

int main()
{
    Solution s;
    string a = s.minWindow("ADOBECODEBANC",
        "ABC");
    printf("%d\n", a);
    return 0;
}