#include "헤더.h"

class Solution 
{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> 겹치는거체크;
        // 0 -> 판정되지 않음, 1 -> 한 번 판정됨, 2 -> 교집합
        겹치는거체크.resize(1000);

        // nums1 체크
        for (int i = 0; i < nums1.size(); ++i)
            겹치는거체크[nums1[i]] = 1;

        // nums2 체크
        for (int i = 0; i < nums2.size(); ++i)
        {
            if (겹치는거체크[nums2[i]] == 1)
                겹치는거체크[nums2[i]] = 2;

        }

        vector<int> returnVec;

        for (int i = 0; i < 겹치는거체크.size(); ++i)
        {
            if (겹치는거체크[i] == 2)
                returnVec.push_back(i);
        }

        return returnVec;
    }
};