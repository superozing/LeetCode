#include "헤더.h"

int isOverlap(string& _str, list<string>& city, int cacheSize)
{
    for (auto& ch : _str)
        if (ch < 'a') ch += ('a' - 'A');

    bool isFind = false;

    for (list<string>::iterator iter = city.begin(); iter != city.end();)
    {
        if (*iter == _str)
        {
            isFind = true;
            city.erase(iter);
            city.push_back(_str);
            break;
        }
        ++iter;
    }

    if (!isFind)
    {
        city.push_back(_str);

        if (city.size() >= cacheSize)
            city.pop_front();

        return 5;
    }


    return 1;
}

int solution(int cacheSize, vector<string> cities)
{
    // 조건)
    // 1. 대소문자 구분 없음. 이 걸 구분할 수 있는 입력을 받아야 한다. 변환할 수 있는 함수를 하나 만드는 것도 좋을 듯.

    // 2. 왠만하면 큐 로 구현하는게 좋아보임.

    // 3. 데이터를 찾을 때, 만약 있는 데이터 인지 판별하기 위해서 큐를 순회해야 하고
    //      있을 경우) 데이터를 뽑아서 push_back하면 될 듯
    //      없을 경우) 새로 데이터 삽입. 이 경우 만약 데이터 크기가 초과한다면 pop_front하면 될 것.

    list<string> cityList;
    int secCount = 0;

    for (size_t i = 0; i < cities.size(); ++i)
        secCount += isOverlap(cities[i], cityList, cacheSize);

    return secCount;
}