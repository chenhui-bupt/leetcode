/**
 * 算法一：哈希表计数
 * 算法二：排序 + 双指针
 */

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, vector<int>> mp;
        for (int num : nums1) {
            if (mp.find(num) == mp.end()) {
                mp[num] = {0, 0};
            }
            mp[num][0]++;
        }
        for (int num : nums2) {
            if (mp.find(num) == mp.end()) {
                mp[num] = {0, 0};
            }
            mp[num][1]++;
        }
        vector<int> res;
        for (auto [k, v] : mp) {
            for (int i = 0; i < min(v[0], v[1]); ++i) {
                res.push_back(k);
            }
        }
        return res;
    }
};