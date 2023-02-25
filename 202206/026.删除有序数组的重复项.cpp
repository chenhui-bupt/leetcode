/**
 * 算法：双指针法
 * 思路：左指针负责指向最新的不重复的数字，右指针负责指向目前正在处理数字
 * 这题虽是简单题，但经常成为其他题中的一部分，所以也需要掌握
 */
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