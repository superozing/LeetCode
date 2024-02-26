#include <iostream>
#include <vector>

using namespace std;

class BAEKJOON // ��� ���� ����
{
public:
    int                 T;      // �׽�Ʈ ���̽� ����
    vector<int>         t;      // �׽�Ʈ ���̽�

    unsigned long long  dp[1001][10]; // dp[x][y] - x => ��й�ȣ ����, y => 0~9������ Ű����

public:
    BAEKJOON() { progress(); }
    void init();
    int progress();
};

void BAEKJOON::init()
{
    cin >> T;

    t.resize(T);

    for (int i = 0; i < T; ++i)
        cin >> t[i];

    // ��й�ȣ ���̰� 1�� ����� �ʱ� �� ���� (1)
    for (int i = 0; i < 10; ++i)
        dp[1][i] = 1;

}

int BAEKJOON::progress()
{
    init();

    // ��й�ȣ�� ���� 2~1000���� ���
    for (int i = 2; i <= 1000; ++i)
    {
        // ��� ���ڿ� ���ؼ� ������ ����� �� ����
        for (int j = 0; j <= 10; ++j)
        {
            switch (j)
            {
            case 0: // 7
                dp[i][j] = dp[i - 1][7];
                break;
            case 1: // 2, 4
                dp[i][j] = dp[i - 1][2] + dp[i - 1][4];
                break;
            case 2: // 1, 3, 5
                dp[i][j] = dp[i - 1][1] + dp[i - 1][3] + dp[i - 1][5];
                break;
            case 3: // 2, 6
                dp[i][j] = dp[i - 1][2] + dp[i - 1][6];
                break;
            case 4: // 1, 5, 7
                dp[i][j] = dp[i - 1][1] + dp[i - 1][5] + dp[i - 1][7];
                break;
            case 5: // 2, 4, 6, 8
                dp[i][j] = dp[i - 1][2] + dp[i - 1][4] + dp[i - 1][6] + dp[i - 1][8];
                break;
            case 6: // 3, 5, 9
                dp[i][j] = dp[i - 1][3] + dp[i - 1][5] + dp[i - 1][9];
                break;
            case 7: // 4, 8, 0
                dp[i][j] = dp[i - 1][4] + dp[i - 1][8] + dp[i - 1][0];
                break;
            case 8: // 5, 7, 9
                dp[i][j] = dp[i - 1][5] + dp[i - 1][7] + dp[i - 1][9];
                break;
            case 9: // 6, 8
                dp[i][j] = dp[i - 1][6] + dp[i - 1][8];
                break;
            }
        }
    }

    // ��� ���
    unsigned long long res = 0;

    for (auto& it : t)
    {
        res = 0;

        // ���� ������ ���� �����ؾ� ������ �Ѿ�� ����
        for (int i = 0; i < 10; ++i)
            res = (res + dp[it][i]) % 1234567;

        cout << res % 1234567 << endl;
    }

    return 0;
}

int main()
{
    BAEKJOON b;
    return 0;
}

