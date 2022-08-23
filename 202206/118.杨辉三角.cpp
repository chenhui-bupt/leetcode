/*
杨辉三角
*/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if (numRows == 0) {
            return res;
        }
        vector<int> last = {1};
        res.push_back(last);
        for (int i = 1; i <= numRows; ++i) {
            vector<int> cur;
            cur.push_back(1);
            for (int j = 0; j < last.size() - 1; ++j) {
                cur.push_back(last[j] + last[j+1]);
            }
            cur.push_back(1);
            res.push_back(cur);
            last = cur;
        }
        return res;
    }
};