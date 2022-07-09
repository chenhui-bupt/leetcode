class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 转化成找第k大的数
    	int n1 = nums1.size();
    	int n2 = nums2.size();
    	if ((n1 + n2) % 2 == 1) {
    		return findKth(nums1, 0, nums2, 0, (n1 + n2 + 1) / 2);
    	} else {
    		return (findKth(nums1, 0, nums2, 0, (n1 + n2) / 2) + findKth(nums1, 0, nums2, 0, (n1 + n2) / 2 + 1)) / 2.0;
    	}
    }

    int findKth(vector<int>& nums1, int i, vector<int>& nums2, int j, int k) {
    	// 累次剔除劣策略
        if (i == nums1.size()) { // 边界条件1：数组1已经剔除完
            return nums2[j + k - 1];
        } else if (j == nums2.size()) { // 边界条件2：数组2已经剔除完
            return nums1[i + k - 1];
        }
    	if (k == 1) { // 边界条件3：找到结果
    		return min(nums1[i], nums2[j]);
    	}
        
    	int m = min(int(i + k/2 - 1), int(nums1.size() - 1));
    	int n = min(int(j + k/2 - 1), int(nums2.size() - 1));
    	if (nums1[m] < nums2[n]) { // 左边小于右边，可剔除左边 k/2的无效变量
    		k = k - (m - i + 1);
    		i = m + 1;
    		return findKth(nums1, i, nums2, j, k);
    	} else {
    		k = k - (n - j + 1);
    		j = n + 1;
    		return findKth(nums1, i, nums2, j, k);
    	}
    }
};