/*
找出所有的子集，C_n_0, C_n_1, ..., C_n_n
方法一：宽度优先搜索
先处理0个组合问题，然后1个组合，2个组合，而后一层就是前一层再增加一个组合（要保证元素不重复）
方法二：深度优先搜索
每次选择或者不选，这样就能找出所有组合
*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        queue<vector<int>> q;
        q.push({});
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                vector<int> vec = q.front();
                res.push_back(vec);
                q.pop();
                for (int num : nums) {
                    if (vec.size() == 0 || vec.back() < num) {
                        vec.push_back(num);
                        q.push(vec);
                        vec.pop_back();
                    }
                }
            }
        }
        return res;
    }

    void dfs(vector<int>& nums, int i, vector<int>& comb, vector<vector<int>>& res) {
        if (i = nums.size()) {
            res.push_back(comb);
            return;
        }
        // 不选
        dfs(nums, i + 1, comb, res);
        // 选
        comb.push_back(nums[i]);
        dfs(nums, i + 1, comb, res);
        comb.pop_back();
    }
};