

vector<int> ans;
priority_queue<pair<int, int>> q;
for (int i = 0; i < k; ++i) {
    q.emplace(nums[i], i);
}
ans.push_back(q.top().first);

for (int i = k; i < nums.size(); ++i) {
    q.emplace(nums[i], i);
    while (q.top().second <= i - k) {
        q.pop();
    }
    ans.push_back(q.top().first);
}
return ans;


vector<int> maxSlidingWindow(vector<int>& nums, int k) {
	vector<int> ans;
	deque<int> q;
	for (int i = 0; i < k; ++i) {
	    while (!q.empty() && nums[q.back()] <= nums[i]) {
	        q.pop_back();
	    }
	    q.push_back(i);
	}
	ans.push_back(nums[q.front()]);

	for (int i = k; i < nums.size(); ++i) {
	    while (!q.empty() && nums[q.back()] <= nums[i]) {
	        q.pop_back();
	    }
	    q.push_back(i);
	    while (q.front() <= i - k) {
	        q.pop_front();
	    }
	    ans.push_back(nums[q.front()]);
	}
	return ans;
}


vector<int> pre_vec(nums.size(), 0);
vector<int> post_vec(nums.size(), 0);
for (int i = 0; i < nums.size(); ++i) {
	if (i % k == 0) {
		pre_vec[i] = nums[i];
	} else {
		pre_vec[i] = max(pre_vec[i-1], nums[i]);
	}
}

fro (int i = nums.size() - 1; i >= 0; --i) {
	if (i == nums.size() - 1 || (i + 1) % k == 0) {
		post_vec[i] = nums[i];
	} else {
		post_vec[i] = max(post_vec[i + 1], nums[i]);
	}
}

for (int i = 0; i <= nums.size() - k; ++i) {
	ans.push_back(max(post_vec[i], pre_vec[i + k - 1]));
}
return ans;

