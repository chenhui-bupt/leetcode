/* 思路：把问题转化成负数相除，那商为正数，假定X、Y为负数，Z为商
所以：X/Y >= Z && X/Y < (Z+1)
所以，Z*Y >= X > (Z+1)*Y
所以，可以通过某种快速的方法找到ZY大于X的最大的Z
*/
class Solution {
public:
    int divide(int dividend, int divisor) {
        // 边界条件
        if (dividend == INT_MIN) {
            if (divisor == 1) { // 除数最小
                return INT_MIN;
            }
            if (divisor == -1) { // 除数最大
                return INT_MAX;
            }
        }

        if (divisor == INT_MIN) {
            return dividend == INT_MIN ? 1 : 0;
        }

        if (dividend == 0) {
            return 0;
        }

        int sign = 1;
        if (dividend > 0) {
            sign = -sign;
            dividend = -dividend;
        }
        if (divisor > 0) {
            sign = -sign;
            divisor = -divisor;
        }

        int left = 1;
        int right = INT_MAX;
        int res = 0;
        while (left <= right) {
            int mid = left + (right - left) >> 1;
            if (quickAdd(dividend, divisor, mid)) {
                res = mid;
                if (mid == INT_MAX) {
                    break;
                }
                left = mid + 1; // 找出满足条件的最大值
            } else {
                right = mid - 1;
            }
        }
        return sign * res;
    }

    bool quickAdd(int x, int y, int z) {
        // x 和 y 是负数，z 是正数
        // 需要判断 z * y >= x 是否成立
        int result = 0, add = y;
        while (z) {
            if (z & 1) {
                // 需要保证 result + add >= x
                if (result < x - add) {
                    return false;
                }
                result += add;
            }
            if (z != 1) {
                // 需要保证 add + add >= x
                if (add < x - add) {
                    return false;
                }
                add += add;
            }
            // 不能使用除法
            z >>= 1;
        }
        return true;
    }
};