/*
用递归思路，遇到'*'或'/'则先计算后递归，遇到'+'或'-'则先递归后计算。
*/
class Solution {
public:
    int calculate(string s) {
        vector<int> vec;
        int res = 0;
        int num = 0;
        char sign = '+';
        for (int i = 0; i < s.size(); ++i) {
            // 情形1：是数字
            if (isdigit(s[i])) {
                num = num * 10 + int(s[i] - '0');
            }
            cout << "tmp" << num << endl;
            // 情形2：是符号或结束
            if ((!isdigit(s[i]) && s[i] != ' ') || i == s.size() - 1) {
                cout << sign << num << endl;
                switch (sign) {
                    case '+':
                        vec.push_back(num);
                        break;
                    case '-':
                        vec.push_back(-num);
                        break;
                    case '*':
                        vec.back() *= num;
                        break;
                    case '/':
                        vec.back() /= num;
                        break;
                    default:
                        break;
                }
                sign = s[i]; // 重新记录符号
                num = 0; // 重新计数
                cout << sign << endl;
            }
        }

        return accumulate(vec.begin(), vec.end(), 0);
    }
};