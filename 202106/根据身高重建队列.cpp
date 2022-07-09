class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    	// 从低到高
    	sort(people.begin(), people.end(), [](vector<int>& left, vector<int>& right) {
    		return (left[0] < right[0]) || (left[0] == right[0] && left[1] > right[1]);
    	});

    	int n = people.size();
    	vector<vector<int>> res(n);
    	for (auto& p : people) {
    		int spaces = p[1];
    		for (int i = 0; i < n; ++i) {
    			if (res[i].empty()) {
    				if (!spaces) {
    					res[i] = p;
    					break;
    				}
    				--spaces;
    			}
    		}
    	}
    	return res;

    	// 从高到低
    	sort(people.begin(), people.end(), [](vector<int>& left, vector<int>& right) {
    		return left[0] > right[0] || (left[0] == right[0] && left[1] < right[1]);
    	});

    	vector<vector<int>> res;
    	for (auto& p : people) {
    		res.insert(res.begin() + p[1], p);
    	}
    	return res;
    }
};