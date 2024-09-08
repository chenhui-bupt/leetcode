/*
此题是第207题一样，只不过该题需要输出课程的顺序
算法思路：
1、编码（该题已编好码）
2、构建邻接矩阵edges和入度
3、宽度优先遍历，记录课程的完成顺序
4、判断是否完成
*/

// 算法一、宽度优先遍历
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edges(numCourses, vector<int>());
        vector<int> inDegree(numCourses);
        for (auto& prerequisite : prerequisites) {
            int ia = prerequisite[0];
            int ib = prerequisite[1];
            edges[ib].push_back(ia);
            inDegree[ia]++;
        }

        vector<int> res;
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            res.push_back(u);
            for (int v : edges[u]) {
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        if (res.size() == numCourses) {
            return res;
        } else {
            return {};
        }
    }
};


// 算法二、深度优先遍历：floyd判圈法
class Solution {
public:
    vector<int> res;
    bool valid = true;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edges(numCourses);
        vector<int> visited(numCourses);
        for (auto prerequisite : prerequisites) {
            edges[prerequisite[1]].push_back(prerequisite[0]);
        }
        for (int i = 0; i < numCourses; ++i) {
            if (visited[i] == 0 && valid) {
                dfs(edges, visited, i, res);
            }
        }
        if (!valid) {
            return {};
        } else {
            reverse(res.begin(), res.end());
            return res;
        } 
    }

    void dfs(vector<vector<int>>& edges, vector<int>& visited, int i, vector<int>& res) {
        visited[i] = 1;
        for (int j : edges[i]) {
            if (visited[j] == 0) {
                dfs(edges, visited, j, res);
            } else if (visited[j] == 1) {
                valid = false;
                return;
            }
        }
        res.push_back(i);
        visited[i] = 2;
    }
};