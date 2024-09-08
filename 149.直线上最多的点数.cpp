class Solution {
public:
    int gcd(int x, int y) {
        return y > 0 ? gcd(y, x % y) : x;
    }

    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n < 2) {
            return n;
        }

        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (res > n - i || res > n / 2) { // 已经找到最大的结果
                break;
            }

            unordered_map<int, int> mp;
            for (int j = i + 1; j < n; ++j) {
                int x = points[i][0] - points[j][0];
                int y = points[i][1] - points[j][1];
                if (x == 0) {
                    y = 1;
                } else if (y == 0) {
                    x = 1;
                } else {
                    if (y < 0) {
                        x = -x;
                        y = -y;
                    }
                    int z = gcd(abs(x), abs(y));
                    x = x / z;
                    y = y / z;
                }
                mp[x + 20001 * y]++;
            }
            int m = 0;
            for (auto [k, v] : mp) {
                m = max(m, v + 1);
            }
            res = max(res, m);
        }
        return res;
    }
};