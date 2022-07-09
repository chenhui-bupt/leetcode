/*
找出消失的数字
方法一：
那就把没消失的数字放在自己的位置上，不对的就是消失的呗
方法二：
加n标记法
*/
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            while (nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1) {
                res.push_back(i + 1);
            }
        }
        return res;
    }


    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int x = (nums[i] - 1) % n; // 取下标
            nums[x] += n;
        }

        for (int i = 0; i < n; ++i) {
            if (nums[i] <= n) {
                res.push_back(i + 1);
            } eles {
                nums[i] = nums[i] % n;
            }
        }
        return res;
    }
};