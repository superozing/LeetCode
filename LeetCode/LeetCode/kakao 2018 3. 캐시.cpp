#include "���.h"

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
    // ����)
    // 1. ��ҹ��� ���� ����. �� �� ������ �� �ִ� �Է��� �޾ƾ� �Ѵ�. ��ȯ�� �� �ִ� �Լ��� �ϳ� ����� �͵� ���� ��.

    // 2. �ظ��ϸ� ť �� �����ϴ°� ���ƺ���.

    // 3. �����͸� ã�� ��, ���� �ִ� ������ ���� �Ǻ��ϱ� ���ؼ� ť�� ��ȸ�ؾ� �ϰ�
    //      ���� ���) �����͸� �̾Ƽ� push_back�ϸ� �� ��
    //      ���� ���) ���� ������ ����. �� ��� ���� ������ ũ�Ⱑ �ʰ��Ѵٸ� pop_front�ϸ� �� ��.

    list<string> cityList;
    int secCount = 0;

    for (size_t i = 0; i < cities.size(); ++i)
        secCount += isOverlap(cities[i], cityList, cacheSize);

    return secCount;
}