#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef pair<int, bool> p;

class BAEKJOON_14890 // ����
{
public:
	int					n; // nxn ���
	int					L; // ������ ����
	vector<vector<p>> vMap; // �̹��� pair�� �����غ��ƿ�. first ���� ����, second ���� ���� ��ġ ���θ� ����ϸ� �� ��.

public:
	BAEKJOON_14890() { init(); }
	void init();
	int  progress();

};

void BAEKJOON_14890::init()
{
	cin >> n;
	cin >> L;

	vector<p> vBuf(n, {0, false}); // ����� �⺻ ���� 0,0���� �ʱ�ȭ

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			cin >> vBuf[i].first;

		vMap.push_back(vBuf);
	}
}


int BAEKJOON_14890::progress()
{
	// ����)
	// 0. ������ �� �ֵ��� ���� ĭ�� ���θ� ��ġ���־�� ��.
	// 1. ���� ���̰� 1 �̻��̸� ������ �� ���� ��.
	// 2. ���ΰ� ���ļ��� �ȵȴ�.
	// 3. ���θ� ���� �� ���� ĭ�� ������� �ȵȴ�.

	// �� ����.. �� �ϱ� ���� ù ��° �� ���� ������ �غ��� �÷����°� ���� ��.

	int returnVal = 0;
	bool isVaild = false;
	bool flag = false;
	for (int i = 0; i < n; ++i)
	{
		vector<p>& v = vMap[i];
		isVaild = false;

		// n - 1���� ���Ƽ� ������ �����ͱ��� �˾Ƽ� �����ϱ�.
		for (int j = 0; j < n - 1; ++j)
		{
			// ���� ���
			if (v[j].first > v[j + 1].first)
			{
				// 1. ���� ���̰� 1�� �ƴ϶�� ��ȿ���� ���� ����
				if (v[j].first - v[j + 1].first != 1 || j + L >= n)
					break;

				flag = false;

				// 2. ���� �ε����� �̹� ���ΰ� ����ִ°�?
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

				// 1�� 2��
				v[j + 1].second = true;
			}
			// ���� ���
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



	// �� ����




	return 0;
}


int main()
{
	BAEKJOON_14890 b;
	cout << b.progress();
	return 0;
}