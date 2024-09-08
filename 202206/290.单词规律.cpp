class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mp;
        unordered_set<string> st;
        int k = 0;
        int j = 0;
        int i = 0;
        while (i < s.size()) {
            while (i < s.size() && s[i] != ' ') {
                ++i;
            }
            string word = s.substr(j, i - j);
            if (mp.find(pattern[k]) != mp.end() && mp[pattern[k]] != word) {
                return false;
            }
            
            if (mp.find(pattern[k]) == mp.end()) {
                if (st.find(word) != st.end()) {
                    return false;
                }
                st.insert(word);
            }
            mp[pattern[k++]] = word;
            j = i + 1;
            while (j < s.size() && s[j] == ' ') {
                ++j;
            }
            i = j;
        }

        return k == pattern.size();
    }
};