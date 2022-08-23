/*
图算法（环装替换）
环装替换，不占用额外空间，当替换到起始位置时，替换完成。
但此时仍有位置没有替换到，由a * n = b * k，知需要替换b = gcd(n, k)次。
*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        int count = gcd(n, k);
        for (int start = 0; start < count; ++start) {
            int i = start;
            int tmp = nums[i];
            do {
                int j = (i + k) % n;
                swap(tmp, nums[j]);
                i = j;
            } while  (i != start);
        }        
    }
};