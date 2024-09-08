class Solution {
public:
    vector<int> _nums;

public:
    Solution(vector<int>& nums) {
        _nums = nums;
    }
    
    vector<int> reset() {
        return _nums;
    }
    
    vector<int> shuffle() {
        //srand((unsigned)time(NULL)); // 此处不能随意更改种子，会影响随机分布
        vector<int> res = _nums;
        int n = res.size();
        for (int i = 0; i < n; ++i) {
            int j = rand() % (n - i) + i;
            swap(res[i], res[j]);
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */