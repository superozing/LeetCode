#include "���.h"

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



class Solution 
{
public:
    ListNode* sortList(ListNode* head) 
    {
        map<int, ListNode*> sortmap;
        
        ListNode* lIter = head;

        // ������ ������ ����
        while (lIter != nullptr)
        {
            sortmap.insert({ lIter->val, lIter });
            lIter = lIter->next;
        }


        // 1. ���� ��带 �����ϰ� �ֱ�
        // 2. ���� ��带 ����Ű��
        // 3. ���� ��带 ���� ����� second.next�� ���ϱ�.
        // 4. ���� ��带 ���� ���� �����ϰ� �ֱ�
        // 5. ���� ��带 ����Ű��... 2, 3, 4 �ݺ��ϸ� �� ��

        lIter = sortmap.begin()->second;
        head = sortmap.begin()->second;

        for (auto& iter : sortmap)
        {
            lIter->next = iter.second;
            iter.second = lIter;
        }

        lIter->next = nullptr;

        return head;
    }
};