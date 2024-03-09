#include <iostream>
#include <vector>
#include <string>
#include <list>

#include <algorithm>

using namespace std;

auto constexpr _MAX = 999999999;

class BAEKJOON
{
	// NxM 행렬
	int N; // 행 수
	int M; // 열 수

	vector<string> vMap;	// 지도 (NxM 행렬)
	vector<string> visited; // 방문 확인 용도 (NxM 행렬)

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
	// (1, 1)에서 (N, M)까지 이동해야 해요.

	cin >> N >> M;

	vMap.resize(N);
	visited.resize(N, string(M, '0'));


	// 지도에 정보 입력 받기
	for (int i = 0; i < N; ++i)
		cin >> vMap[i];

}

void BAEKJOON::progress()
{
	// 음... 바로 떠오르는 생각은
	// 지도 중에 벽 하나를 0으로 무시하고 탐색을 하고,
	// 이 것을 모든 1이 들어있는 위치에 반복하면 될 것 같기도 하고요...?


	int returnVal = _MAX;

	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < M; ++x)
		{
			// 지도를 순회하면서 벽이 있을 경우, 해당 벽을 제거한 상태로 순회한 결과를 반환받음.
			if (vMap[y][x] == '1')
				returnVal = min(returnVal, ignoreSearch(y, x));
		}
	}

	// 마지막으로 아무 벽도 세워져있지 않을 경우에 대한 예외 처리를 해주어요.
	returnVal = min(returnVal, ignoreSearch(0, 0));

	if (_MAX == returnVal)
		cout << -1;
	else
		cout << returnVal;
}

typedef pair<pair<int, int>, int>  pii;

int BAEKJOON::ignoreSearch(int ignoreY, int ignoreX)
{
	// piii의 1번째 - Y, 2번째 - X, 3번째 - 탐색 횟수
	int returnVal = _MAX;

	// 인자로 들어온 부분을 0으로 생각하고 탐색
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


			if (0 <= curY && curY < N		// Y가 인덱스 조건에 부합
				&& 0 <= curX && curX < M	// X가 인덱스 조건에 부합
				&& visited[curY][curX] != '1'  // 이미 방문하지 않은 지점
				&& vMap[curY][curX] != '1')	// 길이 막혀있나요
			{
				// 탈출 조건
				if (curY == N - 1 && curX == M - 1)
				{
					returnVal = count + 1;
					break;
				}
				visited[curY][curX] = '1'; // 방문 처리
				q.push_back({ { curY , curX }, count });
			}
		}

	}


	// visited 깔끔하게 밀기
	visited.clear();
	visited.resize(M, string(N, '0'));

	// 원래대로 벽 세우기
	vMap[ignoreY][ignoreX] = '1';

	return returnVal;
}

int main()
{
	BAEKJOON b;
	b.progress();

	return 0;
}