/*
斐波那契数列，动态规划
*/
class Solution {
public:
    int climbStairs(int n) {
    	int f1 = 1;
    	int f2 = 2;
    	if (n == 1) {
    		return f1;
    	} else if (n == 2) {
    		return f2;
    	}
    	int f = 0;
    	for (int i = 3; i <= n; ++i) {
    		f = f1 + f2;
    		f1 = f2;
    		f2 = f;
    	}
    	return f;
    }
};