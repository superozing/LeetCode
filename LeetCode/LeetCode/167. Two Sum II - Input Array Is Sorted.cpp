#include "헤더.h"

class Solution 
{
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        // 배열에서 두 숫자의 합 찾기. 투 포인터를 사용하면 된다고 기억함.

        int left = 0;
        int _right = numbers.size() - 1;

        // 만약 right가 작아지면 올바른 인덱스가 없다는 뜻...! 
        // 근데 문제에서 정확히 하나의 해결책이 있다고 했었다. 이 조건은 필요 없나?
        while (true)
        {
            if (numbers[left] + numbers[_right] > target)
                --_right;
            else if (numbers[left] + numbers[_right] < target)
                ++left;
            else
                return vector<int>{left + 1, _right + 1};
        }
    }
};