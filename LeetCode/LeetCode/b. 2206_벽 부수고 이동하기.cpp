#include <iostream>
#include <vector>
#include <string>
#include <list>

#include <algorithm>

using namespace std;

auto constexpr _MAX = 999999999;

class BAEKJOON
{
	// NxM ���
	int N; // �� ��
	int M; // �� ��

	vector<string> vMap;	// ���� (NxM ���)
	vector<string> visited; // �湮 Ȯ�� �뵵 (NxM ���)

	int arrY[4] = { -1, 0, 1, 0 };
	int arrX[4] = { 0, -1, 0, 1 };

public:
	void init();
	void progress();

	int ignoreSearch(int ignoreY, int ignoreX);

public:
	BAEKJOON() { init(); }
	~BAEKJOON() {}
};


void BAEKJOON::init()
{
	// (1, 1)���� (N, M)���� �̵��ؾ� �ؿ�.

	cin >> N >> M;

	vMap.resize(N);
	visited.resize(N, string(M, '0'));


	// ������ ���� �Է� �ޱ�
	for (int i = 0; i < N; ++i)
		cin >> vMap[i];

}

void BAEKJOON::progress()
{
	// ��... �ٷ� �������� ������
	// ���� �߿� �� �ϳ��� 0���� �����ϰ� Ž���� �ϰ�,
	// �� ���� ��� 1�� ����ִ� ��ġ�� �ݺ��ϸ� �� �� ���⵵ �ϰ��...?


	int returnVal = _MAX;

	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < M; ++x)
		{
			// ������ ��ȸ�ϸ鼭 ���� ���� ���, �ش� ���� ������ ���·� ��ȸ�� ����� ��ȯ����.
			if (vMap[y][x] == '1')
				returnVal = min(returnVal, ignoreSearch(y, x));
		}
	}

	// ���������� �ƹ� ���� ���������� ���� ��쿡 ���� ���� ó���� ���־��.
	returnVal = min(returnVal, ignoreSearch(0, 0));

	if (_MAX == returnVal)
		cout << -1;
	else
		cout << returnVal;
}

typedef pair<pair<int, int>, int>  pii;

int BAEKJOON::ignoreSearch(int ignoreY, int ignoreX)
{
	// piii�� 1��° - Y, 2��° - X, 3��° - Ž�� Ƚ��
	int returnVal = _MAX;

	// ���ڷ� ���� �κ��� 0���� �����ϰ� Ž��
	vMap[ignoreY][ignoreX] = '0';

	list<pii> q;

	q.push_back({ { 0, 0 }, 0 });

	visited[0][0] = 1;

	while (!q.empty())
	{
		pii cur = q.front();
		q.pop_front();

		int Y = cur.first.first;
		int X = cur.first.second;
		int count = cur.second + 1;

		for (int i = 0; i < 4; ++i)
		{
			int curY = Y + arrY[i];
			int curX = X + arrX[i];


			if (0 <= curY && curY < N		// Y�� �ε��� ���ǿ� ����
				&& 0 <= curX && curX < M	// X�� �ε��� ���ǿ� ����
				&& visited[curY][curX] != '1'  // �̹� �湮���� ���� ����
				&& vMap[curY][curX] != '1')	// ���� �����ֳ���
			{
				// Ż�� ����
				if (curY == N - 1 && curX == M - 1)
				{
					returnVal = count + 1;
					break;
				}
				visited[curY][curX] = '1'; // �湮 ó��
				q.push_back({ { curY , curX }, count });
			}
		}

	}


	// visited ����ϰ� �б�
	visited.clear();
	visited.resize(M, string(N, '0'));

	// ������� �� �����
	vMap[ignoreY][ignoreX] = '1';

	return returnVal;
}

int main()
{
	BAEKJOON b;
	b.progress();

	return 0;
}