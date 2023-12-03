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
        // �ڸ������� ���ϰ� ���� �۾��� �غ��ƿ�.
        int �� = 0;
        int i = 0;

        // ���غ��ƿ�
        while (l1 || l2)
        {
            if (l1 != nullptr)
            {
                �� += l1->val * (int)pow(10.f, (float)i);
                l1 = l1->next;
            }
            if (l2 != nullptr)
            {
                �� += l2->val * (int)pow(10.f, (float)i);
                l2 = l2->next;
            }

            if (l1 || l2)
                ++i;
        }

        // 1 2 3
        ListNode* ������� = nullptr;
        ListNode* ����� = nullptr;

        for (; i >= 0; --i)
        {
            if (������� == nullptr)
            {
                ������� = new ListNode(�� / (int)pow(10.f, i));
            }
            else
            {
                ����� = new ListNode(�� / (int)pow(10.f, i), �������);
                ������� = �����;
            }
            �� %= (int)pow(10.f, (float)i);
        }

        return �������;
    }
};