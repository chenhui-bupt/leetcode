class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
    	int m = board.size();
    	int n = board[0].size();
    	vector<vector<int>> visited(m, vector<int>(n));
    	for (int i = 0; i < m; ++i) {
    		for (int j = 0; j < n; ++j) {
    			if (!visited[i][j] && board[i][j] == word[0]) {
    				if (dfs(board, word, visited, i, j,0)) {
    					return true;

					}
    			}
    		}
    	}
    	return false;
    }

    bool dfs(vector<vector<char>>& board, string word, int i, int j, int k, vector<vector<int>>& visited) {
    	if (k == word.size()) {
    		return true;
    	}

    	if (i < 0 || i == board.size() || j < 0 || j == board[0].size()) {
    		return false;
    	}
    	if (visited[i][j] || board[i][j] != word[k]) {
    		return false;
    	}

    	visited[i][j] = 1;
		if (dfs(board, word, i-1, j, k+1, visited)) {
			return true;
		}
		if (dfs(board, word, i+1, j, k+1, visited)) {
			return true;
		}
		if (dfs(board, word, i, j-1, k+1, visited)) {
			return true;
		}
		if (dfs(board, word, i, j+1, k+1, visited)) {
			return true;
		}
    	visited[i][j] = 0;
    	return false;
    }
};