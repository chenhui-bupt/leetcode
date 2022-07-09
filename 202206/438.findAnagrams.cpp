/*
找到字母异位词所有起始位置，用一个划窗去找
*/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        vector<int, int> p_vec(26);
        vector<int, int> s_vec(26);
        for (char c : p) {
            p_vec[c - 'a']++;
        }

        int n = p.size();
        for (int i = 0; i < n; ++i) {
            s_vec[s[i] - 'a']++;
        }

        if (check(p_vec, s_vec)) {
            res.push_back(0);
        }

        for (int i = n; i < s.size(); ++i) {
            s_vec[s[i] - 'a']++;
            s_vec[s[i-n] - 'a']--;
            if (check(p_vec, s_vec)) {
                res.push_back(i - n + 1);
            }
        }
        return res;
    }

    bool check(vector<int, int>& p_vec, vector<int, int>& s_vec) {
        for (int i = 0; i < 26; ++i) {
            if (p_vec[i] != s_vec[i]) {
                return false;
            }
        }
        return true;
    }
};