#include "���.h"

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
        // "������� ����" �� ��ǥ
        // ������, ���� ������ ��带 ����ų �����Ͱ� �ϳ� �ʿ��ϰڳ׿�.
        // �� ���� ��带 ���ۿ� ���� ���� ����, ���� ���� �ڽ��� ���� ��ġ�� ã�� �־�� �Ѵ�.

        // �ϴ� ���� ���� ����Ʈ�̱� ������...
        // 1. �Ųٷ� ����Ű�� �� ���� �������� ����
        // 2. �տ������� �ڽ��� ���� üũ

        // ��ȯ�� ����Ʈ�� �������� ����ų ��ȯ���
        ListNode* returnNode = head;

        // �������� ��ȯ ����Ʈ�� ���� ���� �� ��� ����
        ListNode* NextSort = head->next;

        // ���� ���� ���� �� ��� ����
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