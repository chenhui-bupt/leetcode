class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        for (int i = 1; i < n; ++i) {
            res[i] = res[i-1] * nums[i-1];
        }
        
        int t = 1;
        for (int i = n - 2; i >= 0; --i) {
            res[i] *= (nums[i+1] * t);
            t = nums[i+1] * t;
        }
        
        return res;
    }
};