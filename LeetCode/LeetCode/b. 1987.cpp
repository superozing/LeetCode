#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <cmath>

using namespace std;

class BAEKJOON // 알파벳
{
public:
    int x;
    int y;

    int max;

    vector<string> p;

public:
    BAEKJOON() { init(); }
    void init();
    void progress();
    void print();

    int search(int x, int y);
};

void BAEKJOON::init()
{
    cin >> y;
    cin >> x;

    string s;
    for (int i = 0; i < y; ++i)
    {
        cin >> s;
        p.push_back(s);
    }

}

typedef pair<int, int> ii;
typedef pair<ii, int> iii;

int BAEKJOON::search(int Y, int X)
{
    bool visit['Z']{};
    visit[p[0][0]] = true;

    list<iii> stack;
    int count = 0;
    stack.push_back({ { Y, X }, 0 });

    while (!stack.empty())
    {
        iii& b = stack.back();

        int cY = b.first.first;
        int cX = b.first.second;

        bool MoveFlag = false;
        if (cX != 0 && visit[p[cY][cX - 1]] == false) // 왼 쪽
        {
            visit[p[cY][cX - 1]] = true;
            MoveFlag = true;
            stack.push_back({ { cY, cX - 1 }, b.second + 1 });
        }
        if (cX + 1 < x && visit[p[cY][cX + 1]] == false) // 오른 쪽
        {
            visit[p[cY][cX + 1]] = true;
            MoveFlag = true;
            stack.push_back({ { cY, cX + 1 }, b.second + 1 });
        }
        if (cY != 0 && visit[p[cY - 1][cX]] == false) // 위 쪽
        {
            visit[p[cY - 1][cX]] = true;
            MoveFlag = true;
            stack.push_back({ { cY - 1, cX }, b.second + 1 });
        }
        if (cY + 1 < y && visit[p[cY + 1][cX]] == false) // 아래 쪽
        {
            visit[p[cY + 1][cX]] = true;
            MoveFlag = true;
            stack.push_back({ { cY + 1, cX }, b.second + 1 });
        }

        if (!MoveFlag)
        {
            stack.pop_back();
        }
    }

    return count;
}

void BAEKJOON::progress()
{


}

void BAEKJOON::print()
{
}

int main()
{
    BAEKJOON b;
    b.progress();
    b.print();
    return 0;
}
