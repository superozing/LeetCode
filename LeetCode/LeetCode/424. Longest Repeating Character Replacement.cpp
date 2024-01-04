#include "���.h"
class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        // �����̵� ������� �׸��� �˰����� ����غ�����. - GPT
        //    �����̵� �����츦 ����Ͽ� �κ� ���ڿ��� ����� �����ϴ�.
        //    ������ ������ ���� �󵵼��� ���� ���ڸ� ã���ϴ�.
        //    ������ ũ�⸦ �����Ͽ� �ִ� k���� ���� ������ ����ϵ��� �մϴ�.
        //    ���� �� �κ� ���ڿ��� ���̸� ��ȯ�մϴ�.
        // �κ� ���ڿ��� ���� �� � ���ڸ� �����ؾ� �ұ�?
        // �ϴ� �����̵� ������� �պκ� �ø��� �޺κ� ���̰�. �� �϶�� �����ݾ�?
        // ����ؼ� �����͸� �Է¹ް�, �󵵰� ���� ���� ������ �ֺ��� k����ŭ �ٲپ��� ���� ���̸� ����

        // �� üũ
        vector<int> FrequencyCount('Z' + 1); // �� �� ������ �Ʊ���� �ϳ׿�...?
        
        int LIdx = 0;
        int RIdx = 0;

        // �ִ� ��
        int MaxFrequency = 0;

        int ReturnVal = 0;

        while (RIdx != s.length()) // ���� �� �����Ͱ� ���� �ٴٸ� �� ���� �ݺ�
        {
            // �ִ� ������ �Ÿ� ���
            int CurWndLen = RIdx - LIdx + 1;

            // ���� ���� �����͸� ������Ű�� MaxFrequency ����
            ++FrequencyCount[s[RIdx]];
            MaxFrequency = max(FrequencyCount[s[RIdx]], MaxFrequency);

            // ������ ������ k + MaxFrequency ���� ũ�� ������ ����. (��ġ���� �ʴ� k���� ���ڸ� �ٲپ ���� �ٲ��� ���� ���ڰ� �ִٴ� ��)
            if (CurWndLen > k + MaxFrequency)
                --FrequencyCount[s[LIdx++]];
            // �������� ���ڸ� k�� ��ŭ �ٲپ��� �� ���� ������ ���
            else 
                ReturnVal = max(ReturnVal, CurWndLen); // ReturnVal�� ����

            ++RIdx;
        }

        return ReturnVal;
    }
};