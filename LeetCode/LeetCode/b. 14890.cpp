#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef pair<int, bool> p;

class BAEKJOON_14890 // 경사로
{
public:
	int					n; // nxn 행렬
	int					L; // 경사로의 길이
	vector<vector<p>> vMap; // 이번엔 pair로 관리해보아요. first 값은 높이, second 값은 경사로 설치 여부를 사용하면 될 듯.

public:
	BAEKJOON_14890() { init(); }
	void init();
	int  progress();

};

void BAEKJOON_14890::init()
{
	cin >> n;
	cin >> L;

	vector<p> vBuf(n, {0, false}); // 페어의 기본 값을 0,0으로 초기화

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			cin >> vBuf[i].first;

		vMap.push_back(vBuf);
	}
}


int BAEKJOON_14890::progress()
{
	// 조건)
	// 0. 지나갈 수 있도록 낮은 칸에 경사로를 설치해주어야 함.
	// 1. 높이 차이가 1 이상이면 지나갈 수 없는 길.
	// 2. 경사로가 겹쳐서는 안된다.
	// 3. 경사로를 놓을 때 남은 칸을 벗어나서는 안된다.

	// 행 정렬.. 을 하기 전에 첫 번째 줄 먼저 정렬을 해보고 늘려보는게 좋을 듯.

	int returnVal = 0;
	bool isVaild = false;
	bool flag = false;
	for (int i = 0; i < n; ++i)
	{
		vector<p>& v = vMap[i];
		isVaild = false;

		// n - 1번만 돌아서 마지막 데이터까지 알아서 정렬하기.
		for (int j = 0; j < n - 1; ++j)
		{
			// 높을 경우
			if (v[j].first > v[j + 1].first)
			{
				// 1. 높이 차이가 1이 아니라면 유효하지 않은 높이
				if (v[j].first - v[j + 1].first != 1 || j + L >= n)
					break;

				flag = false;

				// 2. 다음 인덱스에 이미 경사로가 깔려있는가?
				for (int k = 1; k < L; ++k)
				{
					if (v[j + k].second == true)
					{
						flag = true;
						break;
					}
				}
				if (flag) 
					break;

				// 1과 2는
				v[j + 1].second = true;
			}
			// 낮을 경우
			else if (v[j].first < v[j + 1].first)
			{
				if ((v[j + 1].first - v[j].first != 1) || (v[j].second == true))
					break;

				v[j].second = true;
			}

		}

		if (isVaild)
			++returnVal;
	}



	// 열 정렬




	return 0;
}


int main()
{
	BAEKJOON_14890 b;
	cout << b.progress();
	return 0;
}