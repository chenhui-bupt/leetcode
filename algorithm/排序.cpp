// 冒泡排序
void sort(std::vector<int>& nums) {
	if (nums.size() == 0) {
		return;
	}

	for (int i = 0; i < nums.size(); ++i) {
		for (int j = nums.size() - 1; j >= i; --j) {
			if (nums[j-1] > nums[j]) {
				swap(nums[j-1], nums[j]);
			}
		}
	}
}

// 快排
void sort(std::vector<int>& nums) {
	if (nums.size() == 0) {
		return;
	}
	quickSort(nums, 0, nums.size() - 1);
}

int partition(std::vector<int>& nums, int left, int right) {
	int temp = nums[left];
	while (left < right) {
		while (left < right && nums[right] >= temp) {
			--right;
		}
		nums[left] = nums[right]; // 把小的移到左边
		while (left < right && nums[left] <= temp) {
			++left;
		}
		nums[right] = nums[left]; // 把大的移到右边
	}
	nums[left] = temp;
	return left;
}

void quickSort(std::vector<int>& nums, int left, int right) {
	if (left >= right) {
		return;
	}
	int mid = partition(nums, left, right);
	quickSort(nums, left, mid - 1);
	quickSort(nums, mid + 1, right);
	return;
}


// 选择排序
void selectSort(std::vector<int>& nums) {
	if (nums.size() == 0) {
		return;
	}
	for (int i = 0; i < nums.size() - 1; ++i) {
		int minIndex = i;
		for (int j = i + 1; j < nums.size(); ++j) {
			if (nums[j] < nums[minIndex]) {
				minIndex = j;
			}
		}
		if (minIndex != i) {
			swap(nums[i], nums[minIndex]);
		}
	}
}

// 插入排序
void insertSort(std::vector<int> nums) {
	if (nums.size() == 0) {
		return;
	}

	for (int i = 1; i < nums.size(); ++i) {
		int temp = nums[i];
		int j = i - 1;
		while (j >= 0 && temp <= nums[j]) {
			nums[j+1] = nums[j];
			--j;
		}
		nums[j + 1] = temp;
	}
}


// 堆排序
void heapSort(std::vector<int>& nums) {
	for (int i = int(nums.size() / 2); i >= 0; --i) {
		headAdjust(nums, i, nums.size() - 1);
	}

	for (int i = nums.size() - 1; i >= 0; --i) {
		swap(nums[0], nums[i]);
		heapAjust(nums, 0, i - 1);
	}
}

// 大顶堆
void headAdjust(std::vector<int>& nums, start, end) {
	int temp = nums[start];
	int child = 2 * start + 1
	while (child <= end) {
		if (child < end && nums[child] < nums[child + 1]) {
			++child;
		}
		if (temp >= nums[child]) {
			break; // 已经是大顶堆
		}
		nums[start] = nums[child];
		start = child;
		child = 2 * start + 1;
	}
	nums[start] = temp;
}



void sort(std::vector<int>& nums) {
	mergeSort(nums, 0, nums.size() - 1);
}

void mergeSort(std::vector<int>& nums, int left, int right) {
	if (left >= right) {
		return;
	}
	int mid = (left + right) >> 1;
	mergeSort(nums, left, mid);
	mergeSort(nums, mid + 1, right);
	merge(nums, left, mid, right);
}

void merge(std::vector<int> nums, int left, int mid, int right) {
	std::vector<int> temp;
	int i = left;
	int j = mid + 1;
	while (i <= mid && j <= right) {
		if (nums[i] < nums[j]) {
			temp.push_back(nums[i]);
			++i;
		} else {
			temp.push_back(nums[j]);
			++j;
		}
	}
	while (i <= mid) {
		temp.push_back(nums[i]);
		++i;
	}
	while (j <= right) {
		temp.push_back(nums[j]);
		++j;
	}
	for (int i = 0; i < temp.size(); ++i) {
		nums[left + i] = temp[i];
	}
}


