/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
链表相交的形式：
（1）不想交
（2）相交有环
    按环处理
（3）相交无环
    两次交换遍历
*/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        while (p1 != p2) {
            p1 = p1 ? p1->next : headB; // 要能走到末尾的nullptr，才能退出循环！
            p2 = p2 ? p2->next : headA;
        }
        return p1; // 如果不想交，则p1 = nullptr，相交则为正常节点
    }
};