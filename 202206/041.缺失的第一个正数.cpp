/*缺失的第一个正数
数据结构：数组
算法1：类哈希表标记法
算法2：置换法

因为答案的取值范围是[1, N+1]，证明：
若数组为[1,N]之间，答案是N+1，否则答案是[1, N]

思路1：通过哈希表标记存在的正数，然后从1到N+1遍历查找是否在哈希表中，但题目要求空间复杂度为常数只能借助数组本身，
对存在的正数其对应下标元素标记为负数，最后遍历数组找到一个不为负数元素的下标+1即可

思路2：可通过交换存在的正数到正确的下标，然后遍历数组，找到下标不符的第一个元素的下标+1即可
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
    	// 算法1：类哈希表（自身标记法）
    	int  n = nums.size();
    	for (int i = 0; i < n; ++i) {
    		if (nums[i] <= 0) {
    			nums[i] = n + 1;
    		}
    	}
    	for (int i = 0; i < n; ++i) {
            int idx = abs(nums[i]) - 1;
    		if (idx >= 0 && idx < n && nums[idx] > 0) {
    			nums[idx] = -nums[idx];
    		}
    	}

    	for (int i = 0; i < n; ++i) {
    		if (nums[i] > 0) {
    			return i + 1;
    		}
    	}
    	return n + 1;

    	// 算法2：置换法
    	for (int i = 0; i < n; ++i) {
            // 把nums[i]放在nums[i] - 1位置上
    		while (nums[i] > 0 && nums[i] - 1 < n && nums[nums[i] - 1] != nums[i]) {
    			swap(nums[i], nums[nums[i] - 1]);
    		}
    	}

    	for (int i = 0; i < n; ++i) {
    		if (nums[i] != i + 1) {
    			return i + 1;
    		}
    	}
    	return n + 1;
    }
};
