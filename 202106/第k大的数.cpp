

// 第k个大的数
// 快排的思路是找到一个下标，左边数都比他小，右边的数都比他大，然后递归

int partition(vector<int>& nums, int left, int right) {
	int tmp = nums[left];
	while (left < right) {
		while (left < right && nums[right] >= tmp) {
			--right;
		}
		nums[left] = nums[right];
		while (left < right && nums[left] <= tmp) {
			++left;
		}
		nums[right] = nums[left];		
	}
	nums[left] = tmp;
	return left;
}

int quicksort(vector<int>& nums, int left, int right) {
	int sep = partition(nums, left, right);
	if (sep == nums.size() - k) {
		return nums[sep];
	} else if (sep < nums.size() - k) {
		quicksort(nums, sep + 1, right);
	} else {
		quicksort(nums, left, sep - 1);
	}
	return 0;
}


// 构建堆、调整堆、排序or删除
// 大顶堆
int heapAdjust(vector<int>& nums, int start, int end) {
	int target = nums[start];
	while (start <= end) {
		int child = 2 * start + 1;
		if (child < end && nums[child] <= nums[child + 1]) {
			++child;
		}

		if (target >= nums[child]) {
			break;
		}

		nums[start] = nums[child];
		start = child;
		child = 2 * start + 1;
	}
	nums[start] = target;
}

for (int i = nums.size() / 2; i >= 0; --i) {
	heapAdjust(nums, i, nums.size() - 1);
}

for (int i = 0; i < k; ++i) {
	swap(0, nums.size() - 1 - i);
	heapAdjust(nums, 0, nums.size() - 1 - i);
}
return nums[nums.size() - k];



