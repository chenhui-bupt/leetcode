/*
个数大于n/2的数，用计数消解法
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int tnum = 0;
        for (int num : nums) {
            if (num == tnum) {
                cnt++;
            } else {
                if (cnt == 0) {
                    tnum = num;
                    cnt = 1;
                } else {
                    cnt--;
                }
            }
        }
        return num;
    }
};