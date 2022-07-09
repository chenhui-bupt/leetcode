// 异或运算
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // 异或运算
        int res = 0;
        for (int num : nums) {
            res ^= num;
        }
        return res;
    }
};