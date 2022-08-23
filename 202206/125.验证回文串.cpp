class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;
        while (l < r) {
            if (!isalpha(s[l]) or !isdigit(s[l])) {
                l++;
                continue;
            }
            if (!isalpha(s[r]) or !isdigit(s[r])) {
                r--;
                continue;
            }

            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};