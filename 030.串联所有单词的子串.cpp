class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int len = s.size();
        int m = words.size();
        int n = words[0].size();
        vector<int> res;
        // 滑窗需要为n，减少计算量
        for (int i = 0; i < n && i + m * n <= len; ++i) {
            unordered_map<string, int> mp;
            for (int j = 0; j < m; ++j) {
                mp[s.substr(i + j * n, n)]++;
            }
            for (const string& word : words) {
                if (--mp[word] == 0) {
                    mp.erase(word);
                }
            }
            

            // 滑窗
            for (int start = i; start < len - m * n + 1; start += n) {
                if (start != i) { // 处理滑窗
                    string word = s.substr(start + (m - 1) * n, n);  // 右滑
                    if (++mp[word] == 0) {
                        mp.erase(word);
                    }

                    word = s.substr(start - n, n); // 剔左
                    if (--mp[word] == 0) {
                        mp.erase(word);
                    }
                }

                if (mp.empty()) {
                    res.push_back(start);
                }
            }
        }
        return res;
    }
};
