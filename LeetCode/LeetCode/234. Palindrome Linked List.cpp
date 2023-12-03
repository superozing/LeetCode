/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include "헤더.h"

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution 
{
public:
    bool isPalindrome(ListNode* head) 
    {
        vector<int> vec;
        // 전체 값을 기준으로 하면 펠린드롬이 아닌 경우에도 true가 나올 수 있어요.
        // 음... 어떻게 하는게 좋을까?
        while (head != nullptr)
        {
            vec.push_back(head->val);
            head = head->next;
        }
        int size = vec.size();

        for (int i = 0; i < size / 2; ++i)
            if (vec[i] - vec[size - i - 1])
                return false;
        

        return true;
    }
};