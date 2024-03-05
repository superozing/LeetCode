#include <iostream>
#include <vector>

#include <algorithm>

using namespace std;

class BAEKJOON // ������ �ý�
{
public:
    int         N;      // ������ ��
    vector<int> wine;   // ������ ����
    vector<int> dp;     // dp[n] => wine[n]���� ������ �� �ִ�� ���� �� �ִ� �������� ��

public:
    BAEKJOON() { init(); }
    void init();
    void progress();

private:
};

void BAEKJOON::init()
{
    cin >> N;

    wine.resize(N + 1, 0);
    dp.resize(N + 1, 0);

    // ������ ���� ä���
    for (int i = 1; i < wine.size(); ++i)
        cin >> wine[i];
}


void BAEKJOON::progress()
{
    // dp�� �ʱⰪ ����
    dp[0] = 0;
    dp[1] = wine[1];
    dp[2] = wine[1] + wine[2];

    // �׷��� dp[3]�� �����ϱ�...?
    // dp[3] = (wine[1] + wine[2]) , (wine[1] + wine[3]) , (wine[2] + wine[3]) �߿� max

    // �׷��� dp[4]�� �����ϱ�...?
    // dp[4] = (wine[1] + wine[2] + wine[4]) �Ǵ� (wine[1] + wine[3] + wine[4]) �Ǵ� (wine[2] + wine[3]) �߿� max

    // �̰� �����ϸ�
    //      (wine[2] + wine[3]) => dp[3]�� ���ԵǾ� �ִ� 3����(wine[1] + wine[2],  wine[1] + wine[3],  wine[2] + wine[3]) �� �ϳ�. 
    //              wine[1] + wine[2], wine[1] + wine[3]�� ��쿡�� ������ wine[4]�� ���� ���� ũ�� ������ 
    //              ���� dp[3]�� ���� wine[2] + wine[3]�̾��� ��찡 Ŭ ���� ���ؼ� üũ��.
    //              �׷��� dp[3]���� ġȯ ����
    //      (wine[1] + wine[2] + wine[4]) => dp[2]�� wine[4]�� ���� ��. 
    //      (wine[1] + wine[3] + wine[4]) => dp[1]�� wine[3] + wine[4]�� ���� ��. 
    // 
    //      
    // dp[4] = max( { dp[3], dp[2] + wine[4], dp[1] + wine[3] + wine[4] } ); 


    // �̰� i�� �ٲٸ�
    // dp[i] = max( { dp[i - 1], dp[i - 2] + wine[i], dp[i - 3] + wine[i - 1] + wine[i] } );


    for (int i = 3; i < dp.size(); ++i)
    {
        dp[i] = max({ dp[i - 1]
                    , dp[i - 2] + wine[i]
                    , dp[i - 3] + wine[i - 1] + wine[i] });
    }

    cout << dp.back();
}

int main()
{
    BAEKJOON b;
    b.progress();

    return 0;
}
