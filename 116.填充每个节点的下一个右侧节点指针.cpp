/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) {
            return root;
        }
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            Node* pre = nullptr;
            for (int i = 0; i < size; ++i) {
                if (i > 0) {
                    pre->next = q.front();
                }
                pre = q.front();
                q.pop();
                if (pre->left) {
                    q.push(pre->left);
                }
                if (pre->right) {
                    q.push(pre->right);
                }
            }
        }
        return root;
    }
};