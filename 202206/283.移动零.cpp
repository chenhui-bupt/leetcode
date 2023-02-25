/*
双指针法，p0指向第一个0元素，p1指向连续0后的第一个非零元素
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int p0 = 0;
        int p1 = 0;
        while (p0 < nums.size()) {
            while (p0 < nums.size() && nums[p0] != 0) {
                p0++;
            }
            if (p0 == nums.size()) {
                break;
            }
            p1 = p0 + 1;
            while (p1 < nums.size() && nums[p1] == 0) {
                p1++;
            }

            if (p1 == nums.size()) {
                break;
            }

            swap(nums[p0], nums[p1]);
            p0++;
        }
    }

    void moveZeroes(vector<int>& nums) {
        // 将不等于0的数字移到左边，剩下的位置直接补0即可
        int j = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                if (i != j) {
                    num[j] = num[i];
                }
                j++;
            }
        }
        for (int i = j; i < nums.size(); ++i) {
            nums[i] = 0;
        }
    }
};