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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        ListNode* ListIter = nullptr;
        ListNode* ReturnVal = nullptr;

        // 예외
        if (!list1)
            return list2;
        else if (!list2)
            return list1;

        // 초기 값 설정
        if (list1->val <= list2->val)
        {
            ListIter = list1;
            ReturnVal = list1;
            list1 = list1->next;
        }
        else if (list1->val > list2->val)
        {
            ListIter = list2;
            ReturnVal = list2;
            list2 = list2->next;
        }

        // 데이터 채우기
        while (list1 && list2)
        {
            if (list1->val <= list2->val)
            {
                ListIter->next = list1;
                ListIter = ListIter->next;
                list1 = list1->next;
            }
            else if (list1->val >= list2->val)
            {
                ListIter->next = list2;
                ListIter = ListIter->next;
                list2 = list2->next;
            }
        }

        // 생각해보니 둘 중 하나만 남았다면 한 개씩 이어붙일 필요가 없다.
        // 통째로 붙여도 되는거잖아?
        if (!list1 && list2)
        {
            ListIter->next = list2;
            ListIter = ListIter->next;
            list2 = list2->next;
        }

        if (list1 && !list2)
        {
            ListIter->next = list1;
            ListIter = ListIter->next;
            list1 = list1->next;
        }
        return ReturnVal;
    }
};