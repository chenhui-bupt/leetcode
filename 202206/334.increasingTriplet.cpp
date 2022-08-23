/**
 * 错误算法：快排思路，当移动数字个数少于n-2次时，满足有i < j < k, nums[i] < nums[j] < nums[k];
 * 算法一：若位置i，左边有个小的，右边有个大的，则满足，实现方式通过构造左右最小、最大数组
 * 算法二：贪心，双指针first、second表示前两个数，贪心的假设使得first和second尽可能小，这样当遇到
 * second < nums[i]时，总能找到元素first'满足答案要求。
 */
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int target = nums[left];
        int cnt = 0;
        while (left < right) {
            while (left < right && nums[right] >= target) {
                right--;
            }
            if (left != right) {
                nums[left] = nums[right];
                cnt++;
            }
            while (left < right && nums[left] <= target) {
                left++;
            }
            if (left != right) {
                nums[right] = nums[left];
                cnt++;
            }
        }
        return cnt < nums.size() - 2;
    }

    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, INT_MAX);
        vector<int> right(n, INT_MIN);
        for (int i = 1; i < n; ++i) {
            left[i] = min(left[i-1], nums[i-1]);
        }
        for (int i = n - 2; i >= 0; --i) {
            right[i] = max(right[i+1], nums[i+1]);
        }

        for (int i = 1; i < n-1; ++i) {
            if (left[i] < nums[i] && nums[i] < right[i]) {
                return true;
            }
        }
        return false;
    }

    bool increasingTriplet(vector<int>& nums) {
        int first = nums[0];
        int second = INT_MAX;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > second) {
                return true;
            } else if (nums[i] > first && nums[i] <= second) {
                second = nums[i]; // 一定要确保更新的second，前面一定有小于其的first
            } else {
                first = nums[i];
            }
        }
        return false;
    }
};