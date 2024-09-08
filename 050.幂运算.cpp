/*
数据结构：数字
算法1：快速幂 + 递归
算法2：快速幂 + 迭代
*/
class Solution {
public:
    // 算法一：递归
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

    // 算法二：迭代
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
            if (N & 1) { // N的二进制表示位为1，需要将贡献x^(2^k)记录答案；不为1时p只是中间结果
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