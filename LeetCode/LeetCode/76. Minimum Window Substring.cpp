#include "���.h"

class Solution
{
public:
    string minWindow(string s, string t)
    {
        // �ϴ� �迭�� ���� ����� ���ؼ� - 'A'�� ��� ���־�� ��.
        bool tCheck[26]{};
        for (auto &it : t)
            tCheck[it - 'A'] = true;

        int MinIdx = 0;
        int MaxIdx = 0;
        int CurIdx = 0;
        
        // MaxIdx�� �÷����鼭 s�� ���ԵǴ��� üũ

        // MinIdx�� �÷����鼭 s�� ���ԵǴ��� üũ

    }

    bool ��(int min, int max, const string& s, const bool* boolArr)
    {
        for (; min <= max; ++min)
        {
            if (boolArr[s[min] - 'A'] == false)
                return false;
        }

        return true;
    }

    

};



//class Solution
//{
//public:
//    string minWindow(string s, string t)
//    {
//        // ����
//        if (s.length() < t.length()) return "";
//
//        vector<int> tIdxVec;
//
//        bool stringCheck['Z' - 'A']{};
//
//        int LIdx = 0;
//        int RIdx = 0;
//
//        // t üũ
//        for (int i = 0; i < t.length(); ++i)
//            tIdxVec.push_back(t[i] - 'A');
//
//
//        // s üũ
//        deque<int> dq;
//
//        string ret{};
//
//        // 1. s�� t�� ��� ���ڰ� �� �� ���� ���� �� �ε����� ����ؼ� Ȯ��
//        // �ϴ� �κй��ڿ��� �ּ� ���̴� t.
//        while (RIdx != s.length())
//        {
//            while (!isIncludeString(tIdxVec, stringCheck))
//            {
//                dq.push_back(s[++RIdx]);
//                stringCheck[s[RIdx] - 'A'] = true;
//            }
//            while (isIncludeString(tIdxVec, stringCheck))
//            {
//                stringCheck[s[dq.front()] - 'A'] = false;
//                dq.pop_front();
//                ++LIdx;
//            }
//
//            // 
//            if (ret.length() > RIdx - LIdx)
//            {
//                ret = {};
//                for (int i = LIdx - 1; i < RIdx; ++i)
//                {
//                    ret += s[i];
//                }
//            }
//        }
//
//        return ret;
//    }
//
//    bool isIncludeString(vector<int>& checked, bool* stringCheck)
//    {
//        for (int i = 0; i < checked.size(); ++i)
//        {
//            if (!stringCheck[checked[i]])
//                return false;
//        }
//
//        return true;
//    }
//
//};