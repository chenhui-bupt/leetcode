/**
 * 算法一：排序，O(nlogn)
 * 思路一：第一步，预排序
 * 第二步：计算H指数（即引用文章次数大于H次）
 * 
 * 算法二：计数排序，O(n)
 * 思路二：第一步，先计数。我们发现H指数不可能大于总论文数n，所以遇到引用次数大于n的，都记在n上即可。
 * 第二步：后“按照计数排序”
 */
class Solution {
public:
    // 算法一：排序
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int res = 0;
        int i = citations.size() - 1; // 从大到小
        while (i >= 0 && citations[i] > res) {
            res++;
            i--;
        }
        return res;
    }

    // 算法二：计数排序
    int hIndex(vector<int>& citations) {
        int tt = 0;
        int n = citations.size();
        vector<int> counter(n + 1);
        for (int i = 0; i < n; ++i) {
            if (citations[i] >= n) {
                counter[n]++;
            } else {
                counter[citations[i]]++;
            }
        }

        for (int i = n; i >= 0; --i) {
            tt += counter[i];
            if (tt >= i) {
                return i;
            }
        }
        return 0;
    }
};