/**
 * 记住这个结论：分数的结果是有理数
 */
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long num = numerator;
        long denom = denominator;
        // 1.整除
        if (num % denom == 0) {
            return to_string(num / denom);
        }

        // 2.有限小数或循环小数
        string res = "";
        // 负号
        if ((numerator < 0) ^ (denominator < 0)) {
            res += "-";
        }

        // 整数部分
        num = abs(num);
        denom = abs(denom);
        res += to_string(num / denom);
        res += ".";

        // 小数部分
        string fraction = "";
        long remainder = num % denom;
        unordered_map<long, int> mp; // 哈希表记录循环数字
        int index = 0;
        while (remainder != 0 && mp.count(remainder) == 0) {
            mp[remainder] = index++;
            remainder *= 10;
            fraction += to_string(remainder / denom);
            remainder = remainder % denom;            
        }

        // 循环小数
        if (remainder != 0) {
            index = mp[remainder];
            res += fraction.substr(0, index) + "(" + fraction.substr(index) + ")";
        } else {
            res += fraction;
        }
        return res;
    }
};