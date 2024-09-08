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
 * （1）总剩余油量大于0； -> space > 0
 * （2）每时每刻的剩余油量大于0。 -> minIdx
 * 所以，从总剩余油量最小的点出发能走完一圈，则满足上诉两个条件。
 */ 
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int minSpace = INT_MAX;
        int minIdx = -1;
        int space = 0;
        for (int i = 0; i < gas.size(); ++i) {
            space += (gas[i] - cost[i]);
            //cout << space << endl;
            if (space < minSpace) {
                minSpace = space;
                minIdx = i;
            }
        }
        // spare >= 0保证总剩余油量大于0（可以走完一圈）
        // minIndex表示从最低点minIndex出发，才能保证每时每刻油量大于等于0
        return space >= 0 ? (minIdx + 1) % gas.size() : -1;
    }
};
