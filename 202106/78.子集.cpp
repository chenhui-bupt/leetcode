class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
    	vector<vector<int>> ans;
    	queue<vector<int>> q;
    	q.push({});
    	while (!q.empty()) {
    		vector<int> front = q.front();
    		ans.push_back(front);
    		q.pop();
    		for (int num : nums) {
    			if (front.empty() || front.back() < num) {
    				vector<int> tmp(front);
    				tmp.push_back(num);
    				q.push_back(tmp);
    			}
    		}
    	}
    	return ans;
    }
};