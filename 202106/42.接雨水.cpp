// 1.暴力法
class Solution {
public:
    int trap(vector<int>& height) {
    	int ans = 0;
    	for (int i = 1; i < height.size() - 1; ++i) {
    		int left_max = 0;
    		int right_max = 0;
    		for (int j = i; j >=0; --j) {
    			if (left_max < height[j]) {
    				left_max = height[j];
    			}
    		}
    		for (int j = i; j < height.size(); ++j) {
    			if (right_max < heigh[j]) {
    				right_max = height[j];
    			}
    		}
    		ans += min(left_max, right_max) - height[i];
    	}
    	return ans;
    }
};

// 2.动态规划
class Solution {
public:
    int trap(vector<int>& height) {
    	int ans = 0;
    	if (height.size() == 0) {
    		return 0;
    	}
    	vector<int> dp_left(height.size());
    	vector<int> dp_right(height.size());
    	dp_left[0] = height[0];
    	dp_right[height.size() - 1] = height[height.size() - 1];
    	for (int i = 1; i < height.size(); ++i) {
    		dp_left[i] = max(dp_left[i-1], height[i]);
    	}
    	for (int i = height.size() - 2; i >= 0; --i) {
    		dp_right[i] = max(dp_right[i+1], height[i]);
    	}
    	for (int i = 1; i < height.size() - 1; ++i) {
    		ans += min(dp_left[i], dp_right[i]) - height[i];
    	}
    	return ans;
    }
};

// 3.栈
class Solution {
public:
    int trap(vector<int>& height) {
    	if (height.size() == 0) {
    		return 0;
    	}
    	int ans = 0;
    	vector<int> st;
    	int i = 0;
    	while (i < height.size()) {
    		while (!st.empty() && height[i] > height[st.back()]) {
    			int bottom = st.back();
    			st.pop_back();
    			if (st.empty()) {
                    break;
                }
    			ans += (min(height[i], height[st.back()]) - height[bottom]) * (i - st.back() - 1);
    		}
    		st.push_back(i++);
    	}
    	return ans;
    }
};

// 4.双指针
class Solution {
public:
    int trap(vector<int>& height) {
    	int ans = 0;
    	if (height.size() == 0) {
    		return 0;
    	}
    	int left = 0;
    	int right = height.size() - 1;
    	int left_max = 0;
    	int right_max = 0;
    	while (left < right) {
    		if (height[left] < height[right]) {
    			if (height[left] > left_max) {
    				left_max = height[left];
    			} else {
    				ans += left_max - height[left];
    			}
    			left++;
    		} else {
    			if (height[right] > right_max) {
    				right_max = height[right];
    			} else {
    				ans += right_max - height[right];
    			}
    			right--;
    		}
    	}
    	
    	return ans;
    }
};