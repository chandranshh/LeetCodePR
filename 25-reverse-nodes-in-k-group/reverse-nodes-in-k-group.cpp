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
    ListNode* reverseKGroup(ListNode* head, int k) {
    // Create a dummy node to simplify the logic
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* before = dummy;  // Pointer to the node before the current group
    ListNode* after = head;    // Pointer to the node after the current group
    ListNode* curr = nullptr;  // Temporary pointer for the current node
    ListNode* prev = nullptr;  // Temporary pointer for the previous node
    ListNode* nxt = nullptr;   // Temporary pointer for the next node

    // Traverse the linked list in groups of size k
    while (true) {
        // Check if there are at least k nodes left in the list
        ListNode* cursor = after;
        for (int i = 0; i < k; i++) {
            if (cursor == nullptr) {
                return dummy->next;  // Return the reversed list if less than k nodes left
            }
            cursor = cursor->next;
        }

        // Reverse the current group of k nodes
        curr = after;
        prev = before;
        for (int i = 0; i < k; i++) {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        // Update the pointers for the next group
        after->next = curr;
        before->next = prev;
        before = after;
        after = curr;
    }
}
};