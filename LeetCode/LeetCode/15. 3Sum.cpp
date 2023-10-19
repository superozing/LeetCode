#include "���.h"

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
        // �� ���� ã�� ���ؼ�...
        // (�� ���� ��) * -1 == �� ���� ���� �� �� �Ǿ�� �ϰ�
        // �� �� ���� Key �� ����

        // 1. �ϴ� ���� �迭�� �����ؾ� �� �� ����
        set<sValue> sNums;
        vector<vector<int>> vReturn;
        for (int i = 0; i < nums.size(); ++i)
        {
            sValue v(nums[i], i);
            sNums.insert(v);
        }

        //  2. ���� ū ���� Key ������ ����
        // (Key * -1) == ������ �� �� -> �� ���� ã��
        set<sValue>::iterator BufIter = sNums.begin();

        set<sValue>::iterator LIter = BufIter;
        ++LIter;
        set<sValue>::iterator RIter = sNums.end();


        // L�� begin + �ݺ� Ƚ����ŭ...
        // L�� ������ �Űܰ��鼭 R�� �� ��ȸ�ϸ��ϸ� n�����ε�...?
        // �� ������ �����

        while (true)
        {
            // 1. LIter RIter ���� ���� BufIter���� ũ��
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
            // 2. LIter RIter ���� ���� BufIter���� ������
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