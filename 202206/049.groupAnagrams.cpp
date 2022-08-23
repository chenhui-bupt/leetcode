/*
没有特别技巧的算法，直接求解，即对各字符串求哈希进行分组！
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mp;
        for (string s: strs) {
            string tmp = s;
            sort(tmp.begin(), tmp.end());
            if (mp.find(tmp) == mp.end()) {
                mp[tmp] = {};
            }
            mp[tmp].push_back(s);
        }
        for (unordered_map<string, vector<string>>::iterator iter = mp.begin(); iter != mp.end(); ++iter) {
            res.push_back(iter->second);
        }
        return res;
    }
};