#include "���.h"

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        // ����
        if (prerequisites.size() == 0)
        {
            return true;
        }

        vector<int> vecCourse;
        vecCourse.resize(numCourses);

        // ����� �� ������
        for (int i = 0; i < prerequisites.size(); ++i)
        {
            ++vecCourse[prerequisites[i][0]];
            --vecCourse[prerequisites[i][1]];
        }

        // ������ ��û�� �� �ִ��� üũ
        for (int i = 0; i < vecCourse.size(); ++i)
        {
            if (vecCourse[i] == 0)
                return false;
        }

        return true;
    }
};