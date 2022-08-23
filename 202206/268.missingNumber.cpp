/*
数组位标志法，即将数字num对应的位置数+n+1，即不影响原来的值大小，又能标记该位置的数字已存在
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        for (int num : nums) {
            int i = num % (n + 1);
            if (i == n) {
                continue;
            }
            nums[i] += n + 1;
        }

        for (int i = 0; i < n; ++i) {
            if (nums[i] < n + 1) {
                return i; // 小于n+1即为未找到
            }
        }
        return n; // 都找到，则为n不存在
    }
};