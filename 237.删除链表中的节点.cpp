/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
因为无法获取head节点，所以只能从node节点开始移位操作，最后一位删除即可。
为了能够删除最后一位，则需要维护pre节点的指针。
*/
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* pre = nullptr;
        while (node->next) {
            node->val = node->next->val;
            pre = node;
            node = node->next;
        }
        if (pre) {
            pre->next = nullptr;
        }
    }
};