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
    ListNode* insertionSortList(ListNode* head)
    {
        // "순서대로 정렬" 이 목표
        // 헤드부터, 다음 정렬할 노드를 가리킬 포인터가 하나 필요하겠네요.
        // 한 개의 노드를 버퍼에 따로 빼낸 다음, 값에 따라서 자신이 있을 위치를 찾아 넣어야 한다.

        // 일단 단일 연결 리스트이기 때문에...
        // 1. 거꾸로 가리키게 한 다음 마지막에 정렬
        // 2. 앞에서부터 자신의 값을 체크

        // 반환할 리스트의 시작점을 가리킬 반환노드
        ListNode* returnNode = head;

        // 다음으로 반환 리스트에 삽입 정렬 할 노드 버퍼
        ListNode* NextSort = head->next;

        // 현재 삽입 정렬 할 노드 버퍼
        ListNode* NodeBuffer = NextSort;
        NextSort = NextSort->next;

        head->next = nullptr;

        if (NodeBuffer->val > head->val)
        {
            NodeBuffer->next = head;
            head = NodeBuffer;
            returnNode = NodeBuffer;

            NodeBuffer = NextSort;
            NextSort = NextSort->next;
        }
        else
        {
            head = head->next;
        }




        NextSort = NextSort->next;
        

        return ReturnNode;
    }
};