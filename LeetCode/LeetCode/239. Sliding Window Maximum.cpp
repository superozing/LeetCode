#include "���.h"
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        vector<int> returnVector;
        int MaxValueIdx = -1;
        int PopTime = 0;


        while (nums.size() - k + 1 != PopTime)
        {
            // 1. ���� MaxValue�ε����� pop �Ǿ��°�?
            if (MaxValueIdx - PopTime == -1)
            {
                // �ʱ�ȭ �� ���ο� �ִ� �� ã��
                int MaxValue = -10000;

                // 1. ù K�� �� ���� ���� ������ ��������
                for (int i = PopTime; i < k + PopTime; ++i)
                {
                    if (MaxValue < nums[i])
                    {
                        MaxValue = nums[i];
                        MaxValueIdx = i;
                    }
                }
            }
            // 2. ���� k��° �����Ͱ� MaxValue���� ���ų� ū��?
            else if (nums[MaxValueIdx] <= nums[k - 1 + PopTime])
            {
                MaxValueIdx = k - 1 + PopTime;
            }
            // 3. ���� ���� ���� �����Ͱ� MaxValue���� �۾Ƽ� ������ MaxValue�� ���� Ŭ �� - �ƹ� ���� ���ص� ��.

            returnVector.push_back(nums[MaxValueIdx]);
            ++PopTime;
        }

        return returnVector;
    }

};

//class Solution
//{
//public:
//    vector<int> maxSlidingWindow(vector<int>& nums, int k)
//    {
//        // 1. deque�� ����ؾ� �ϴ� �� ���ƿ�.
//        // 2. ���� ������� nums�� ������ ũ�⸸ŭ �ϸ� �� �� ���ƿ�.
//        // 3. pop_front�� ����ؼ� �ʿ� ���� �� �� �����͸� �����ؾ� �� �� ���ƿ�.
//        // 4. k �� ���� �� �� �����ʹ� ���� �ʾƵ� �� �� ���ƿ�.
//        // 5. ���� ū �����͸� ����ؼ� ã�� �ʾƵ� �� �� ���׿�?
//        //      1) ���� ���� �����Ͱ� �ڽź��� Ŭ ���
//        //          ���� ���� �����Ͱ� �ڽź��� ũ�ٸ�, ���� ū �����ʹ� �ش� �����Ͱ� �� ���̰� �� ��ŭ�� �ݺ��� �ʿ䰡 ��������.
//        //      2) ���� ���� �����Ͱ� �ڽź��� ���� ���
//        //          �� ��쿡�� ������ ã�� ���� ū �����͸� �迭�� �߰��ϱ⸸ �ϸ� �ȴ�.
//        //      3) ���� ���� ū �����Ͱ� ���� ������ �Ѿ ���
//        //          �� ��쿡�� ū �����͸� �ٽ� ã�ƾ� �Ѵ�.
//        //          �ƴϸ� ������ �̸� ���� �� ���� �����͸� ã�Ƴ��� ����� �ֱ� �ѵ�... �ϴ� ���ο� �����͸� ã�� ����� �غ��°� ���� ��.
//        //      
//        // ����
//
//
//
//        int MaxValueIdx = -1;
//        int MaxValue = -10000;
//
//        vector<int> returnVector;
//        deque<int> ��(nums.begin(), nums.end());
//
//        while (k <= ��.size())
//        {
//            // 1. ���� MaxValue�ε����� pop �Ǿ��°�?
//            if (MaxValueIdx == -1)
//            {
//                // �ʱ�ȭ �� ���ο� �ִ� �� ã��
//                MaxValue = -10000;
//
//                // 1. ù K�� �� ���� ���� ������ ��������
//                for (int i = 0; i < k; ++i)
//                {
//                    if (MaxValue < ��[i])
//                    {
//                        MaxValue = ��[i];
//                        MaxValueIdx = i;
//                    }
//                }
//            }
//            // 2. ���� k��° �����Ͱ� MaxValue���� ���ų� ū��?
//            else if (MaxValue <= ��[k - 1])
//            {
//                MaxValue = ��[k - 1];
//                MaxValueIdx = k - 1;
//            }
//            // 3. ���� ���� ���� �����Ͱ� MaxValue���� �۾Ƽ� ������ MaxValue�� ���� Ŭ �� - �ƹ� ���� ���ص� ��.
//
//            returnVector.push_back(MaxValue);
//            ��.pop_front();
//            --MaxValueIdx;
//        }
//
//        return returnVector;
//    }
//
//};


//class Solution
//{
//    int MaxValue = 0;
//
//public:
//    vector<int> maxSlidingWindow(vector<int>& nums, int k)
//    {
//        // �״ϱ� ���ڿ��� �޾Ƽ� �����̵� �����츦 ���� �����ؼ� ���� ū ���� ã����� ������?
//        // ����Ʈ�� ����ؼ� ���ڸ� �ް� �������� �ݺ��ϸ� �� ��.
//        // for���� ����ؼ� ���ڿ� ���θ� �ѹ� �о��.
//        // �ϴ� �ʱ� ���� ä���, nums.length - k + 1 �� ��ŭ �ݺ��ؼ�, �� �� ���� ū ���� ã�ƾ� �Ѵ�.
//
//        list<int> ��;
//        int idx = 0;
//        MaxValue = -10000;
//        vector<int> returnVector;
//
//        // �ʱ� �� ä���
//        for (; idx < k; ++idx)
//            ��.push_back(nums[idx]);
//
//        sum(��, returnVector);
//
//        for (; idx < nums.size(); ++idx)
//        {
//            // 1. pop front�� ������ ������
//            // 2. push_back�� ���ο� �����͸� �ְ�
//            // 3. sum ȣ���ϱ�.
//            ��.pop_front();
//            ��.push_back(nums[idx]);
//            sum(��, returnVector);
//        }
//
//        return returnVector;
//    }
//
//
//
//    void sum(list<int>& sum, vector<int>& returnVec)
//    {
//        int WindowSum = -10000;
//        for (auto& iter : sum)
//        {
//            if (WindowSum < iter)
//                WindowSum = iter;
//        }
//        returnVec.push_back(WindowSum);
//        return;
//    }
//};