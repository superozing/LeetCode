#include <iostream>
#include <vector>

using namespace std;

class BAEKJOON // �ﰢ���� ��
{
public:
    int N; // ��ȣ�� count
    int K; // �������� �����ؾ� �ϴ� ��ȣ���� ����
    int B; // ���峭 ��ȣ���� ����
    vector<bool> road;

public:
    BAEKJOON() { init(); }
    void init();
    void progress();

private:

    int search(int l, int r);

};
int BAEKJOON::search(int l, int r)
{
    static int sinhoCount = -1;

    if (-1 == sinhoCount) // ù �����
    {
        sinhoCount = 0;
        for (int i = l; i <= r; ++i)
        {
            if (road[i])
                ++sinhoCount;
        }
    }
    else // ���� �����
    {
        if (road[l - 1] == true)
            --sinhoCount;
        if (road[r] == true)
            ++sinhoCount;
    }

    return sinhoCount;
}

void BAEKJOON::init()
{
    cin >> N;
    road.resize(N + 1);
    cin >> K;
    cin >> B;

    int buf = 0;

    for (int i = 0; i < B; ++i)
    {
        cin >> buf;
        road[buf] = true;
    }
}

void BAEKJOON::progress()
{
    // �����̵� ������ ����.
    // ������ ũ��: K

    // �ּ� �� ���� ��ȣ���� �����ؾ� �ϴ°�? -> bool �� �� true�� ����.
    // left ~ right ������ bool ���� ����ؼ� ���� ��, ���� ���� ���� ����ؾ� �Ѵ�.
    // �ٵ� �̷��� Ǯ�� ���� Ÿ�� �ƿ��� �� �� ���� ������ ��µ���...???
    // �����͸� �ߺ��ؼ� �˻��ϸ� �ȵ� ������ ��¦ ���.
    // �ϴ� �ߺ��ؼ� �˻��ϴ� ���� ����ؼ� �غ����? -> ���ó� �ð� �ʰ��� ����.

    int left = 1;
    int right = K;

    int returnVal = K;

    while (right != N + 1)
    {
        returnVal = min(search(left, right), returnVal);
        //cout << returnVal << endl << endl;
        ++left;
        ++right;
    }

    cout << returnVal;
}

int main()
{
    BAEKJOON b;
    b.progress();

    return 0;
}
