/*
字符串相乘，不准调用任何库，即，用字符串-'0'转换成整形
*/
class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.size();
        int n2 = num2.size();
        vector<int> num(n1 + n2, 0);
        for (int i = n1 - 1; i >= 0; --i) {
            for (int j = n2 - 1; j >= 0; --j) {
                num[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
                num[i + j] += num[i + j + 1] / 10;
                num[i + j + 1] %= 10;
            }
        }
        int i = 0;
        while (i < n1 + n2 && num[i] == 0) {
            i++;
        }
        std::string res = "";
        while (i < n1 + n2) {
            res.push_back(num[i] + '0');
            i++;
        }
        return res.size() > 0 ? res : "0";
    }
};