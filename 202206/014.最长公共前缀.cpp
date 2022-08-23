class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        if (strs.empty()) {
            return res;
        }

        int i = 0;
        bool isEnd = false;
        while (1) {
            if (i >= strs[0].size()) {
                break;
            }
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); ++j) {
                if (strs[j].size() <= i || strs[j][i] != c) {
                    isEnd = true;
                    break;
                }
            }

            if (isEnd) {
                break;
            }
            i++;
            res += string(1, c);
        }
        return res;
    }
};