/*
单调递减栈，（但其维护的下标是有有效期的，因此本题改成单调队列）
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> q;
        for (int i = 0; i < k; ++i) {
            while (!q.empty() && nums[q.back()] <= nums[i]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        res.push_back(nums[q.front()]);

        for (int i = k; i < nums.size(); ++i) {
            while (!q.empty() && q.front() <= i - k) {
                q.pop_front();
            }

            while (!q.empty() && nums[q.back()] <= nums[i]) {
                q.pop_back();
            }
            q.push_back(i);

            res.push_back(nums[q.front()]);
        }
        return res;
    }
};