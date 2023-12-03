/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *Next;
 *     ListNode() : val(0), Next(nullptr) {}
 *     ListNode(int x) : val(x), Next(nullptr) {}
 *     ListNode(int x, ListNode *Next) : val(x), Next(Next) {}
 * };
 */

struct ListNode 
{
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right)
    {
        // 첫 노드는 마지막 노드를 가리키도록 하면 되지 않을까?
        // 그리고 다음 노드가 nullptr일 때 까지 이전에 이어 붙인 노드를 가리키도록 반복만 하면 될 것 같아.

        // 다음 노드의 타겟을 이전으로 바꾸어주기
        // 첫 노드의 다음 타겟은 nullptr로 바꾸어주고
        // 다음 노드부터는 이전 타겟을 next로 가지도록 해주면 될 것 같은데?


        // 초기 값
        ListNode* Prev = head;
        ListNode* Cur = nullptr;

        ListNode* F = head;
        ListNode* L = head;
        // 시작 위치를 찾기.
        for (int i = 0; i <= right; ++i)
        {
            if (i < left)
            {
                Prev = Prev->next;
                continue;
            }
            else if (i == left)
            {
                F = Prev;
                Cur = 
            }
            else if (i == right)
                L = Prev;
            else
            {
                Prev->next = 
            }
        }

        //ListNode* Next = nullptr;

        //if (!Cur) return head;
        //
        //Next = Cur->next;

        //for (; Next->val = right;)
        //{
        //    Cur->next = Prev;

        //    Prev = Cur;
        //    Cur = Next;
        //    Next = Next->next;
        //}

        //int buf = head->val;
        //head->val = Cur->val;
        //Cur->val = buf;

        return Cur;
    }
};