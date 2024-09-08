class Solution {
public:
    string longestPalindrome(string s) {
    	string res = "";
    	for (int i = 0; i < s.size(); ++i ) {
    		string s1 = palindrome(s, i, i);
    		string s2 = palindrome(s, i, i + 1);
    		if (res.size() < s1.size()) {
    			res = s1;
    		}
    		if (res.size() < s2.size()) {
    			res = s2;
    		}
    	}
    	return res;
    }

    string palindrome(string& s, int i, int j) {
    	if (i < 0 || j > s.size() || s[i] != s[j]) {
    		return s.substr(i + 1, j - i - 1);
    	}
    	return palindrome(s, i - 1, j + 1);
    }

    string palindrome(string& s, int i, int j) {
    	while (i >= 0 && j <= s.size() - 1 && s[i] == s[j]) {
    		i--;
    		j++;
    	}
    	return s.substr(i + 1, j - i - 1);
    }
};