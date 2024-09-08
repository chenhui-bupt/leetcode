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
/*
方法一：迭代
方法二：递归
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* p = head;
        ListNode* pre = nullptr;
        while (p) {
            ListNode* next = p->next;
            p->next = pre;
            pre = p;
            p = next;
        }
        return pre;
    }

    ListNode* dfs(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* node = dfs(head->next);
        head->next->next = head;
        head->next = nullptr;
        return node;
    }
};