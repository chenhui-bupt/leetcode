/*
找到左边下降和右边上升的转折点，同时根据两个波峰和波谷判断是否需要延长
*/
class Solution {
public:
    // 算法一：传统寻找波谷波峰法
    int findUnsortedSubarray(vector<int>& nums) {
        int tmin = INT_MAX;
        int tmax = INT_MIN;
        // 第一步：从左到右寻找波谷
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] > nums[i+1] && nums[i+1] < tmin) {
                tmin = nums[i+1];
            }
        }

        // 第二步：从右到左寻找波峰
        for (int i = nums.size() - 1; i > 0; --i) {
            if (nums[i-1] > nums[i] && nums[i-1] > tmax) {
                tmax = nums[i-1];
            }
        }

        int left = 0;
        int right = nums.size() - 1;
        // 第三步：从左到右寻找无序的左边界
        while (left < nums.size() && nums[left] <= tmin) {
            left++;
        }

        // 第四步：从右到左寻找无序的右边界
        while (right >= 0 && nums[right] >= tmax) {
            right--;
        }
        // 第五步：计算闭区间长度
        if (right > left) {
            return right - left + 1;
        } else {
            return 0;
        }
    }

    // 算法二：一次遍历
    // 思路二：无序数组必然存在两段有序数组的中间
    int findUnsortedSubarray(vector<int>& nums) {
        int left = 0;
        int right = -1;
        int minn = nums[nums.size() - 1];
        int maxn = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            // 第一步：从左往右找出右边界
            if (maxn <= nums[i]) {
                maxn = nums[i];
            } else {
                right = i;
            }

            // 第二步：从右往左找出左边界
            int j = nums.size() - i - 1;
            if (minn >= nums[j]) {
                minn = nums[j];
            } else {
                left = j;
            }
        }
        // 第三步：计算无序子数组长度
        if (left < right) {
            return right - left + 1;
        } else {
            return 0;
        }
    }
};