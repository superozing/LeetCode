#include <iostream>
#include <vector>
#include <string>

using namespace std;


class BAEKJOON_2805 // ���� �ڸ���
{
public:
	int			m_treeLength;
	int			m_MaxLength = 0;
	vector<int> m_vecTree;

public:
	void init();
	void progress();

	long long cutTree(long long _size);
};



void BAEKJOON_2805::init()
{
	long long n = 0;
	long long buf = 0;

	cin >> n;
	cin >> buf;

	m_treeLength = buf;

	for (long long i = 0; i < n; ++i)
	{
		cin >> buf;

		if (buf > m_MaxLength)
			m_MaxLength = buf;

		m_vecTree.push_back(buf);
	}
}

long long BAEKJOON_2805::cutTree(long long _size)
{
	long long treeLength = 0;
	long long CutSize = 0;

	for (auto& iter : m_vecTree)
	{
		CutSize = iter - _size;

		if (CutSize > 0)
			treeLength += CutSize;
	}

	return treeLength;
}

void BAEKJOON_2805::progress()
{
	// �̰�... �������͸� ����ϸ� �ǰڴ°�?

	// ���� ���� ������ ���̸� ���ڸ� �Է� ���� �� üũ�ϰ�
	// min ���̸� 0���� �����ؼ�
	// ���� ��� ���̷� ������ ������ �� ���̰� m_treeLength���� ũ�� ��� ���̸� ���� ���� ���̷� ����.
	// �ƴϸ� ���� ���� ���̷� ����.
	// ���� ���� ���̰� ������ ���̻� Ž���� �ʿ䰡 ��������..!!

	long long low = 0;
	long long high = m_MaxLength;

	long long curHeight = 0;
	long long cutTreeSize = 0;

	while (true)
	{
		curHeight = (low + high) / 2;

		cutTreeSize = cutTree(curHeight);

		if (m_treeLength < cutTreeSize)
			low = curHeight;
		else if (m_treeLength > cutTreeSize)
			high = curHeight;
		else
		{
			printf("%d", curHeight);
			return;
		}

		if (high - low < 10)
			break;
	}

	for (; low != high; --high)
	{
		if (m_treeLength <= cutTree(high))
			break;
	}

	printf("%d", high);
	return;
}


int main()
{
	BAEKJOON_2805 b;

	b.init();
	b.progress();
	return 0;

}

