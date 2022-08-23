/*
不断计算当前能跳越的最远距离，如果不能到达当前节点，则跳跃失败（好像是任务拆解，既然能跳到最后一个节点，也就能跳到任意一个位置）
如何更新最远距离呢？正常更新就行
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int jumpMax = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (jumpMax < i) {
                return false;
            }
            jumpMax = max(jumpMax, i + nums[i]);
        }
        return true;
    }
};