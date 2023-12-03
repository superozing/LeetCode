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
#include "���.h"

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
        // ��ü ���� �������� �ϸ� �縰����� �ƴ� ��쿡�� true�� ���� �� �־��.
        // ��... ��� �ϴ°� ������?
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