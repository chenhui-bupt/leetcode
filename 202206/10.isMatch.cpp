class Solution {
public:
    bool isMatch(string s, string p) {
    	return regex(s, 0, p, 0);
    }

    bool regex(string& s, int i, string& p, int j) {
    	if (i == s.size() && j == p.size()) {
    		return true;
    	} else if (j == p.size()) {
    		return false;
    	}

    	if (j < p.size() - 1 && p[j + 1] == '*') {
    		return regex(s, i, p, j + 2) || (i < s.size() && (s[i] == p[j] || p[j] == '.') && regex(s, i + 1, p, j));
    	}

    	if ((i < s.size() && s[i] == p[j]) || p[j] == '.') {
    		return regex(s, i + 1, p, j + 1);
    	} else {
    		return false;
    	}
    }
};