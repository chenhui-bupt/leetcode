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
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* p = dummy;
        while (p->next && getKNode(p, k)) {
            ListNode* p1 = p->next;
            ListNode* p2 = getKNode(p, k);
            ListNode* end = p2->next;
            p->next = reverse(p1, end);
            p1->next = end;
            p = p1;
        }
        return dummy->next;
    }

    ListNode* getKNode(ListNode* head, int k) {
        while (k && head) {
            head = head->next;
            --k;
        }
        return head;
    }

    ListNode* reverse(ListNode* head, ListNode* end) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur != end) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};