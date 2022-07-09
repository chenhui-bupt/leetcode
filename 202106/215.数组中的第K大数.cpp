
// 快排
class Solution {
	int getKth(vector<int>& nums, int k) {
		return quickSort(nums, 0, nums.size() - 1, k);
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

	int quickSort(vector<int>& nums, int left, int right, int k) {
		int mid = partition(nums, left, right);
		if (mid == nums.size() - k) {
			return nums[mid];
		} else if (mid < nums.size() - k) {
			return quickSort(nums, mid + 1, right, k);
		} else {
			return quickSort(nums, left, mid - 1, k);
		}
	}
}


// 堆排
class Solution {
public:
	int getKth(vector<int>& nums, int k) {
		// 构建堆
		for (int i = nums.size() / 2 - 1; i >= 0; --i) {
			heapAdjust(nums, i, nums.size() - 1);
		}

		// 排序
		for (int i = 0; i < k; ++i) {
			swap(nums[0], nums[nums.size() - i - 1]);
			heapAdjust(nums, 0, nums.size() - i - 2);
		}
		return nums[nums.size() - k];
	}

	def heapAdjust(vector<int>& nums, int start, int end) {
		int target = nums[start];
		int child = 2 * start + 1;
		while (child < end) {
			if (child <= end && nums[child] <= nums[child+1]) {
				child++;
			}

			if (nums[child] >= target) {
				break; // 已是大顶堆
			}

			nums[start] = nums[child];
			start = child;
			child = 2 * start + 1;
		}
		nums[start] = target;
	}
}