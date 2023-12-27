#include "헤더.h"

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

        // 데이터 넣으며 정렬
        while (true)
        {
            sortmap.insert({ NodeBuff->val, NodeBuff });
            NodeBuff = NodeBuff->next;
            if (NodeBuff == nullptr)
                break;
        }


        // 1. 이전 노드를 저장하고 있기
        // 2. 다음 노드를 가리키기
        // 3. 다음 노드를 이전 노드의 second.next로 정하기.
        // 4. 다음 노드를 이전 노드로 저장하고 있기
        // 5. 다음 노드를 가리키기... 2, 3, 4 반복하면 될 듯

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