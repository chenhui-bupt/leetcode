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
};