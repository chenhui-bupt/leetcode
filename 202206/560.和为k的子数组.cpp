/*
类似二叉树的路径和，相同点：（1）连续；（2）不必从根节点开始
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSum;
        prefixSum[0] = 1;
        int res = 0;
        int curSum = 0;
        for (int num : nums) {
            curSum += num;
            if (prefixSum.find(curSum - k) != prefixSum.end()) {
                res += prefixSum[curSum - k];
            }
            prefixSum[curSum]++;
        }
        return res;
    }
};