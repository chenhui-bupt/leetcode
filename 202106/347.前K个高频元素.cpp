class Solution {
public:

	vector<int> topKFrequent(vector<int>& nums, int k) {
		unorder_map<int, int> mp;
		for (int num : nums) {
			mp[num]++;
		}

		vector<pair<int, int>> vec;
		for (auto [k, v] : mp) {
			vec.push_back(make_pair<int, int>(k, v));
		}

		// 快排
		quickSort(vec, 0, vec.size()-1, k);
		// 遍历，取出前k大元素
		
		// 堆排
	}

	void quickSort(vector<pair<int, int>> vec, int left, int right, int k) {
		if (left >= right) {
			return;
		}

		int mid = partition(vec, left, right);
		if (mid == k - 1) {
			return;
		} else if (mid < k - 1) {
			quickSort(vec, mid + 1, right);
		} else {
			quickSort(vec, left, mid);
		}
	}

	int partition(vector<pair<int, int>> vec, int left, int right) {
		if (left >= right) {
			return left;
		}

		int target = vec[left];
		while (left < right) {
			while (left < right && vec[right].second >= target.second) {
				--right;
			}
			vec[left] = vec[right];
			while (left < right && vec[left].second <= target.second) {
				++left;
			}
			vec[right] = vec[left];
		}
		vec[left] = target;
		return left;
	}
}