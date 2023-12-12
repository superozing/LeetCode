#include "헤더.h"

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        // 예외
        if (prerequisites.size() == 0)
        {
            return true;
        }

        vector<int> vecCourse;
        vecCourse.resize(numCourses);

        // 경우의 수 따지기
        for (int i = 0; i < prerequisites.size(); ++i)
        {
            ++vecCourse[prerequisites[i][0]];
            --vecCourse[prerequisites[i][1]];
        }

        // 과목을 신청할 수 있는지 체크
        for (int i = 0; i < vecCourse.size(); ++i)
        {
            if (vecCourse[i] == 0)
                return false;
        }

        return true;
    }
};