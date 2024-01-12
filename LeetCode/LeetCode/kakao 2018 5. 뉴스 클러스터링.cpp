#include "헤더.h"

int solution(string str1, string str2)
{
    //return (float)2 / 3 * 65536;
    int 분자 = 0;
    int 분모 = 0;
    multiset<string> 비교;

    for (int i = 0; i < str1.length() - 1; ++i)
    {
        string buf;
        if ('a' <= str1[i] && str1[i] <= 'z')
            buf += str1[i];
        else if ('A' <= str1[i] && str1[i] <= 'Z')
            buf += str1[i] + ('a' - 'A');
        else
            continue;

        if ('a' <= str1[i + 1] && str1[i + 1] <= 'z')
            buf += str1[i + 1];
        else if ('A' <= str1[i + 1] && str1[i + 1] <= 'Z')
            buf += str1[i + 1] + ('a' - 'A');
        else
            continue;

        비교.insert(buf);
        ++분모; // 새 데이터면 분모를 늘림(같은 문자열끼리의 중복은 체크하지 않음)
    }

    for (int i = 0; i < str2.length(); ++i)
    {
        string buf;
        if ('a' <= str2[i] && str2[i] <= 'z')
            buf += str2[i];
        else if ('A' <= str2[i] && str2[i] <= 'Z')
            buf += str2[i] + ('a' - 'A');
        else
            continue;

        if ('a' <= str2[i + 1] && str2[i + 1] <= 'z')
            buf += str2[i + 1];
        else if ('A' <= str2[i + 1] && str2[i + 1] <= 'Z')
            buf += str2[i + 1] + ('a' - 'A');
        else
            continue;
        auto it = 비교.find(buf);
        if (it != 비교.end())
        {
            비교.erase(it);
            ++분자; // 중복이면 분자를 늘림
        }
        else
        {
            ++분모; // 새 데이터면 분모를 늘림
        }
    }

    if (분자 == 0)
    {
        if (분모 == 0) // -> 어떤 조합도 유효하지 않음
            return 65536;
        return 0; // -> 두 문자열 중 아무 조합도 겹치지 않음
    }

    return int(((float)분자 / 분모) * 65536.f);
}