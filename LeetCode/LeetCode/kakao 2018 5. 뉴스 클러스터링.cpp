#include "���.h"

int solution(string str1, string str2)
{
    //return (float)2 / 3 * 65536;
    int ���� = 0;
    int �и� = 0;
    multiset<string> ��;

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

        ��.insert(buf);
        ++�и�; // �� �����͸� �и� �ø�(���� ���ڿ������� �ߺ��� üũ���� ����)
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
        auto it = ��.find(buf);
        if (it != ��.end())
        {
            ��.erase(it);
            ++����; // �ߺ��̸� ���ڸ� �ø�
        }
        else
        {
            ++�и�; // �� �����͸� �и� �ø�
        }
    }

    if (���� == 0)
    {
        if (�и� == 0) // -> � ���յ� ��ȿ���� ����
            return 65536;
        return 0; // -> �� ���ڿ� �� �ƹ� ���յ� ��ġ�� ����
    }

    return int(((float)���� / �и�) * 65536.f);
}