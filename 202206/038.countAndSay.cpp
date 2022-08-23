class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }

        string res = "";
        string s = countAndSay(n - 1);
        int i = 0;
        while (i < s.size()) {
            int j = i + 1;
            while (j < s.size() && s[j] == s[i]) {
                j++;
            }
            res += to_string(j - i) + s[i];
            i = j;
        }
        return res;
    }
};