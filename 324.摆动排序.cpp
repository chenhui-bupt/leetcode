/**
 * 摆动排序
 * 找出大小分界线，若数组个数为奇数，则最中间的数放在左边，然后左右两个子数组交叉排列即可。
 * 同时会发下若从小到大穿插，当分界线数字的重复次数较多时，左右数组的”摆动“特性会打破，
 * 通过选择从大到小穿插，可以有效解决。
 * 题解：https://leetcode.cn/problems/wiggle-sort-ii/solution/yi-bu-yi-bu-jiang-shi-jian-fu-za-du-cong-onlognjia/
 * 算法一：排序+逆序穿插
 * 算法二：快排
 * 思路二：第一步找出中位数；第二步分区将小数放在左侧，大数放在右侧；第三步逆序穿插
 */

class Solution {
public:
    // 算法一：排序+逆序穿插，时间o(nlogn)，空间o(n)
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> res;
        int mid = (nums.size() - 1) / 2;
        int right = nums.size() - 1;
        int i = mid;
        int j = right;
        while (j > mid) {
            res.push_back(nums[i--]);
            res.push_back(nums[j--]);
        }
        if (i==0) {
            res.push_back(nums[0]);
        }

        for (int i = 0; i < nums.size(); ++i) {
            nums[i] = res[i];
        }
    }

    // 算法二：快排，时间O(n)，空间O(n)
    void wiggleSort(vector<int>& nums) {
        // 第一步：找出中位数
        int n = nums.size();
        int mid = n / 2;
        quickSort(nums, 0, n - 1, mid);
        
        // 第二步：分区
        int i = 0, j = n - 1, k = 0;
        while (k < j) {
            if (nums[k] > nums[mid]) {
                swap(nums[k], nums[j]);
                j--; // 右边界
            } else if (nums[k] < nums[mid]) {
                swap(nums[k], nums[i]);
                i++; // 左边界
                k++; // 指针
            } else { // 相等，指针右移
                k++;
            }
        }

        // 第三步：穿插
        vector<int> res;
        if (n % 2 == 0) {
            mid--;
        }

        i = mid;
        j = n - 1;
        while (j > mid) {
            res.push_back(nums[i--]);
            res.push_back(nums[j--]);
        }
        if (i==0) {
            res.push_back(nums[0]);
        }

        for (int i = 0; i < nums.size(); ++i) {
            nums[i] = res[i];
        }
    }

    int partition(vector<int>& nums, int left, int right) {
        int target = nums[left];
        while (left < right) {
            while (left < right && nums[right] >= target) {
                right--;
            }
            nums[left] = nums[right];
            while (left < right && nums[left] <= target) {
                left++;
            }
            nums[right] = nums[left];
        }
        nums[left] = target;
        return left;
    }

    void quickSort(vector<int>& nums, int left, int right, int k) {
        if (left >= right) {
            return;
        }
        int mid = partition(nums, left, right);
        if (mid == k - 1) {
            return;
        } else if (mid < k - 1) {
            quickSort(nums, mid + 1, right, k);
        } else {
            quickSort(nums, left, mid - 1, k);
        }
    }
};