class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> vec(numRows);
        int direction = 0;
        int row = 0;
        for (int i = 0; i < s.size(); ++i) {
            vec[row].push_back(s[i]);
            if (numRows == 1) {
                direction = 0;
            } else if (row == numRows - 1) {
                direction = -1;
            } else if (row == 0) {
                direction = 1;
            }
            row += direction;
        }
        string res = "";
        for (int i = 0; i < numRows; ++i) {
            res += vec[i];
        }
        return res;
    }
};