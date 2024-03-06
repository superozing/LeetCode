#include <iostream>
#include <vector>

#include <algorithm>

using namespace std;

class BAEKJOON // ���� 2
{
public:
    int         N;      // ���� ���� 
    int         K;      // ��ǥ ��

    vector<int> coins;

    vector<int> dp;     // dp[i] - i���� �� �ּ� ���� ���� 

public:
    BAEKJOON() { init(); }
    void init();
    void progress();

private:
};

void BAEKJOON::init()
{
    cin >> N >> K;

    coins.resize(N);
    
    // ���� ���� ������ ���ϱ� ���ؼ� �ʱ� ���� ���� ū ������ ������־��.
    dp.resize(K + 1, INT_MAX);

    for (int i = 0; i < N; ++i)
        cin >> coins[i];
}


void BAEKJOON::progress()
{
    for (auto& coin : coins)
    {
        for (int i = coin; i * coin < dp.size(); ++i)
            dp[i] = min(dp[i], dp[i - coin] + i);   

    }

    cout << dp.back();

}

int main()
{
    BAEKJOON b;
    b.progress();

    return 0;
}
