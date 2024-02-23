#include <iostream>
#include <vector>

using namespace std;

class BAEKJOON // �ﰢ���� ��
{
public:
    int N; // �뷡 ����
    int L; // �뷡 �ϳ� �� ����
    int D; // ��ȭ���� �︮�� ����
    vector<bool> vec;

public:
    BAEKJOON() { cout << progress(); }
    void init();
    int progress();

};

void BAEKJOON::init()
{
    cin >> N;
    cin >> L;
    cin >> D;
}

int BAEKJOON::progress()
{
    init();

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < L; ++j)
            vec.push_back(true);
        for (int j = 0; j < 5; ++j)
            vec.push_back(false);
    }

    // �߰��� ���� �ð�: 5��
    int i = 1;
    for (; i * D < vec.size(); ++i)
    {
        if (vec[i * D] == false)
            return i * D;
    }

    return i * D;

}

int main()
{
    BAEKJOON b;

    return 0;
}
