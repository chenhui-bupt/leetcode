/**
 * 给你一个整数数组 citations ，其中 citations[i] 表示研究者的第 i 篇论文被引用的次数，citations 已经按照 升序排列 。计算并返回该研究者的 h 指数。
 * h 指数的定义：h 代表“高引用次数”（high citations），一名科研人员的 h 指数是指他（她）的 （n 篇论文中）至少 有 h 篇论文分别被引用了至少 h 次。
 * 请你设计并实现对数时间复杂度的算法解决此问题。
*/
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int left = 0;
        int right = n - 1;
        // 寻找大于等于n-mid的最左侧的数
        while (left <= right) {
            int mid = (left + right) / 2;
            if (citations[mid] >= n - mid) { // 满足h，继续向左寻找
                right = mid - 1;
            } else { // 不满足，只能往右寻找
                left = mid + 1;
            }
        }
        return n - left;
    }
};