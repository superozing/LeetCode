#include <iostream>
#include <queue>

using namespace std;


class BAEKJOON // ÃÖ´ë Èü
{
public:
    priority_queue<int> pq;
    int             count;

public:
    BAEKJOON() { progress(); }
    void progress();

};

void BAEKJOON::progress()
{
    cin >> count;

    int buf = 0;

    for (int i = 0; i < count; ++i)
    {
        cin >> buf;
        if (buf != 0)
        {
            pq.push(buf);
        }
        else
        {
            if (pq.empty())
            {
                cout << 0 << endl;
            }
            else
            {
                cout << pq.top() << endl;
                pq.pop();
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    BAEKJOON b;

    return 0;
}
