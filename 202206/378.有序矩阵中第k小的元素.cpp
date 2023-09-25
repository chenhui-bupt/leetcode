/**
 * 二分查找，已知最小值matrix[0][0], 最大值matrix[n-1][n-1]，通过二分查找中间值mid，
 * 通过判断mid是否为第k小的数，若是，则返回，否则更新搜寻空间
 */
class Solution {
public:
    int check(vector<vector<int>>& matrix, int mid, int k) {
        int n = matrix.size();
        int num = 0;
        for (int j = 0; j < n; ++j) {
            for (int i = n-1; i >= 0; --i) {
                if (matrix[i][j] <= mid) {
                    num += (i + 1);
                    break;
                }
            }
        }
        if (num == k) {
            return 0;
        } else if (num > k) {
            return 1;
        } else {
            return -1;
        }
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0];
        int right = matrix[n-1][n-1];
        while (left < right) {
            int mid = left + (right - left) / 2;
            int flag = check(matrix, mid, k);
            if (flag >= 0) {
                right = mid; // 为什么没有用mid - 1，避免mid刚好是答案，而错过（且left < right所以mid严格小于right，不会死循环）
            } else {
                left = mid + 1; // 为设么不把上述条件放在left这里，避免死循环
            }
        }
        return left;
    }
};