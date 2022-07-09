/* 空间换时间
方法一：两次遍历，第一次把数字记录的集合中
第二次，找到起始数字，遍历查找，计算长度

方法二：哈希表记录每个数字的连续长度，如何更新每个数字的长度呢？
查找当前数字左边小于1个和右边大于1个的数字的长度，加和即是当前数字的长度（连接起来了）
同时更新左右边界数字的长度！
遍历过程中，不断更新最长长度即可！
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> mp;
        for (int num : nums) {
            if (mp.find(num) == mp.end()) {
                int left = mp.find(num - 1) != mp.end() ? mp[num - 1] : 0;
                int right = mp.find(num + 1) != mp.end() ? mp[num + 1] : 0;
                int len = left + right + 1;
                res = max(res, len);
                mp[num] = len;
                mp[num - left] = len; // 左边更新长度，便于之后与num - left - 1相连
                mp[num + right] = len; // 右边界更新长度，便于之后与num + right + 1相连
            }
        }
        return res;

        // 两次遍历
        unordered_set<int> st;
        for (int num : nums) {
            st.insert(num);
        }

        for (int num : nums) {
            if (st.find(num - 1) == st.end()) { // 确保num位起始值
                int next = num + 1;
                while (st.find(next) != st.end()) { // 遍历查找呀
                    next++;
                }
                res = max(res, next - num);
            }
        }
        return res;
    }
};