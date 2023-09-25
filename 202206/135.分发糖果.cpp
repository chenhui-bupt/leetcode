class Solution {
public:
    int candy(vector<int>& ratings) {
        int res = 0;
        int n = ratings.size();
        vector<int> left(n, 1);
        vector<int> right(n, 1);
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i-1]) {
                left[i] = left[i-1] + 1;
            }
        }
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i+1]) {
                right[i] = right[i+1] + 1;
            }
            res += max(left[i], right[i]);
        }
        res += max(left[n-1], right[n-1]);
        return res;
    }
};