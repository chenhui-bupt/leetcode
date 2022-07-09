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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    	if (lists.size() == 0) {
            return nullptr;
        }
        return merge(lists, 0, lists.size() - 1);
    }

    ListNode* merge(vector<ListNode*>& lists, int left, int right) {
    	if (left == right) {
    		return lists[left];
    	}
    	int mid = (left + right) >> 1;
    	return mergeTwoLists(merge(lists, left, mid), merge(lists, mid + 1, right)); // 归并
    }

    // 归并算法
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    	ListNode* dummy = new ListNode(0);
    	ListNode* p = dummy;
    	ListNode* p1 = list1;
    	ListNode* p2 = list2;
    	while (p1 && p2) {
    		if (p1->val < p2->val) {
    			p->next = p1;
    			p1 = p1->next;
    		} else {
    			p->next = p2;
    			p2 = p2->next;
    		}
    		p = p->next;
    	}
    	p->next = p1 ? p1 : p2;
    	return dummy->next;
    }
};