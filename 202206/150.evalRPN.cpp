class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> st;
        for (string token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                long b = st.top();
                st.pop();
                long a = st.top();
                st.pop();
                long c = 0;
                if (token == "+") {
                    c = a + b;
                } else if (token == "-") {
                    c = a - b;
                } else if (token == "*") {
                    c = a * b;
                } else if (token == "/") {
                    c = a / b;
                }
                st.push(c);
            } else {
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};