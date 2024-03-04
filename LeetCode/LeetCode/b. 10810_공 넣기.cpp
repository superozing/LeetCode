#include <iostream>
#include <vector>

using namespace std;

class BAEKJOON // �� �ֱ�
{
public:
    int N; // �ٱ��� ����
    int M; // ���� ���� ��

    vector<int> basket;

public:
    BAEKJOON() { init(); }
    void init();
    void progress();

private:
};

void BAEKJOON::init()
{
    cin >> N >> M;
    basket.resize(N + 1);
}

void BAEKJOON::progress()
{
    int start = 0;
    int end = 0;
    int fill = 0;

    for (int i = 0; i < M; ++i)
    {
        cin >> start >> end >> fill;

        for (; start <= end; ++start)
            basket[start] = fill;
    }

    for (int i = 1; i < basket.size(); ++i)
        cout << basket[i] << " ";
}

int main()
{
    BAEKJOON b;
    b.progress();

    return 0;
}
