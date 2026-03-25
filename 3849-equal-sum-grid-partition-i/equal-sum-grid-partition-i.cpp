class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        long long total = 0;

        // Step 1: total sum
        for (auto &row : grid) {
            for (int val : row) {
                total += val;
            }
        }

        // If total is odd → impossible
        if (total % 2 != 0) return false;

        long long curr = 0;

        // Step 2: horizontal cut
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n; j++) {
                curr += grid[i][j];
            }
            if (curr == total - curr) return true;
        }

        // Step 3: vertical cut
        curr = 0;
        for (int j = 0; j < n - 1; j++) {
            for (int i = 0; i < m; i++) {
                curr += grid[i][j];
            }
            if (curr == total - curr) return true;
        }

        return false;
    }
};