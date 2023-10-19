#include "헤더.h"

struct sValue
{
    const int iVal;
    int iIdx;

public:
    sValue()
        :iVal(0)
        , iIdx(0)
    {

    }
    sValue(int a, int b)
        :iVal(a)
        , iIdx(b)
    {
    }
};


class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        // 세 수를 찾기 위해서...
        // (한 수의 값) * -1 == 두 수의 값의 합 이 되어야 하고
        // 이 한 수를 Key 로 저장

        // 1. 일단 들어온 배열을 정렬해야 할 것 같다
        set<sValue> sNums;
        vector<vector<int>> vReturn;
        for (int i = 0; i < nums.size(); ++i)
        {
            sValue v(nums[i], i);
            sNums.insert(v);
        }

        //  2. 제일 큰 수를 Key 값으로 설정
        // (Key * -1) == 나머지 두 수 -> 세 수를 찾음
        set<sValue>::iterator BufIter = sNums.begin();

        set<sValue>::iterator LIter = BufIter;
        ++LIter;
        set<sValue>::iterator RIter = sNums.end();


        // L은 begin + 반복 횟수만큼...
        // L을 앞으로 옮겨가면서 R을 다 순회하면하면 n제곱인데...?
        // 투 포인터 써야죠

        while (true)
        {
            // 1. LIter RIter 더한 값이 BufIter보다 크면
            int LValue = LIter->iVal;
            int RValue = RIter->iVal;
            if (LIter == RIter)
            {
                ++BufIter;
                if (BufIter == sNums.end())
                {
                    break;
                }
                LIter = BufIter;
                ++LIter;
                RIter = sNums.end();
            }
            if (LValue + RValue > BufIter->iVal)
            {
                --RIter;
            }
            // 2. LIter RIter 더한 값이 BufIter보다 작으면
            else if (LValue + RValue < BufIter->iVal)
            {
                ++LIter;
            }
            else if (LValue + RValue == BufIter->iVal)
            {
                vector<int> vBuf;
                vBuf.push_back(LIter->iIdx);
                vBuf.push_back(RIter->iIdx);
                vBuf.push_back(BufIter->iIdx);
                vReturn.push_back(vBuf);
            }
        }

        return vReturn;
    }
};