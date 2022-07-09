/*
字符串解码
输入：s = "3[a2[c]]"
输出："accaccacc"
方法一：递归dfs
方法二：栈
*/
class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        for (char c : s) {
            if (c == ']') {
                string str = "";
                while (!st.empty() && st.top() != "[") {
                    str = st.top() + str;
                    st.pop();
                }
                st.pop(); // '['
                string integer = "";
                while (!st.empty() && st.top() >= "0" && st.top() <= "9") {
                    integer = st.top() + integer;
                    st.pop();
                }

                string new_str = "";
                for (int i = 0; i < stoi(integer); ++i) {
                    new_str += str;
                }
                st.push(new_str);
            } else {
                st.push(string(1, c));
            }
        }

        string res = "";
        while (!st.empty()) {
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};


class Solution {
public:
    string decodeString(string s) {
        int index = 0;
        return dfs(s, index);
    }

    string dfs(string s, int index) {
        if (index == s.size() || s[index] == ']') {
            return "";
        }

        string res = "";
        if (isdigit(s[index])) {
            string integer = "";
            while (isdigit(s[index])) {
                integer += s[index++];
            }
            index++; // 跳过'['
            string str = dfs(s, index);
            index++; // 跳过']'
            for (int i = 0; i < stoi(integer); ++i) {
                res += str;
            }
        } else if (isalpha(s[index])) {
            while (isalpha(s[index])) {
                res += s[index++];
            }
        }
        res += dfs(s, index);
        return res;
    }
};

