#include <iostream>
#include <vector>
#include <string>

using namespace std;


class BAEKJOON_2805 // 퇴사
{
public:
	int			n;
	vector<int> vecT;
	vector<int> vecP;

public:
	void init();
	void progress();
};



void BAEKJOON_2805::init()
{
	string strbuf = "";
	string strnum = "";
	int index;

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		strbuf = "";
		strnum = "";
		index = 0;
		cin >> strbuf;
		while (strbuf[index] != ' ')
		{
			strnum += strbuf[index++];
			vecT.push_back(stoi(strnum));
		}
		++index;
		strnum = "";
		for (; index < strbuf.length(); ++index)
		{
			strnum += strbuf[index];
			vecP.push_back(stoi(strnum));
		}
	}
}

void BAEKJOON_2805::progress()
{
	n;	  // 최대날짜
	vecT; // 쿨
	vecP; // 이익
	// 모든 경우를 탐색해야만 하나봐요.

	int maxProfit = 0;
	int curProfit = 0;
	

	// 1) n만큼 돌면 되는데, 남은 날짜보다 더 많은 날짜를 상담해야 할 경우, 해당 인덱스는 사용할 수가 없어요.
	for (int i = 0; i < n; ++i)
	{
		// 현재 남은 날짜보다 상담 기간이 크다면 해당 날짜에 상담을 진행할 수 없다.
		// 이걸 미리 체크해두는 것도 좋을 듯.
		if (vecT[i] > n - i)
		{
			vecT[i] = 0;
			vecP[i] = 0;
		}
	}


	// 2) 모든 경우를 하나하나 전부 탐색하기 위해서는 어떻게 해야 할까?
	// 이게 한 가지의 경우를 구하는 방법.
	for (int i = 0; i < n; ++i)
	{
		curProfit += vecP[i];
		i += vecT[i];
	}



	cout << curProfit;
	return;



}












int main()
{
	BAEKJOON_2805 b;

	b.init();
	b.progress();
	return 0;

}