/*
数据结构：数字
算法1：快速幂 + 递归
算法2：快速幂 + 迭代
*/
class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if (N >= 0) {
            return dfs(x, N);
        } else {
            return 1.0 / dfs(x, -N);
        }
    }

    double dfs(double x, long long n) {
        if (n == 0) {
            return 1;
        }

        double y = myPow(x, n / 2);
        if (n % 2 == 1) {
            return y * y * x;
        } else {
            return y * y;
        }
    }

    double myPow(double x, int n) {
        long long N = n;
        bool sign = false;
        if (N < 0) {
            N = -N;
            sign = true;
        }

        double res = 1;
        double p = x;
        while (N) {
            if (N & 1) {
                res *= p;
            }
            N = N >> 1;
            p = p * p;
        }
        if (sign) {
            return 1.0 / res;
        } else {
            return res;
        }
    }
};