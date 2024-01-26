#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;


class BAEKJOON // 퇴사
{
public:
	int cur;
	int	target;

	int acc;

public:
	BAEKJOON() { init(); }
	void init();
	int progress();
};


void BAEKJOON::init()
{
	cin >> cur;
	cin >> target;
}

int BAEKJOON::progress()
{
	//그냥 계속 2로 나누다가 나머지 생긴 만큼 이동하면 되는거 아닌가?

	return acc;
}

int main()
{
	BAEKJOON b;
	cout << b.progress();
	return 0;
}