/**
 * 预排序降低计算时间复杂度，重点在于怎么剔除重复的问题！！！
 * 
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    	vector<vector<int>> res;
    	// 排序
    	sort(nums.begin(), nums.end());

    	for (int i = 0; i < nums.size(); ++i) {
    		if (i > 0 && nums[i] == nums[i-1]) {
    			continue;
    		}
    		int target = 0 - nums[i];
    		int l = i + 1;
    		int r = nums.size() - 1;
    		while (l < r) {
    			if (l > i + 1 && nums[l] == nums[l-1]) {
    				++l;
    				continue;
    			}
    			if (nums[l] + nums[r] == target) {
    				res.push_back({nums[i], nums[l], nums[r]});
    				++l;
    			} else if (nums[l] + nums[r] < target) {
    				l++;
    			} else {
    				r--;
    			}
    		}
    	}
    	return res;
    }
};

