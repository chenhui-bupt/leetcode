class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        reverse(s.begin(), s.end());
        
        int i = 0;
        int j = 0;
        while (i < n) {
            while (i < n && s[i] == ' ') {
                ++i;
            }
            j = i;
            while (j < n && s[j] != ' ') {
                ++j;
            }
            reverse(s.begin() + i, s.begin() + j);
            i = j + 1;
        }

        i = 0;
        j = 0;
        while (i < n) {
            if (s[i] != ' ' || (j > 0 && s[j-1] != ' ')) {
                s[j++] = s[i];
            }
            ++i;
        }

        return s[j-1] == ' ' ? s.substr(0, j-1) : s.substr(0, j);
    }
};