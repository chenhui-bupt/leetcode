/*
找出所有的子集，宽度优先搜索
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
};