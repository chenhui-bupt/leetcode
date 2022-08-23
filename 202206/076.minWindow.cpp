/*直接算
1.记录当前窗口大小，当匹配成功，不断右移左边界，寻找最优解空间
2.右移右边界
*/
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> s_mp;
        unordered_map<char, int> t_mp;
        for (char c: t) {
            t_mp[c]++;
        }
        int l = 0;
        int r = 0;
        int res_l = 0;
        int res_r = INT_MAX;
        while (r < s.size()) {
            s_mp[s[r]]++;
            while (check(s_mp, t_mp)) {
                if (res_r - res_l > r - l) {
                    res_r = r;
                    res_l = l;
                }
                s_mp[s[l++]]--;
            }
            r++;
        }
        if (res_r < INT_MAX) {
            return s.substr(res_l, res_r - res_l + 1);
        } else {
            return "";
        }
    }

    bool check(unordered_map<char, int>& s_mp, unordered_map<char, int>& t_mp) {
        for (auto [c, v] : t_mp) {
            if (s_mp.find(c) == s_mp.end() || s_mp[c] < v) {
                return false;
            }
        }
        return true;
    }
};