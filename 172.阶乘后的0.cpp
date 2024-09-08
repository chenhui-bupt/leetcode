/*
阶乘后的零
通过数学归纳可以看出，末尾为0主要有5和0决定，而0本质上是5和2决定（每隔一个5就会出现2与5的组合）
而每隔一个25又会出现两个5（即5 * 5，末尾两个0），每隔一个125会出现三个5（即5 * 5 * 5，末尾三个0）
以此类推，res = n / 5 + n / 25 + n / 125 + ...
*/
class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        while (n > 0) {
            res += n / 5;
            n /= 5;
        }
        return res;
    }
};