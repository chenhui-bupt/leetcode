// 快排
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }

        vector<pair<int, int>> vec;
        for (auto& kv : mp) {
            vec.push_back(kv);
        }

        quick_sort(vec, 0, vec.size() - 1, k, res);
        return res;
    }

    void quick_sort(vector<pair<int, int>>& vec, int left, int right, int k, vector<int>& res) {
        int mid = partition(vec, left, right);
        if (mid == vec.size() - k) {
            for (int i = mid; i < vec.size(); ++i) {
                res.push_back(vec[i].first);
            }
        } else if (mid < vec.size() - k) {
            quick_sort(vec, mid + 1, right, k, res);
        } else {
            quick_sort(vec, left, mid - 1, k, res);
        }
        return;
    }

    int partition(vector<pair<int, int>>& vec, int left, int right) {
        int ran = rand() % (right - left + 1) + left;
        swap(vec[left], vec[ran]);
        auto pivot = vec[left];
        int index = left;
        for (int i = left + 1; i <= right; ++i) {
            if (vec[i].second <= pivot.second) {
                swap(vec[i], vec[index++]);
            }
        }
        vec[index] = pivot;
        return index;
    }

    int partition2(vector<pair<int, int>>& nums, int left, int right) {
        auto target = nums[left];
        while (left < right) {
            while (left < right && nums[right].second >= target.second) {
                --right;
            }
            nums[left] = nums[right];
            while (left < right && nums[left].second <= target.second) {
                ++left;
            }
            nums[right] = nums[left];
        }
        nums[left] = target;
        return left;
    }
};


// 优先队列
class Solution {
public:

    static bool cmp(pair<int, int> left, pair<int, int> right) {
        return left.second > right.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> q(cmp);
        for (auto [num, cnt] : mp) {
            if (q.size() == k) {
                if (cnt > q.top().second) {
                    q.pop();
                    q.emplace(num, cnt);
                }
            } else {
                q.push(make_pair(num, cnt));
            }
        }

        vector<int> res;
        while (!q.empty()) {
            res.push_back(q.top().first);
            q.pop();
        }
        return res;
    }
};