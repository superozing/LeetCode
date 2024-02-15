#include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace std;

class BAEKJOON // ����� ����
{
public:

    int T; // �׽�Ʈ ���̽� ��

    int M; // ���� ���� x
    int N; // ���� ���� y
    int K; // ���� ����

    vector<string> d; // ���� ���̴� string�� ���̰� �Ǿ�� �ϰ�, ���� ���̴� string�� ������ �Ǿ�� �Ѵ�.
    vector<string> visited;


    int returnVal;

public:
    BAEKJOON() { init(); }
    void init();
    void progress();
    void search(int y, int x);

};

typedef pair<int, int> ii;


void BAEKJOON::search(int y, int x)
{
    // ��...���� ��� ���� �κп� visited üũ�� ���־�� �Ѵ�.
    // [y][x] ������ �����ؾ� �Ѵٴ� ���� ���� ���ƿ�.
    list<ii> q;

    q.push_back({ y, x });
    visited[y][x] = '1';

    while (!q.empty())
    {
        ii cur = q.front(); q.pop_front();

        int y = cur.first;
        int x = cur.second;


        // 1. �ε��� ���� üũ
        // 2. ���� �ִ��� Ȯ��
        // 3. visited Ȯ��
        if ((y + 1 < N) && (d[y + 1][x] == '1') && (visited[y + 1][x] == '0'))
        {
            q.push_back({ y + 1, x });
            visited[y + 1][x] = '1';
        }

        if ((y - 1 >= 0) && (d[y - 1][x] == '1') && (visited[y - 1][x] == '0'))
        {
            q.push_back({ y - 1, x });
            visited[y - 1][x] = '1';
        }

        if ((x + 1 < M) && (d[y][x + 1] == '1') && (visited[y][x + 1] == '0'))
        {
            q.push_back({ y, x + 1 });
            visited[y][x + 1] = '1';
        }

        if ((x - 1 >= 0) && (d[y][x - 1] == '1') && (visited[y][x - 1] == '0'))
        {
            q.push_back({ y, x - 1 });
            visited[y][x - 1] = '1';
        }
    }
}


// [y][x] �� �����ؾ߸� �Ѵ�.
void BAEKJOON::init()
{
    cin >> T;

    for (int i = 0; i < T; ++i)
    {
        M = 0;
        N = 0;
        K = 0;
        returnVal = 0;

        cin >> M;
        cin >> N;

        d.clear();
        visited.clear();

        string s;
        s.resize(M, '0');
        d.resize(N, s);
        visited.resize(N, s);

        cin >> K;

        int x = 0;
        int y = 0;

        for (int i = 0; i < K; ++i)
        {
            cin >> x;
            cin >> y;
            d[y][x] = '1';
        }

        progress();
    }
}


void BAEKJOON::progress()
{
    for (int y = 0; y < N; ++y)
        for (int x = 0; x < M; ++x)
            if (visited[y][x] == '0' && d[y][x] == '1')
            {
                search(y, x);
                ++returnVal;
            }

    cout << returnVal << endl;
}


int main()
{
    BAEKJOON b;

    return 0;
}
