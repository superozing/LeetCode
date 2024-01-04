#include "헤더.h"

class Solution 
{
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        if (n == 0)
            return tasks.size();

        int returnVal = 0;

        // **n번의 간격 동안 같은 동작을 수행할 수 없다**
        // 그러면 많은 애들부터 천천히 까면 되겠네요.
        vector<int> TaskCount(26);
        vector<int> Cool(26);

        // 일단 업무 수를 기록하기.
        for (auto& task : tasks)
            ++TaskCount[task - 'A'];

        while (true)
        {
            // 큰 값 찾기
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