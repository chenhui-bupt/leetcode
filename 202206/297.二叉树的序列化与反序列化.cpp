/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node) {
                res += to_string(node->val) + " ";
                q.push(node->left);
                q.push(node->right);
            } else {
                res += "# ";
            }
        }
        return res;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        string s;
        vector<string> splits;
        while (in >> s) {
            splits.push_back(s);
        }

        if (splits[0] == "#") {
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(splits[0]));
        queue<TreeNode*> q;
        q.push(root);
        int i = 1;
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            string s1 = splits[i];
            string s2 = splits[i+1];
            if (s1 != "#") {
                node->left = new TreeNode(stoi(s1));
                q.push(node->left);
            }
            if (s2 != "#") {
                node->right = new TreeNode(stoi(s2));
                q.push(node->right);
            }
            i += 2;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));