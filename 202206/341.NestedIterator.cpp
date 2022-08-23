/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

/**
 * 因为它是嵌套数组，很容易想到递归调用（或栈）来实现遍历
 */

class NestedIterator {
private:
    stack<NestedInteger> st;
    NestedInteger cur;

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i = nestedList.size() - 1; i >= 0; --i) {
            st.push(nestedList[i]);
        }
    }
    
    int next() {
        cur = st.top(); // cur指针可以变成私有变量
        st.pop();
        return cur.getInteger();
    }
    
    bool hasNext() {
        while (!st.empty()) {
            cur = st.top();
            if (cur.isInteger()) {
                return true;
            }
            st.pop();
            for (int i = cur.getList().size() - 1; i >= 0; --i) {
                st.push(cur.getList()[i]);
            }
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */