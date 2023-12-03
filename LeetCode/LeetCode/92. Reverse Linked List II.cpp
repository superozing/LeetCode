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
        // ù ���� ������ ��带 ����Ű���� �ϸ� ���� ������?
        // �׸��� ���� ��尡 nullptr�� �� ���� ������ �̾� ���� ��带 ����Ű���� �ݺ��� �ϸ� �� �� ����.

        // ���� ����� Ÿ���� �������� �ٲپ��ֱ�
        // ù ����� ���� Ÿ���� nullptr�� �ٲپ��ְ�
        // ���� �����ʹ� ���� Ÿ���� next�� �������� ���ָ� �� �� ������?


        // �ʱ� ��
        ListNode* Prev = head;
        ListNode* Cur = nullptr;

        ListNode* F = head;
        ListNode* L = head;
        // ���� ��ġ�� ã��.
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