#include "���.h"

int ttom(string& _time)
{
	int min = (_time[0] - '0') * 10;
	min += _time[1] - '0';

	// �ð��� ������ ��ȯ
	min *= 60;

	min += (_time[3] - '0') * 10;
	min += _time[4] - '0';

	return min;
}

string mtot(int _time)
{
	string h = to_string(_time / 60);
	string m = to_string(_time % 60);
	string ret = "00:00";

	if (h.length() == 1)
		ret[1] = h[0];
	else
	{
		ret[0] = h[0];
		ret[1] = h[1];
	}
	if (m.length() == 1)
		ret[4] = m[0];
	else
	{
		ret[3] = m[0];
		ret[4] = m[1];
	}

	return ret;
}

struct Bus
{
	int n;
	int m;

	Bus(int _n) : n(_n) {}
	Bus() {}
};

string solution(int n, int t, int m, vector<string> timetable)
{
	vector<Bus> bus(t, Bus(n));
	vector<int> time(timetable.size());

	int startMin = 9 * 60;

	for (int i = 0; i < t; ++i)
	{
		bus[i].m = startMin;
		startMin += m;
	}

	for (int i = 0; i < timetable.size(); ++i)
		time[i] = ttom(timetable[i]);

	sort(time.begin(), time.end());

	int busIdx = 0;
	
	for (int i = 0; i < time.size(); ++i)
	{
		if (bus[busIdx].m >= time[i])
		{
			--bus[busIdx].n;

			if (bus[busIdx].n == 0)
			{
				++busIdx;
			}
		}
		else
		{
			++busIdx;
			--i;
		}
		if (busIdx == bus.size()) // ��� ������ ��ȸ���� ��쿡�� ��� �ؾ� �ұ�?
		{

		}
	}

	// �� ���, ��� �°��� ź �Ŀ��� ������ �ڸ��� ���Ҵ�.
	if (bus.back().n != 0)
		return mtot(bus.back().m);


}