/*
看似简单却一点也不简单的比特位计数，要学会利用二进制比特之间的关系，
比如1110比0110最高位多个1，1110比1111最低位少个1.
*/
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1);
        // 方法四：最低有效位
        for (int i = 0; i <= n; ++i) {
            res[i] = res[i & (i - 1)] + 1;
        }

        // 方法三：最低有效位
        for (int i = 0; i <= n; ++i) {
            res[i] = res[i >> 1] + i & 1;
        }

        // 方法二：最高有效位
        int highBit = 0;
        for (int i = 0; i <= n; ++i) {
            if (i & (i - 1) == 0) {
                highBit = i; // 即，0，2，4，8...
            }
            res[i] = res[i - highBit] + 1;
        }

        // 方法一：直接计数法
        for (int i = 0; i <= n; ++i) {
            res[i] = count(i);
        }
        
        return res;
    }

    int count(n) {
        cnt = 0;
        while (n) {
            n = n & (n - 1); // 将最低有效位置0
            cnt++;
        }
        return cnt;
    }
};