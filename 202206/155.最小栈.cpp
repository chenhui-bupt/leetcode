/*
两个栈，一个栈用来维护数据的先后关系，一个栈用来维护最小数
空间换时间
*/
class MinStack {
public:
    MinStack() {
        st1 = new stack<int>();
        st2 = new stack<int>();
    }
    
    void push(int val) {
        st1.push(val);
        if (!st2.empty() && st2.top() < val) {
            st2.push(st2.top());
        } else {
            st2.push(val);
        }
    }
    
    void pop() {
        st1.pop();
        st2.pop();
    }
    
    int top() {
        return st1.top();
    }
    
    int getMin() {
        return st2.top();
    }

private:
    stack<int> st1;
    stack<int> st2;
};