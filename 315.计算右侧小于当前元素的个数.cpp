/**
 * 数据结构一：数组
 * 算法一：归并排序，O(nlogn)
 * 思路一：
 * 第一步：我们可以利用归并排序逆序对的方法，统计右边小于该数的个数
 * 所以需要从小到大归并，这样才能找到有多少是逆序的，可以仔细想想。
 * 第二步：归并完成后将排序结果更新到原数组中，同时更新下标索引（便于下次计算逆序数）
 */
class Solution {
public:
    vector<int> tmp_nums;
    vector<int> tmp_idx;
    vector<int> idx;
    vector<int> res;

public:
    vector<int> countSmaller(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            idx.push_back(i);
        }
        res.resize(nums.size());
        tmp_nums.resize(nums.size());
        tmp_idx.resize(nums.size());
        mergeSort(nums, 0, nums.size() - 1);
        return res;
    }

    void mergeSort(vector<int>& nums, int left, int right) {
        if (right >= left) {
            return;
        }
        int mid = (left + right) >> 1;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }

    void merge(vector<int>& nums, int left, int mid, int right) {
        int i = left;
        int j = mid + 1;
        int p = left;
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                tmp_nums[p] = nums[i];
                tmp_idx[p] = idx[i];
                res[idx[i]] += j - (mid + 1); // 累加计算逆序数
                ++i;
                ++p;
            } else { // nums[i] > nums[j]仍处于逆序中，暂时无法计算逆序数
                tmp_nums[p] = nums[j];
                tmp_idx[p] = idx[j];
                ++j;
                ++p;
            }
        }
        while (i <= mid) {
            tmp_nums[p] = nums[i];
            tmp_idx[p] = idx[i];
            res[idx[i]] += j - (mid + 1); // 累加计算逆序数
            ++i;
            ++p;
        }
        while (j <= right) {
            tmp_nums[p] = nums[j];
            tmp_idx[p] = idx[j];
            ++j;
            ++p;
        }
        for (int i = left; i <= right; ++i) {
            nums[i] = tmp_nums[i]; // 归并排序好的子结果更新到原数组中
            idx[i] = tmp_idx[i]; // 同时更新下标索引
        }
    }
};


/**
 * 数据结构二：栈
 * 算法二：单调栈，O(n^2)
 * 思路二：利用单调递增栈，当栈元素弹出时，即可统计逆序数
*/
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        vector<int> st;
        for (int i = 0; i < n; i++) {
            if (st.empty()) {
                st.push_back(i);
            } else {
                int j = st.size() - 1;
                while (j >= 0 && nums[st[j]] > nums[i]) {
                    res[st[j]]++;
                    j--;
                }
                st.insert(st.begin()+j+1, i);
            }
        }
        return res;
    }
};

