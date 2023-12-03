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
struct ListNode 
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution 
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        // 자릿수별로 더하고 빼는 작업을 해보아요.
        int 합 = 0;
        int i = 0;

        // 더해보아요
        while (l1 || l2)
        {
            if (l1 != nullptr)
            {
                합 += l1->val * (int)pow(10.f, (float)i);
                l1 = l1->next;
            }
            if (l2 != nullptr)
            {
                합 += l2->val * (int)pow(10.f, (float)i);
                l2 = l2->next;
            }

            if (l1 || l2)
                ++i;
        }

        // 1 2 3
        ListNode* 기존노드 = nullptr;
        ListNode* 새노드 = nullptr;

        for (; i >= 0; --i)
        {
            if (기존노드 == nullptr)
            {
                기존노드 = new ListNode(합 / (int)pow(10.f, i));
            }
            else
            {
                새노드 = new ListNode(합 / (int)pow(10.f, i), 기존노드);
                기존노드 = 새노드;
            }
            합 %= (int)pow(10.f, (float)i);
        }

        return 기존노드;
    }
};