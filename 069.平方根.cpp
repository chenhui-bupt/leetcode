/*
算法1：对数法
算法2：二分查找
算法3：牛顿迭代法
*/

class Solution {
public:
    // 算法1：对数法
    int mySqrt(int x) {
        int res = 0;
        res = int(exp(0.5 * log(x)));
        return (res + 1) * (res + 1) <= x ? res + 1 : res;
    }

    // 算法2：二分查找
    int mySqrt(int x) {
        int left = 0;
        int right = x;
        int res = -1;
        while (left <= right) {
            int mid = left + (right - left) >> 1;
            if ((long long)mid * mid <= x) {
                res = mid; // 类似于查找元素的最后一个位置
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return res;
    }

    // 算法3：牛顿迭代法
    int mySqrt(int x) {
        if (x == 0) {
            return 0; // 防止后面除以零
        }
        double C = x;
        double x0 = C;
        while (true) {
            double xi = 0.5 * (x0 + C / x0);
            if (fabs(xi - x0) < 1e-6) {
                break;
            }
            x0 = xi;
        }
        return int(x0);
    }
};