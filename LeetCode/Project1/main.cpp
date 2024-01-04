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

        vector<int> 빈도수('Z' + 1);
        int LIdx = 0;
        int RIdx = 0;
        int 최대빈도 = 0;

        int Return = 0;

        while (RIdx != s.length()) // 오른 쪽 포인터가 끝에 다다를 때 까지 반복
        {
            // 최대 윈도우 거리 계산
            int MaxWndLen = RIdx - LIdx + 1;

            // 새로 들어온 데이터를 증가시키고 최대빈도 갱신
            ++빈도수[s[RIdx]];
            최대빈도 = max(빈도수[s[RIdx]], 최대빈도);

            // 윈도우 개수가 k + 최대 빈도보다 크면 문제가 있음.
            if (MaxWndLen > k + 최대빈도)
                --빈도수[s[LIdx++]];
            else // 아니면 정상적이래요.
                Return = max(Return, MaxWndLen);

            ++RIdx;
        }

        return Return;
    }
};


int main()
{
    Solution s;
    printf("%d\n", s.characterReplacement("ABAB", 2));
    return 0;
}