/*
按照0、1、2排序
双指针法，p0指向0所应该在的位置，p2指向2所在的位置
为什么先排2呢，因为先排2，可以保证交换过来的0能被继续交换，不会错过，且0交换时不会交换出2，因为前面已经遍历过了
如果先排0，交换过来的2能被继续交换，但再次交换过来的0无法再次交换了，错过
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p0 = 0;
        int p2 = nums.size() - 1;
        for (int i = 0; i < nums.size(); ++i) {
            while (i < p2 && nums[i] == 2) {
                swap(nums[i], nums[p2]);
                p2--;
            }
            if (nums[i] == 0) {
                swap(nums[i], nums[p0]);
                p0++;
            }
        }
    }
};