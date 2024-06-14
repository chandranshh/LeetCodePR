class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }

        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *temp = head;

        while (fast && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        while (temp->next != slow) {
            temp = temp->next;
        }

        temp->next = slow->next;

        return head;
    }
};