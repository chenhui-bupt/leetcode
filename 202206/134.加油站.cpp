/*
贪心算法 or 动态规划
当前油箱油量大于下一段路程消耗量，即可继续；否则，重新设定起始加油站和油量
*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int dp = 0; // 油箱油量
        int start = -1;
        for (int i = 0;;i++) {
            int j = i % n;
            if (i >= 2 * n) {
                return -1;
            }
            if (j == start) {
                if (dp >= 0) {
                    return start;
                } else {
                    return -1;
                }
            }
            if (dp <= 0) {
                dp = gas[j] - cost[j];
                if (dp >= 0) {
                    start = j;
                }
            } else {
                dp += (gas[j] - cost[j]) // 到达j+1时油箱油量
            }
        }
        return -1;
    }
};


// 参考题解，找到总剩余油量最小的点（波谷）从该处出发如果能走完一圈，即是求解，不能则无解
/**
 * 能走完一圈必须满足条件：
 * （1）总剩余油量大于0；
 * （2）每时每刻的剩余油量大于0。
 * 所以，从总剩余油量最小的点出发能走完一圈，则满足上诉两个条件。
 */ 
public int canCompleteCircuit(int[] gas, int[] cost) {
    int len = gas.length;
    int spare = 0;
    int minSpare = Integer.MAX_VALUE;
    int minIndex = 0;

    for (int i = 0; i < len; i++) {
        spare += gas[i] - cost[i];
        if (spare < minSpare) {
            minSpare = spare;
            minIndex = i;
        }
    }

    return spare < 0 ? -1 : (minIndex + 1) % len;
}

