#include "헤더.h"


class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        // 1. deque를 사용해야 하는 것 같아요.
        // 2. 덱의 사이즈는 nums의 데이터 크기만큼 하면 될 것 같아요.
        // 3. pop_front를 사용해서 필요 없는 앞 쪽 데이터를 제거해야 할 것 같아요.
        // 4. k 개 이후 뒤 쪽 데이터는 읽지 않아도 될 것 같아요.
        // 5. 가장 큰 데이터를 계속해서 찾지 않아도 될 것 같네요?
        //      1) 다음 판정 데이터가 자신보다 클 경우
        //          다음 판정 데이터가 자신보다 크다면, 가장 큰 데이터는 해당 데이터가 될 것이고 그 만큼은 반복할 필요가 없어지네.
        //      2) 다음 판정 데이터가 자신보다 작을 경우
        //          이 경우에는 이전에 찾은 가장 큰 데이터를 배열에 추가하기만 하면 된다.
        //      3) 이전 가장 큰 데이터가 판정 범위를 넘어갈 경우
        //          이 경우에는 큰 데이터를 다시 찾아야 한다.
        //          아니면 이전에 미리 조금 더 작은 데이터를 찾아놓는 방법이 있긴 한데... 일단 새로운 데이터를 찾는 방법을 해보는게 좋을 듯.
        //      
        // 쒸빨



        // 그러면 일단 deque를 초기화 해보아요.
        int MaxValueIdx = 0;
        int MaxValue = -10000;
        vector<int> returnVector; // 매 반복마다 가장 큰 값을 넣어서 반환할 벡터.
        deque<int> 덱(nums.begin(), nums.end());

        // 그러면 덱에는 지금 모든 nums의 요소가 들어있겠죠?
        // 모든 덱을 훑을 필요가 없다.

        // 덱의 size()보다 k(윈도우 크기) 커진다면 더이상 비교할 데이터가 없다는 뜻이겠죠?
        while (k < 덱.size())
        {

            // 5-3)의 경우. 데이터를 훑으며 새로운 데이터를 찾아야 할 때. 일단 처음의 경우에는 반드시 진행해야 함.
            for (int i = 0; i < k; ++i)
            {
                // 여기서 해야 할 것은 최대 값과 최대 값의 인덱스를 찾는 것.
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