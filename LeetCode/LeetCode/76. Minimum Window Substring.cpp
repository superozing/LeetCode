#include "헤더.h"

class Solution
{
public:
    string minWindow(string s, string t)
    {
        // 일단 배열을 적게 만들기 위해서 - 'A'를 상시 해주어야 해.
        bool tCheck[26]{};
        for (auto &it : t)
            tCheck[it - 'A'] = true;

        int MinIdx = 0;
        int MaxIdx = 0;
        int CurIdx = 0;
        
        // MaxIdx를 늘려가면서 s가 포함되는지 체크

        // MinIdx를 늘려가면서 s가 포함되는지 체크

    }

    bool ㅇ(int min, int max, const string& s, const bool* boolArr)
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
//        // 예외
//        if (s.length() < t.length()) return "";
//
//        vector<int> tIdxVec;
//
//        bool stringCheck['Z' - 'A']{};
//
//        int LIdx = 0;
//        int RIdx = 0;
//
//        // t 체크
//        for (int i = 0; i < t.length(); ++i)
//            tIdxVec.push_back(t[i] - 'A');
//
//
//        // s 체크
//        deque<int> dq;
//
//        string ret{};
//
//        // 1. s에 t의 모든 문자가 들어갈 때 까지 오른 쪽 인덱스를 계속해서 확장
//        // 일단 부분문자열의 최소 길이는 t.
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