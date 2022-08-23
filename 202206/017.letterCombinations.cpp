class Solution {
public:
	unordered_map<char, string> code = {
    		{'2', "abc"},
    		{'3', "def"},
    		{'4', "ghi"},
    		{'5', "jkl"},
    		{'6', "mno"},
    		{'7', "pqrs"},
    		{'8', "tuv"},
    		{'9', "wxyz"}
    };

    vector<string> letterCombinations(string digits) {
    	vector<string> res;
    	string comb = "";
    	dfs(digits, 0, comb, res);
    	return res;
    }

    void dfs(string& digits, int i, string& comb, vector<string>& res) {
    	if (i == digits.size()) {
    		res.push_back(comb);
    	}
    	for (char c: code[digits[i]]) {
    		dfs(digits, i + 1, comb + c, res);
    	}
    }

    void bfs(string& digits, std::vector<string>& res) {
    	// 宽度优先遍历的核心思想是用队列归纳栈的调用！！！
    	queue<string> q;
    	q.push("");
    	for (char digit: digits) {
    		int size = q.size();
    		for (int i = 0; i < size; ++i) {
    			string comb = q.front();
    			q.pop();
    			for (char c : code[d]) {
    				q.push(comb + c);
    			}
    		}
    	}

    	while (!q.empty()) {
    		res.push_bak(q.front());
    		q.pop();
    	}
    }
};