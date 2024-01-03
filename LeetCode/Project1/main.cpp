#include "���.h"


#define üũ�ϱ� ��(MinIdx, MaxIdx, s, tCheck)
#define üũ�ϱ�1 ��(MinIdx + 1, MaxIdx, s, tCheck)
class Solution
{
public:
    string minWindow(string s, string t)
    {
        // �ϴ� �迭�� ���� ����� ���ؼ� - 'A'�� ��� ���־�� ��.
        vector<bool> tCheck(26);
        for (auto& it : t)
            tCheck[it - 'A'] = true;

        int MinIdx_r = 0;
        int MaxIdx_r = t.length() - 1;

        int MinIdx = 0;
        int MaxIdx = t.length() - 1;

        // MaxIdx�� �÷����鼭 s�� ���ԵǴ��� üũ
        while (true)
        {
            if (üũ�ϱ�)
                break;
            else
                ++MaxIdx;
        }


        // MinIdx�� �÷����鼭 s�� ���ԵǴ��� üũ
        while (true)
        {
            if (üũ�ϱ�1)
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

    bool ��(int min, int max, const string& s, const vector<bool>& boolArr)
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