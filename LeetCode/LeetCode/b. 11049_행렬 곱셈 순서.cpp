#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ii;

class BAEKJOON // 행렬 곱셈 순서
{
public:
    int                 N;      // 행렬 개수
    vector<ii>          mat;    // 행렬 벡터 - pair<행, 열>
    vector<vector<int>> dp;     // dp[x][y] - x번째 행렬에서 y번째 행렬까지 연산했을 경우의 최솟값

public:
    BAEKJOON() { cout << progress() << endl; }
    void init();
    int progress();
};

void BAEKJOON::init()
{
    cin >> N;

    mat.resize(N + 1);
    mat.push_back({});

    for (int i = 1; i < N; ++i)
        cin >> mat[i].first >> mat[i].second;

    vector<int> buf(N + 1);
    dp.resize(N + 1, buf);
}

int BAEKJOON::progress()
{
    init();

    // i - 행렬 개수
    // j - 시작 행렬
    // k - 행렬 가르기

    // for문으로 j ~ i + j까지 행렬 곱셈의 최소 개수를 구함.
    // k - j ~ j + i까지 반복

    int _N = 0;
    int _M = 0;
    int _K = 0;

    for (int i = 1; i < N; ++i)
    {
        for (int j = 1; i + j < N; ++j)
        {
            dp[j][i + j] = INT_MAX;

            for (int k = j; k <= i + j; ++k)
            {
                // N * M * K = 행렬 곱셈 개수
                int mulCount = mat[j].first * mat[k].second * mat[i + j].second;

                // 행렬 범위를 k를 기준으로 두 부분의 행렬으로 쪼개고, 두 행렬의 곱셈 연산 개수를 구함
                int dpA = dp[j][k];
                int dpB = dp[k + 1][i + j];

                dp[j][i + j] = min(dp[j][i + j], dpA + dpB + mulCount);
            }
        }
    }

    return dp[1][N];
}

int main()
{
    BAEKJOON b;
    return 0;
}

