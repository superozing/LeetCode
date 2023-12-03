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
        // ���� ����� ������ ��� �ֱ�
        // ���� ����� ������ ���� ���� ���߱�
        // ���� ��� = ���� ���, ���� ��� = ���� ���, ���� ��� = ;
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