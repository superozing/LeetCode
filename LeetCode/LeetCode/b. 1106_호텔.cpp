#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ii;

class BAEKJOON // ȣ��
{
public:
    int C; // ��� �÷��� �� �� ��
    int N; // ȫ���� �� �ִ� ������ ����
    vector<ii> city; // pair<ȫ�� ���, �� ��>
    vector<int> dp;  // ���� i ��ŭ ����� �� �ִ� �� �� 

public:
    BAEKJOON() { cout << progress() << endl; }
    void init();
    int progress();
};

void BAEKJOON::init()
{
    cin >> C;
    cin >> N;

    city.resize(N);

    for (int i = 0; i < N; ++i)
        cin >> city[i].first >> city[i].second;

    dp.resize(100001); // N �ִ밪 1000 * C �ִ밪 100
}

int BAEKJOON::progress()
{
    init();

    int cost = 0;
    int man = 0;

    // max(dp[i], dp[i - cost] + man)
    // 
    //  i(���� ����) ���� cost(ȫ�� ���) ��ŭ �� ������ 
    //  ȫ���� �������� ���� ����� ���ȴ�.
    //  
    //  dp[i]���� �ᱹ i��ŭ�� ����� ������� �� 
    //  i - cost ���� ȫ���� ������ �Ͱ�, �������� ���� �� 
    //  �� �߿� ������ �̵����� ����ȴ�.
    //  �� ���� ��� ������ ��쿡�� üũ�ذ��鼭 dp�� ä��������.

    for (auto& it : city)
    {
        cost = it.first; // ȫ���� ���Ǵ� ���
        man = it.second; // ȫ���� ��� ��� ��

        for (int i = 1; i <= 100000; ++i)
            if (i - cost >= 0)
                dp[i] = max(dp[i], dp[i - cost] + man);

    }


    for (int i = 1; i <= 100000; ++i)
        if (dp[i] >= C)
            return i;

    return 0;
}

int main()
{
    BAEKJOON b;
    return 0;
}

