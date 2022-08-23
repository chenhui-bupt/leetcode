/*
贪心算法，先将数组排序，再逐个合并
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        // 排序
        sort(intervals.begin(), intervals.end());
        // 合并
        int i = 0;
        while (i < intervals.size()) {
            int j = i + 1;
            int right = intervals[i][1];
            while (j < intervals.size() && intervals[j][0] <= right) { // 不断寻找右边界
                right = max(right, intervals[j][1]);
                j++;
            }
            res.push_back({intervals[i][0], right});
            i = j;
        }
        return res;
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        // 排序
        sort(intervals.begin(), intervals.end());
        for (auto interval : intervals) {
            if (res.size() == 0 || interval[0] > res.back()[1]) {
                res.push_back(interval);
            } else {
                res.back()[1] = max(res.back()[1], interval[1]);
            }
        }
        return res;
    }
};