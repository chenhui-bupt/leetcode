/*矩形面积由矩形左右边界和高度决定，
左右边界有两种方式：（1）中心开花；（2）两边包围
高度由最小矩形决定
用中心开花哨兵法！！！寻找i的左右边界！
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int area = 0;
        int n = heights.size();
        vector<int> left(n);
        vector<int> right(n, n);
        stack<int> st;
        for (int i = 0; i < heights.size(); ++i) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        st = stack<int>();
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        for (int i = 0; i < n; ++i) {
            area = max(area, (right[i] - left[i] - 1) * heights[i]);
        }
        return area;
    }

    int largestRectangleArea(vector<int>& heights) {
        /*
        使用一遍遍历：我们在维持单调递增栈，循环弹出，寻找i的左右边界时，被弹出元素的右边界也就确定了（想想为什么是右边界）
        那左边界怎么确认呢？此时栈顶的元素就是i的左边界
        */
        int area = 0;
        int n = heights.size();
        vector<int> left(n);
        vector<int> right(n, n);
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                right[st.top()] = i;
                st.pop();
            }
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        for (int i = 0; i < n; ++i) {
            area = max(area, (right[i] - left[i] - 1) * heights[i]);
        }
        return area;
    }
};