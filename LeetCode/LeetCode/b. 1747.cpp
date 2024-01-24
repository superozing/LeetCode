#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;


class BAEKJOON // 퇴사
{
public:
	long long n;

public:
	BAEKJOON() { init(); }
	void init();
	long long progress();

	bool isPalindrome(string n);
	bool isPrime(long long n);
};


void BAEKJOON::init()
{
	cin >> n;
}

long long BAEKJOON::progress()
{
	while (true)
	{
		if (isPalindrome(to_string(n)) && isPrime(n))
			break;
		else
			++n;
	}

	return n;
}

bool BAEKJOON::isPalindrome(string n)
{
	int len = n.length();

	for (int i = 0; i < len / 2; ++i)
		if (n[i] != n[len - i - 1])
			return false;

	return true;
}

bool BAEKJOON::isPrime(long long n)
{
	if (n == 1)
		return false;
	// 판정할 부분: 2~sqrt(n)
	for (long long i = 2; i <= sqrt(n); ++i)
	{
		if (n % i == 0)
			return false;
	}

	return true;
}

int main()
{
	BAEKJOON b;
	cout << b.progress();
	return 0;
}