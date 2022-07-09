class Solution {
public:
	bool need_check = true;
	map<char, int> cur_map, str_map;
	

	bool check() {
		for (auto& it : str_map) {
			if (cur_map[it.first] < it.second) {
				return fasle;
			}
		}
		return true;
	}

    string minWindow(string s, string t) {
    	vector<int> ans {0, s.size()};

    	for (char c: t) {
    		str_map[c]++;
    	}

    	int left = 0;
    	int right = 0;
    	while (right < s.size()) {
    		cur_map[s[right]]++;
    		while (left <= right && check()) {
    			if (right - left < ans[1] - ans[0]) {
    				ans = {left, right};
    			}

    			if (str_map.find(s[left]) != str_map.end()) {
    				cur_map[s[left]]--;
    			}
    			left++;
    		}

    		right++;
    	}

    	if (ans[1] - ans[0] == s.size()) {
    		return "";
    	} else{
    		return s.substr(ans[0], ans[1] - ans[0] + 1);
    	}
    }
};