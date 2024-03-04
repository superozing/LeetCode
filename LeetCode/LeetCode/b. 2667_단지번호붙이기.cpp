#include <iostream>
#include <vector>
#include <string>
#include <list>

#include <algorithm>

using namespace std;

class BAEKJOON // ������ȣ���̱�
{
public:
    int N;                  // ���� ���� NxN
    vector<string>  vMap;   // ����

    vector<int>     result; // ���� ������ �����ؿ�.

    int _arrX[4] = { 0, -1, 0, 1 };
    int _arrY[4] = { -1, 0, 1, 0 };

public:
    BAEKJOON() { init(); }
    void init();
    void progress();

private:
    int search(int y, int x);
};

void BAEKJOON::init()
{
    cin >> N;

    vMap.resize(N);

    // ���� ���� �Է¹޾� �����ϱ�
    for (int i = 0; i < N; ++i)
        cin >> vMap[i];

}

typedef pair<int, int> pii;

int BAEKJOON::search(int y, int x)
{
    vMap[y][x] = '0';

    list<pii> q;
    q.push_back({ y, x });

    int Y = 0;
    int X = 0;

    int houseCount = 0;

    while (!q.empty())
    {
        // ť�� ù ������ ������
        pii ii = q.front();
        q.pop_front();

        // ���� ���� ���� ++
        ++houseCount;

        // �̹����� for�� ����غ��Ҿ��.
        for (int i = 0; i < 4; ++i)
        {
            Y = ii.first + _arrY[i];
            X = ii.second + _arrX[i];

            // �ε��� ������ ����� �����鼭, �������� �ش� ��ġ�� ���� ���� �� ����ֱ�
            if ((0 <= Y && Y < N && 0 <= X && X < N) && (vMap[Y][X] == '1'))
            {
                q.push_back({ Y, X });
                vMap[Y][X] = '0'; // ���� ������� �ε����� 0���� ����
            }
        }
    }

    return houseCount;
}

void BAEKJOON::progress()
{
    // ��� ������ ��ȸ�ϸ鼭, ���� �ε����� ���� ���� ��� Ž��
    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < N; ++x)
        {
            if (vMap[y][x] == '1')
                result.push_back(search(y, x));
        }
    }


    // ��� ���
    cout << result.size() << endl;

    for (auto& it : result)
        cout << it << endl;
}

int main()
{
    BAEKJOON b;
    b.progress();

    return 0;
}
