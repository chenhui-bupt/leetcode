// bfs
class Solution {
public:
	vector<vector<int>> edges;
	vector<int> inDegree;
	vector<int> ans;

	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		edges.resize(numCourses);
		inDegree.resize(numCourses);

		for (auto& prerequisite : prerequisites) {
			edges[prerequisite[1]].push_back(prerequisite[0]);  // 父亲节点的孩子节点
			inDegree[prerequisite[0]]++; // 孩子节点的入度++			
		}

		queue<int> q;
		for (int i = 0; i < numCourses; ++i) {
			if (inDegree[i] == 0) {
				q.push(i);
			}
		}

		while (!q.empty()) {
			int i = q.front();
			ans.push_back(i);
			q.pop();
			for (int j : edges[i]) {
				inDegree[j]--;
				if (inDegree[j] == 0) {
					q.push(j);
				}
			}
		}
		return ans.size() == numCourses;
	}
}


// dfs
class Solution {
public:
	vector<vector<int>> edges;
	vector<int> visited;
	bool valid = true;
	vector<int> ans;

	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		edges.resize(numCourses);
		visited.resize(numCourses);

		for (auto& prerequisite : prerequisites) {
			edges[prerequisite[1]].push_back(prerequisite[0]);
		}

		for (int i = 0; i < numCourses && valid; ++i) {
			if (visited[i] == 0) {
				dfs(i);
			}
		}
		return valid;
	}

	void dfs(int i) {
		if (!valid) {
			return;
		}

		visited[i] = 1;
		for (int j : edges[i]) {
			if (visited[j] == 1) {
				valid = false;
				return;
			}
			if (visited[j] == 0) {
				dfs(j);
			}
		}
		visited[i] = 2;
		ans.push_back(i);
	}
}