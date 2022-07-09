/*
除法求值
方法一：宽度优先搜索
方法二：Floyd算法
方法三：并查集
*/

// 方法一：宽度优先搜索
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // 1.编码
        unordered_map<string, int> node_id;
        int num = 0;
        for (auto& equation : equations) {
            if (node_id.find(equation[0]) == node_id.end()) {
                node_id[equation[0]] = num++;
            }
            if (node_id.find(equation[1]) == node_id.end()) {
                node_id[equation[1]] = num++;
            }
        }

        // 2.建立边的关系，并存储除数
        vector<vector<pair<int, double>>> edges(num);
        for (int i = 0; i < equations.size(); ++i) {
            auto& equation = equations[i];
            int ia = node_id[equation[0]];
            int ib = node_id[equation[1]];
            edges[ia].push_back(pair<int, double>(ib, values[i]));
            edges[ib].push_back(pair<int, double>(ia, 1.0 / values[i]));
        }

        // 3.宽度优先搜索，计算结果
        vector<double> res;
        for (auto& query : queries) {
            double result = -1.0;
            if (node_id.find(query[0]) != node_id.end() && node_id.find(query[1]) != node_id.end()) {
                int ia = node_id[query[0]];
                int ib = node_id[query[1]];
                vector<double> weights(num, -1.0);
                weights[ia] = 1.0;
                queue<int> q;
                q.push(ia);
                while (!q.empty() && weights[ib] == -1.0) { // 找不到 或者 找到ib退出
                    int u = q.front();
                    q.pop();
                    for (auto [v, w] : edges[u]) {
                        if (weights[v] == -1.0) {
                            q.push(v);
                            weights[v] = weights[u] * w;
                        }
                    }
                }
                result = weights[ib];
            }
            res.push_back(result);
        }
        return res;
    }
};

// 方法二：Floyd算法
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double> values, vector<vector<strint>>& queries) {
        // 1.编码
        unordered_map<string, int> node_id;
        int num = 0;
        for (auto& equation : equations) {
            if (node_id.find(equation[0]) == node_id.end()) {
                node_id[equation[0]] = num++;
            }
            if (node_id.find(equation[1]) == node_id.end()) {
                node_id[equation[1]] = num++;
            }
        }

        // 2.建立图，并存储除法值
        vector<vector<double>> graph(num, vector<double>(num, -1.0));
        for (int i = 0; i < equations.size(); ++i) {
            auto& equation = equations[i];
            int ia = node_id[equation[0]];
            int ib = node_id[equation[1]];
            graph[ia][ib] = values[i];
            graph[ib][ia] = 1.0 / values[i];
        }

        // 3.Floyd算法
        // 一定要k在最外层循环，因为k是动态规划的阶段
        for (int k = 0; k < num; ++k) { 
            for (int i = 0; i < num; ++i) {
                for (int j = 0; j < num; ++j) {
                    if (graph[i][k] > 0 && graph[k][j] > 0) {
                        graph[i][j] = graph[i][k] * graph[k][j];
                    }
                }
            }
        }

        // 4.查询
        vector<double> res;
        for (auto& query : queries) {
            double result = -1.0;
            if (node_id.find(query[0]) != node_id.end() && node_id.find(query[1]) != node_id.end()) {
                int ia = node_id[query[0]];
                int ib = node_id[query[1]];
                result = graph[ia][ib];
            }
            res.push_back(result);
        }
        return res;
    }
};

// 方法三：并查集
class Solution {
public:
    vector<int> parents;
    vector<double> weights;

public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double> values, vector<vector<string>> queries) {
        // 1.编码
        unordered_map<string, int> node_id;
        int num = 0;
        for (auto& equation : equations) {
            if (node_id.find(equation[0]) == node_id.end()) {
                node_id[equation[0]] = num++;
            }
            if (node_id.find(equation[1]) == node_id.end()) {
                node_id[equation[1]] = num++;
            }
        }

        // 2.并查集初始化
        parents.resize(num);
        weights.resize(num, 1.0);
        for (int i = 0; i < num; ++i) {
            parents[i] = i;
        }

        for (int i = 0; i < equations.size(); ++i) {
            auto& equation = equations[i];
            int ia = node_id[equation[0]];
            int ib = node_id[equation[1]];
            union_func(ia, ib, valuex[i]);
        }

        // 3.查找
        vector<double> res;
        for (auto& query : queries) {
            double result = -1.0;
            if (node_id.find(query[0]) != node_id.end() && node_id.find(query[1]) != node_id.end()) {
                int ia = node_id[query[0]];
                int ib = node_id[query[1]];
                int pa = find(ia);
                int pb = find(ib);
                if (pa == pb) {
                    result = weights[ia] / weights[ib];
                }
            }
            res.push_back(result);
        }
        return res;
    }

    // 路径压缩
    int find(int x) {
        if (x != parents[x]) {
            int ori_p = parents[x]; // x当前的父亲
            int p = find(parents[x]); // x新的父亲
            weights[x] = weights[x] * weights[ori_p]; // 更新权值和父亲节点
            parents[x] = p;
        }
        return parents[x];
    }

    // 边查找边路径压缩
    void union_func(int x, int y, double value) {
        int px = find(x);
        int py = find(y);
        parents[px] = py;
        weights[px] = weights[y] * value / weights[x];
    }

};