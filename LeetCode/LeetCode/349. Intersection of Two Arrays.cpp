#include "���.h"

class Solution 
{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> ��ġ�°�üũ;
        // 0 -> �������� ����, 1 -> �� �� ������, 2 -> ������
        ��ġ�°�üũ.resize(1000);

        // nums1 üũ
        for (int i = 0; i < nums1.size(); ++i)
            ��ġ�°�üũ[nums1[i]] = 1;

        // nums2 üũ
        for (int i = 0; i < nums2.size(); ++i)
        {
            if (��ġ�°�üũ[nums2[i]] == 1)
                ��ġ�°�üũ[nums2[i]] = 2;

        }

        vector<int> returnVec;

        for (int i = 0; i < ��ġ�°�üũ.size(); ++i)
        {
            if (��ġ�°�üũ[i] == 2)
                returnVec.push_back(i);
        }

        return returnVec;
    }
};