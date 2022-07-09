/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head) {
            return nullptr;
        }
        ListNode* p1 = head;
        ListNode* p2 = head;
        bool hasCircle = false;
        while (p1->next && p1->next->next) {
            p2 = p2->next;
            p1 = p1->next->next;
            if (p1 == p2) {
                hasCircle = true;
                break;
            }
        }

        if (!hasCircle) {
            return nullptr;
        }

        p2 = head;
        while (p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p2;
    }
};