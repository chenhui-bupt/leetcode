class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (mid != left && numbers[left] + numbers[mid] == target) {
                return {left + 1, mid + 1};
            } else if (numbers[left] + numbers[mid] > target) {
                right = mid - 1;
            } else if (numbers[mid] + numbers[right] < target) {
                left = mid + 1;
            } else if (left != right && numbers[left] + numbers[right] == target) {
                return {left + 1, right + 1};
            } else if (numbers[left] + numbers[right] > target) {
                --right;
            } else {
                ++left;
            }
        }
        return {-1, -1};
    }
};