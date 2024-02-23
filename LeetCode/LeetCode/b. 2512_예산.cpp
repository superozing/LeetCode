#include <iostream>
#include <vector>

using namespace std;

class BAEKJOON // ����
{
public:
    int N;              // ���� ����
    int M;              // �� ����
    vector<int> area;   // ���渶�� ��û���� ����

    int maxBudget;

public:
    BAEKJOON() { cout << progress() << endl; }
    void init();
    int progress();

private:
    int fullBudget(int budget);
};

void BAEKJOON::init()
{
    cin >> N;

    area.resize(N);

    maxBudget = 0;

    for (int i = 0; i < N; ++i)
    {
        // M ��Ȱ�� �غþ��.
        cin >> M;
        area[i] = M;
        maxBudget = max(maxBudget, M);
    }

    cin >> M;
}

int BAEKJOON::progress()
{
    init();

    int l = N;
    int r = maxBudget;
    int sum = 0;
    int mid = 0;

    while (l <= r)
    {
        mid = (l + r) / 2;

        sum = fullBudget(mid);

        // �غ�� ���꺸�� ���� ���
        if (M >= sum)
            l = mid + 1;

        // �غ�� ���꺸�� Ŭ ���
        else
            r = mid - 1;
    }

    return r;
}

int BAEKJOON::fullBudget(int budget)
{
    int ret = 0;

    for (int i = 0; i < area.size(); ++i)
        ret += min(area[i], budget);

    return ret;
}

int main()
{
    BAEKJOON b;

    return 0;
}

