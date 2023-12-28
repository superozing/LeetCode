#include "���.h"

class Solution 
{
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        // �迭���� �� ������ �� ã��. �� �����͸� ����ϸ� �ȴٰ� �����.

        int left = 0;
        int _right = numbers.size() - 1;

        // ���� right�� �۾����� �ùٸ� �ε����� ���ٴ� ��...! 
        // �ٵ� �������� ��Ȯ�� �ϳ��� �ذ�å�� �ִٰ� �߾���. �� ������ �ʿ� ����?
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