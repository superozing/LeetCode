#include <iostream>
#include <vector>

#include <algorithm>

using namespace std;

class BAEKJOON
{
	int			N;	 // ���� A�� ũ��

	vector<int> arr; // ����
	vector<int> res; // ���̸� ������ ����

public:
	void init();
	void progress();

public:
	BAEKJOON() { init(); }
	~BAEKJOON() {}
};


void BAEKJOON::init()
{
	cin >> N;

	arr.resize(N);

	for (int i = 0; i < N; ++i)
		cin >> arr[i];
}

void BAEKJOON::progress()
{
	int arrCount = 0;

	// ù ���Ҹ� ��Ƽ� for�� �ȿ��� ������ �� �ֵ��� ��
	res.push_back(arr[0]);
	++arrCount;

	for (int i = 1; i < N; ++i)
	{
		if (res.back() < arr[i])
		{
			// ���� arr[i]�� ������ ���Һ��� Ŭ ��쿡�� ���������� ������������ ���ĵǰ� �ֱ⿡ �ڿ� �־���.
			res.push_back(arr[i]);

			// ������ ������ 1�� ����
			++arrCount;
		}
		else
		{
			// ���� arr[i]�� ������ ���Һ��� ���� ��쿡��, 
			// arr[i]���� ó������ ū �κ��� �ε����� ã�Ƽ� ������������ ���Ľ�����.
			int idx = lower_bound(res.begin(), res.end(), arr[i]) - res.begin();
			res[idx] = arr[i];
		}
	}

	// res�� ����ִ� �迭�� ���Ұ� LIS�� �����ϴ� ���Ҵ� �ƴ϶�� ���� �����Ϸ���.
	// ���� ���� ���Һ��� lower_bound�� ã�� ��ġ�� �� ������ �� �ֱ� �����̷���.

	cout << arrCount;

}

int main()
{
	BAEKJOON b;
	b.progress();

	return 0;
}