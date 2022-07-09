// 二叉树路径和
// 核心思想前缀和！！！

class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
    	map<int, int> prefix;
    	prefix[0] = 1;
    	return dfs(root, targetSum, prefix, 0);
    }

    int dfs(TreeNode* root, int targetSum, map<int, int>& prefix, int curSum) {
    	if (!root) {
    		return 0;
    	}
    	
    	curSum += root->val;

    	int res = 0;
    	if (prefix.count(curSum - targetSum) > 0) {
    		res = prefix[curSum - targetSum];
    	}
    	
    	prefix[curSum]++;
    	res += dfs(root->left, targetSum, prefix, curSum);
    	res += dfs(root->right, targetSum, prefix, curSum);
    	prefix[curSum]--;

    	return res;
    }
};