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
        // 연결된 2개의 노드를 바꾸고 그 다음 노드도 바꾸고...
        // 이걸 하려면 최소한 3개의 노드는 가리켜야 한다고 생각해요.
        // 12를 교환하고 
        // 2->1 
        // 1->3으로 가리키게 한 다음
        // 1 = 3; 2 = 3의 다음 노드, 3은 2의 다음 노드로 바꾼 다음 다시 돌리면 되겠네요.
       
        // 노드가 하나도 없거나 하나만 있을 경우의 예외처리
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* swapNode1 = head;
        ListNode* swapNode2 = head->next;
        ListNode* nextSwapNode;

        // 반환해줄 값을 교환노드2로 변경
        head = swapNode2;

        // 플래그
        bool IsSwapEnd = false;
        
        // 노드 교환
        while (true)
        {
            nextSwapNode = swapNode2->next;

            // 교환이 종료되었을 때
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