class Solution {
public:
    int titleToNumber(string columnTitle) {
        long res = 0;
        long carry = 1;
        for (int i = columnTitle.size() - 1; i >= 0; --i) {
            res += carry * (columnTitle[i] - 'A' + 1);
            carry *= 26;
        }
        return res;
    }
};