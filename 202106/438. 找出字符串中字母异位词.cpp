class Solution {
	vector<int> findAnagrams(string s, string p) {
		vector<int> p_vec(26);
		vector<int> window(26);
		for (char c : p) {
			p_vec[c - 'a']++;
		}

		for (int i = 0; i < p.size() - 1; ++i) {
			window[s[i] - 'a']++;
		}

		int left = 0;
		int right = p.size() - 1;
		while (right < s.size()) {
			window[s[right++] - 'a']++;
			if (window == p_vec) {
				ans.push_back(left);
			}
			
			window[s[left++] - 'a']--;
		}
	}	
}