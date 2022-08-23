class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    	// 不重复字符串的左边界法
    	int res = 0;
    	int left = 0;
    	unordered_map<char, int> mp;
    	for (int i = 0; i < s.size(); ++i) {
    		char c = s[i];
    		// 遇到重复字符，调整左边界
    		if (mp.find(c) != mp.end() && mp[c] >= left) {
    			left = mp[c] + 1;
    		}
    		res = max(res, i - left + 1);
    		mp[c] = i;
    	}
    	return res;
    }
};