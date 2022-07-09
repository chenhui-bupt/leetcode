// 宽度优先搜索
class Solution {
	string serialize(TreeNode* root) {
		string res;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			TreeNode* node = q.top();
			if (node) {
				res += to_string(node->val) + " ";
				q.push(node->left);
				q.push(node->right);
			} else {
				res += "# "
			}

		}
	}

	TreeNode* deserialize(string s) {
		vector<string> splits;
		istringstream in(s);
		string val;
		while (in >> val) {
			splits.push_back(val);
		}

		if (splits[0] == '#') {
			return nullptr;
		}

		TreeNode* root = new TreeNode(stoi(splits[0]));
		queue<TreeNode*> q;
		q.push(root);
		int index = 1;
		while (index < splits.size()) {
			TreeNode* node = q.front();
			q.pop();
			if (splits[index] != '#') {
				node->left = new TreeNode(stoi(spltis[index]));
				q.push(node->left);
			}
			if (splits[index + 1] != '#') {
				node->right = new TreeNode(stoi(splits[index + 1]));
				q.push(node->right);
			}
			index += 2;
		}
	}
}



// 深度优先

class Solution {
	void serialize(TreeNode* root, ostringstream out) {
		if (!root) {
			out << "# ";
			return;
		}
		out << root->val << " ";
		serialize(root->left);
		serialize(root->right);
	}

	TreeNode* deserialize(istringstream in) {
		string val;
		in >> val;
		if (val == "#") {
			return nullptr;
		}

		TreeNode* root = new TreeNode(stoi(val));
		root->left = deserialize(s, index + 1);
		root->right = deserialize(s, index + 2);
		return root;
	}
}