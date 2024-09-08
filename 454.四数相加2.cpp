/**
 * 算法一：暴力解法，时间复杂度O(n^4)
 * 算法二：两两组合，时间复杂度O(n^2)
 * 思路二：先对数组1和2遍历，并用哈希表存储”加和“的个数，再遍历数组3和4，根据哈希表存储的数据计算满足
 * 题目要求的结果。
*/
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums1.size(); ++i) {
            for (int j = 0; j < nums2.size(); ++j) {
                mp[nums1[i] + nums2[j]]++;
            }
        }
        int res = 0;
        for (int i = 0; i < nums3.size(); ++i) {
            for(int j = 0; j < nums4.size(); ++j) {
                int num = -(nums3[i] + nums4[j]);
                if (mp.find(num) != mp.end()) {
                    res += mp[num];
                }
            }
        }
        return res;
    }

    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int res = 0;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        sort(nums3.begin(), nums3.end());
        sort(nums4.begin(), nums4.end());
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n3 = nums3.size();
        int n4 = nums4.size();
        vector<vector<int>> arr1(n1, vector<int>(n2));
        vector<vector<int>> arr2(n3, vector<int>(n4));
        for (int i = 0; i < nums1.size(); ++i) {
            for (int j = 0; j < nums2.size(); ++j) {
                arr1[i][j] = nums1[i] + nums2[j];
            }
        }

        for (int k = 0; k < nums3.size(); ++k) {
            for (int l = 0; l < nums4.size(); ++l) {
                arr2[k][l] = nums3[k] + nums4[l];
            }
        }
        for (int i = 0; i < nums1.size(); ++i) {
            for (int j = 0; j < nums2.size(); ++j) {
                for (int k = 0; k < nums3.size(); ++k) {
                    for (int l = 0; l < nums4.size(); ++l) {
                        int num = arr1[i][j] + arr2[k][l];
                        if (num == 0) {
                            res++;
                        } else if (num > 0) {
                            break;
                        }
                    }
                }
            }
        }
        return res;

        dfs(nums1, nums2, nums3, nums4, 0, 0, 0, 0, res);
        return res;
    }
};