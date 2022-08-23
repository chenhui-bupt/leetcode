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
/**
 * 算法：分离链表再合并
 * 思路：先将奇偶链表分离，再头尾合并
 */

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head) {
            return nullptr;
        }
        ListNode* odd = new ListNode(0);
        ListNode* even = new ListNode(0);
        ListNode* p_odd = odd;
        ListNode* p_even = eve;
        int num = 1;
        ListNode* p = head;
        while (p) {
            if (n % 2 == 1) {
                p_odd->next = p;
                p_odd = p_odd->next;
            } else {
                p_even->next = p;
                p_even = p_even->next;
            }
            p = p->next;
            n++;
        }
        p_odd->next = even->next;
        return odd->next;
    }
};