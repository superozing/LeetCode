#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ii;

class BAEKJOON // ��� ���� ����
{
public:
    int                 N;      // ��� ����
    vector<ii>          mat;    // ��� ���� - pair<��, ��>
    vector<vector<int>> dp;     // dp[x][y] - x��° ��Ŀ��� y��° ��ı��� �������� ����� �ּڰ�

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

    // i - ��� ����
    // j - ���� ���
    // k - ��� ������

    // for������ j ~ i + j���� ��� ������ �ּ� ������ ����.
    // k - j ~ j + i���� �ݺ�

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
                // N * M * K = ��� ���� ����
                int mulCount = mat[j].first * mat[k].second * mat[i + j].second;

                // ��� ������ k�� �������� �� �κ��� ������� �ɰ���, �� ����� ���� ���� ������ ����
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

