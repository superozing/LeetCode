#include "���.h"

int gm = 0;
int gn = 0;

int BoardCheck(vector<string>& board, vector<vector<int>>& check)
{
    int ret = 0;

    // üũ�� ���� ������ �迭 �����.
    // [0][0], [0][1], [1][0], [1][1]�� ������ �ش� ������ ������ ��.

    for (int i = 0; i < gm - 1; ++i)
    {
        for (int j = 0; j < gn - 1; ++j)
        {
            if (board[i][j] != '0' 
                && board[i][j] == board[i][j + 1] 
                && board[i][j + 1] == board[i + 1][j] 
                && board[i + 1][j] == board[i + 1][j + 1])
            {
                check[i][j] = true;
                check[i + 1][j] = true;
                check[i][j + 1] = true;
                check[i + 1][j + 1] = true;
            }
        }
    }

    // ���� ��� üũ
    for (int i = 0; i < gm; ++i)
    {
        for (int j = 0; j < gn; ++j)
        {
            if (check[i][j])
            {
                board[i][j] = '0';
                check[i][j] = false;
                ++ret;
            }
        }
    }

    return ret; // �Ͷ߸� ��� ������ ��ȯ�ϸ� �� ��?
}

void BoardSort(vector<string>& board)
{
    // ���� �ڽ��� ���� ����ΰ�?
        // Y -> 
            // �ڽ��� 1�࿡ ��ġ�� �� ���� ���� �ö󰡸鼭 �������� �Ʒ��� �����ֱ�.
    // �� �ƴ�, ������ �Ʒ��� ���� ����� �ƴ� �� ���� ������ �ϳ׿�?
    // �̰� �ξ� �����ϰ� �� ��.

    bool isEnd = false;

    while (!isEnd)
    {
        isEnd = true;
        for (int i = 0; i < gm - 1; ++i)
        {
            for (int j = 0; j < gn; ++j)
            {
                // ���� �� ���� üũ ���ְ�, ���� �Ʒ� �ִ� ���ڰ� 0�� �ƴ� ��쿡 �Ʒ��� �����־�� ��.
                // �ƴϾ�...�̰� �ƴϾ�....
                // �ƴϸ� �ݴ�� üũ�ϸ� ���� �������?
                // ������ - 1 ����� üũ�ؼ� �Ʒ� �ִ� ���ڰ� 0�ΰ�? �� üũ�ϸ� �ǰڴµ�?
                char l = board[i][j];
                char r = board[i + 1][j];
                if (l != '0' && (r == '0'))
                {
                    char temp = board[i][j];
                    board[i][j] = '0';
                    board[i + 1][j] = temp;
                    isEnd = false;
                }
            }
        }
    }
}



int solution(int m, int n, vector<string> board)
{
    gm = m;
    gn = n;
    vector<vector<int>> check(gm, vector<int>(gn, false));
    int ret = 0;
    int isEnd = 0;


    while (true)
    {
        isEnd = 0;
        isEnd += BoardCheck(board, check);
        if (isEnd == 0) // ���̻� �Ͷ߸� ����� ���� ���
            break;
        ret += isEnd;
        BoardSort(board);
    }

    return ret;
}

int main()
{
    vector<string> a{ "CCBDE", "AAADE", "AAABF", "CCBBF" };
    printf("%d\n", solution(4,5,a));
    return 0;
}