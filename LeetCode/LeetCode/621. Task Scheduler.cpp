#include "���.h"

class Solution 
{
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        if (n == 0)
            return tasks.size();

        int returnVal = 0;

        // **n���� ���� ���� ���� ������ ������ �� ����**
        // �׷��� ���� �ֵ���� õõ�� ��� �ǰڳ׿�.
        vector<int> TaskCount(26);
        vector<int> Cool(26);

        // �ϴ� ���� ���� ����ϱ�.
        for (auto& task : tasks)
            ++TaskCount[task - 'A'];

        while (true)
        {
            // ū �� ã��
            int Max = 0;

            for (int i = 0; i < 26; ++i)
                Max = max(Max, TaskCount[i]);

            bool flag = false;
            bool end = false;

            for (int i = 0; i < 26; ++i)
            {
                if (Cool[i] == 0 && TaskCount[i] == Max)
                {
                    --TaskCount[i];
                    ++returnVal;
                    Cool[i] = n + 1;
                    flag = true;
                    end = true;
                    break;
                }

            }

            for (int i = 0; i < 26; ++i)
            {
                if (Cool[i] > 0)
                {
                    --Cool[i];
                    end = true;
                }
            }

            if (flag == false)
                ++returnVal;

            if (end == false)
                break;
        }

        return returnVal;
    }
};