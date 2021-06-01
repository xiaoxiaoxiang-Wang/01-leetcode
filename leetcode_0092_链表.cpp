class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* res = new ListNode();
        ListNode* prev = res;
        prev->next = head;
        for(int i=0;i<m-1;i++) {
            prev = prev->next;
        }
        ListNode* curr = prev->next;
        ListNode* next = NULL;

        for(int i=m;i<n;i++) {
           next = curr->next;
           curr->next = next->next;
           next->next = prev->next;
           prev->next = next;
        }
        return res->next;
    }
};