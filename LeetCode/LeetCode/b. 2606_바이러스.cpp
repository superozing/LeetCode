#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef pair<int, int> ii;

class BAEKJOON
{
public:
	int				maxCount;
	int				linkCount;
	vector<ii>		vLinked;
	vector<bool>	vInfect;

public:
	BAEKJOON() { init(); }
	void init();
	int progress();
};


void BAEKJOON::init()
{
	cin >> maxCount;
	cin >> linkCount;

	vInfect.resize(maxCount + 1);
	vInfect[1] = true;

	ii pii{};
	
	for (int i = 0; i < linkCount; ++i)
	{
		cin >> pii.first >> pii.second;
		vLinked.push_back(pii);
	}
}

bool compare(ii& a, ii& b) { return a.first < b.first ? false : (a.first > b.first ? true : (a.second > b.second)); }

int BAEKJOON::progress()
{
	vector<bool> visit(linkCount);
	bool visitFlag = true;

	sort(vLinked.begin(), vLinked.end(), compare);

	// ù ��° ��ǻ�ͺ��� �˻�.
	// ù ��° ��ǻ�Ϳ� ����� ��ǻ�͸� �˻�
	// ��.. �׷��� �� ���� ��ǻ�Ϳ� ����� ��ǻ�͸� �� �˻�
	// �� �ݺ��ϸ� �ǰڳ׿�.







	return 0;
}

int main()
{
	BAEKJOON b;
	cout << b.progress();
	return 0;
}