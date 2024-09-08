/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* dummy = new Node(0);
        Node* p1 = head;
        Node* p2 = dummy;
        unordered_map<Node*, Node*> mp;
        while (p1) {
            Node* node = new Node(p1->val);
            p2->next = node;
            mp[p1] = node;
            p1 = p1->next;
            p2 = p2->next;
        }

        p1 = head;
        p2 = dummy->next;
        while (p1) {
            Node* r1 = p1->random;
            p2->random = mp[r1];
            p1 = p1->next;
            p2 = p2->next;
        }
        return dummy->next;
    }
};