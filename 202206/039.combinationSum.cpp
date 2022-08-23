class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    	vector<vector<int>> res;
    	vector<int> comb;
    	dfs(candidates, comb, 0, target, res);
    	return res;
    }

    void dfs(vector<int>& candidates, vector<int>& comb, int i, int target, vector<vector<int>>& res) {
    	if (target == 0) {
    		res.push_back(comb);
    		return;
    	}
    	if (i == candidates.size()) {
    		return; // 边界
    	}

    	// 核心思想是选与不选！！！
    	dfs(candidates, comb, i + 1, target, res);
    	if (candidates[i] <= target) {
    		comb.push_back(candidates[i]);
    		dfs(candidates, comb, i, target - candidates[i], res);
    		comb.pop_back();
    	}
    }
};