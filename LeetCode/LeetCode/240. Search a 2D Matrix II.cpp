#include "헤더.h"

class Solution
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int minLow = 0;
        int minCol = 0;

        int maxLow = matrix.size() - 1;
        int maxCol = matrix[0].size() - 1;

        int CurLow = 0;
        int CurCol = 0;

        int CurVal = 0;

        // 이 것도 이진 탐색 쓰라는 문제 같네용.
        // 근데 세로를 사용해야 하네요.

        // 제일 가운데의 값을 보고, 가로 세로로 비교하면 
        // 행렬을 4등분 했을 때 내가 찾는 숫자가 4개 방향 중 어느 방향에 있을 지 알 수 있다.

        // 이런 식으로 계속 행렬을 깎아내려가면 언젠가는 찾지 않을까?

        // 1xn
        if (minLow == maxLow && minCol == maxCol)
        {
            return matrix[minLow][minCol] == target;
        }
        else if (minLow == maxLow)
        {
            int left = minCol;
            int right = maxCol;
            while (left <= right)
            {
                CurCol = (left + right) / 2;
                CurVal = matrix[0][CurCol];
                if (CurVal < target)
                {
                    left = CurCol + 1;
                }
                else if (CurVal > target)
                {
                    right = CurCol - 1;
                }
                else
                {
                    return true;
                }
            }
            return false;
        }
        // nx1
        else if (minCol == maxCol)
        {
            int up = minLow;
            int down = maxLow;
            while (up <= down)
            {
                CurLow = (up + down) / 2;
                CurVal = matrix[CurLow][0];
                if (CurVal < target)
                {
                    up = CurLow + 1;
                }
                else if (CurVal > target)
                {
                    down = CurLow - 1;
                }
                else
                {
                    return true;
                }
            }
            return false;
        }
       
        if (maxLow == 1 && maxCol == 1)
        {
            if (matrix[0][1] == target) return true;
            else if (matrix[0][0] == target)return true;
            else if (matrix[1][1] == target)return true;
            else if (matrix[1][0] == target)return true;
            else return false;
        }


        // nx1, 1xn이 아닌 경우
        while (minLow <= maxLow && minCol <= maxCol)
        {
            CurLow = (minLow + maxLow) / 2;
            CurCol = (minCol + maxCol) / 2;
            CurVal = matrix[CurLow][CurCol];

            if (CurVal == target)
            {
                return true;
            }
            else if (CurVal < target)
            {
                minLow = CurLow + 1;
                minCol = CurCol + 1;
            }
            else
            {
                maxLow = CurLow - 1;
                maxCol = CurCol - 1;
            }
        }

        return false;
    }
};