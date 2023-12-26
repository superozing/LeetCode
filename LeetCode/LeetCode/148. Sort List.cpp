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
        map<int, ListNode*> sortmap;
        
        ListNode* lIter = head;

        // 데이터 넣으며 정렬
        while (lIter != nullptr)
        {
            sortmap.insert({ lIter->val, lIter });
            lIter = lIter->next;
        }


        // 1. 이전 노드를 저장하고 있기
        // 2. 다음 노드를 가리키기
        // 3. 다음 노드를 이전 노드의 second.next로 정하기.
        // 4. 다음 노드를 이전 노드로 저장하고 있기
        // 5. 다음 노드를 가리키기... 2, 3, 4 반복하면 될 듯

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