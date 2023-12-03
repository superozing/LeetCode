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


class Solution 
{
public:
    ListNode* swapPairs(ListNode* head) 
    {
        // ����� 2���� ��带 �ٲٰ� �� ���� ��嵵 �ٲٰ�...
        // �̰� �Ϸ��� �ּ��� 3���� ���� �����Ѿ� �Ѵٰ� �����ؿ�.
        // 12�� ��ȯ�ϰ� 
        // 2->1 
        // 1->3���� ����Ű�� �� ����
        // 1 = 3; 2 = 3�� ���� ���, 3�� 2�� ���� ���� �ٲ� ���� �ٽ� ������ �ǰڳ׿�.
       
        // ��尡 �ϳ��� ���ų� �ϳ��� ���� ����� ����ó��
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* swapNode1 = head;
        ListNode* swapNode2 = head->next;
        ListNode* nextSwapNode;

        // ��ȯ���� ���� ��ȯ���2�� ����
        head = swapNode2;

        // �÷���
        bool IsSwapEnd = false;
        
        // ��� ��ȯ
        while (true)
        {
            nextSwapNode = swapNode2->next;

            // ��ȯ�� ����Ǿ��� ��
            if (nextSwapNode == nullptr)
            {
                IsSwapEnd = true;
                swapNode1->next = nullptr;
            }
            else if (nextSwapNode->next == nullptr)
            {
                IsSwapEnd = true;
                swapNode1->next = nextSwapNode;
            }
            else
                swapNode1->next = nextSwapNode->next;

            swapNode2->next = swapNode1;

            if (IsSwapEnd)
            {
                break;
            }
            else
            {
                swapNode1 = nextSwapNode;
                swapNode2 = nextSwapNode->next;
            }

        }

        return head;
    }
};