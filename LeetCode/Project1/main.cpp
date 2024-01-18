#include <iostream>
#include <vector>
#include <string>

using namespace std;


class BAEKJOON_2805 // ���
{
public:
	int			n; // ������ ���� ��¥
	vector<int> T; // ��� ���� �Ⱓ
	vector<int> P; // ������� ��� ����

public:
	void init();
	int progress();
};



void BAEKJOON_2805::init()
{
	cin >> n;
	int buf = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> buf;
		T.push_back(buf);

		cin >> buf;
		P.push_back(buf);
	}
}

int BAEKJOON_2805::progress()
{
	// DP�� �̿��� Ǯ�̰� �ʿ��ϴ�...?
	// �� �� ���� ������ ����ϸ� ä��������.
	vector<int> dp(n, -1);

	// ������ �� ���� ���
	int t = T.back();
	int p = P.back();

	if (t > 1) // -> �� ��� ��� ���� �Ұ�
		dp[n - 1] = 0;
	else
		dp[n - 1] = p;

	for (int i = n - 2; i >= 0; --i)
	{
		t = T[i];
		p = P[i];

		// 0. �ϴ� �� ��¥�� ����� ���������� �Ǵ��ؾ� �Ѵ�.
		if (i + t > n)
		{
			dp[i] = dp[i + 1];
			continue;
		}

		// 1. ���� ��¥�� �����Ű�°� �� ���� �̵��� ���ϴ���, �ƴϸ� ���� ��¥�� �����Ű�� �ʴ°� �� ���� �̵��� ���ϴ����� ����ؾ� �Ѵ�.
		// �� ��, t��ŭ ������ �̵��� ���� �ڽ��� ���� ���� ���� �� ū���� i + 1�� ���� ���ؼ� ����ִ´�.
		if (i + t > n - 1) // -> �� ���, �ڽŰ� ���������� ���� �����ش�
			dp[i] = dp[i + 1] > p ? dp[i + 1] : p;
		else
			dp[i] = dp[i + 1] > dp[i + t] + p ? (dp[i + 1]) : (dp[i + t] + p);
	}

	return dp.front();
}

int main()
{
	BAEKJOON_2805 b;
	b.init();
	cout << b.progress();
	return 0;
}