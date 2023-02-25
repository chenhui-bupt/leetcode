class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> mp;
        for (int i = 0; i < s.size(); ++i) {
            if (mp.find(s[i]) == mp.end()) {
                mp[s[i]] = i;
            } else {
                mp[s[i]] = -1;
            }
        }
        int res = s.size();
        for (auto [k, v] : mp) {
            if (v >= 0 && v < res) {
                res = v;
            }
        }
        return res == s.size() ? -1 : res;
    }
};