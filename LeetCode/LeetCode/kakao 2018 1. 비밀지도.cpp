#include "���.h"

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2)
{
    vector<string> returnVec(n);
    // ��Ʈ ���� �۾��� �ؾ� �ϳ׿�.

    for (int i = 0; i < n; ++i)
    {
        for (int j = n - 1; j >= 0; --j)
        {
            if (arr1[i] & 1 << j || arr2[i] & 1 << j)
                returnVec[i] += '#';
            else
                returnVec[i] += ' ';
        }
    }

    return returnVec;
}