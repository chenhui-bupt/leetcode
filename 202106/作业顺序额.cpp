

vector<vector<int>> edges;
vector<int> inDegree;
vector<int> result;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
	// 宽度有限搜索
	edges.resize(numCourses);
	inDegree.resize(numCourses);
	cout << inDegree.size() << "," << inDegree.capacity() << endl;

	for (const auto& edge : prerequisites) {
		edges[edge[1]].push_back(edge[0]);
		++inDegree[edge[0]];
	}

	queue<int> q;
	for (int i = 0; i < numCourses; ++i) {
		if (inDegree[i] == 0) {
			q.push(i);
		}
	}
	
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		result.push_back(u);

		for (int v : edge[u]) {
			--inDegree[v];
			if (inDegree[v] == 0) {
				q.push(v);
			}
		}
	}

	return result;

	for (int i = 0; i < numCourses && valid; ++i) {
		if (!visited[i]) {
			dfs(i);
		}
	}

	if (!valid) {
		return {};
	} else {
		return result;
	}
}


void dfs(u) {
	if (!valid) {
		return;
	}
	visited[i] = 1;
	for (int v : edges[u]) {
		if (visited[v] == 1) {
			valid = false;
		} else {
			dfs(v);
		}
	}
	visited[u] = 2;
	result.push_back(u);
}