class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if (nums.empty()) {
            return res;
        }
        int start = nums[0];
        int pre = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != pre + 1) {
                if (start != pre) {
                    res.push_back(to_string(start) + "->" + to_string(pre));
                } else {
                    res.push_back(to_string(pre));
                }
                start = nums[i];
            }
            pre = nums[i];
        }

        if (start != pre) {
            res.push_back(to_string(start) + "->" + to_string(pre));
        } else {
            res.push_back(to_string(pre));
        }
        return res;
    }
};