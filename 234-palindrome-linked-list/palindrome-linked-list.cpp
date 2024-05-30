class Solution {
public:
    ListNode* reverseLL(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* temp;

        while (curr != NULL) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return true;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prevSlow = NULL;

        while (fast != NULL && fast->next != NULL) {
            prevSlow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // If the list has odd number of nodes, move slow one step further
        if (fast != NULL) {
            prevSlow = slow;
            slow = slow->next;
        }

        prevSlow->next = NULL; // Break the list into two parts

        ListNode* newMiddle = reverseLL(slow);

        ListNode* newFirst = head;

        while (newMiddle != NULL) {
            if (newMiddle->val != newFirst->val) {
                return false;
            }
            newMiddle = newMiddle->next;
            newFirst = newFirst->next;
        }

       

        return true;
    }
};