#include "헤더.h"

int gm = 0;
int gn = 0;

int BoardCheck(vector<string>& board, vector<vector<int>>& check)
{
    int ret = 0;

    // 체크를 위해 이차원 배열 만들기.
    // [0][0], [0][1], [1][0], [1][1]이 같으면 해당 공간은 터져야 해.

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

    // 터진 블록 체크
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

    return ret; // 터뜨린 블록 개수를 반환하면 될 듯?
}

void BoardSort(vector<string>& board)
{
    // 만약 자신이 터진 블록인가?
        // Y -> 
            // 자신이 1행에 위치할 때 까지 위로 올라가면서 나머지를 아래로 내려주기.
    // 가 아닌, 위에서 아래로 터진 블록이 아닐 때 까지 내려야 하네요?
    // 이게 훨씬 간단하게 될 듯.

    bool isEnd = false;

    while (!isEnd)
    {
        isEnd = true;
        for (int i = 0; i < gm - 1; ++i)
        {
            for (int j = 0; j < gn; ++j)
            {
                // 위에 걸 먼저 체크 해주고, 만약 아래 있는 숫자가 0이 아닐 경우에 아래로 내려주어야 함.
                // 아니야...이게 아니야....
                // 아니면 반대로 체크하면 되지 않을까요?
                // 마지막 - 1 행부터 체크해서 아래 있는 숫자가 0인가? 를 체크하면 되겠는데?
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
        if (isEnd == 0) // 더이상 터뜨릴 블록이 없을 경우
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