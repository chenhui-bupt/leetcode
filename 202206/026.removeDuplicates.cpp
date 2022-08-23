class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int j = 1;
        while (j < nums.size()) {
            if (nums[i] == nums[j]) {
                while (j < nums.size() && nums[i] == nums[j]) {
                    j++;
                }
                if (j < nums.size()) {
                    nums[i+1] = nums[j];
                    i++;
                }
            } else {
                i++;
                j++;
            }
        }
        return i + 1;
    }
};