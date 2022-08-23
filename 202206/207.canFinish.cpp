/*
方法一：递减法
（1）先计算每个节点的入度大小和出度关系
（2）遍历节点，找到入度为0的节点（即没有父亲节点依赖），可以直接完成，把他们放进队列queue中
（3）执行队列任务：即相继弹出可以被完成的节点，同时给孩子节点的入度各减一，若孩子节点入度为0，则放入队列中
（4）记录队列弹出的个数与课程数比较，看是否完成所有课程

方法二：Floyd判圈算法
visited[i] == 0，递归
== 1，返回false
否则，= 2，表明可以完成！

*/
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, int> inDegree;
        unordered_map<int, vector<int>> edges;
        for (auto prerequisite : prerequisites) {
            inDegree[prerequisite[0]]++;
            if (edges.find(prerequisite[1]) == edges.end()) {
                edges[prerequisite[1]] = vector<int>();
            }
            edges[prerequisite[1]].push_back(prerequisite[0]);
        }

        queue<int> q;
        int courses = 0;
        for (auto iter = inDegree.begin(); iter != inDegree.end(); ++iter) {
            if (iter->second == 0) {
                q.push(iter->first);
            }
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            courses++;
            for (int v : edges[u]) {
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        return numCourses == courses;
    }

};



class Solution {
public:
    bool valid = true;

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edges;
        edges.resize(numCourses);
        vector<int> visited;
        visited.resize(numCourses);
        for (auto prerequisite : prerequisites) {
            edges[prerequisite[1]].push_back(prerequisite[0]);
        }

        for (int i = 0; i < numCourses; ++i) {
            if (visited[i] == 0 && valid) {
                dfs(edges, visited, i);
            }
        }
        return valid;
    }

    void dfs(vector<vector<int>>& edges, vector<int>& visited, int i) {
        // 0表示未处理，1表示有环（任务结束），2表示任务处理完成
        visited[i] = 1;
        for (int j : edges[i]) {
            if (visited[j] == 0) {
                dfs(edges, visited, j);
            } else if (visited[j] == 1) {
                valid = false;
                return;
            }
        }
        visited[i] = 2; // 课程i完成
        //res.push_back(i);
    }
};