#include <iostream>
#include <set>
#include <vector>
#include <string>

using namespace std;

class BAEKJOON // �躸��
{
public:
    int N; // �赵 ���� ���
    int M; // ���� ���� ���

    set<string> s; // �赵 ���� ��� ���

    set<string> v; // �赵 ���� ���� ��� ���

public:
    BAEKJOON() { init(); }
    void init();
    void progress();

private:
};

void BAEKJOON::init()
{
    cin >> N >> M;

    string buf{};

    // ��
    for (int i = 0; i < N; ++i)
    {
        cin >> buf;
        s.insert(buf);
    }
}

void BAEKJOON::progress()
{
    string buf{};

    // ��
    for (int i = 0; i < M; ++i)
    {
        cin >> buf;

        if (s.find(buf) != s.end())
            v.insert(buf);
    }

    cout << v.size() << endl;

    // �躸
    for (auto& it : v)
        cout << it << endl;

}

int main()
{
    BAEKJOON b;
    b.progress();

    return 0;
}
