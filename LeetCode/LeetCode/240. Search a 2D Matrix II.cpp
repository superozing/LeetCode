#include "���.h"

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

        // �� �͵� ���� Ž�� ����� ���� ���׿�.
        // �ٵ� ���θ� ����ؾ� �ϳ׿�.

        // ���� ����� ���� ����, ���� ���η� ���ϸ� 
        // ����� 4��� ���� �� ���� ã�� ���ڰ� 4�� ���� �� ��� ���⿡ ���� �� �� �� �ִ�.

        // �̷� ������ ��� ����� ��Ƴ������� �������� ã�� ������?

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


        // nx1, 1xn�� �ƴ� ���
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