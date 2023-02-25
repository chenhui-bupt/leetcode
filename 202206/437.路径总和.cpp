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
因为题目要求不必从根节点开始，所以二叉树在递归的时候要能记录前一段的和与后一段的和，当后一段的和等于targetSum时，
所以问题转换为，前一段的和等于sum - targetSum的问题！！！
你看累不类似 dp[i - num[j]]的动态规划问题，哈哈哈！万物都是互相关联的，所以要训练自己发现问题本质的能力
这题就是就是动态规划，通过空间记忆，换递推关系，赢得时间效率
*/
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long, int> prefixSum;
        int res = 0;
        prefixSum[0] = 1; // 二叉树上的动态规划啊！！！
        dfs(root, targetSum, prefixSum, 0, res);
        return res;
    }

    void dfs(TreeNode* root, int targetSum, unordered_map<long, int>& prefixSum, long curSum, int& res) {
        if (!root) {
            return;
        }

        curSum += root->val;
        if (prefixSum.find(curSum - targetSum) != prefixSum.end()) {
            res += prefixSum[curSum - targetSum];
        }
        prefixSum[curSum]++;
        dfs(root->left, targetSum, prefixSum, curSum, res);
        dfs(root->right, targetSum, prefixSum, curSum, res);
        prefixSum[curSum]--;
    }
};