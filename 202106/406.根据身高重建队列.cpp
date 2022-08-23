class Solution {
public:
	vector<vector<int>> reconstructQueue(vector<vector<int>> people) {
		sort(people.begin(), people.end(), [](vector<int>& left,  vector<int>& right) {
			return left[0] < right[0] || (left[0] == right[0] && left[1] > right[1]);
		});

		vector<vector<int>> ans(people.size());
		for (auto& p : people) {
			int idx = 0;
			int space = p[1] + 1;			
			while (space) {
				if (ans[idx].empty()) {
					space--;
				}
				idx++;
			}
			ans[idx] = p;
		}
	}
}

vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
	sort(people.begin(), people.end(), [](vector<int>& left, vector<int>& right) {
		return left[0] > right[0] || (left[0] == right[0] && left[1] < right[1]);
	});

	vector<vector<int>> ans(people.size());
	for (auto& p: people) {
		ans.insert(p[1], p);
	}
	return ans;
}