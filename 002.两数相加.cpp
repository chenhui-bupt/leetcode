class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	int carry = 0;
    	ListNode* dummy = new ListNode(0);
    	ListNode* p = dummy;
    	ListNode* p1 = l1;
    	ListNode* p2 = l2;
    	while (p1 or p2) {
    		int num = carry;
    		if (p1) {
    			num += p1->val;
    			p1 = p1->next;
    		}
    		if (p2) {
    			num += p2->val;
    			p2 = p2->next;
    		}
    		carry = num / 10;
    		num = num % 10;
    		p->next = new ListNode(num);
    		p = p->next;
    	}
    	if (carry > 0) {
    		p->next = new ListNode(carry);
    	}
    	return dummy->next;
    }
};