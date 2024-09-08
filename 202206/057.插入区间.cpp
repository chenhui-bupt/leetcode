class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int i = 0;
        while (i < intervals.size() && intervals[i][0] < newInterval[0]) {
            ++i;
        }
        intervals.insert(intervals.begin() + i, newInterval);
        
        for (int i = 0; i < intervals.size(); ++i) {
            if (res.empty() || intervals[i][0] > res.back()[1]) {
                res.push_back(intervals[i]);
            } else {
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
        }
        return res;
    }
};