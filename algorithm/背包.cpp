int main () {
	int N = 3;
	int W = 4;
	int wt[] = {1, 1, 3};
	int v[] = {4, 2, 3};
	// 两个状态，一个是物品的个数，一个是物品的重量
	vector<vector<int>> dp(N+1, vector<int>(W+1));
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= W; ++j) {
			if (wt[i-1] > j) {
				dp[i][j] = dp[i-1][j];
			} else {
				dp[i][j] = max(dp[i-1][j], v[i-1] + dp[i-1][j - wt[i-1]]);
			}
			cout << i << ", " << j << ", " << dp[i][j] << endl;
		}
	}
	cout << dp[N][W];
}