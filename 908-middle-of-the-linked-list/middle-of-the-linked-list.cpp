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
    int countLL(ListNode* head) {
        int ct = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            ct++;
            temp = temp->next;
        }
        return ct;
    }

    ListNode* middleNode(ListNode* head) {

        int count = countLL(head);
        

        if (count % 2 != 0) {
            int n = (count / 2)+1;
            ListNode* temp = head;
            for (int i = 1; i <=n-1; i++) {
                temp = temp->next;
            }
            return temp;
        } else {
            int n = (count / 2);
            ListNode* temp = head;
            for (int i = 1; i <=n; i++) {
                temp = temp->next;
            }
            return temp;
        }
        return head;
    }
};