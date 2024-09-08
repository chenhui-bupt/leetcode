/**
 * 算法：贪心算法-优先最近的大任务
 */
class Solution {
public:
	int leastInterval(vector<char>& tasks, int n) {
		 unordered_map<char, int> mp;
		 for (char task : tasks) {
		 	mp[task]++;
		 }

		 // 1.初始化：记录任务下次执行时间和剩余任务数
		 vector<int> nextTime;
		 vector<int> restTasks;
		 for (auto [k, v] : mp) {
		 	nextTime.push_back(1); // 也可以为0，则函数返回时，为res + 1
		 	restTasks.push_back(v);
		 }

		 // 2.执行任务
		 int res = 0;
		 for (int i = 0; i < tasks.size(); ++i) {
		 	// 2.0 执行一个任务
		 	res++;

		 	// 2.1 寻找最近执行的任务时间，并累加任务的总体耗时
		 	int minTime = INT_MAX;
		 	for (int t : nextTime) {
		 		minTime = std::min(minTime, t);
		 	}
		 	res = max(res, minTime);

		 	// 2.2 寻找剩余任务数最多的任务
		 	int task = -1;
		 	for (int j = 0; j < restTasks.size(); ++j) {
		 		if (restTasks[j] > 0 && nextTime[j] <= res && (task == -1 || restTasks[task] <= restTasks[j])) {
		 			task = j;
		 		}
		 	}

		 	// 3.更新任务状态，包括下次任务执行时间和剩余任务数
		 	nextTime[task] = res + n + 1;
		 	restTasks[task]--;
		 }
		 return res;
}