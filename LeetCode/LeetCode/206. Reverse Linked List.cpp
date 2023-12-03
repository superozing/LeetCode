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
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
        if (!head || !head->next)
            return head;
        // 현재 노드의 다음을 들고 있기
        // 현재 노드의 다음을 이전 노드로 맟추기
        // 이전 노드 = 현재 노드, 현재 노드 = 다음 노드, 다음 노드 = ;
        ListNode* CurNode = head;
        ListNode* NextNode = CurNode->next;
        ListNode* NextNextNodeBuf = NextNode->next;
        head->next = nullptr;
        while (true)
        {
            if (NextNode)
                NextNode->next = CurNode;
            else
                break;
            CurNode = NextNode;
            NextNode = NextNextNodeBuf;
            if (NextNextNodeBuf) NextNextNodeBuf = NextNextNodeBuf->next;
        }
        return CurNode;
    }
};