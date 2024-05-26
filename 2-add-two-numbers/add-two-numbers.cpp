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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode{0, nullptr};
        ListNode* temp = dummy;
        int carry = 0;

        while (l1 != NULL || l2 != NULL || carry) {
            int sum = carry;

            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }

            temp->next = new ListNode{sum % 10, nullptr};
            carry = sum / 10;
            temp = temp->next;
        }

        if(carry){
            temp->next = new ListNode{carry, nullptr};
        }

        return dummy->next;
    }
};