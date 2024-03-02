class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        set <int> s;
        ListNode * temp = head;
        ListNode * prev = NULL;
        while(temp!=NULL){
            if(s.find(temp->val)!=s.end())
                prev->next = temp->next;
            else{
                s.insert(temp->val);
                prev = temp;
            }
            temp = temp->next;
        }
        return head;
    }
};