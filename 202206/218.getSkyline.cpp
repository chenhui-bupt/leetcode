/* 算法思路
第一步：合并矩形区间
第二步：寻找轮廓（天际线）
这种方法是不行的。

可以这样考虑，天际线出现在左边缘，因此通过画竖线的方法。
题目要求：”输出每个矩形的上边左端点，同时跳过可由前一矩形上边延展而来的那些边”
所以需要维护一个最大高度的优先队列。使用的算法是线扫描法：
第一步：构建建筑物的边缘数组，并从左往右排序（用于线扫描）
第二步：线扫描，遍历边缘数组，并用优先队列存储该条线上的建筑物，
（2.1）加入左边界在线上的建筑；
（2.2）弹出右边界不在线上的建筑；
（2.3）优先队列对顶建筑的最大高度，即是天际线。

*/

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        // 一、建筑边界（线扫描准备）
        vector<int> boundaries;
        for (auto& building : buildings) {
            boundaries.push_back(building[0]); // 左边界
            boundaries.push_back(building[1]); // 右边界
        }
        sort(boundaries.begin(), boundaries.end());

        // 二、优先队列（线扫描）
        auto cmp = [](const pair<int, int>& left, const pair<int, int>& right) -> bool {return left.second < right.second;}; // 大顶堆
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);

        vector<vector<int>> res;
        int i = 0;
        for (int boundary : boundaries) {
            // 2.1 加入左边界在线上的建筑
            while (i < buildings.size() && buildings[i][0] <= boundary) {
                q.push(pair<int, int>(buildings[i][1], buildings[i][2]));
                i++;
            }

            // 2.2 弹出右边界不在线上的建筑
            while (!q.empty() && q.top().first <= boundary) {
                q.pop();
            }

            // 2.3 计算天际线
            int line = q.empty() ? 0 : q.top().second;
            if (res.size() == 0 || line != res.back()[1]) {
                res.push_back({boundary, line});
            }
        }
        return res;
    }
};