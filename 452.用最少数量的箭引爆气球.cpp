class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) {
            return 0;
        }
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        });

        int res = 1;
        int right = points[0][1];
        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] > right) {
                ++res;
                right = points[i][1];  // 最靠左的右边界
            }
        }
        return res;
    }
};
