class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {    
        int carry = 0;
        ListNode *ans = new ListNode(-1);
        ListNode *head = ans;
        while(l1 != NULL && l2 != NULL) {
            int sum = l1->val + l2->val;
            head->next = new ListNode((sum+carry)%10);
            carry = (sum+carry) / 10;
            
            head = head->next;
            l1 = l1->next, l2 = l2->next;
        }
        
        while(l1 != NULL) {
            int val = l1->val;
            head->next = new ListNode((val+carry)%10);
            carry = (val+carry) / 10;
            head = head->next;
            l1 = l1->next;
        }
        
        while(l2 != NULL) {
            int val = l2->val;
            head->next = new ListNode((val+carry)%10);
            carry = (val+carry) / 10;
            head = head->next;
            l2 = l2->next;
        }
        
        if(carry != 0)
            head->next = new ListNode(carry);
        
        return ans->next;
    }
};
