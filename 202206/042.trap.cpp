/*
本质是求洼地（先下行、后上行）的积水面积
方法一：单调栈
可利用栈维护洼地左边界，即下行时入栈，上行时出栈并计算局部面积（水平方向）
方法二：动态规划
因为洼地的左右两边都高，所以可以先统计每个i处左右方向的最高点，左右边界的较小值即是位置i所能盛水面积（垂直方向）
*/
class Solution {
public:
    int trap(vector<int>& height) {
    	int area = 0;
    	stack<int> st;
    	st.push(0);
    	int i = 1;
    	while (i < height.size()) {
    		// 上行时弹出
            while (!st.empty() && height[st.top()] < height[i]) {
                int bottom = st.top();
                st.pop();
                if (st.empty()) {
                    break;
                }
                area += (min(height[i], height[st.top()]) - height[bottom]) * (i - st.top() - 1);
            }
            st.push(i++);
    	}
    	return area;
    }

    int trap(vector<int>& height) {
        int area = 0;
        int n = height.size();
        vector<int> dp1(n);
        vector<int> dp2(n);
        dp1[0] = height[0];
        dp2[n - 1] = height[n - 1];
        for (int i = 1; i < n; ++i) {
            dp1[i] = max(height[i], dp1[i-1]);
        }

        for (int i = n - 2; i >= 0; --i) {
            dp2[i] = max(height[i], dp2[i + 1]);
        }

        for (int i = 1; i < n - 1; ++i) {
            area += min(dp1[i], dp2[i]) - height[i];
        }
        return area;
    }
};