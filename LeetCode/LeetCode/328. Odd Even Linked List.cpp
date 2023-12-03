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
    ListNode* oddEvenList(ListNode* head) 
    {
        ListNode* EvenNodeArr = nullptr;
        ListNode* EvenNodeIter = nullptr;
        ListNode* CurNode = head;
        ListNode* NextNode = nullptr;

        while (head)
        {
            if (CurNode->next == nullptr)
            {
                CurNode->next = EvenNodeArr;
                return head;
            }

            NextNode = CurNode->next;
            CurNode->next = NextNode->next;

            if (!EvenNodeArr)
            {
                EvenNodeArr = NextNode;
                EvenNodeIter = NextNode;
            }
            else
            {
                EvenNodeIter->next = NextNode;
                EvenNodeIter = NextNode;
            }

            NextNode->next = nullptr;

            if (CurNode->next == nullptr)
            {
                CurNode->next = EvenNodeArr;
                return head;
            }
            else
                CurNode = CurNode->next;
        }

        return head;
    }
};