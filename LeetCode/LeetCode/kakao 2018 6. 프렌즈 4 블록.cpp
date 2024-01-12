#include "헤더.h"

int gm = 0;
int gn = 0;

int 블록터뜨리기(vector<string>& board, vector<vector<int>>& check)
{
    int ret = 0;

    // 체크를 위해 이차원 배열 만들기.
    // [0][0], [0][1], [1][0], [1][1]이 같으면 해당 공간은 터져야 해.

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

    return ret; // 터뜨린 블록 개수를 반환하면 될 듯?
}

int 블록재정렬(vector<string>& board, vector<vector<int>>& check)
{
    // 만약 자신이 터진 블록인가?
        // Y -> 
            // 자신이 1행에 위치할 때 까지 위로 올라가면서 나머지를 아래로 내려주기.

    for (int i = 0; i < gm - 1; ++i)
        for (int j = 0; j < gn - 1; ++j)
            if (check[i][j] == true)
                올리기(board, i, j);

}

void 올리기(vector<string>& check, int i, int j)
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
        int isEnd = 블록터뜨리기(board, check);
        if (isEnd == 0) 
            break;
        ret += isEnd;
        블록재정렬(board, check);
    }

    return ret;
}