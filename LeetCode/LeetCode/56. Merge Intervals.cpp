#include "���.h"

bool First(vector<int>& a, vector<int> b)
{
    return a[0] < b[0];
}


class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        // ��ġ�� ���� -> �� ���� �� ��° ���Һ��� �� ���� ù ��° ���Ұ� �۰ų� ���� ��� ������ ����.
        // ���� -> �� ���͸� ��ħ. �� ���� ù ��° ���ҿ� �� ���� �� ��° ���Ҹ� ���ļ� ���ο� ���͸� �����ϸ� ���� ������?
        // �ϴ� �� ���Ͱ� ���ĵǾ��ִ°�? �� �����׿�. ���ĵǾ��ٰ� �����ϰ� Ǯ���. - ������ �ٸ��� ������ �ȵ� ���µ� �ֳ׿�.
        // �񱳸� �� ���͸� �ؾ� �ϴϱ�, ��ü size - 1 �� ��ŭ�� �񱳸� �ϸ� �ǰڴ�.

        vector<vector<int>> returnVec;

        sort(intervals.begin(), intervals.end(), First);

        bool sorted = true;

        while (sorted)
        {
            sorted = false;
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

                    if (intervals[i][1] >= intervals[i + 1][1])
                        vecBuf.push_back(intervals[i][1]);
                    else
                        vecBuf.push_back(intervals[i + 1][1]);

                    returnVec.push_back(vecBuf);
                    ++i;
                    sorted = true;
                }
                else
                {
                    returnVec.push_back(intervals[i]);
                }
            }
            intervals.swap(returnVec);
            returnVec.clear();
        }

        return intervals;

    }
};