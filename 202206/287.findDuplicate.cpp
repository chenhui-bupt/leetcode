/*
题解：只能使用O(1)存储空间，时间复杂度为O(n)，不能修改数组
只能通过修改数组，然后在改回去，所以需要设计一个特殊的编解码函数，同时能起到标记的作用

方法二：转换成历史问题，有环链表法
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int num = nums[i] % n;
            nums[num] += n; // 标志位
        }

        for (int i = 0; i < n; ++i) {
            if (nums[i] / n >= 2) { // 重复次数超过2次
                return i;
            }
        }
        return 0;
    }

    int findDuplicate(vector<int>& nums) {
        // 快慢指针
        int p1 = nums[0];
        int p2 = nums[0];
        while (1) {
            p1 = nums[nums[p1]];
            p2 = nums[p2];
            if (p1 == p2) {
                break;
            }
        }
        // 寻找环的入口
        p2 = nums[0];
        while (p1 != p2) {
            p1 = nums[p1];
            p2 = nums[p2];
        }
        return p2;
    }
};