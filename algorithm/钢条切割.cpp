int main() {
    vector<int> prices = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int n = prices.size();
    vector<int> dp(n + 1);
    for (int i = 1; i <= n; ++i) {
        int maxPrice = dp[i];
        for (int j = 0; j <= i / 2; ++j) {
            maxPrice = max(maxPrice, prices[j] + prices[i - j]);
        }
        dp[i] = maxPrice;
    }
    return dp[n];
}