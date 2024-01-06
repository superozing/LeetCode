#include "헤더.h"

struct p
{
    int score;
    int opt;
public:
    p(){}
    p(int a, int b) : score(a), opt(b){}
};

int solution(string str)
{
    p resVec[3]{ {0, 1}, {0, 1}, {0, 1} };

    int strIdx = 0;

    for (int i = 0; i < 3; ++i)
    {
        // 점수
        string scoreBuf = "";
        for (;; ++strIdx)
        {
            if ('0' <= str[strIdx] && str[strIdx] <= '9')
                scoreBuf += str[strIdx];
            else
                break;
        }

        resVec[i].score = stoi(scoreBuf);

        // 보너스
        switch (str[strIdx])
        {
        case 'T':
            resVec[i].score = pow(resVec[i].score, 3);
            break;

        case 'D':
            resVec[i].score = pow(resVec[i].score, 2);
        case 'S':
            break;
        }

        ++strIdx;

        // 옵션
        switch (str[strIdx])
        {
        case '*':
            resVec[0].opt *= 2;

            if (i > 0)
                resVec[i - 1].opt *= 2;

            break;

        case '#':
            resVec[i].opt *= -1;
            break;
        }
    }

    int ret = 0;

    for (int i = 0; i < 3; ++i)
        ret += resVec[i].score * resVec[i].opt;

    return ret;
}
