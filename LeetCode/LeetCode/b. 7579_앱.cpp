#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ii;

class BAEKJOON // ��
{
public:
    int N; // ���ø�ĳ�̼� ����
    int M; // ��� ������ �ʿ��� �޸�
    vector<ii> app;     // ���ø����̼� - pair<������� �޸� ����Ʈ, ��Ȱ��ȭ ���>
    vector<int> dp;     // i ��ŭ�� cost�� ������� ��, �ִ�� ���� �� �ִ� �޸� ����Ʈ ���� �����ϴ� dp

public:
    BAEKJOON() { cout << progress() << endl; }
    void init();
    int progress();
};

void BAEKJOON::init()
{
    cin >> N;
    cin >> M;

    app.resize(N);

    for (int i = 0; i < N; ++i)
        cin >> app[i].first;

    for (int i = 0; i < N; ++i)
        cin >> app[i].second;

    // C �ִ� 100 * N �ִ� 100
    dp.resize(10001);
}

int BAEKJOON::progress()
{
    init();

    int byte = 0;
    int cost = 0;

    // i ��ŭ�� cost�� ������� ��, ������ �� �ִ� �ִ� byte ���� dp�� ����.
    //  dp[i - cost] + byte => dp[i - cost]���� ���� ��Ȱ��ȭ ������ �� ������ ����Ʈ ��.
    //  dp[i]               => ���� ��
    //  ������ ����Ʈ ���� ���� ���� dp�� �����Ŵ.

    for (auto& it : app)
    {
        byte = it.first;
        cost = it.second;

        for (int i = 10000; i >= 0; --i)
            if (i - cost >= 0)
                dp[i] = max(dp[i], dp[i - cost] + byte);
    }

    for (int i = 0; i <= 10000; ++i)
        if (M <= dp[i])
            return i;

    return 0;
}

int main()
{
    BAEKJOON b;
    return 0;
}

