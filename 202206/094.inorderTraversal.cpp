/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/*
方法一：dfs递归
方法二：迭代，栈stack
方法三：二叉树的前馈节点，空间复杂度O(1)
*/
class Solution {
public:
    // 方法一：递归
    void dfs(TreeNode* root, vector<int>& res) {
        if (!root) {
            return;
        }

        dfs(root->left, res);
        res.push_back(root->val);
        dfs(root->right, res);
    }

    // 方法二：递归调用栈
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;

        while (!st.empty() || root) {
            while (root) {
                st.push(root);
                root = root->left;
            }

            root = st.top();
            st.pop();
            res.push_back(root->val);
            root = root->right;
        }
    }

    vector<int> inorderTraversal(TreeNode* root) {
        /*
        类比二叉树的下一个节点问题，从根节点出发，依次构建左子树的最右节点的下一个节点（这是中序遍历的顺序）
        如何打印节点呢？
        当构建到最左侧的叶子节点时，即是第一个节点，然后处理其下一个节点，也就是它的右子节点
        （它的右子树肯定已经被构建过”下一节点“关系）但右子树的打印逻辑”左中右“跟构建”下一节点关系“时一样，
        可以复用那块代码。
        构建完的”下一节点关系“如何处理呢？
        即，当左子树节点的右节点指向根节点时呗！p->right == root!
        此时需要打印节点，并断开“下一个”关系，这样左子树就完全处理完了，可以处理右子树了
        */
        vector<int> res;
        TreeNode* p = nullptr;
        while (root) {
            if (root->left) {
                p = root->left;
                while (p->right && p->right != root) {
                    p = p->right;
                }

                if (p->right == nullptr) {
                    p->right = root; // 指向下一个节点
                    root = root->left; // 继续处理下一个左子树
                } else {
                    // 下一个节点关系需要断开，并且打印根节点，这样左子树就完全处理完了，继续处理右子树
                    res.push_back(root->val);
                    p->right = nullptr;
                    root = root->right;
                }
            } else {
                // 遍历到最左边的叶子结点，打印
                res.push_back(root->val);
                root = root->right;
            }
        }

    }
};