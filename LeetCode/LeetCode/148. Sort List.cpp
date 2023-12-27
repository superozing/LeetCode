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
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        map<int, ListNode*> sortmap;
        
        ListNode* NodeBuff = head;

        // ������ ������ ����
        while (true)
        {
            sortmap.insert({ NodeBuff->val, NodeBuff });
            NodeBuff = NodeBuff->next;
            if (NodeBuff == nullptr)
                break;
        }


        // 1. ���� ��带 �����ϰ� �ֱ�
        // 2. ���� ��带 ����Ű��
        // 3. ���� ��带 ���� ����� second.next�� ���ϱ�.
        // 4. ���� ��带 ���� ���� �����ϰ� �ֱ�
        // 5. ���� ��带 ����Ű��... 2, 3, 4 �ݺ��ϸ� �� ��

        head = NodeBuff = sortmap.begin()->second;
        auto iter = sortmap.begin();
        ++iter;
        for (; iter != sortmap.end(); ++iter)
        {
            NodeBuff->next = iter->second;
            NodeBuff = iter->second;
        }

        NodeBuff->next = nullptr;

        return head;
    }
};