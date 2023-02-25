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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    	ListNode* dummy = new ListNode(0);
    	dummy->next = head;
    	ListNode* p1 = dummy;
    	ListNode* p2 = dummy;
    	while (n--) {
    		p1 = p1->next;
    	}
    	while (p1->next) {
    		p1 = p1->next;
    		p2 = p2->next;
    	}
    	p2->next = p2->next->next;
    	return dummy->next;
    }
    
};