/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
环形链表，快慢指针
举一反三，找出环形链表的入口节点
（1）快慢指针判断有环
（2）两个指针同步走，相交处即是入口节点
*/
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) {
            return false;
        }
        ListNode* p1 = head;
        ListNode* p2 = head;
        while (p1->next && p1->next->next) {
            p2 = p2->next;
            p1 = p1->next->next;
            if (p1 == p2) {
                return true;
            }
        }
        return false;
    }
};