#include "���.h"

int gm = 0;
int gn = 0;

int ����Ͷ߸���(vector<string>& board, vector<vector<int>>& check)
{
    int ret = 0;

    // üũ�� ���� ������ �迭 �����.
    // [0][0], [0][1], [1][0], [1][1]�� ������ �ش� ������ ������ ��.

    for (int i = 0; i < gm - 1; ++i)
        for (int j = 0; j < gn - 1; ++j)
            if (board[i][j] == board[i][j + 1] == board[i + 1][j] == board[i + 1][j + 1])
            {
                check[i][j]         = true;
                check[i + 1][j]     = true;
                check[i][j + 1]     = true;
                check[i + 1][j + 1] = true;
            }

    for (auto& it : check)
        for (auto& bl : it)
            if (bl)
                ++ret;

    return ret; // �Ͷ߸� ��� ������ ��ȯ�ϸ� �� ��?
}

int ���������(vector<string>& board, vector<vector<int>>& check)
{
    // ���� �ڽ��� ���� ����ΰ�?
        // Y -> 
            // �ڽ��� 1�࿡ ��ġ�� �� ���� ���� �ö󰡸鼭 �������� �Ʒ��� �����ֱ�.

    for (int i = 0; i < gm - 1; ++i)
        for (int j = 0; j < gn - 1; ++j)
            if (check[i][j] == true)
                �ø���(board, i, j);

}

void �ø���(vector<string>& check, int i, int j)
{
    for (; j != 0; --j)
    {
        char temp = check[i][j];
        check[i][j] = check[i][j - 1]; 
        check[i][j - 1] = temp;
    }
}


int solution(int m, int n, vector<string> board) 
{
    gm = m;
    gn = n;
    vector<vector<int>> check(gm, vector<int>(gn));
    int ret = 0;

    
    while (true)
    {
        int isEnd = ����Ͷ߸���(board, check);
        if (isEnd == 0) 
            break;
        ret += isEnd;
        ���������(board, check);
    }

    return ret;
}