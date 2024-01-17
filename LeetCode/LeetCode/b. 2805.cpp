#include <iostream>
#include <vector>
#include <string>

using namespace std;


class BAEKJOON_2805 // ���
{
public:
	int			m_treeLength;
	int			m_MaxtreeLength = 0;
	vector<int> m_vecTree;

public:
	void init();
	void progress();
};



void BAEKJOON_2805::init()
{
	int n = 0;
	int buf = 0;
	
	cin >> n;
	cin >> buf;

	m_treeLength = buf;

	for (int i = 0; i < n; ++i)
	{
		cin >> buf;
		
		if (buf > m_MaxtreeLength)
			m_MaxtreeLength = buf;

		m_vecTree.push_back(buf);
	}
}

void BAEKJOON_2805::progress()
{
	int Pow = 2;
	int H = m_MaxtreeLength;
	int buf = 0;
	int Ŀ������ = -1;

	int accCurTreeLen = 0;

	while (Pow > m_MaxtreeLength)
	{
		H += m_MaxtreeLength * Ŀ������ / Pow;
		accCurTreeLen = 0;
		for (auto& it : m_vecTree)
		{
			buf = it - H;
			if (buf < 0)
				buf = 0;
			accCurTreeLen += buf;
		}
		if (m_treeLength > accCurTreeLen)		Ŀ������ = 1;
		else if (m_treeLength < accCurTreeLen)	Ŀ������ = -1;
		if (Ŀ������ == -1 && m_treeLength > accCurTreeLen) break;
		Pow *= 2;
	}
	printf("%d", accCurTreeLen);

	// �ϴ� �� ū �κ��� ã�� �� ������ �ݺ��� ��������...??
	// �׸��� ���� 1�� ���鼭 ������ ���� ���ϸ鼭 �ϸ� ���ư��� �������?
}


int main()
{
	BAEKJOON_2805 b;

	b.init();
	b.progress();
	return 0;

}