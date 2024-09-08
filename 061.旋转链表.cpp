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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0) {
            return head;
        }
        ListNode* p = head;
        int len = 1;
        while (p->next) {
            ++len;
            p = p->next;
        }
        p->next = head;
        int i = 1;
        p = head;
        while (i < len - k % len) {
            p = p->next;
            ++i;
        }
        ListNode* res = p->next;
        p->next = nullptr;
        return res;
    }
};