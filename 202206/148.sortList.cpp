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
链表排序，在链表本身上进行排序，因为是单向链表，所以快排、插入排序不太适合，归并比较合适
merge()：递归调用
mergeTwoLists() : 完成两个链表合并
*/
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        return merge(head, nullptr);
    }

    ListNode* merge(ListNode* head, ListNode* tail) {
        if (!head) {
            return nullptr;
        }
        if (head->next == tail) { // 只剩一个节点了，要断开，并返回head节点
            head->next = nullptr;
            return head;
        }
        ListNode* p1 = head;
        ListNode* p2 = head;
        while (p1 != tail) { // 寻找中间节点！！！与tail比较不是与nullptr比较哈！
            p1 = p1->next;
            if (p1 != tail) {
                p1 = p1->next;
            }
            p2 = p2->next;
        }
        return mergeTwoLists(merge(head, p2), merge(p2, tail));
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* p1 = list1;
        ListNode* p2 = list2;
        ListNode* dummy = new ListNode(0);
        ListNode* p = dummy;
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