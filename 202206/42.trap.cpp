/*
本质是求洼地（先下行、后上行）的积水面积
可利用栈维护洼地左边界，即下行时入栈，上行时出栈并计算局部面积
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
};