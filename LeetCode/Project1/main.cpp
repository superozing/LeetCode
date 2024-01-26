#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <cmath>

using namespace std;

class BAEKJOON // 숨바꼭질
{
public:
    int n; // 수빈이의 위치
    int k; // 동생의 위치
    const int MAX = 100001;
    string road;

public:
    BAEKJOON() { init(); }
    void init();
    int progress();

    int search();
};

void BAEKJOON::init()
{
    cin >> n;
    cin >> k;

    road.resize(MAX, 'x');
}

typedef pair<int, int> ii;

int BAEKJOON::search()
{
    list<ii> q;

    q.push_back({ n, 0 });
    road[n] = 'o';

    while (!q.empty())
    {
        ii b = q.front(); q.pop_front();
        int N = b.first;
        int move = b.second;

        if (N == k) // 일치하는 경우
            return move;
        else
        {
            if (N + 1 < MAX && road[N + 1] == 'x') // +1 움직일 경우
            {
                road[N + 1] = 'o';
                q.push_back({ N + 1, move + 1 });
            }
            if (N * 2 < MAX && road[N * 2] == 'x') // *2 움직일 경우
            {
                road[N * 2] = 'o';
                q.push_back({ N * 2, move + 1 });
            }
            if (N > 0 && road[N - 1] == 'x') // -1 움직일 경우
            {
                road[N - 1] = 'o';
                q.push_back({ N - 1, move + 1 });
            }
        }
    }

    return -1;
}

int BAEKJOON::progress()
{
    return search();
}

int main()
{
    BAEKJOON b;
    cout << b.progress();
    return 0;
}
