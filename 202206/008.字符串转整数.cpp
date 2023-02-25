/* 字符串转换数字
算法：有限状态机
空格、符号、数字、其他字符
*/
class Solution {
public:
    int myAtoi(string s) {
        unordered_map<string, vector<string>> table = {
            // 空格、符号、数字、其他
            {"start", {"start", "sign", "number", "end"}},
            {"sign", {"end", "end", "number", "end"}},
            {"number", {"end", "end", "number", "end"}},
            {"end", {"end", "end", "end", "end"}}
        };

        int sign = 1;
        long long res = 0;
        string state = "start";
        for (char c : s) {
            state = table[state][get_state_idx(c)];
            if (state == "number") {
                res = res * 10 + (c - '0');
                res = sign == 1 ? min(res, (long long) INT_MAX) : min(res, -(long long) INT_MIN);
            } else if (state == "sign") {
                if (c == '-') {
                    sign = -1;
                }
            }
        }
        return int(sign * res);
    }

    int get_state_idx(char c) {
        if (c == ' ') {
            return 0;
        } else if (c == '+' || c == '-') {
            return 1;
        } else if (c >= '0' && c <= '9') {
            return 2;
        } else {
            return 3;
        }
    }
};