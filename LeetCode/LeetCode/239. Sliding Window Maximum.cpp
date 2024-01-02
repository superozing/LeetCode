#include "���.h"


class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        // 1. deque�� ����ؾ� �ϴ� �� ���ƿ�.
        // 2. ���� ������� nums�� ������ ũ�⸸ŭ �ϸ� �� �� ���ƿ�.
        // 3. pop_front�� ����ؼ� �ʿ� ���� �� �� �����͸� �����ؾ� �� �� ���ƿ�.
        // 4. k �� ���� �� �� �����ʹ� ���� �ʾƵ� �� �� ���ƿ�.
        // 5. ���� ū �����͸� ����ؼ� ã�� �ʾƵ� �� �� ���׿�?
        //      1) ���� ���� �����Ͱ� �ڽź��� Ŭ ���
        //          ���� ���� �����Ͱ� �ڽź��� ũ�ٸ�, ���� ū �����ʹ� �ش� �����Ͱ� �� ���̰� �� ��ŭ�� �ݺ��� �ʿ䰡 ��������.
        //      2) ���� ���� �����Ͱ� �ڽź��� ���� ���
        //          �� ��쿡�� ������ ã�� ���� ū �����͸� �迭�� �߰��ϱ⸸ �ϸ� �ȴ�.
        //      3) ���� ���� ū �����Ͱ� ���� ������ �Ѿ ���
        //          �� ��쿡�� ū �����͸� �ٽ� ã�ƾ� �Ѵ�.
        //          �ƴϸ� ������ �̸� ���� �� ���� �����͸� ã�Ƴ��� ����� �ֱ� �ѵ�... �ϴ� ���ο� �����͸� ã�� ����� �غ��°� ���� ��.
        //      
        // ����



        // �׷��� �ϴ� deque�� �ʱ�ȭ �غ��ƿ�.
        int MaxValueIdx = 0;
        int MaxValue = -10000;
        vector<int> returnVector; // �� �ݺ����� ���� ū ���� �־ ��ȯ�� ����.
        deque<int> ��(nums.begin(), nums.end());

        // �׷��� ������ ���� ��� nums�� ��Ұ� ����ְ���?
        // ��� ���� ���� �ʿ䰡 ����.

        // ���� size()���� k(������ ũ��) Ŀ���ٸ� ���̻� ���� �����Ͱ� ���ٴ� ���̰���?
        while (k < ��.size())
        {

            // 5-3)�� ���. �����͸� ������ ���ο� �����͸� ã�ƾ� �� ��. �ϴ� ó���� ��쿡�� �ݵ�� �����ؾ� ��.
            for (int i = 0; i < k; ++i)
            {
                // ���⼭ �ؾ� �� ���� �ִ� ���� �ִ� ���� �ε����� ã�� ��.
            }



        }

        



        return returnVector;
    }

};


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