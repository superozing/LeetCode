#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;


class BAEKJOON // ���
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
	//�׳� ��� 2�� �����ٰ� ������ ���� ��ŭ �̵��ϸ� �Ǵ°� �ƴѰ�?

	return acc;
}

int main()
{
	BAEKJOON b;
	cout << b.progress();
	return 0;
}