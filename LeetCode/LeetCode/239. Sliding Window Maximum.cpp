#include "헤더.h"
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
            // 1. 만약 MaxValue인덱스가 pop 되었는가?
            if (MaxValueIdx - PopTime == -1)
            {
                // 초기화 후 새로운 최대 값 찾기
                int MaxValue = -10000;

                // 1. 첫 K개 중 가장 많은 데이터 가져오기
                for (int i = PopTime; i < k + PopTime; ++i)
                {
                    if (MaxValue < nums[i])
                    {
                        MaxValue = nums[i];
                        MaxValueIdx = i;
                    }
                }
            }
            // 2. 만약 k번째 데이터가 MaxValue보다 같거나 큰가?
            else if (nums[MaxValueIdx] <= nums[k - 1 + PopTime])
            {
                MaxValueIdx = k - 1 + PopTime;
            }
            // 3. 만약 새로 들어온 데이터가 MaxValue보다 작아서 여전히 MaxValue가 가장 클 때 - 아무 동작 안해도 됨.

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
//        // 1. deque를 사용해야 하는 것 같아요.
//        // 2. 덱의 사이즈는 nums의 데이터 크기만큼 하면 될 것 같아요.
//        // 3. pop_front를 사용해서 필요 없는 앞 쪽 데이터를 제거해야 할 것 같아요.
//        // 4. k 개 이후 뒤 쪽 데이터는 읽지 않아도 될 것 같아요.
//        // 5. 가장 큰 데이터를 계속해서 찾지 않아도 될 것 같네요?
//        //      1) 다음 판정 데이터가 자신보다 클 경우
//        //          다음 판정 데이터가 자신보다 크다면, 가장 큰 데이터는 해당 데이터가 될 것이고 그 만큼은 반복할 필요가 없어지네.
//        //      2) 다음 판정 데이터가 자신보다 작을 경우
//        //          이 경우에는 이전에 찾은 가장 큰 데이터를 배열에 추가하기만 하면 된다.
//        //      3) 이전 가장 큰 데이터가 판정 범위를 넘어갈 경우
//        //          이 경우에는 큰 데이터를 다시 찾아야 한다.
//        //          아니면 이전에 미리 조금 더 작은 데이터를 찾아놓는 방법이 있긴 한데... 일단 새로운 데이터를 찾는 방법을 해보는게 좋을 듯.
//        //      
//        // 쒸빨
//
//
//
//        int MaxValueIdx = -1;
//        int MaxValue = -10000;
//
//        vector<int> returnVector;
//        deque<int> 덱(nums.begin(), nums.end());
//
//        while (k <= 덱.size())
//        {
//            // 1. 만약 MaxValue인덱스가 pop 되었는가?
//            if (MaxValueIdx == -1)
//            {
//                // 초기화 후 새로운 최대 값 찾기
//                MaxValue = -10000;
//
//                // 1. 첫 K개 중 가장 많은 데이터 가져오기
//                for (int i = 0; i < k; ++i)
//                {
//                    if (MaxValue < 덱[i])
//                    {
//                        MaxValue = 덱[i];
//                        MaxValueIdx = i;
//                    }
//                }
//            }
//            // 2. 만약 k번째 데이터가 MaxValue보다 같거나 큰가?
//            else if (MaxValue <= 덱[k - 1])
//            {
//                MaxValue = 덱[k - 1];
//                MaxValueIdx = k - 1;
//            }
//            // 3. 만약 새로 들어온 데이터가 MaxValue보다 작아서 여전히 MaxValue가 가장 클 때 - 아무 동작 안해도 됨.
//
//            returnVector.push_back(MaxValue);
//            덱.pop_front();
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
//        // 그니까 문자열을 받아서 슬라이딩 윈도우를 직접 구현해서 가장 큰 수를 찾으라는 것이죠?
//        // 리스트를 사용해서 인자를 받고 내보내고를 반복하면 될 듯.
//        // for문을 사용해서 문자열 전부를 한번 읽어보자.
//        // 일단 초기 값을 채우고, nums.length - k + 1 번 만큼 반복해서, 이 중 가장 큰 수를 찾아야 한다.
//
//        list<int> 덱;
//        int idx = 0;
//        MaxValue = -10000;
//        vector<int> returnVector;
//
//        // 초기 값 채우기
//        for (; idx < k; ++idx)
//            덱.push_back(nums[idx]);
//
//        sum(덱, returnVector);
//
//        for (; idx < nums.size(); ++idx)
//        {
//            // 1. pop front로 앞쪽을 빼내고
//            // 2. push_back로 새로운 데이터를 넣고
//            // 3. sum 호출하기.
//            덱.pop_front();
//            덱.push_back(nums[idx]);
//            sum(덱, returnVector);
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