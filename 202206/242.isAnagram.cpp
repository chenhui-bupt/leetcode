class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> s_vec(26);
        vector<int> t_vec(26);
        for (char c : s) {
            s_vec[c - 'a']++;
        }
        for (char c : t) {
            t_vec[c - 'a']++;
        }

        for (int i = 0; i < 26; ++i) {
            if (s_vec[i] != t_vec[i]) {
                return false;
            }
        }
        return true;
    }
};