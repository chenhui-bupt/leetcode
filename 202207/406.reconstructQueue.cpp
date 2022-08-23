class Solution {
public:
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
		// 方法一：从小到大
		sort(people.begin(), people.end(), [](vector<int> left, vector<int> right) {
			return (left[0] < right[0] || (left[0] == right[0] && left[1] > right[1]));
		});

		int n = people.size():
		vector<vector<int>> res(n);
		for (auto p : people) {
			int space = p[1];
			for (i = 0; i < n; ++i) {
				if (res[i].empty()) {
					if (space == 0) {
						res[i] = p;
						break;
					}
					space--;
				}
			}
		}

		// 方法二：从大到小
		sort(people.begin(), people.end(), [](vector<int>& left, vector<int>& right) {
			return (left[0] > right[0]) || (left[0] == right[0] && left[1] < right[1]);
		});

		for (auto p: people) {
			res.insert(p[1], p);
		}

		return res;
	}
}