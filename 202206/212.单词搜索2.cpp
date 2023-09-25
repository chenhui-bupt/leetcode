/*
单词查找：前缀树+dfs
算法一：正常建树 + 查找
算法二：正常建树 + 剪枝查找
思路二：考虑到树只需要查找一次，因此考虑对树进行删除，避免重复查找（见dfs2)。
*/

struct Trie {
    Trie () {
        this->word = "";
    }
    string word;
    unordered_map<char, Trie*> children;
};


class Solution {
public:
    Trie* root = new Trie();
    unordered_set<string> st;
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
    void insertTrie(Trie* root, string& word) {
        for (char c : word) {
            if (root->children.find(c) == root->children.end()) {
                root->children[c] = new Trie();
            }
            root = root->children[c];
        }
        root->word = word; // 结束
    }

    void dfs(vector<vector<char>>& board, int x, int y, Trie* root, unordered_set<string>& st) {
        char c = board[x][y];
        if (root->children.find(c) == root->children.end()) {
            return;
        }

        root = root->children[c];
        if (root->word.size() > 0) {
            st.insert(root->word);
        }

        board[x][y] = '#'; // 暂时置“空”避免
        for (int i = 0; i < 4; ++i) {
            int ix = x + dirs[i][0];
            int iy = y + dirs[i][1];
            if (ix >= 0 && ix < board.size() && iy >= 0 && iy < board[0].size() && board[ix][iy] != '#') {
                dfs(board, ix, iy, root, st);
            }
        }
        board[x][y] = c;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        // 第一步：构建前缀树
        for (string& word : words) {
            insertTrie(root, word);
        }

        // 第二步：搜索矩阵
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                dfs(board, i, j, root, st);
            }
        }

        for (auto iter = st.begin(); iter != st.end(); ++iter) {
            res.push_back(*iter);
        }
        return res;
    }


    void dfs2(vector<vector<char>>& board, int x, int y, Trie* root, vector<string>& res) {
        char c = board[x][y];
        if (root->children.find(c) == root->children.end()) {
            return;
        }

        Trie* child = root->children[c];
        if (child->word.size() > 0) {
            res.push_back(child->word);
            child->word = ""; // 已经查询到的单词进行删除！
        }

        if (!child->children.empty()) {
            board[x][y] = '#';
            for (int i = 0; i < 4; ++i) {
                int ix = x + dirs[i][0];
                int iy = y + dirs[i][1];
                if (ix >= 0 && ix < board.size() && iy >= 0 && iy < board[0].size() && board[ix][iy] != '#') {
                    dfs2(board, ix, iy, child, res);
                }
            }
            board[x][y] = c;
        } else {
            root->children.erase(c); // 回退删除
        }
        
    }
};