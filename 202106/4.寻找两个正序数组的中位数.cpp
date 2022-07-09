// 寻找两个数组第k小的数
// (m+n) % 2 == 1, 取（m+n+1)/2 个
// (m+n) % 2 == 0, 取(m+n) / 2和(m+n) / 2 + 1的平均数

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    	int n1 = nums1.size();
    	int n2 = nums2.size();
    	if ((n1 + n2) % 2 == 1) { 
    		return getKth(nums1, nums2, (n1 + n2 + 1) / 2);
    	} else {
    		return (getKth(nums1, nums2, (n1 + n2) / 2) + getKth(nums1, nums2, (n1 + n2) / 2 + 1)) / 2.0;
    	}
    }

    int getKth(vector<int>& nums1, vector<int>& nums2, int k) {
    	int n1 = nums1.size();
    	int n2 = nums2.size();
    	int index1 = 0;
    	int index2 = 0;

    	while (true) {
    		if (index1 == n1) {
    			return nums2[index2 + k - 1];
    		}
    		
    		if (index2 == n2) {
    			return nums1[index1 + k - 1];
    		}
    		
    		if (k == 1) {
    			return min(nums1[index1], nums2[index2]);
    		}

    		int newIndex1 = min(index1 + k/2 - 1, n1-1);
    		int newIndex2 = min(index2 + k/2 - 1, n2-1);
    		if (nums1[newIndex1] <= nums2[newIndex2]) {
    			k -= (newIndex1 - index1 + 1);
    			index1 = newIndex1 + 1;
    		} else {
    			k -= (newIndex2 - index2 + 1);
    			index2 = newIndex2 + 1;
    		}
    	}
    }
};