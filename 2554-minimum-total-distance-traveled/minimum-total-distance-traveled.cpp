class Solution {
public:
    vector<vector<long long>> dp;

    long long solve(int i, int j, vector<int>& robot, vector<int>& fac) {
        if (i == robot.size()) return 0;
        if (j == fac.size()) return 1e15;

        if (dp[i][j] != -1) return dp[i][j];

        long long skip = solve(i, j + 1, robot, fac);
        long long take = abs((long long)robot[i] - fac[j]) + solve(i + 1, j + 1, robot, fac);

        return dp[i][j] = min(skip, take);
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        vector<int> fac;
        for (auto &f : factory) {
            for (int i = 0; i < f[1]; i++) {
                fac.push_back(f[0]);
            }
        }

        dp.resize(robot.size(), vector<long long>(fac.size(), -1));

        return solve(0, 0, robot, fac);
    }
};