class Solution {
public:
    int dp[100001][2][3];

    int solve(vector<int>& prices, int i, int buy, int cap) {
        if (i == prices.size() || cap == 0)
            return 0;

        if (dp[i][buy][cap] != -1)
            return dp[i][buy][cap];

        if (buy) {
            return dp[i][buy][cap] = max(
                -prices[i] + solve(prices, i + 1, 0, cap),   // Buy
                solve(prices, i + 1, 1, cap)                 // Skip
            );
        } else {
            return dp[i][buy][cap] = max(
                prices[i] + solve(prices, i + 1, 1, cap - 1), // Sell
                solve(prices, i + 1, 0, cap)                  // Skip
            );
        }
    }

    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return solve(prices, 0, 1, 2);
    }
};