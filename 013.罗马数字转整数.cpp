// 记住规则就行
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> table = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int res = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'I' && i < s.size() - 1 && (s[i+1] == 'V' || s[i+1] == 'X')) {
                res += (table[s[i+1]] - table[s[i]]);
                i++;
            } else if (s[i] == 'X' && i < s.size() - 1 && (s[i+1] == 'L' || s[i+1] == 'C')) {
                res += (table[s[i+1]] - table[s[i]]);
                i++;
            } else if (s[i] == 'C' && i < s.size() - 1 && (s[i+1] == 'D' || s[i+1] == 'M')) {
                res += (table[s[i+1]] - table[s[i]]);
                i++;
            } else {
                res += table[s[i]];
            }
        }
        return res;
    }
};