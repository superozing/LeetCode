#include <iostream>
#include <vector>
#include <string>

using namespace std;


class BAEKJOON_2805 // ���
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
	n;	  // �ִ볯¥
	vecT; // ��
	vecP; // ����
	// ��� ��츦 Ž���ؾ߸� �ϳ�����.

	int maxProfit = 0;
	int curProfit = 0;
	

	// 1) n��ŭ ���� �Ǵµ�, ���� ��¥���� �� ���� ��¥�� ����ؾ� �� ���, �ش� �ε����� ����� ���� �����.
	for (int i = 0; i < n; ++i)
	{
		// ���� ���� ��¥���� ��� �Ⱓ�� ũ�ٸ� �ش� ��¥�� ����� ������ �� ����.
		// �̰� �̸� üũ�صδ� �͵� ���� ��.
		if (vecT[i] > n - i)
		{
			vecT[i] = 0;
			vecP[i] = 0;
		}
	}


	// 2) ��� ��츦 �ϳ��ϳ� ���� Ž���ϱ� ���ؼ��� ��� �ؾ� �ұ�?
	// �̰� �� ������ ��츦 ���ϴ� ���.
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