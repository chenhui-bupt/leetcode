/*
题目：多数元素二，找出出现次数大于n/3的元素
每次消除三个不相同的数字，不影响结果，转化成子问题求解（分治算法、动态规划、贪心算法）
*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int a = 0;
        int b = 0;
        int cnt1 = 0;
        int cnt2 = 0;
        for (int num : nums) {
            if (cnt1 > 0 && a == num) {
                cnt1++;
            } else if (cnt2 > 0 && b == num) {
                cnt2++;
            } else if (cnt1 == 0) {
                a = num;
                cnt1 = 1;
            } else if (cnt2 == 0) {
                b = num;
                cnt2 = 1;
            } else {
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0;
        cnt2 = 0;
        for (int num : nums) {
            if (num == a) {
                cnt1++;
            } else if (num == b) {
                cnt2++;
            }
        }
        vector<int> res;
        if (cnt1 > nums.size() / 3) {
            res.push_back(a);
        }
        if (cnt2 > nums.size() / 3) {
            res.push_back(b);
        }
        return res;
    }
};