#include "헤더.h"
class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        // 슬라이딩 윈도우와 그리디 알고리즘을 사용해보세요. - GPT
        //    슬라이딩 윈도우를 사용하여 부분 문자열을 만들어 나갑니다.
        //    윈도우 내에서 가장 빈도수가 높은 문자를 찾습니다.
        //    윈도우 크기를 조정하여 최대 k번의 문자 변경을 허용하도록 합니다.
        //    가장 긴 부분 문자열의 길이를 반환합니다.
        // 부분 문자열을 만들 때 어떤 문자를 수정해야 할까?
        // 일단 슬라이딩 윈도우는 앞부분 늘리고 뒷부분 줄이고. 를 하라는 뜻이잖아?
        // 계속해서 데이터를 입력받고, 빈도가 가장 높은 문자의 주변을 k개만큼 바꾸었을 때의 길이를 저장

        // 빈도 체크
        vector<int> FrequencyCount('Z' + 1); // 앞 쪽 공간이 아깝기는 하네요...?
        
        int LIdx = 0;
        int RIdx = 0;

        // 최대 빈도
        int MaxFrequency = 0;

        int ReturnVal = 0;

        while (RIdx != s.length()) // 오른 쪽 포인터가 끝에 다다를 때 까지 반복
        {
            // 최대 윈도우 거리 계산
            int CurWndLen = RIdx - LIdx + 1;

            // 새로 들어온 데이터를 증가시키고 MaxFrequency 갱신
            ++FrequencyCount[s[RIdx]];
            MaxFrequency = max(FrequencyCount[s[RIdx]], MaxFrequency);

            // 윈도우 개수가 k + MaxFrequency 보다 크면 문제가 있음. (일치하지 않는 k개의 문자를 바꾸어도 아직 바꾸지 않은 문자가 있다는 것)
            if (CurWndLen > k + MaxFrequency)
                --FrequencyCount[s[LIdx++]];
            // 윈도우의 문자를 k개 만큼 바꾸었을 때 전부 동일한 경우
            else 
                ReturnVal = max(ReturnVal, CurWndLen); // ReturnVal에 저장

            ++RIdx;
        }

        return ReturnVal;
    }
};