#include "헤더.h"
struct t
{
    double sqrt;
    int idx;

    t()
    {

    }

    t(double a, int b)
        : sqrt(a)
        , idx(b)
    {

    }
};

int cmp(t a, t b)
{
    return a.sqrt < b.sqrt;
}

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
    {
        // 원점에 가장 가까운 점 -> 절대 값을 곱한 값이 가장 적은 점
        // k개를 반환해야 한다. 큐를 쓰면 좀 좋을 듯?
        vector<t> tvec;
        vector<int> curPoint;
        int size = points.size();

        for (int i = 0; i < size; ++i)
        {
            curPoint = points[i];
            tvec.push_back(t{ sqrt(curPoint[0] * curPoint[0] + curPoint[1] * curPoint[1]), i });
        }


        sort(tvec.begin(), tvec.end(), cmp);

        vector<vector<int>> returnVec;
        returnVec.reserve(k);


        for (int i = 0; i < k; ++i)
        {
            returnVec.push_back(points[tvec[i].idx]);
        }
        return returnVec;
    }
};