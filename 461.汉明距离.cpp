/*
汉明距离，异位的个数
1.先求异或
2.再求二进制1的个数
*/
class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x ^ y;
        int res = 0;
        while (z) {
            res++;
            z = z & (z - 1); // 消去最后面的1
        }
        return res;
    }
};