// 翻转数字
class Solution {
public:
    int reverse(int x) {
        // 整除取余法
        int res = 0;
        while (x) {
            int r = x % 10;
            if (res < INT_MIN / 10 || res > INT_MAX / 10) { 
                return 0;
            }
            res = res * 10 + r;
            x /= 10;
        }
        return res;
    }
};