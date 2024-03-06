#include <iostream>
#include <vector>

#include <algorithm>

using namespace std;

class BAEKJOON // 동전 2
{
public:
    int         N;      // 동전 개수 
    int         K;      // 목표 원

    vector<int> coins;

    vector<int> dp;     // dp[i] - i원일 때 최소 동전 개수 

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
    
    // 가장 적은 개수를 구하기 위해서 초기 값을 가장 큰 값으로 만들어주어요.
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
