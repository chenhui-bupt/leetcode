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
    bool isPalindrome(ListNode* head) {
        // 第一步：将链表二分，翻转链表，再比较
        ListNode* p1 = head;
        ListNode* p2 = head;
        while (p1) {
            p1 = p1->next;
            p2 = p2->next;
            if (p1) {
                p1 = p1->next;
            }
        }

        // 第二步：翻转链表
        ListNode* pre = nullptr;
        while (p2) {
            ListNode* next = p2->next;
            p2->next = pre;
            pre = p2;
            p2 = next;
        }

        // 第三步：比较是否相等
        p1 = head;
        p2 = pre;
        while (p2) {
            if (p2->val != p1->val) {
                return false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        return true;
    }
};


class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // 快慢指针
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* half = reverseList(slow);
        ListNode* p1 = head;
        ListNode* p2 = half;
        bool res = true;
        while (p2) {
            if (p1->val != p2->val) {
                res = false;
                break;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        //slow->next = reverseList(half);
        return res;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};