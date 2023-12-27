#include "헤더.h"
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        // 겹치는 구간 -> 앞 쪽의 두 번째 원소보다 뒤 쪽의 첫 번째 원소가 작거나 같을 경우 병합이 가능.
        // 병합 -> 두 벡터를 합침. 앞 쪽의 첫 번째 원소와 뒤 쪽의 두 번째 원소를 합쳐서 새로운 벡터를 생성하면 되지 않을까?
        // 일단 이 벡터가 정렬되어있는가? 가 문제네요. 정렬되었다고 가정하고 풀어보자.
        // 비교를 두 벡터를 해야 하니까, 전체 size - 1 번 만큼만 비교를 하면 되겠다.

        vector<vector<int>> returnVec;

        // 두 벡터를 비교만 해볼까요?


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