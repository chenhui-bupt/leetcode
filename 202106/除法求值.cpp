// 广度优先搜索
/*
1. 节点编码
2. 存储边的关系
3. 迭代查找
*/
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    	unordered_map<string, int> node_id;
    	int node_num = 0;
    	for (auto& equation : equations) {
    		if (node_id.find(equation[0]) == node_id.end()) {
    			node_id[equation[0]] = node_num++;
    		}

    		if (node_id.find(equation[1]) == node_id.end()) {
    			node_id[equation[1]] = node_num++;
    		}
    	}

    	vector<vector<pair<int, double>>> edges(node_num);
    	for (int i = 0; i < equations.size(); ++i) {
    		int ia = node_id[equations[i][0]];
    		int ib = node_id[equations[i][1]];
    		edges[ia].push_back(make_pair(ib, values[i]));
    		edges[ib].push_back(make_pair(ia, 1.0 / values[i]));
    	}

    	vector<double> res;
    	for (auto & query : queries) {
    		double result = -1.0;
    		if (node_id.find(query[0]) != node_id.end() && node_id.find(query[1]) != node_id.end()) {
    			int ia = node_id[query[0]];
    			int ib = node_id[query[1]];
    			if (ia == ib) {
    				result = 1.0;
    			} else {
    				queue<int> q;
	    			q.push(ia);
	    			vector<double> weights(node_num, -1.0);
	    			weights[ia] = 1.0;
	    			while (!q.empty() && weights[ib] < 0) {
	    				int u = q.front();
	    				q.pop();
	    				for (auto [v, w] : edges[u]) {
	    					if (weights[v] < 0) {
	    						q.push(v);
	    						weights[v] = weights[u] * w;
	    					}
	    				}
	    			}
	    			result = weights[ib];
    			}
    		}
    		res.push_back(result);
    	}
    	return res;
    }
};

// Floyd算法
/*
1. 节点编码
2. 构建图
3. Floyd算法，计算节点间路径权值
4. 查找
*/
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    	unordered_map<string, int> node_id;
    	int node_num = 0;
    	for (auto& equation : equations) {
    		if (node_id.find(equation[0]) == node_id.end()) {
    			node_id[equation[0]] = node_num++;
    		}

    		if (node_id.find(equation[1]) == node_id.end()) {
    			node_id[equation[1]] = node_num++;
    		}
    	}

    	vector<vector<double>> graph(node_num, vector(node_num, -1.0));
    	for (int i = 0; i < equations.size(); ++i) {
    		int ia = node_id[equations[i][0]];
    		int ib = node_id[equations[i][1]];
    		graph[ia][ib] = values[i];
    		graph[ib][ia] = 1.0 / values[i];
    	}

    	for (int k = 0; k < node_num; ++k) {
    		for (int i = 0; i < node_num; ++i) {
    			for (int j = 0; j < node_num; ++j) {
    				if (graph[i][k] > 0 && graph[k][j] > 0) {
    					graph[i][j] = graph[i][k] * graph[k][j];
    				}
    			}
    		}
    	}

    	vector<double> res;
    	for (auto& query : queries) {
    		double result = -1.0;
    		if (node_id.find(query[0]) != node_id.end() && node_id.find(query[1]) != node_id.end()) {
    			int ia = node_id[query[0]];
    			int ib = node_id[query[1]];
    			if (graph[ia][ib] > 0) {
    				result = graph[ia][ib];
    			}
    		}
    		res.push_back(result);
    	}
    	return res;
    }
};

// 并查集
/*
1. 节点编码
2. 初始化并查集，合并节点
3. 查找, 并更新并查集
*/
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    	unordered_map<string, int> node_id;
    	int node_num = 0;
    	for (auto& equation : equations) {
    		if (node_id.find(equation[0]) == node_id.end()) {
    			node_id[equation[0]] = node_num++;
    		}

    		if (node_id.find(equation[1]) == node_id.end()) {
    			node_id[equation[1]] = node_num++;
    		}
    	}

    	parents.resize(node_num);
    	weight.resize(node_num, 1.0);
    	for (int i = 0; i < node_num; ++i) {
    		parents[i] = i;
    		weight[i] = 1.0;
    	}

    	for (int i = 0; i < equations.size(); ++i) {
    		int ia = node_id[equations[i][0]];
    		int ib = node_id[equations[i][1]];
    		union_func(ia, ib, values[i]);
    	}

    	vector<double> res;
    	for (auto& query : queries) {
    		double result = -1.0;
    		if (node_id.find(query[0]) != node_id.end() && node_id.find(query[1]) != node_id.end()) {
    			int ia = node_id[query[0]];
    			int ib = node_id[query[1]];
    			int pa = find(ia);
    			int pb = find(ib);
    			if (pa == pb) {
    				result = weight[ia] / weight[ib];
    			}
    		}
    		res.push_back(result);
    	}
    	return res;
    }

private:
	vector<int> parents;
	vector<double> weight;

	int find(int x) {
		if (parents[x] != x) {
			int p = find(parents[x]);
			weight[x] = weight[x] * weight[parents[x]];
			parents[x] = p;
		}
		return parents[x];
	}

	void union_func(int x, int y, double value) {
		int px = find(x);
		int py = find(y);
		parents[px] = py;
		weight[px] = value * weight[y] / weight[x];
	}
};