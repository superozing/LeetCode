#include "���.h"
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        // ��ġ�� ���� -> �� ���� �� ��° ���Һ��� �� ���� ù ��° ���Ұ� �۰ų� ���� ��� ������ ����.
        // ���� -> �� ���͸� ��ħ. �� ���� ù ��° ���ҿ� �� ���� �� ��° ���Ҹ� ���ļ� ���ο� ���͸� �����ϸ� ���� ������?
        // �ϴ� �� ���Ͱ� ���ĵǾ��ִ°�? �� �����׿�. ���ĵǾ��ٰ� �����ϰ� Ǯ���.
        // �񱳸� �� ���͸� �ؾ� �ϴϱ�, ��ü size - 1 �� ��ŭ�� �񱳸� �ϸ� �ǰڴ�.

        vector<vector<int>> returnVec;

        // �� ���͸� �񱳸� �غ����?


        // 
        for (int i = 0; i < intervals.size(); ++i)
        {
            if (i == intervals.size() - 1)
            {
                returnVec.push_back(intervals[i]);
            }
            else if (intervals[i][1] >= intervals[i + 1][0])
            {
                vector<int> vecBuf;
                vecBuf.push_back(intervals[i][0]);
                vecBuf.push_back(intervals[i + 1][1]);
                returnVec.push_back(vecBuf);
                ++i;
            }
            else
            {
                returnVec.push_back(intervals[i]);
            }
        }

        return returnVec;

    }
};