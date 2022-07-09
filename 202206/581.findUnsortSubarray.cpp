/*
找到左边下降和右边上升的转折点，同时根据两个波峰和波谷判断是否需要延长
*/
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int tmin = INT_MAX;
        int tmax = INT_MIN;
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] > nums[i+1] && nums[i+1] < tmin) {
                tmin = nums[i+1];
            }
        }

        for (int i = nums.size() - 1; i > 0; --i) {
            if (nums[i-1] > nums[i] && nums[i-1] > tmax) {
                tmax = nums[i-1];
            }
        }

        int left = 0;
        int right = nums.size() - 1;
        while (left < nums.size() && nums[left] <= tmin) {
            left++;
        }

        while (right >= 0 && nums[right] >= tmax) {
            right--;
        }
        if (right > left) {
            return right - left + 1;
        } else {
            return 0;
        }
    }
};