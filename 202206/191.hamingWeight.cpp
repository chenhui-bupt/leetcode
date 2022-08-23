/*
与比特位计数题相同
*/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n) {
            n = n & (n - 1); // 消去最高位的1
            res++;
        }
        return res;
    }
};