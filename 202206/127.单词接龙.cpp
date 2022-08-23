/*
你脑筋这么直吗，这题不明显的图模型吗，还在这里用所谓用似是而非的暴力解法，受不了了！
遇到问题，先想什么数据结构最合适啊！！！长点心好吗
*/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        vector<int> dp(n);
        for (int i = 0; i < n; ++i) {
            if (check(beginWord, wordList[i])) {
                dp[i] = 1;
            }
        }

        for (int i = 0; i < n; ++i) {
            int cnt = INT_MAX;
            for (int j = 0; j < n; ++j) {
                if (i == j || beginWord == wordList[i]) {
                    continue;
                }
                if (dp[i] == 0 && dp[j] > 0 && check(wordList[i], wordList[j])) {
                    cnt = min(dp[j] + 1, cnt);
                    cout << wordList[i] << ", " << wordList[j] << ", " << dp[j] << endl;
                }
            }
            if (cnt < n) {
                dp[i] = cnt;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (endWord == wordList[i]) {
                return dp[i] > 0 ? dp[i] + 1 : 0;
            }
        }
        return 0;
    }

    bool check(string& s1, string& s2) {
        if (s1.size() != s2.size()) {
            return false;
        }

        int cnt = 0;
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) {
                cnt++;
            }
        }
        return cnt == 1;
    }
};


/*
算法1：广度优先搜索 + 优化建图
最短路径问题，首先考虑的是广度优先遍历;
考虑到直接建图的时间复杂度是O(N^2)，且单词之间的图关系是靠单一字母的变换得来，因此引入“词根”，来串联起节点之间的关系。
*/
class Solution {
public:
    unordered_map<string, int> node_id;
    int node_num;
    vector<vector<int>> edges;

public:
    void addNode(string& word) {
        if (node_id.find(word) == node_id.end()) {
            node_id[word] = node_num++;
            edges.emplace_back(); // 追加一个空数组
        }
    }

    void addEdge(string& word) {
        addNode(word);
        int id1 = node_id[word];
        for (char& c : word) {
            char tmp = c;
            c = '*';
            addNode(word);
            int id2 = node_id[word];
            edges[id1].push_back(id2);
            edges[id2].push_back(id1);
            c = tmp;
        }
    }

    int ladderLength(string& beginWord, string endWord, vector<string> wordList) {
        for (string word : wordList) {
            addEdge(word);
        }
        addEdge(beginWord);

        if (node_id.find(endWord) == node_id.end()) {
            return 0;
        }

        int begin = node_id[beginWord];
        int end = node_id[endWord];
        vector<int> dis(node_num, INT_MAX);
        dis[begin] = 0;
        queue<int> q;
        q.push(begin);
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (u == end) {
                return dis[end] / 2 + 1; // 找到即结束
            }
            for (int v : edges[u]) {
                if (dis[v] == INT_MAX) { // 确保不是环
                    q.push(v);
                    dis[v] = dis[u] + 1;
                }
            }
        }

        return 0;
    }
};
