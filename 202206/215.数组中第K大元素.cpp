/*
使用快排，因为快排是将比mid小的数放在左边，大的放在右边，这样可以逐步找到第k大元素
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quicksort(nums, 0, nums.size() - 1, k);
    }

    int quicksort(vector<int>& nums, int left, int right, int k) {
        int mid = partition(nums, left, right);
        if (mid == nums.size() - k) {
            return nums[mid];
        } else if (mid < nums.size() - k) {
            return quicksort(nums, mid + 1, right, k);
        } else {
            return quicksort(nums, left, mid - 1, k);
        }
    }
    int partition(vector<int>& nums, int left, int right) {
        int temp = nums[left];
        while (left < right) {
            while (left < right && nums[right] >= temp) {
                right--;
            }
            nums[left] = nums[right];
            while (left < right && nums[left] <= temp) {
                left++;
            }
            nums[right] = nums[left];
        }
        nums[left] = temp;
        return left;
    }
};


/*
使用堆排
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = n / 2; i >= 0; --i) {
            headAdjust(nums, i, n - 1);
        }

        for (int i = 0; i < k; ++i) {
            swap(nums[0], nums[n - 1 - i]);
            headAdjust(nums, 0, n - 1 - i - 1);
        }
        return nums[n - k];
    }

    void headAdjust(vector<int>& nums, int start, int end) {
        int target = nums[start];
        int child = 2 * start + 1;
        while (child <= end) {
            if (child < end && nums[child] < nums[child + 1]) {
                child++;
            }

            if (nums[child] <= target) {
                break;
            }
            nums[start] = nums[child];
            start = child;
            child = 2 * start + 1;
        }
        nums[start] = target;
    }
};
