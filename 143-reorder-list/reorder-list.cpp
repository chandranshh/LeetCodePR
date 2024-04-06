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
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode *temp = head, *half = head, *prev = NULL;

        if (!head) {
            return;
        }

        while (temp && temp->next) {
            temp = temp->next->next;
            half = half->next;
        }

        if (temp && temp->next) {
            half = half->next;
        }

        while (half) {
            temp = half->next;
            half->next = prev;
            prev = half;
            half = temp;
        }
        half = prev;

        while (head && half) {
            temp = head->next;
            prev = half->next;
            head->next = half;
            half->next = temp;
            head = temp;
            half = prev;
        }

        if (head && head->next) {
            head->next->next = NULL;
        }
    }
};
