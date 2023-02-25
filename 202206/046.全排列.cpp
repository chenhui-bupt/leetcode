/*
全排列考察的是选与不选，并且选满，如何保证选与不选能选满呢，使用status标志位较为方便！！！
*/
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> perm;
        vector<int> status(nums.size(), 0);
        dfs(nums, status, perm, res);
        return res;
    }   

    void dfs(vector<int>& nums, vector<int>& status, vector<int>& perm, vector<vector<int>>& res) {
        if (perm.size() == nums.size()) {
            res.push_back(perm);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (status[i] == 0) {
                status[i] = 1;
                perm.push_back(nums[i]);
                dfs(nums, status, perm, res);
                perm.pop_back();
                status[i] = 0;
            }
        }
    }
};