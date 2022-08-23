/*
快排算法
*/
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        string res = "";
        for (int num : nums) {
            res += to_string(num);
        }
        return res;
    }

    void quickSort(vector<int>& nums, int left, int right) {
        if (left >= right) {
            return;
        }
        int mid = partition(nums, left, right);
        quickSort(nums, left, mid - 1);
        quickSort(nums, mid + 1, right);
    }

    int partition(vector<int>& nums, int left, int right) {
        int target = nums[left];
        while (left < right) {
            while (left < right && comp(target, nums[right]) >= 0) {
                right--;
            }
            nums[left] = nums[right];
            while (left < right && comp(nums[left], target) >= 0) {
                left++;
            }
            nums[right] = nums[left];
        }
        nums[left] = target;
        return left;
    }

    int comp(int num1, int num2) {
        if (num1 == num2) {
            return 0;
        }

        string s1 = to_string(num1) + to_string(num2);
        string s2 = to_string(num2) + to_string(num1);
        return s1 < s2 ? -1 : 1;
    }
};