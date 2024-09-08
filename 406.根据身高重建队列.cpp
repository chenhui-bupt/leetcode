class Solution {
public:
    // 算法一：预排序（从大到小排序）
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // 1.按身高从大到小，人数从小到大排序
        sort(people.begin(), people.end(), [](vector<int>& left, vector<int>&right) {
            return left[0] > right[0] || (left[0] == right[0] && left[1] < right[1]);
        });

        // 2.按照人数ki指定位置插入
        vector<vector<int>> res;
        for (auto& p : people) {
            res.insert(res.begin() + p[1], p);
        }
        return res;
    }

    // 算法二：预排序（从小到大排序）
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // 1.按身高从小到大排序（身高相同时，按ki倒排，仔细想想为什么？）
        sort(people.begin(), people.end(), [](vector<int>& left, vector<int>& right) {
            return left[0] < right[0] || (left[0] == right[0] && left[1] > right[1]);
        });

        // 2.按照人数ki规则空白位置放置
        vector<vector<int>> res(people.size());
        for (auto& p : people) {
            int space = p[1];
            for (int i = 0; i < people.size(); ++i) {
                if (res[i].empty()) { // 为空的才能被放置
                    if (space == 0) {
                        res[i] = p; // 找到位置
                        break;
                    }
                    --space;
                }
            }
        }
        return res;
    }
};